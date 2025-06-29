/**
 * @file    OneWire_example.c
 * @brief   1-Wire模块使用示例
 * @details 展示如何使用解耦后的1-Wire模块
 */
#include "OneWire_platform_adapter.h"
#include "OneWire_portable.h"

// 1-Wire设备句柄
static onewire_handle_t onewire_dev;

/**
 * @brief 初始化1-Wire模块
 * @return 0: 成功, 非0: 失败
 */
int onewire_example_init(void)
{
    int ret;

    // 1. 初始化平台适配层
    ret = onewire_platform_init();
    if (ret != 0)
    {
        return ret;
    }

    // 2. 初始化1-Wire设备（使用PA0引脚）
    ret = onewire_init(&onewire_dev, A0);
    if (ret != 0)
    {
        return ret;
    }

    return 0;
}

/**
 * @brief 1-Wire总线复位示例
 * @return 0: 成功, 非0: 失败
 */
int onewire_example_reset(void)
{
    int ret;

    // 执行总线复位
    ret = onewire_reset(&onewire_dev);
    if (ret == 0)
    {
        // 复位成功，有设备响应
        return 0;
    }
    else if (ret == 1)
    {
        // 复位成功，但无设备响应
        return 1;
    }
    else
    {
        // 复位失败
        return ret;
    }
}

/**
 * @brief 发送1-Wire命令示例
 * @param command 要发送的命令
 * @return 0: 成功, 非0: 失败
 */
int onewire_example_send_command(uint8_t command)
{
    return onewire_send_command(&onewire_dev, command);
}

/**
 * @brief 接收1-Wire数据示例
 * @param data 接收数据缓冲区
 * @return 0: 成功, 非0: 失败
 */
int onewire_example_receive_data(uint8_t *data)
{
    return onewire_receive_byte(&onewire_dev, data);
}

/**
 * @brief 搜索1-Wire设备示例
 * @param rom_code 64位ROM码输出缓冲区
 * @return 0: 成功, 非0: 失败
 */
int onewire_example_search_device(uint8_t *rom_code)
{
    return onewire_search_rom(&onewire_dev, rom_code);
}

/**
 * @brief 完整的1-Wire通信示例
 * @return 0: 成功, 非0: 失败
 */
int onewire_example_communication(void)
{
    int ret;
    uint8_t command = 0xCC; // Skip ROM command
    uint8_t data;

    // 1. 总线复位
    ret = onewire_reset(&onewire_dev);
    if (ret != 0)
    {
        return ret;
    }

    // 2. 发送命令
    ret = onewire_send_command(&onewire_dev, command);
    if (ret != 0)
    {
        return ret;
    }

    // 3. 接收数据
    ret = onewire_receive_byte(&onewire_dev, &data);
    if (ret != 0)
    {
        return ret;
    }

    return 0;
}