// ========================= api_TOF.h =========================
// TOF激光测距模块 API 头文件
// 提供TOF实例结构体定义、API接口声明
// ============================================================

#ifndef _API_TOF_H_
#define _API_TOF_H_

#include "hal_TOF.h"
#include "device_TOF.h"

// ========================= TOF实例结构体定义 =========================
/**
 * @brief TOF激光测距模块实例结构体
 *        支持多实例扩展，成员可挂载底层驱动和数据解析函数
 */
typedef struct
{
    // 数据成员
    uint32_t distance; // 距离值
} TOF_Instance_t;
// ===================================================================

// ========================= TOF实例声明 =============================
// 默认全局TOF实例声明（如需多实例可自行定义）
extern TOF_Instance_t TOF_1;
// ===================================================================
 


void TOF_API_Init(void);
void TOF_API_GetDistance(TOF_Instance_t *tof_inst);
void TOF_API_UART_IRQHandler(void);

#endif // _API_TOF_H_
