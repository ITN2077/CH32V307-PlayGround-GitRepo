#include "Task_Manager.h"

#define Buf_Size 32 // 定义缓冲区大小为32个32位数据

//!------------------🍅🍅🍅🍅🍅🍅 变量 START 🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
// 源数据缓冲区，使用更容易识别的模式
u32 SRC_BUF[Buf_Size] = {
    0xAAAAAAAA, 0xBBBBBBBB, 0xCCCCCCCC, 0xDDDDDDDD,
    0xEEEEEEEE, 0xFFFFFFFF, 0x11111111, 0x22222222,
    0x33333333, 0x44444444, 0x55555555, 0x66666666,
    0x77777777, 0x88888888, 0x99999999, 0xAAAAAAAA,
    0xBBBBBBBB, 0xCCCCCCCC, 0xDDDDDDDD, 0xEEEEEEEE,
    0xFFFFFFFF, 0x11111111, 0x22222222, 0x33333333,
    0x44444444, 0x55555555, 0x66666666, 0x77777777,
    0x88888888, 0x99999999, 0xAAAAAAAA, 0xBBBBBBBB};

u32 DST_BUF[Buf_Size] = {0}; // 目标数据缓冲区，初始化为0
u8 Flag = 0;                 // 传输结果标志位
u32 DMA_Transfer_Count = 0;  // DMA传输计数器

/*********************************************************************
 * @fn      DMA1_CH3_Init
 *
 * @brief   初始化DMA1的通道3，配置为内存到内存传输模式
 *
 * @return  none
 */
void DMA1_CH3_Init(void)
{
    DMA_InitTypeDef DMA_InitStructure = {0};
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); // Enable DMA1 clock

    DMA_DeInit(DMA1_Channel3);
    DMA_StructInit(&DMA_InitStructure);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(SRC_BUF);              // Set source data address
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)DST_BUF;                    // Set destination data address
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;                      // Set transfer direction
    DMA_InitStructure.DMA_BufferSize = 32;                                  // Set transfer size
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;         // Enable source address increment
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                 // Enable destination address increment
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word; // Set peripheral data width to word
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;         // Set memory data width to word
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;                           // Set to normal mode
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;                 // Set highest priority
    DMA_InitStructure.DMA_M2M = DMA_M2M_Enable;                             // Enable memory to memory mode
    DMA_Init(DMA1_Channel3, &DMA_InitStructure);

    // 配置中断
    NVIC_SetPriority(DMA1_Channel3_IRQn, 0x00);     // 首先设置NVIC中断优先级
    NVIC_EnableIRQ(DMA1_Channel3_IRQn);             // 然后使能NVIC中断
    DMA_ITConfig(DMA1_Channel3, DMA_IT_TC, ENABLE); // 最后配置DMA中断标志位

    DMA_Cmd(DMA1_Channel3, ENABLE); // 使能DMA通道，在所有配置完成后，最后启动DMA通道
}

//!------------------✨✨✨✨✨✨ 变量 END 🌸🌸🌸🌸🌸🌸---------⬆️⬆️⬆️⬆️⬆️⬆️

//!------------------🍅🍅🍅🍅🍅🍅 注册时间片轮询任务 START 🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
STR_XxxTimeSliceOffset While_task, Uart_task; // 创建任务句柄,While_task,Key_task,
/**
 *  @brief 时间片轮询任务创建函数
 *  @note 记得创建任务句柄
 */
void Time_Slice_Offset_Register(void)
{
    // !任务调度系统节拍 单位 10 ms 以下是注册任务
    XxxTimeSliceOffset_Register(&While_task, While_Task, 0, 0);             // 注册while循环任务。
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
/**
 *  @brief 全部外设的初始化
 */
void PeripheraAll_Init()
{
    UART_DEBUG_Init();

    pit_ms_init(TIM6_PIT, 10);            // 定时器6初始化，提供软实时任务调度系统节拍
    interrupt_set_priority(TIM6_IRQn, 0); // 最高中断优先级

    // pit_ms_init(TIM7_PIT, 50);            // 定时器七初始化，用于硬实时任务调度
    // interrupt_set_priority(TIM7_IRQn, 0);

    // timer_init(TIM_5, TIMER_US); // 初始化定时器5用于计时

    DMA1_CH3_Init(); // 初始化DMA1通道3

    // key_init(20); // 按键初始化，20ms一次中断

    uint32_t ma[10] __attribute__((aligned(4))) = {0};
    printf_USART_DEBUG("addr:0x%08X\r\n", (uint32_t)ma);

    printf_USART_DEBUG("hello,WSY! Let`s start!\r\n");
    printf_USART_DEBUG("This is NEW VERSION\r\n");
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
    u8 i = 0;
    u32 j = 0;
    u32 last_count = 0;

    // printf_USART_DEBUG("\r\n=== DMA Transfer Test Start ===\r\n");

    // while (DMA_GetFlagStatus(DMA1_FLAG_TC3) == RESET)
    // {
    //     // CPU is busy waiting here
    // }

    // DMA_Cmd(DMA1_Channel3, DISABLE);

    // for (i = 0; i < Buf_Size; i++)
    // {
    //     printf_USART_DEBUG("DST_BUF[%d] = 0x%08X\r\n", i, DST_BUF[i]);
    // }

    // printf_USART_DEBUG("\r\n=== DMA Transfer Test End ===\r\n");

    // while (1)
    // {

    // }
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
