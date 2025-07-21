// ========================= hal_TOF.h =========================
// TOF激光测距模块 硬件平台交互部分头文件
// 提供硬件相关接口声明
// ============================================================

#ifndef _HAL_TOF_H_
#define _HAL_TOF_H_

#include "zf_driver_uart.h"


void TOF_hal_init(void);
uint8_t TOF_hal_get_uart_byte(uint8_t *byte);


#endif // _HAL_TOF_H_
