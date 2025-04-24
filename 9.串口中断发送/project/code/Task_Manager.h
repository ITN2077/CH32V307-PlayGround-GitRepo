#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_

#include "zf_common_headfile.h"

//---------时间片轮询任务调度的变量 START
extern ring_buffer_t ringbuffer_UART7_tx;
extern uint8_t ringbuffer_place_UART7_tx[64];
extern bool tx_done_UART7;
extern ring_buffer_t ringbuffer_UART7_rx;
extern uint8_t ringbuffer_place_UART7_rx[64];
//---------时间片轮询任务调度的变量 END

// ******任务函数
void PeripheraAll_Init();
void Time_Slice_Offset_Register(void);
void While_Task(void);
void UART_packet_TASKhandler(void);
void key_Processing(void);
void Hard_Real_Time_Processing(void);
void uart7_rx_buffer_process(void);
// ******任务函数 END

#endif /* TASK_MANAGER_H_ */
