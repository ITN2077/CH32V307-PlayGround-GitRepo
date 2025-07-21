#include "weight_sensor_ttl_interface.h"

#define UART_INDEX UART_7
#define UART_TX_PIN UART7_MAP3_TX_E12
#define UART_RX_PIN UART7_MAP3_RX_E13

// 定义环形缓冲区
ring_buffer_t weight_sensor_ttl_uart_rx_buffer;
static uint8_t weight_sensor_ttl_uart_rx_buffer_data[64]; // 缓冲区大小可以根据需要调整

// 初始化串口及环形缓冲区
void weight_sensor_ttl_uart_init(void)
{
    // 初始化环形缓冲区
    ring_buffer_init(&weight_sensor_ttl_uart_rx_buffer, weight_sensor_ttl_uart_rx_buffer_data, sizeof(weight_sensor_ttl_uart_rx_buffer_data));

    // 初始化串口
    uart_init(UART_INDEX, 115200, UART_TX_PIN, UART_RX_PIN);
    uart_rx_interrupt(UART_INDEX, ENABLE);
    interrupt_set_priority(UART7_IRQn, 0);
}

// 串口中断处理函数
void uart_irq_handler(void)
{
    uint8_t byte = 0;
    if (uart_query_byte(UART_INDEX, &byte))
    {
        ring_buffer_queue(&weight_sensor_ttl_uart_rx_buffer, byte); // 将字节放入环形缓冲区
    }
}

int weight_sensor_ttl_uart_send(const uint8_t *data, uint16_t len)
{
    uart_write_buffer(UART_INDEX, data, len);
    return 0;
}

// 零位校准
void zero_calibration(WeightSensor_t *sensor)
{
    // 发送读取AD值命令
    WeightSensor_ReadAD(sensor);

    // 等待并解析数据
    while (1)
    {
        if (WeightSensor_ParseFromRingBuffer(&weight_sensor_ttl_uart_rx_buffer) == 1)
        {
            if (sensor->data.is_valid)
            { // 读取AD值响应且数据有效
                sensor->zero_value = sensor->data.value;
                break;
            }
        }
        // 如果数据无效，重新发送读取命令
        WeightSensor_ReadAD(sensor);
    }
    ring_buffer_init(&weight_sensor_ttl_uart_rx_buffer, weight_sensor_ttl_uart_rx_buffer_data, sizeof(weight_sensor_ttl_uart_rx_buffer_data));
}

WeightSensor_t sp3_sensor = {
    .address = 0x00,
    .send = weight_sensor_ttl_uart_send};

WeightSensor_t sp4_sensor = {
    .address = 0x01,
    .send = weight_sensor_ttl_uart_send};
