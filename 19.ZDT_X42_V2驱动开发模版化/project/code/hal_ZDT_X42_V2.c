// ========================= hal_ZDT_X42_V2.c =========================
// ZDT_X42_V2 电机驱动模块 硬件平台交互部分实现文件
// 实现串口初始化与硬件抽象接口
// ============================================================

#include "hal_ZDT_X42_V2.h"

#define ZDT_X42_V2_UART_INDEX UART_7
#define ZDT_X42_V2_UART_BAUDRATE 115200
#define ZDT_X42_V2_UART_TX_PIN UART7_MAP3_TX_E12
#define ZDT_X42_V2_UART_RX_PIN UART7_MAP3_RX_E13
#define ZDT_X42_V2_UART_IRQ UART7_IRQn

/**
 * @brief 初始化ZDT_X42_V2串口接口，使用逐飞hal库实现
 */
void HAL_ZDT_X42_V2_init(void)
{
    // 初始化串口，打开接收中断并设置为最高优先级
    uart_init(ZDT_X42_V2_UART_INDEX, ZDT_X42_V2_UART_BAUDRATE, ZDT_X42_V2_UART_TX_PIN, ZDT_X42_V2_UART_RX_PIN);
    uart_rx_interrupt(ZDT_X42_V2_UART_INDEX, ENABLE);
    interrupt_set_priority(ZDT_X42_V2_UART_IRQ, 0);
}

/**
 * @brief 发送数据到ZDT_X42_V2串口接口，使用逐飞hal库实现
 * @param data 要发送的数据
 * @param length 数据长度
 */
void HAL_ZDT_X42_V2_send_data(uint8_t *data, uint16_t length)
{
    uart_write_buffer(ZDT_X42_V2_UART_INDEX, data, length);
}

// =============================================================