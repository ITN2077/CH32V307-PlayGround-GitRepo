/**
 * @file SHT40.c
 * @brief SHT40温湿度传感器驱动实现
 * @details 本文件实现了SHT40温湿度传感器的底层驱动，包括I2C通信、数据读取和转换等功能
 */

#include "SHT40.h"

// #include "i2c.h"

// #include <rtthread.h>
// #include <rtdbg.h>

// #define SHT40_ADDR_WRITE 0x44 << 1      // 10001000
// #define SHT40_ADDR_READ (0x44 << 1) + 1 // 10001011

// #define CRC8_POLYNOMIAL 0x31

// uint8_t SHT40_CheckCrc8(uint8_t *const message, uint8_t initial_value)
// {
//     uint8_t remainder;    // 余数
//     uint8_t i = 0, j = 0; // 循环变量

//     /* 初始化 */
//     remainder = initial_value;

//     for (j = 0; j < 2; j++)
//     {
//         remainder ^= message[j];

//         /* 从最高位开始依次计算  */
//         for (i = 0; i < 8; i++)
//         {
//             if (remainder & 0x80)
//             {
//                 remainder = (remainder << 1) ^ CRC8_POLYNOMIAL;
//             }
//             else
//             {
//                 remainder = (remainder << 1);
//             }
//         }
//     }

//     /* 返回计算的CRC码 */
//     return remainder;
// }
// /**
//  * @brief   向SHT40发送一条指令(16bit)
//  * @param   cmd —— SHT40指令（在etCommands中枚举定义）
//  * @retval  成功返回HAL_OK
//  */
// static uint8_t SHT40_Send_Cmd(SHT40Command cmd)
// {
//     uint8_t cmd_buffer = 0;
//     cmd_buffer = cmd;
//     return HAL_I2C_Master_Transmit(&hi2c1, SHT40_ADDR_WRITE, (uint8_t *)&cmd_buffer, 1, 0x00FF);
// }
// /**
//  * @brief   复位SHT40
//  * @param   none
//  * @retval  none
//  */
// void SHT40_reset(void)
// {
//     SHT40_Send_Cmd(SHT4X_CMD_SOFT_RESET);
//     //    HAL_Delay(20);
//     rt_thread_mdelay(20);
// }
// /**
//  * @brief   初始化SHT40
//  * @param   none
//  * @retval  成功返回HAL_OK
//  * @note    周期测量模式
//  */
// uint8_t SHT40_Init(void)
// {
//     return SHT40_Send_Cmd(SHT4X_CMD_MEASURE_HPM);
// }
// /**
//  * @brief   从SHT40读取一次数据
//  * @param   dat —— 存储读取数据的地址（6个字节数组）
//  * @retval  成功 —— 返回HAL_OK
//  */
// uint8_t SHT40_Read_Dat(uint8_t *dat)
// {
//     SHT40_Send_Cmd(SHT4X_CMD_MEASURE_HPM);
//     rt_thread_mdelay(10);
//     return HAL_I2C_Master_Receive(&hi2c1, SHT40_ADDR_READ, dat, 6, 0xFFFF);
// }
// /**
//  * @brief   将SHT40接收的6个字节数据进行CRC校验，并转换为温度值和湿度值
//  * @param   dat  —— 存储接收数据的地址（6个字节数组）
//  * @retval  校验成功  —— 返回0
//  *          校验失败  —— 返回1，并设置温度值和湿度值为0
//  */
// uint8_t SHT40_Dat_To_Float(uint8_t *const dat, float *temperature, float *humidity)
// {
//     uint16_t recv_temperature = 0;
//     uint16_t recv_humidity = 0;

//     /* 校验温度数据和湿度数据是否接收正确 */
//     if (SHT40_CheckCrc8(dat, 0xFF) != dat[2] || SHT40_CheckCrc8(&dat[3], 0xFF) != dat[5])
//         return 1;

//     /* 转换温度数据 */
//     recv_temperature = ((uint16_t)dat[0] << 8) | dat[1];
//     *temperature = -45 + 175 * ((float)recv_temperature / 65535);

//     /* 转换湿度数据 */
//     recv_humidity = ((uint16_t)dat[3] << 8) | dat[4];
//     *humidity = -6 + 125 * ((float)recv_humidity / 65535);
//     if (*humidity >= 100) // 根据数据手册编写
//         *humidity = 100;
//     else if (*humidity <= 0)
//         *humidity = 0;
//     return 0;
// }

#include "sht40.h"

