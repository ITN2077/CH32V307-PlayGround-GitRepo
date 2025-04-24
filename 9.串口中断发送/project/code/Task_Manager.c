#include "Task_Manager.h"

// UART7发送数据环形缓冲区初始化
ring_buffer_t ringbuffer_UART7_tx;
uint8_t ringbuffer_place_UART7_tx[64] = {0};
bool tx_done_UART7 = true;
ring_buffer_t ringbuffer_UART7_rx;
uint8_t ringbuffer_place_UART7_rx[64] = {0};    
//!------------------🍅🍅🍅🍅🍅🍅 注册时间片轮询任务 START 🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
STR_XxxTimeSliceOffset Uart_task, Uart7_rx_task; // 创建任务句柄,While_task,Key_task,
/**
 *  @brief 时间片轮询任务创建函数
 *  @note 记得创建任务句柄
 */
void Time_Slice_Offset_Register(void)
{
    // !任务调度系统节拍 单位 10 ms 以下是注册任务
    // XxxTimeSliceOffset_Register(&While_task, While_Task, 0, 0);             // 注册while循环任务。
    XxxTimeSliceOffset_Register(&Uart_task, UART_packet_TASKhandler, 0, 0); // 注册串口数据包接收任务, 轮询时间为0即while，偏移0.
    XxxTimeSliceOffset_Register(&Uart7_rx_task, uart7_rx_buffer_process, 1, 0); // 注册串口7接收数据任务, 轮询时间为0即while，偏移0.
    // XxxTimeSliceOffset_Register(&Key_task, key_Processing, 2, 1);           // 按键扫描函数,需要使用记得注册任务以及初始化 key_init(20);
    //  注册任务结束
}
//!------------------✨✨✨✨✨✨ 注册时间片轮询任务 END 🌸🌸🌸🌸🌸🌸---------⬆️⬆️⬆️⬆️⬆️⬆️

//!----------------🍅🍅🍅🍅🍅🍅 串口数据包任务使用的 START 🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
#define NumOfMsg 2 // 定义串口接收的数据要解析的数据的个数
int test_value_1 = 0;
float test_value_2 = 0.000;

PacketTag_TpDef_struct Test_packet[] = {
    {"1", UnpackData_Handle_Int_FireWater, &test_value_1},
    {"2", UnpackData_Handle_Float_FireWater, &test_value_2},
    // 添加更多的映射关系
};
//!------------------✨✨✨✨✨✨ 串口数据包任务使用的 END 🌸🌸🌸🌸🌸🌸---------⬆️⬆️⬆️⬆️⬆️⬆️

//!------------------🍅🍅🍅🍅🍅🍅 非时间片轮询任务调度函数 START  🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
/**********************************************************************
 *  @brief 串口7发送数据非阻塞函数
 *  @param 数据指针，数据长度
 */
void uart7_sendata_non_blocking(uint8_t *data, uint8_t len)
{
    ring_buffer_queue_arr(&ringbuffer_UART7_tx, data, len);
    if (tx_done_UART7 != false)
    {
        uint8_t data;
        ring_buffer_dequeue(&ringbuffer_UART7_tx, &data);
        USART_SendData(UART7, data);
        tx_done_UART7 = false;
        USART_ITConfig(UART7, USART_IT_TXE, ENABLE);                // 开启发送中断
        interrupt_set_priority((uint32)((IRQn_Type)UART7_IRQn), 0); // 设置中断优先级
    }
}
/**********************************************************************
 *  @brief 串口7中断接收数据函数
 *  @param
 *  @return
 *  @note
 *  @warning
 */
void uart7_rx_buffer_process(void)
{
    uint8_t byte = 0;
    while(ring_buffer_dequeue(&ringbuffer_UART7_rx, &byte))
    {
        uart7_sendata_non_blocking(&byte, 1);
    }
}
/**********************************************************************
 *  @brief 全部外设的初始化
 *  @param
 *  @return
 *  @note
 *  @warning
 */
