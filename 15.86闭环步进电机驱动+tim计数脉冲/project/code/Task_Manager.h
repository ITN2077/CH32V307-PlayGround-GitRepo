#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_

#include "zf_common_headfile.h"

//---------时间片轮询任务调度的变量 START
extern STR_XxxTimeSliceOffset While_task, Uart_task, Speed_task, Key_task; // 创建任务调度结构体变量
//---------时间片轮询任务调度的变量 END

// ******任务函数
void PeripheraAll_Init();
void update_speed(int set_num);
void While_Task(void);
void UART_packet_TASKhandler(void);
void control_Speed(void);
void key_Processing(void);
void EXTI_Handler(void);
// ******任务函数 END

#endif /* TASK_MANAGER_H_ */
