/**
 * @file    OneWire_hal.h
 * @brief   1-Wire模块硬件抽象层接口
 * @details 定义平台无关的硬件操作接口，实现平台解耦
 * @note    用户需要根据具体平台实现这些接口函数
 */
#ifndef __ONEWIRE_HAL_H__
#define __ONEWIRE_HAL_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief GPIO方向枚举
     */
    typedef enum
    {
        ONEWIRE_GPIO_INPUT = 0, ///< 输入模式
        ONEWIRE_GPIO_OUTPUT = 1 ///< 输出模式
    } onewire_gpio_dir_t;

    /**
     * @brief GPIO模式枚举
     */
    typedef enum
    {
        ONEWIRE_GPIO_MODE_PULL_UP = 0,   ///< 上拉输入
        ONEWIRE_GPIO_MODE_PULL_DOWN = 1, ///< 下拉输入
        ONEWIRE_GPIO_MODE_PUSH_PULL = 2, ///< 推挽输出
        ONEWIRE_GPIO_MODE_OPEN_DRAIN = 3 ///< 开漏输出
    } onewire_gpio_mode_t;

    /**
     * @brief GPIO电平枚举
     */
    typedef enum
    {
        ONEWIRE_GPIO_LOW = 0, ///< 低电平
        ONEWIRE_GPIO_HIGH = 1 ///< 高电平
    } onewire_gpio_level_t;

    /**
     * @brief 1-Wire硬件抽象层接口结构体
     */
    typedef struct
    {
        /**
         * @brief 初始化GPIO引脚
         * @param pin 引脚号
         * @param dir 方向（输入/输出）
         * @param level 初始电平（输出模式有效）
         * @param mode GPIO模式
         */
        void (*gpio_init)(uint32_t pin, onewire_gpio_dir_t dir, onewire_gpio_level_t level, onewire_gpio_mode_t mode);

        /**
         * @brief 设置GPIO电平
         * @param pin 引脚号
         * @param level 要设置的电平
         */
        void (*gpio_set_level)(uint32_t pin, onewire_gpio_level_t level);

        /**
         * @brief 获取GPIO电平
         * @param pin 引脚号
         * @return 当前电平
         */
        onewire_gpio_level_t (*gpio_get_level)(uint32_t pin);

        /**
         * @brief 微秒延时
         * @param us 延时时间（微秒）
         */
        void (*delay_us)(uint32_t us);

        /**
         * @brief 关闭中断
         */
        void (*disable_irq)(void);

        /**
         * @brief 开启中断
         */
        void (*enable_irq)(void);
    } onewire_hal_t;

    /**
     * @brief 设置硬件抽象层接口
     * @param hal 硬件抽象层接口结构体指针
     */
    void onewire_set_hal(const onewire_hal_t *hal);

    /**
     * @brief 获取当前硬件抽象层接口
     * @return 硬件抽象层接口结构体指针
     */
    const onewire_hal_t *onewire_get_hal(void);

#ifdef __cplusplus
}
#endif

#endif /* __ONEWIRE_HAL_H__ */