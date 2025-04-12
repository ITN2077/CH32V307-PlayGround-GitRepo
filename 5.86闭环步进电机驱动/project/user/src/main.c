/*********************************************************************************************************************
 SWDIO PA13 ,SWCLK PA14
默认DEBUG串口是UART8  TX_E14，RX_E15
KEY_LIST   {A8 , D8 , B12 , B0 } 对应 zf_device_key.h 中 KEY_LIST

定时器6用于软实时任务节拍
定时器7用于硬实时任务节拍

 ********************************************************************************************************************/
#include "Task_Manager.h"

int main(void)
{
    clock_init(SYSTEM_CLOCK_120M); // 初始化芯片时钟 工作频率为 120MHz
    debug_init();                  // 务必保留，本函数用于初始化MPU 时钟 调试串口
    PeripheraAll_Init();           // 全部外设初始化

    // !任务调度系统节拍 单位 10 ms 以下是注册任务
    XxxTimeSliceOffset_Register(&While_task, While_Task, 0, 0);             // 注册while循环任务。
    XxxTimeSliceOffset_Register(&Uart_task, UART_packet_TASKhandler, 0, 0); // 注册串口数据包接收任务, 轮询时间为0即while，偏移0.
    XxxTimeSliceOffset_Register(&Speed_task, control_Speed, 2, 2);        // 速度控制函数，100ms执行一次
    XxxTimeSliceOffset_Register(&Key_task, key_Processing, 2, 1);           // 按键扫描函数
    // 注册任务结束

    XxxTimeSliceOffset_Start(); // 执行任务，包含while，替代了主循环while
}