/*────────────────  内部辅助函数  ────────────────*/

/**
 * @brief 计算CRC8校验值
 * @param d 数据指针
 * @param len 数据长度
 * @return CRC8校验值
 * @note 使用多项式0x31进行CRC8计算
 */
static uint8_t _crc8(const uint8_t *d, size_t len)
{
    uint8_t crc = 0xFF;
    while (len--)
    {
        crc ^= *d++;
        for (uint8_t i = 0; i < 8; ++i)
            crc = (crc & 0x80) ? (crc << 1) ^ 0x31U : (crc << 1);
    }
    return crc;
}

/**
 * @brief 温度原始值转换为实际温度值
 * @param r 16位温度原始值
 * @return 实际温度值(°C)
 */
static inline float _t_conv(uint16_t r) { return -45.0f + 175.0f * (float)r / 65535.0f; }

/**
 * @brief 湿度原始值转换为实际湿度值
 * @param r 16位湿度原始值
 * @return 实际湿度值(%RH)
 */
static inline float _rh_conv(uint16_t r) { return 100.0f * (float)r / 65535.0f; }

/**
 * @brief 延时函数
 * @param ms 延时时间(毫秒)
 * @note 用户需要实现此函数，这里提供弱定义避免链接错误
 */
__attribute__((weak)) void sht40_delay_ms(uint32_t ms) { (void)ms; }

/*────────────────  基础I2C通信函数  ────────────────*/

/**
 * @brief 向SHT40写入8位命令
 * @param d SHT40设备结构体指针
 * @param c 8位命令
 * @return 0:成功 非0:失败
 */
static int _w8(const sht40_t *d, uint8_t c)
{
    return sht40_i2c_write(d->addr << 1, &c, 1);
}

/**
 * @brief 向SHT40写入16位命令
 * @param d SHT40设备结构体指针
 * @param c 16位命令
 * @return 0:成功 非0:失败
 */
static int _w16(const sht40_t *d, uint16_t c)
{
    uint8_t buf[2] = {(uint8_t)(c >> 8), (uint8_t)c};
    return sht40_i2c_write(d->addr << 1, buf, 2);
}

/**
 * @brief 从SHT40读取数据
 * @param d SHT40设备结构体指针
 * @param buf 数据缓冲区
 * @param n 要读取的字节数
 * @return 0:成功 非0:失败
 */
static int _r(const sht40_t *d, uint8_t *buf, size_t n)
{
    return sht40_i2c_read(d->addr << 1, buf, n);
}

/*────────────────  公共函数实现  ────────────────*/

/**
 * @brief 软件复位SHT40
 * @param dev SHT40设备结构体指针
 * @return SHT40_OK:成功 SHT40_E_IO:通信错误
 */
sht40_err_t sht40_soft_reset(sht40_t *dev)
{
    return _w8(dev, SHT40_CMD_SOFT_RESET) ? SHT40_E_IO : SHT40_OK;
}

/**
 * @brief 初始化SHT40
 * @param dev SHT40设备结构体指针
 * @return SHT40_OK:成功 SHT40_E_IO:通信错误
 */
sht40_err_t sht40_init(sht40_t *dev)
{
    sht40_err_t e = sht40_soft_reset(dev);
    sht40_delay_ms(10);
    return e;
}

/**
 * @brief 读取SHT40序列号
 * @param dev SHT40设备结构体指针
 * @param serial 序列号存储地址
 * @return SHT40_OK:成功 SHT40_E_IO:通信错误 SHT40_E_CRC:CRC校验错误
 */
sht40_err_t sht40_read_serial(sht40_t *dev, uint32_t *serial)
{
    uint8_t raw[6];
    if (_w8(dev, SHT40_CMD_READ_SERIAL) ||
            sht40_delay_ms(1),
        _r(dev, raw, 6))
        return SHT40_E_IO;
    if (_crc8(raw, 2) != raw[2] || _crc8(raw + 3, 2) != raw[5])
        return SHT40_E_CRC;
    *serial = (uint32_t)raw[0] << 24 | raw[1] << 16 | raw[3] << 8 | raw[4];
    return SHT40_OK;
}

/**
 * @brief 使用8位命令进行测量并返回原始数据
 * @param dev SHT40设备结构体指针
 * @param cmd 8位测量命令
 * @param rt 温度原始值存储地址
 * @param rh 湿度原始值存储地址
 * @return SHT40_OK:成功 SHT40_E_IO:通信错误 SHT40_E_CRC:CRC校验错误
 */
