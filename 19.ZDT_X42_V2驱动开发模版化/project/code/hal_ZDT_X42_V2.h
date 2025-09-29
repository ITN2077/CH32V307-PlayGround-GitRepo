// ========================= hal_ZDT_X42_V2.h =========================
// ZDT_X42_V2 电机驱动模块 硬件平台交互部分头文件
// 提供硬件相关接口声明
// ============================================================
#ifndef __HAL_ZDT_X42_V2_H__
#define __HAL_ZDT_X42_V2_H__

#include "zf_driver_uart.h"

void HAL_ZDT_X42_V2_init(void);
void HAL_ZDT_X42_V2_send_data(uint8_t *data, uint16_t length);

#endif
