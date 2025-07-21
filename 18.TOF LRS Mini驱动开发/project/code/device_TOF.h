// ========================= device_TOF.h =========================
// TOF激光测距模块 数据解析头文件
// 定义状态机枚举、接口声明
// ===============================================================

#ifndef _DEVICE_TOF_H_
#define _DEVICE_TOF_H_

#include "Ring_Buffer.h"

// ========================= 状态机定义 =========================
/**
 * @brief TOF数据帧解析状态表
 */
typedef enum
{
    WAIT_FOR_HEADER_57, // 等待帧头0x57
    WAIT_FOR_HEADER_00, // 等待帧头0x00
    WAIT_FOR_HEADER_FF, // 等待帧头0xFF
    WAIT_FOR_HEADER_ID, // 等待ID字节
    READ_FRAME          // 读取数据帧
} TOF_ParseState_t;
// =============================================================


void TOF_device_Init(void);
uint32_t TOF_device_Parse_Data(void);
void TOF_device_Queue_Byte(uint8_t byte);

#endif // _DEVICE_TOF_H_