sht40_err_t sht40_measure_raw8(sht40_t *dev, uint8_t cmd,
                               uint16_t *rt, uint16_t *rh)
{
    uint8_t buf[6];
    if (_w8(dev, cmd))
        return SHT40_E_IO;

    /* 根据精度选择延时时间：高精度约10ms，中精度5ms，低精度2ms */
    sht40_delay_ms(cmd == SHT40_CMD_MEAS_HIGH ? 10 : cmd == SHT40_CMD_MEAS_MEDIUM ? 5
                                                                                  : 2);

    if (_r(dev, buf, 6))
        return SHT40_E_IO;
    if (_crc8(buf, 2) != buf[2] || _crc8(buf + 3, 2) != buf[5])
        return SHT40_E_CRC;

    *rt = (uint16_t)buf[0] << 8 | buf[1];
    *rh = (uint16_t)buf[3] << 8 | buf[4];
    return SHT40_OK;
}

/**
 * @brief 使用16位命令进行测量并返回原始数据
 * @param dev SHT40设备结构体指针
 * @param cmd 16位测量命令
 * @param rt 温度原始值存储地址
 * @param rh 湿度原始值存储地址
 * @return SHT40_OK:成功 SHT40_E_IO:通信错误 SHT40_E_CRC:CRC校验错误
 */
sht40_err_t sht40_measure_raw16(sht40_t *dev, uint16_t cmd,
                                uint16_t *rt, uint16_t *rh)
{
    /* 加热命令：根据位模式持续200ms或1s */
    if (_w16(dev, cmd))
        return SHT40_E_IO;
    sht40_delay_ms((cmd & 0x0F00) == 0x0900 ? 1000 : 200);

    uint8_t buf[6];
    if (_r(dev, buf, 6))
        return SHT40_E_IO;
    if (_crc8(buf, 2) != buf[2] || _crc8(buf + 3, 2) != buf[5])
        return SHT40_E_CRC;

    *rt = (uint16_t)buf[0] << 8 | buf[1];
    *rh = (uint16_t)buf[3] << 8 | buf[4];
    return SHT40_OK;
}

/**
 * @brief 使用8位命令进行测量并返回实际物理量
 * @param d SHT40设备结构体指针
 * @param c 8位测量命令
 * @param t 温度值存储地址(°C)
 * @param h 湿度值存储地址(%RH)
 * @return SHT40_OK:成功 其他:错误
 */
static sht40_err_t _conv8(sht40_t *d, uint8_t c, float *t, float *h)
{
    uint16_t rt, rh;
    sht40_err_t e = sht40_measure_raw8(d, c, &rt, &rh);
    if (e)
        return e;
    if (t)
        *t = _t_conv(rt);
    if (h)
        *h = _rh_conv(rh);
    return SHT40_OK;
}

/**
 * @brief 使用16位命令进行测量并返回实际物理量
 * @param d SHT40设备结构体指针
 * @param c 16位测量命令
 * @param t 温度值存储地址(°C)
 * @param h 湿度值存储地址(%RH)
 * @return SHT40_OK:成功 其他:错误
 */
static sht40_err_t _conv16(sht40_t *d, uint16_t c, float *t, float *h)
{
    uint16_t rt, rh;
    sht40_err_t e = sht40_measure_raw16(d, c, &rt, &rh);
    if (e)
        return e;
    if (t)
        *t = _t_conv(rt);
    if (h)
        *h = _rh_conv(rh);
    return SHT40_OK;
}

/**
 * @brief 单次测量温湿度
 * @param dev SHT40设备结构体指针
 * @param cmd 测量命令
 * @param t_c 温度值存储地址(°C)
 * @param rh 湿度值存储地址(%RH)
 * @return SHT40_OK:成功 其他:错误
 */
sht40_err_t sht40_measure_single(sht40_t *dev, uint8_t cmd,
                                 float *t_c, float *rh)
{
    return _conv8(dev, cmd, t_c, rh);
}

/**
 * @brief 带加热功能的温湿度测量
 * @param dev SHT40设备结构体指针
 * @param cmd 测量命令
 * @param t_c 温度值存储地址(°C)
 * @param rh 湿度值存储地址(%RH)
 * @return SHT40_OK:成功 其他:错误
 */
sht40_err_t sht40_measure_heater(sht40_t *dev, uint16_t cmd,
                                 float *t_c, float *rh)
{
    return _conv16(dev, cmd, t_c, rh);
}
