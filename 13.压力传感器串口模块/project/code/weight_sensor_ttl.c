/**
 * @file weight_sensor_ttl.c
 * @brief 称重传感器TTL模块实现
 * @details 该模块实现了与称重传感器TTL串口模块通信的功能
 */

#include "weight_sensor_ttl.h"

/* 命令格式定义 */
#define CMD_READ_AD 0xA1     /**< 读取AD值命令 */
#define CMD_READ_WEIGHT 0xA3 /**< 读取重量命令 */
#define CMD_ZERO 0xAA        /**< 零点校准命令 */
#define CMD_TARE 0xAB        /**< 去皮操作命令 */

#define CMD_START_BYTE 0xAA /**< 返回数据起始字节 */
#define CMD_END_BYTE 0xFF   /**< 返回数据结束字节 */
#define CMD_RSP_LEN 10      /**< 返回数据长度 */

/**
 * @brief 计算校验位
 * @param data 数据数组
 * @param len 数据长度
 * @return 校验值
 */
static uint8_t calc_checksum(const uint8_t *data, uint8_t len)
{
    uint8_t checksum = 0;
    for (uint8_t i = 0; i < len; i++)
    {
        checksum ^= data[i];
    }
    return checksum;
}

/* 串口发送回调函数 */
static uart_send_callback_t uart_send_cb = (void *)0;

/**
 * @brief 发送命令
 * @param cmd 命令字
 * @param address 模块地址
 * @return 0表示成功，非0表示失败
 */
static int send_command(uint8_t cmd, uint8_t address)
{
    uint8_t cmd_buf[5];

    /* 根据说明书格式构建命令 */
    cmd_buf[0] = cmd;                       /* 命令字 */
    cmd_buf[1] = address;                   /* 模块地址 */
    cmd_buf[2] = (uint8_t)(cmd - 1);        /* 由第一个字节减1得到 */
    cmd_buf[3] = (uint8_t)(cmd + 1);        /* 由第一个字节加1得到 */
    cmd_buf[4] = calc_checksum(cmd_buf, 4); /* 前4个字节的异或校验码 */

    if (uart_send_cb == (void *)0)
    {
        return -1;
    }

    return (uart_send_cb(cmd_buf, sizeof(cmd_buf)) == sizeof(cmd_buf)) ? 0 : -1;
}

int weight_sensor_init(uart_send_callback_t send_cb)
{
    if (send_cb == (void *)0)
    {
        return -1;
    }

    uart_send_cb = send_cb;
    return 0;
}

int weight_sensor_read_ad(uint8_t address)
{
    return send_command(CMD_READ_AD, address);
}

int weight_sensor_read_weight(uint8_t address)
{
    return send_command(CMD_READ_WEIGHT, address);
}

int weight_sensor_tare(uint8_t address)
{
    return send_command(CMD_TARE, address);
}

int weight_sensor_zero(uint8_t address)
{
    return send_command(CMD_ZERO, address);
}

/**
 * @brief 解析一帧数据
 * @param frame 完整的数据帧 (10字节)
 * @param result 解析结果
 * @return 0表示成功，非0表示失败
 */
static int parse_frame(const char *frame, weight_sensor_data_t *result)
{
    uint16_t checksum;
    uint16_t calculated_checksum = 0;
    const uint8_t *data = (const uint8_t *)frame;

    /* 检查参数有效性 */
    if (data == (void *)0 || result == (void *)0)
    {
        return -1;
    }

    /* 检查数据帧格式是否正确 */
    if (data[0] != CMD_START_BYTE || data[CMD_RSP_LEN - 1] != CMD_END_BYTE)
    {
        return -1;
    }

    /* 计算校验和 */
    for (int i = 1; i < 7; i++)
    {
        calculated_checksum += data[i];
    }

    /* 获取接收到的校验和 */
    checksum = data[7] * 256 + data[8];

    /* 验证校验和 */
    if (calculated_checksum != checksum)
    {
        return -1;
    }

    /* 填充结果 */
    result->command = data[1]; /* 返回的命令字 */
    result->address = data[2]; /* 模块地址 */

    /* 根据返回命令类型判断数据格式 */
    if (data[1] == CMD_READ_AD)
    {
        /* 读取AD值 */
        result->is_negative = false;
        result->value = ((uint32_t)data[4] << 16) | ((uint32_t)data[5] << 8) | data[6];
    }
    else
    {
        /* 读取重量值或其他命令响应 */
        result->is_negative = (data[3] == 1);
        result->value = ((uint32_t)data[4] << 16) | ((uint32_t)data[5] << 8) | data[6];

        /* 如果是负数，转换为负值 */
        if (result->is_negative)
        {
            result->value = -result->value;
        }
    }

    result->is_valid = true;
    return 0;
}

int weight_sensor_parse_from_ringbuffer(ring_buffer_t *buffer, weight_sensor_data_t *result)
{
    uint8_t frame[CMD_RSP_LEN]; // 临时缓冲区，存放完整数据帧
    ring_buffer_size_t available_items;
    uint8_t byte;
    int i, j;

    /* 初始化结果 */
    if (result)
    {
        result->is_valid = false;
    }

    /* 检查参数有效性 */
    if (buffer == (void *)0 || result == (void *)0)
    {
        return -1;
    }

    /* 获取缓冲区中可用数据量 */
    available_items = ring_buffer_num_items(buffer);

    /* 确保有足够的数据可供解析 */
    if (available_items < CMD_RSP_LEN)
    {
        return -1;
    }

    /* 在缓冲区中查找数据帧起始标志 */
    for (i = 0; i < available_items - CMD_RSP_LEN + 1; i++)
    {
        /* 获取一个字节 */
        if (ring_buffer_peek(buffer, &byte, i) == 0)
        {
            return -1;
        }

        /* 找到起始标志 */
        if (byte == CMD_START_BYTE)
        {
            /* 检查结束标志是否匹配 */
            if (ring_buffer_peek(buffer, &byte, i + CMD_RSP_LEN - 1) == 0 || byte != CMD_END_BYTE)
            {
                /* 结束标志不匹配，继续查找 */
                continue;
            }

            /* 复制一个完整的数据帧到临时缓冲区 */
            for (j = 0; j < CMD_RSP_LEN; j++)
            {
                if (ring_buffer_peek(buffer, (uint8_t *)&frame[j], i + j) == 0)
                {
                    return -1;
                }
            }

            /* 解析数据帧 */
            if (parse_frame(frame, result) == 0)
            {
                /* 解析成功，丢弃已处理的数据 */
                for (j = 0; j <= i + CMD_RSP_LEN - 1; j++)
                {
                    ring_buffer_dequeue(buffer, &byte);
                }
                return 1;
            }
            else
            {
                /* 解析失败，丢弃这一帧数据 */
                for (j = 0; j <= i + CMD_RSP_LEN - 1; j++)
                {
                    ring_buffer_dequeue(buffer, &byte);
                }
                return -1;
            }
        }
    }

    /* 未找到完整的数据帧 */
    return -1;
}
