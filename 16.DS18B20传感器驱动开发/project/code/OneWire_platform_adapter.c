/**
 * @file    OneWire_platform_adapter.c
 * @brief   1-Wire模块平台适配层实现
 * @details 将CH32V307平台接口适配到硬件抽象层接口
 */
#include "OneWire_platform_adapter.h"
#include "OneWire_hal.h"
#include "zf_common_headfile.h"

// 平台特定的GPIO方向映射
static onewire_gpio_dir_t platform_gpio_dir_map(gpio_dir_enum dir)
{
    switch (dir)
    {
    case GPI:
        return ONEWIRE_GPIO_INPUT;
    case GPO:
        return ONEWIRE_GPIO_OUTPUT;
    default:
        return ONEWIRE_GPIO_INPUT;
    }
}

// 平台特定的GPIO模式映射
static onewire_gpio_mode_t platform_gpio_mode_map(gpio_mode_enum mode)
{
    switch (mode)
    {
    case GPI_PULL_UP:
        return ONEWIRE_GPIO_MODE_PULL_UP;
    case GPI_PULL_DOWN:
        return ONEWIRE_GPIO_MODE_PULL_DOWN;
    case GPO_PUSH_PULL:
        return ONEWIRE_GPIO_MODE_PUSH_PULL;
    case GPO_OPEN_DTAIN:
        return ONEWIRE_GPIO_MODE_OPEN_DRAIN;
    default:
        return ONEWIRE_GPIO_MODE_PUSH_PULL;
    }
}

// 平台特定的GPIO电平映射
static onewire_gpio_level_t platform_gpio_level_map(uint8_t level)
{
    return (level == 0) ? ONEWIRE_GPIO_LOW : ONEWIRE_GPIO_HIGH;
}

// 平台特定的GPIO电平反向映射
static uint8_t platform_gpio_level_unmap(onewire_gpio_level_t level)
{
    return (level == ONEWIRE_GPIO_LOW) ? 0 : 1;
}

// 平台特定的GPIO方向反向映射
static gpio_dir_enum platform_gpio_dir_unmap(onewire_gpio_dir_t dir)
{
    return (dir == ONEWIRE_GPIO_INPUT) ? GPI : GPO;
}

// 平台特定的GPIO模式反向映射
static gpio_mode_enum platform_gpio_mode_unmap(onewire_gpio_mode_t mode)
{
    switch (mode)
    {
    case ONEWIRE_GPIO_MODE_PULL_UP:
        return GPI_PULL_UP;
    case ONEWIRE_GPIO_MODE_PULL_DOWN:
        return GPI_PULL_DOWN;
    case ONEWIRE_GPIO_MODE_PUSH_PULL:
        return GPO_PUSH_PULL;
    case ONEWIRE_GPIO_MODE_OPEN_DRAIN:
        return GPO_OPEN_DTAIN;
    default:
        return GPO_PUSH_PULL;
    }
}

// CH32V307平台的GPIO初始化适配函数
static void ch32v307_gpio_init(uint32_t pin, onewire_gpio_dir_t dir, onewire_gpio_level_t level, onewire_gpio_mode_t mode)
{
    gpio_init((gpio_pin_enum)pin,
              platform_gpio_dir_unmap(dir),
              platform_gpio_level_unmap(level),
              platform_gpio_mode_unmap(mode));
}

// CH32V307平台的GPIO设置电平适配函数
static void ch32v307_gpio_set_level(uint32_t pin, onewire_gpio_level_t level)
{
    gpio_set_level((gpio_pin_enum)pin, platform_gpio_level_unmap(level));
}

// CH32V307平台的GPIO获取电平适配函数
static onewire_gpio_level_t ch32v307_gpio_get_level(uint32_t pin)
{
    uint8_t level = gpio_get_level((gpio_pin_enum)pin);
    return platform_gpio_level_map(level);
}

// CH32V307平台的微秒延时适配函数
static void ch32v307_delay_us(uint32_t us)
{
    system_delay_us(us);
}

// CH32V307平台的中断禁用适配函数
static void ch32v307_disable_irq(void)
{
    __disable_irq();
}

// CH32V307平台的中断使能适配函数
static void ch32v307_enable_irq(void)
{
    __enable_irq();
}

// CH32V307平台的硬件抽象层接口结构体
static const onewire_hal_t ch32v307_hal = {
    .gpio_init = ch32v307_gpio_init,
    .gpio_set_level = ch32v307_gpio_set_level,
    .gpio_get_level = ch32v307_gpio_get_level,
    .delay_us = ch32v307_delay_us,
    .disable_irq = ch32v307_disable_irq,
    .enable_irq = ch32v307_enable_irq};

/**
 * @brief 初始化CH32V307平台的1-Wire硬件抽象层
 * @return 0: 成功, 非0: 失败
 */
int onewire_platform_init(void)
{
    // 设置硬件抽象层接口
    onewire_set_hal(&ch32v307_hal);
    return 0;
}

/**
 * @brief 获取CH32V307平台的1-Wire硬件抽象层接口
 * @return 硬件抽象层接口结构体指针
 */
const onewire_hal_t *onewire_get_ch32v307_hal(void)
{
    return &ch32v307_hal;
}