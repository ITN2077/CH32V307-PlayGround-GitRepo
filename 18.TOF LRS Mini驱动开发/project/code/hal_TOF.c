// ========================= hal_TOF.c =========================
// TOF激光测距模块 硬件平台交互部分实现文件
// 实现串口初始化与硬件抽象接口
// ============================================================

#include "hal_TOF.h"

#define TOF_UART_INDEX UART_6
#define TOF_UART_BAUDRATE 921600
#define TOF_UART_TX_PIN UART6_MAP0_TX_C0
#define TOF_UART_RX_PIN UART6_MAP0_RX_C1
#define TOF_UART_IRQ UART6_IRQn

/**
 * @brief 初始化TOF串口接口，使用逐飞hal库实现
 */
void TOF_hal_init(void)
{
    // 初始化串口，打开接收中断并设置为最高优先级
    uart_init(TOF_UART_INDEX, TOF_UART_BAUDRATE, TOF_UART_TX_PIN, TOF_UART_RX_PIN);
    uart_rx_interrupt(TOF_UART_INDEX, ENABLE);
    interrupt_set_priority(TOF_UART_IRQ, 0);
}

/**
 * @brief 获取串口接收到的字节数据
 * @param byte 存储接收到的字节数据
 * @return 如果获取到数据则返回1，否则返回0
 */
uint8_t TOF_hal_get_uart_byte(uint8_t *byte)
{
    if (uart_query_byte(TOF_UART_INDEX, byte))
    {
        return 1;
    }
    return 0;
}

// =============================================================