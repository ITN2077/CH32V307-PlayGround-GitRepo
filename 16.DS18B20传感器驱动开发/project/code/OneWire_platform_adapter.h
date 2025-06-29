/**
 * @file    OneWire_platform_adapter.h
 * @brief   1-Wire模块平台适配层
 * @details 将现有平台接口适配到硬件抽象层接口
 * @note    针对CH32V307平台的适配实现
 */
#ifndef __ONEWIRE_PLATFORM_ADAPTER_H__
#define __ONEWIRE_PLATFORM_ADAPTER_H__

#include "OneWire_hal.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 初始化CH32V307平台的1-Wire硬件抽象层
     * @return 0: 成功, 非0: 失败
     * @note   需要在调用1-Wire功能前先调用此函数
     */
    int onewire_platform_init(void);

    /**
     * @brief 获取CH32V307平台的1-Wire硬件抽象层接口
     * @return 硬件抽象层接口结构体指针
     */
    const onewire_hal_t *onewire_get_ch32v307_hal(void);

#ifdef __cplusplus
}
#endif

#endif /* __ONEWIRE_PLATFORM_ADAPTER_H__ */