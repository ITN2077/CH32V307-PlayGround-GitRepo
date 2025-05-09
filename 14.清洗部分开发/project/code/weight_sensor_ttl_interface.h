#ifndef WEIGHT_SENSOR_TTL_INTERFACE_H
#define WEIGHT_SENSOR_TTL_INTERFACE_H
#include "weight_sensor_ttl.h"
#include "zf_common_headfile.h"
#include "Ring_Buffer.h"


// 初始化串口
void weight_sensor_ttl_uart_init(void);

// 串口中断处理函数
void uart_irq_handler(void);

// 零位校准
void zero_calibration(WeightSensor_t *sensor);

// 外部声明环形缓冲区
extern ring_buffer_t weight_sensor_ttl_uart_rx_buffer;

extern WeightSensor_t sp3_sensor;
extern WeightSensor_t sp4_sensor;

#endif
