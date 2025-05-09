#ifndef WEIGHT_SENSOR_TTL_H
#define WEIGHT_SENSOR_TTL_H

#include <stdint.h>
#include <stdbool.h>
#include "Ring_Buffer.h"

typedef struct
{
    bool is_valid;
    uint8_t command;
    bool is_negative;
    int32_t value;
    int32_t pressure;
} weight_sensor_data_t;

/**
 * @brief 传感器句柄
 */
typedef struct
{
    uint8_t address;                                // 传感器模块地址
    int32_t zero_value;                             // AD零位值
    weight_sensor_data_t data;                     // 传感器数据
    char (*send)(const uint8_t *data, uint16_t len); // 平台发送函数（如 uart_send）
} WeightSensor_t;

// 基本命令接口（实例方法）
char WeightSensor_ReadAD(WeightSensor_t *sensor);
char WeightSensor_ReadWeight(WeightSensor_t *sensor);
char WeightSensor_Tare(WeightSensor_t *sensor);
char WeightSensor_Zero(WeightSensor_t *sensor);
// void handle_sensor_data_pressure(WeightSensor_t *sensor);

// 数据解析接口（静态），从环形缓冲区中解析数据，需要快速轮询调用。
char WeightSensor_ParseFromRingBuffer(ring_buffer_t *buffer, WeightSensor_t *sensor);

#endif
