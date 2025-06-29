/**
 * @file SHT40.h
 * @brief SHT40温湿度传感器驱动头文件
 * @details 提供SHT40温湿度传感器的I2C通信接口和功能函数
 */

#ifndef __SHT40_H
#define __SHT40_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*==========  用户可修改区域  ====================================*/
/**
 * @brief SHT40传感器I2C地址定义
 * @note 根据ADDR引脚连接方式选择对应的地址：
 *       - ADDR引脚接地(GND)：使用0x44
 *       - ADDR引脚接电源(VDD)：使用0x45
 */
#define SHT40_ADDR_GND 0x44U
#define SHT40_ADDR_VDD 0x45U
/*==========  END =================================================*/

/*────────────────  设备句柄  ────────────────*/
/**
 * @brief SHT40设备结构体
 * @details 用于存储SHT40设备的配置信息
 */
typedef struct
{
    uint8_t addr; /* 7-bit I²C 地址 */
} sht40_t;

/*────────────────  命令宏  ────────────────*/
/**
 * @brief 单次测量命令（8位，不带时钟拉伸，推荐使用）
 * @details 不同精度等级的测量命令，响应时间不同
 */
#define SHT40_CMD_MEAS_HIGH 0xFDU   /* 高精度测量，典型响应时间9-10ms */
#define SHT40_CMD_MEAS_MEDIUM 0xF6U /* 中等精度测量，典型响应时间约5ms */
#define SHT40_CMD_MEAS_LOW 0xE0U    /* 低精度测量，典型响应时间约2ms */
/* 16-bit：带加热功率 / 时长（200 ms 或 1 s）*/
#define SHT40_CMD_HEAT_200MS_20MW 0x3024U
#define SHT40_CMD_HEAT_200MS_110MW 0x3126U
#define SHT40_CMD_HEAT_200MS_200MW 0x322CU
#define SHT40_CMD_HEAT_1S_20MW 0x242FU
#define SHT40_CMD_HEAT_1S_110MW 0x2721U
#define SHT40_CMD_HEAT_1S_200MW 0x3920U
/* 其他 */
#define SHT40_CMD_SOFT_RESET 0x94U
#define SHT40_CMD_READ_SERIAL 0x89U /* 返回 6 字节 */

/**
 * @brief 错误码定义
 */
typedef enum
{
    SHT40_OK = 0,
    SHT40_E_IO = -1,
    SHT40_E_CRC = -2,
} sht40_err_t;

/*──────────────  API  ──────────────*/
/**
 * @brief 初始化SHT40传感器
 * @param dev 设备句柄指针
 * @return 错误码
 * @note 执行软复位并等待10ms
 */
sht40_err_t sht40_init(sht40_t *dev); /* 软复位 + 10 ms */
/**
 * @brief 执行软复位
 * @param dev 设备句柄指针
 * @return 错误码
 */
sht40_err_t sht40_soft_reset(sht40_t *dev);
/**
 * @brief 读取传感器序列号
 * @param dev 设备句柄指针
 * @param serial 序列号存储指针
 * @return 错误码
 */
sht40_err_t sht40_read_serial(sht40_t *dev, uint32_t *serial);

/**
 * @brief 执行单次测量（使用8位命令）
 * @param dev 设备句柄指针
 * @param cmd 测量命令
 * @param t_c 温度值存储指针（摄氏度）
 * @param rh 湿度值存储指针（相对湿度，百分比）
 * @return 错误码
 */
sht40_err_t sht40_measure_single(sht40_t *dev, uint8_t cmd,
                                    float *t_c, float *rh); /* 8-bit 命令 */
/**
 * @brief 执行带加热器的测量（使用16位命令）
 * @param dev 设备句柄指针
 * @param cmd 加热器命令
 * @param t_c 温度值存储指针（摄氏度）
 * @param rh 湿度值存储指针（相对湿度，百分比）
 * @return 错误码
 */
sht40_err_t sht40_measure_heater(sht40_t *dev, uint16_t cmd,
                                    float *t_c, float *rh); /* 16-bit 命令 */

/**
 * @brief 获取原始测量数据（8位命令）
 * @param dev 设备句柄指针
 * @param cmd 测量命令
 * @param raw_t 原始温度值存储指针
 * @param raw_rh 原始湿度值存储指针
 * @return 错误码
 */
sht40_err_t sht40_measure_raw8(sht40_t *dev, uint8_t cmd,
                                uint16_t *raw_t, uint16_t *raw_rh);
/**
 * @brief 获取原始测量数据（16位命令）
 * @param dev 设备句柄指针
 * @param cmd 测量命令
 * @param raw_t 原始温度值存储指针
 * @param raw_rh 原始湿度值存储指针
 * @return 错误码
 */
sht40_err_t sht40_measure_raw16(sht40_t *dev, uint16_t cmd,
                                uint16_t *raw_t, uint16_t *raw_rh);

/*─────────  平台适配层（必须由用户实现） ─────────*/
/**
 * @brief I2C写操作接口
 * @param addr 设备地址
 * @param data 要写入的数据
 * @param len 数据长度
 * @return 0表示成功，非0表示失败
 * @note 用户需要根据实际硬件平台实现此函数
 */
__attribute__((weak))
int8_t
sht40_i2c_write(uint8_t addr, const uint8_t *data, size_t len);
/**
 * @brief I2C读操作接口
 * @param addr 设备地址
 * @param data 数据存储缓冲区
 * @param len 要读取的数据长度
 * @return 0表示成功，非0表示失败
 * @note 用户需要根据实际硬件平台实现此函数
 */
__attribute__((weak))
int8_t
sht40_i2c_read(uint8_t addr, uint8_t *data, size_t len);

/**
 * @brief 毫秒延时函数
 * @param ms 延时时间（毫秒）
 * @note 用户可以根据需要实现此函数，默认为空实现
 */
__attribute__((weak)) void sht40_delay_ms(uint32_t ms);

#ifdef __cplusplus
}
#endif
#endif /* __SHT40_H */
