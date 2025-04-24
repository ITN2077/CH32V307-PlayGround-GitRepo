#include "Task_Manager.h"

//!------------------🍅🍅🍅🍅🍅🍅 注册时间片轮询任务 START 🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
STR_XxxTimeSliceOffset While_task, Uart_task; // 创建任务句柄,While_task,Key_task,
/**
 *  @brief 时间片轮询任务创建函数
 *  @note 记得创建任务句柄
 */
void Time_Slice_Offset_Register(void)
{
    // !任务调度系统节拍 单位 10 ms 以下是注册任务
    XxxTimeSliceOffset_Register(&While_task, While_Task, 20, 0);            // 注册while循环任务。
    XxxTimeSliceOffset_Register(&Uart_task, UART_packet_TASKhandler, 0, 0); // 注册串口数据包接收任务, 轮询时间为0即while，偏移0.
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
//张大头步进电机所使用的串口的初始化
void ZDT_uart_init(void)
{
    // 具体的串口初始化实现
    uart_init(UART_7, 115200, UART7_MAP3_TX_E12, UART7_MAP3_RX_E13);
    uart_rx_interrupt(UART_7, ENABLE);
    interrupt_set_priority(UART7_IRQn, (0 << 5) || 1);
}
//张大头步进电机所使用的串口的发送
void ZDT_uart_send(uint8_t *data, uint16_t length)
{
    // 具体的串口发送实现
    uart_write_buffer(UART_7, data, length);
}
// 创建张大头步进电机串口接口实例
ZDT_UartInterface_t uart_if = {
    .init = ZDT_uart_init,
    .send_data = ZDT_uart_send};
/**
 *  @brief 全部外设的初始化
 */
void PeripheraAll_Init()
{
    UART_DEBUG_Init(); // vofa通讯串口初始化
    ZDT_X42_V2_Init(&uart_if); // 张大头步进电机接口初始化

    pit_ms_init(TIM6_PIT, 10);            // 定时器6初始化，提供软实时任务调度系统节拍
    interrupt_set_priority(TIM6_IRQn, 0); // 最高中断优先级

    // pit_ms_init(TIM7_PIT, 50);            // 定时器七初始化，用于硬实时任务调度
    // interrupt_set_priority(TIM7_IRQn, 0);

    timer_init(TIM_5, TIMER_US); // 初始化定时器5用于计时

    // key_init(20); // 按键初始化，20ms一次中断

    printf_USART_debug("hello,WSY!!\r\n");
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

    // 使用ZDT步进电机速度模式接收test_value_1的值作为速度，斜率20。
    ZDT_X42_V2_Velocity_Control(1, 0, 20, test_value_1, 0);
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
        printf_USART_debug("\r\ntestv1:%d\r\n", test_value_1);
        printf_USART_debug("\r\ntestv2:%f\r\n", test_value_2);
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