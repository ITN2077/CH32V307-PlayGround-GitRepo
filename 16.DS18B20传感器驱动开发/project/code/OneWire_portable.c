/**
 * @file    OneWire_portable.c
 * @brief   1-Wire单总线协议驱动模块（平台无关版本）
 * @details 实现了1-Wire协议的基本通信功能，包括初始化、发送和接收数据
 * @note    使用硬件抽象层实现平台解耦
 */
#include "OneWire_portable.h"
#include <string.h>

// 错误码定义
#define ONEWIRE_SUCCESS 0
#define ONEWIRE_ERROR_HAL -1
#define ONEWIRE_ERROR_PARAM -2
#define ONEWIRE_ERROR_TIMEOUT -3

/**
 * @brief 初始化1-Wire设备
 * @param handle 1-Wire设备句柄指针
 * @param pin 使用的GPIO引脚号
 * @return 0: 成功, 非0: 失败
 */
int onewire_init(onewire_handle_t *handle, uint32_t pin)
{
    const onewire_hal_t *hal;

    // 参数检查
    if (handle == NULL)
    {
        return ONEWIRE_ERROR_PARAM;
    }

    // 检查硬件抽象层是否已初始化
    hal = onewire_get_hal();
    if (hal == NULL)
    {
        return ONEWIRE_ERROR_HAL;
    }

    // 初始化句柄
    handle->pin = pin;
    handle->is_initialized = true;

    // 配置GPIO为开漏输出模式，默认高电平（释放总线）
    hal->gpio_init(pin, ONEWIRE_GPIO_OUTPUT, ONEWIRE_GPIO_HIGH, ONEWIRE_GPIO_MODE_OPEN_DRAIN);

    return ONEWIRE_SUCCESS;
}

/**
 * @brief 1-Wire总线复位
 * @param handle 1-Wire设备句柄指针
 * @return 从机响应位，0为响应，1为未响应
 */
int onewire_reset(onewire_handle_t *handle)
{
    const onewire_hal_t *hal;
    onewire_gpio_level_t ack_bit;

    // 参数检查
    if (handle == NULL || !handle->is_initialized)
    {
        return ONEWIRE_ERROR_PARAM;
    }

    // 获取硬件抽象层
    hal = onewire_get_hal();
    if (hal == NULL)
    {
        return ONEWIRE_ERROR_HAL;
    }

    // 关闭总中断，保护1-wire通信时序
    hal->disable_irq();

    // 拉低总线
    hal->gpio_set_level(handle->pin, ONEWIRE_GPIO_LOW);
    hal->delay_us(500); // 延时500us

    // 释放总线
    hal->gpio_set_level(handle->pin, ONEWIRE_GPIO_HIGH);
    hal->delay_us(70); // 延时70us

    // 切换为输入模式读取从机响应
    hal->gpio_init(handle->pin, ONEWIRE_GPIO_INPUT, ONEWIRE_GPIO_HIGH, ONEWIRE_GPIO_MODE_PULL_UP);
    ack_bit = hal->gpio_get_level(handle->pin);

    // 恢复为开漏输出模式
    hal->gpio_init(handle->pin, ONEWIRE_GPIO_OUTPUT, ONEWIRE_GPIO_HIGH, ONEWIRE_GPIO_MODE_OPEN_DRAIN);

    hal->delay_us(500); // 延时500us

    // 恢复总中断
    hal->enable_irq();

    return (ack_bit == ONEWIRE_GPIO_LOW) ? 0 : 1;
}

/**
 * @brief 单总线发送一位数据
 * @param handle 1-Wire设备句柄指针
 * @param bit 要发送的位，0或1
 * @return 0: 成功, 非0: 失败
 */
int onewire_send_bit(onewire_handle_t *handle, uint8_t bit)
{
    const onewire_hal_t *hal;

    // 参数检查
    if (handle == NULL || !handle->is_initialized)
    {
        return ONEWIRE_ERROR_PARAM;
    }

    // 获取硬件抽象层
    hal = onewire_get_hal();
    if (hal == NULL)
    {
        return ONEWIRE_ERROR_HAL;
    }

    // 关闭总中断，保护1-wire通信时序
    hal->disable_irq();

    // 拉低总线
    hal->gpio_set_level(handle->pin, ONEWIRE_GPIO_LOW);

    if (bit)
    {
        hal->delay_us(10); // 延时10us
        hal->gpio_set_level(handle->pin, ONEWIRE_GPIO_HIGH);
        hal->delay_us(50); // 延时50us
    }
    else
    {
        hal->delay_us(60); // 延时60us
        hal->gpio_set_level(handle->pin, ONEWIRE_GPIO_HIGH);
    }

    // 恢复总中断
    hal->enable_irq();

    return ONEWIRE_SUCCESS;
}

