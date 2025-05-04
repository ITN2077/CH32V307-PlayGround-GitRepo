/**
 * @file weight_sensor_ttl.h
 * @brief 称重传感器TTL模块接口头文件
 * @details 该模块用于与称重传感器TTL串口模块通信，支持读取AD值、去皮操作和零点校准
 */

#ifndef WEIGHT_SENSOR_TTL_H
#define WEIGHT_SENSOR_TTL_H

#include <stdint.h>
#include <stdbool.h>
#include "Ring_Buffer.h" // 包含环形缓冲区头文件

/**
 * @brief 串口数据发送回调函数类型定义
 * @param data 待发送的数据
 * @param len 数据长度
 * @return 实际发送的字节数
 */
typedef int (*uart_send_callback_t)(const uint8_t *data, uint16_t len);

/**
 * @brief 传感器数据接收结果
 */
typedef struct
{
    bool is_valid;    /**< 数据是否有效 */
    uint8_t address;  /**< 模块地址 */
    uint8_t command;  /**< 命令字 */
    bool is_negative; /**< 是否为负值 */
    int32_t value;    /**< 数据值 */
} weight_sensor_data_t;

/**
 * @brief 初始化称重传感器模块
 * @param send_cb 平台的串口发送回调函数
 * @return 0表示成功，非0表示失败
 */
int weight_sensor_init(uart_send_callback_t send_cb);

/**
 * @brief 读取AD值
 * @param address 传感器模块地址(0-255)
 * @return 0表示成功，非0表示失败
 */
int weight_sensor_read_ad(uint8_t address);

/**
 * @brief 读取重量值
 * @param address 传感器模块地址(0-255)
 * @return 0表示成功，非0表示失败
 */
int weight_sensor_read_weight(uint8_t address);

/**
 * @brief 去皮操作(临时清零)
 * @param address 传感器模块地址(0-255)
 * @return 0表示成功，非0表示失败
 */
int weight_sensor_tare(uint8_t address);

/**
 * @brief 零点校准操作
 * @param address 传感器模块地址(0-255)
 * @return 0表示成功，非0表示失败
 */
int weight_sensor_zero(uint8_t address);

/**
 * @brief 从环形缓冲区中查找并解析一个完整的数据帧
 * @param buffer 环形缓冲区指针
 * @param result 解析结果
 * @return >0表示成功找到并处理了一帧数据，0表示没有完整数据帧，<0表示出错
 */
int weight_sensor_parse_from_ringbuffer(ring_buffer_t *buffer, weight_sensor_data_t *result);

#endif /* WEIGHT_SENSOR_TTL_H */