void PeripheraAll_Init()
{
    UART_DEBUG_Init();

    pit_ms_init(TIM6_PIT, 10);            // 定时器6初始化，提供软实时任务调度系统节拍
    interrupt_set_priority(TIM6_IRQn, 0); // 最高中断优先级

    // pit_ms_init(TIM7_PIT, 50);            // 定时器七初始化，用于硬实时任务调度
    // interrupt_set_priority(TIM7_IRQn, 0);

    timer_init(TIM_5, TIMER_US); // 初始化定时器5用于计时

    uart_init(UART_7, 115200, UART7_MAP3_TX_E12, UART7_MAP3_RX_E13);
    uart_rx_interrupt(UART_7, ENABLE);
    interrupt_set_priority(UART7_IRQn, (0 << 5) || 1); // 设置usart7的中断优先级

    ring_buffer_init(&ringbuffer_UART7_tx, ringbuffer_place_UART7_tx, 64);
    ring_buffer_init(&ringbuffer_UART7_rx, ringbuffer_place_UART7_rx, 64);

    timer_start(TIM_5);
    char test_data[52] = "00000000001111111111222222222233333333334444444444\r\n";
    uart7_sendata_non_blocking(test_data, 52);
    timer_stop(TIM_5);
    uint16 time_us = timer_get(TIM_5);
    char time_str[20];
    sprintf(time_str, "Time: %d us\r\n", time_us);
    uart7_sendata_non_blocking(time_str, strlen(time_str));
    

    // printf_USART_DEBUG("%s", test_data);
    // timer_stop(TIM_5);
    // printf_USART_DEBUG("Time: %d us\r\n", timer_get(TIM_5));

    // key_init(20); // 按键初始化，20ms一次中断
    printf_USART_DEBUG("hello,WSY!\r\n");
    printf_USART_DEBUG("hello,WSY! Let`s start!\r\n");
    // Task_Disable();  // 定时器中断失能。即所有实时任务停止
}
//!------------------✨✨✨✨✨✨ 非时间片轮询任务调度函数 END 🌸🌸🌸🌸🌸🌸---------⬆️⬆️⬆️⬆️⬆️⬆️

//!------------------🍅🍅🍅🍅🍅🍅 时间片轮询任务 START 🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
/**
 * @brief While 循环，无定时任务，全速运行。
 *
 */
void While_Task(void)
{
    // 写入while循环任务
}
/**
 *  @brief 串口数据包处理任务函数
 *  @note  务必设置为无定时任务，全速运行防止缓冲区溢出
 */
void UART_packet_TASKhandler(void)
{
    UART_DEBUG_Ringbuffer_Processer();
    if (UART_DEBUG_data_packet_ready)
    {
        UART_DEBUG_data_packet_ready = false;
        PacketTag_Analysis(Test_packet, NumOfMsg); // 此处NumOfMsg在串口处定义。
        DebugPrint();                              // 输出接收的数据
        printf_USART_DEBUG("\r\ntestv1:%d\r\n", test_value_1);
        printf_USART_DEBUG("\r\ntestv2:%f\r\n", test_value_2);
    }
}
/**
 *  @brief 按键扫描、处理任务，默认20ms处理一次
 *  @note   按键引脚要修改key.h中的key.list，对应任务句柄Key_task
 */
void key_Processing(void)
{
    key_scanner();
    if (KEY_SHORT_PRESS == key_get_state(KEY_1)) // 按键1短按
    {
        // printf_USART_DEBUG("KEY_1 pressed.");
    }
    else if (KEY_LONG_PRESS == key_get_state(KEY_1)) // 按键1长按
    {
    }
    else if (KEY_SHORT_PRESS == key_get_state(KEY_2))
    {
    }
    else if (KEY_LONG_PRESS == key_get_state(KEY_2))
    {
    }
}
//!------------------✨✨✨✨✨✨ 时间片轮询任务调度 END 🌸🌸🌸🌸🌸🌸---------⬆️⬆️⬆️⬆️⬆️⬆️

//!------------------🍅🍅🍅🍅🍅🍅 硬实时任务 START 🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
/**
 *  @brief 硬实时任务处理，到点就触发，比软实时任务高一级
 *  @param
 *  @return
 *  @note   此函数在TIM7中断中被使用，将函数写入此函数中即可。
 *  @warning
 */
void Hard_Real_Time_Processing(void)
{
}
//!------------------✨✨✨✨✨✨ 硬实时任务 END 🌸🌸🌸🌸🌸🌸---------⬆️⬆️⬆️⬆️⬆️⬆️