/**
 * @brief 单总线接收一位数据
 * @param handle 1-Wire设备句柄指针
 * @param bit 接收到的位指针
 * @return 0: 成功, 非0: 失败
 */
int onewire_receive_bit(onewire_handle_t *handle, uint8_t *bit)
{
    const onewire_hal_t *hal;
    onewire_gpio_level_t level;

    // 参数检查
    if (handle == NULL || !handle->is_initialized || bit == NULL)
    {
        return ONEWIRE_ERROR_PARAM;
    }

    // 获取硬件抽象层
    hal = onewire_get_hal();
    if (hal == NULL)
    {
        return ONEWIRE_ERROR_HAL;
    }

    // 关闭总中断，保护1-wire通信时序
    hal->disable_irq();

    // 拉低总线
    hal->gpio_set_level(handle->pin, ONEWIRE_GPIO_LOW);
    hal->delay_us(5); // 延时5us

    // 释放总线
    hal->gpio_set_level(handle->pin, ONEWIRE_GPIO_HIGH);
    hal->delay_us(5); // 延时5us

    // 切换为输入模式读取数据位
    hal->gpio_init(handle->pin, ONEWIRE_GPIO_INPUT, ONEWIRE_GPIO_HIGH, ONEWIRE_GPIO_MODE_PULL_UP);
    level = hal->gpio_get_level(handle->pin);

    // 恢复为开漏输出模式
    hal->gpio_init(handle->pin, ONEWIRE_GPIO_OUTPUT, ONEWIRE_GPIO_HIGH, ONEWIRE_GPIO_MODE_OPEN_DRAIN);

    hal->delay_us(50); // 延时50us

    // 恢复总中断
    hal->enable_irq();

    *bit = (level == ONEWIRE_GPIO_HIGH) ? 1 : 0;

    return ONEWIRE_SUCCESS;
}

/**
 * @brief 单总线发送一个字节
 * @param handle 1-Wire设备句柄指针
 * @param byte 要发送的字节
 * @return 0: 成功, 非0: 失败
 */
int onewire_send_byte(onewire_handle_t *handle, uint8_t byte)
{
    int ret;
    uint8_t i;

    // 参数检查
    if (handle == NULL || !handle->is_initialized)
    {
        return ONEWIRE_ERROR_PARAM;
    }

    // 从低位开始，依次发送8位数据
    for (i = 0; i < 8; i++)
    {
        ret = onewire_send_bit(handle, (byte >> i) & 0x01);
        if (ret != ONEWIRE_SUCCESS)
        {
            return ret;
        }
    }

    return ONEWIRE_SUCCESS;
}

/**
 * @brief 单总线接收一个字节
 * @param handle 1-Wire设备句柄指针
 * @param byte 接收到的字节指针
 * @return 0: 成功, 非0: 失败
 */
int onewire_receive_byte(onewire_handle_t *handle, uint8_t *byte)
{
    int ret;
    uint8_t i, bit;

    // 参数检查
    if (handle == NULL || !handle->is_initialized || byte == NULL)
    {
        return ONEWIRE_ERROR_PARAM;
    }

    *byte = 0x00;

    // 从低位开始，依次接收8位数据
    for (i = 0; i < 8; i++)
    {
        ret = onewire_receive_bit(handle, &bit);
        if (ret != ONEWIRE_SUCCESS)
        {
            return ret;
        }
        if (bit)
        {
            *byte |= (1 << i);
        }
    }

    return ONEWIRE_SUCCESS;
}

/**
 * @brief 发送1-Wire命令
 * @param handle 1-Wire设备句柄指针
 * @param command 要发送的命令
 * @return 0: 成功, 非0: 失败
 */
int onewire_send_command(onewire_handle_t *handle, uint8_t command)
{
    return onewire_send_byte(handle, command);
}

/**
 * @brief 搜索1-Wire设备
 * @param handle 1-Wire设备句柄指针
 * @param rom_code 64位ROM码输出缓冲区
 * @return 0: 成功, 非0: 失败
 */
int onewire_search_rom(onewire_handle_t *handle, uint8_t *rom_code)
{
    int ret;
    uint8_t i;

    // 参数检查
    if (handle == NULL || !handle->is_initialized || rom_code == NULL)
    {
        return ONEWIRE_ERROR_PARAM;
    }

    // 发送搜索ROM命令
    ret = onewire_send_byte(handle, 0xF0); // Search ROM command
    if (ret != ONEWIRE_SUCCESS)
    {
        return ret;
    }

    // 读取64位ROM码
    for (i = 0; i < 8; i++)
    {
        ret = onewire_receive_byte(handle, &rom_code[i]);
        if (ret != ONEWIRE_SUCCESS)
        {
            return ret;
        }
    }

    return ONEWIRE_SUCCESS;
}