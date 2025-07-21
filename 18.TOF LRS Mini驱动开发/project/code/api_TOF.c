// ========================= api_TOF.c =========================
// TOF激光测距模块 API 实现文件
// 提供TOF实例结构体定义、初始化及对外接口实现
// ============================================================

#include "api_TOF.h"

// ========================= TOF实例定义 =========================
// TOF_1全局实例
TOF_Instance_t TOF_1 = {
    // 数据成员初始化
    .distance = 0,
};
// =============================================================

// ========================= API接口实现 =========================

/**
 * @brief 初始化TOF模块
 */
void TOF_API_Init(void)
{
    // 调用HAL层初始化（串口配置）
    TOF_hal_init();

    // 调用Device层初始化（环形缓冲区）
    TOF_device_Init();
}

/**
 * @brief 解析TOF数据，将解析结果存储到实例的distance成员中
 * @param tof_inst TOF实例指针
 */
void TOF_API_GetDistance(TOF_Instance_t *tof_inst)
{
    tof_inst->distance = TOF_device_Parse_Data();
}

/**
 * @brief 处理TOF串口中断（需在中断服务函数中调用）
 */
void TOF_API_UART_IRQHandler(void)
{
    uint8_t byte = 0;
    // 通过HAL层获取串口数据
    if (TOF_hal_get_uart_byte(&byte))
    {
        // 在API层处理业务逻辑：将数据存入环形缓冲区
        TOF_device_Queue_Byte(byte);
    }
}
// =============================================================
