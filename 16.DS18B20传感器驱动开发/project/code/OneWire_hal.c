/**
 * @file    OneWire_hal.c
 * @brief   1-Wire模块硬件抽象层实现
 * @details 实现硬件抽象层接口的管理功能
 */
#include "OneWire_hal.h"

// 全局硬件抽象层接口指针
static const onewire_hal_t *g_onewire_hal = NULL;

/**
 * @brief 设置硬件抽象层接口
 * @param hal 硬件抽象层接口结构体指针
 */
void onewire_set_hal(const onewire_hal_t *hal)
{
    g_onewire_hal = hal;
}

/**
 * @brief 获取当前硬件抽象层接口
 * @return 硬件抽象层接口结构体指针
 */
const onewire_hal_t *onewire_get_hal(void)
{
    return g_onewire_hal;
}

/**
 * @brief 检查硬件抽象层是否已初始化
 * @return true: 已初始化, false: 未初始化
 */
bool onewire_hal_is_ready(void)
{
    return (g_onewire_hal != NULL);
}