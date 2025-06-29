/**
 * @file    OneWire_portable.h
 * @brief   1-Wire单总线协议驱动模块（平台无关版本）
 * @details 实现了1-Wire协议的基本通信功能，包括初始化、发送和接收数据
 * @note    使用硬件抽象层实现平台解耦
 */
#ifndef __ONEWIRE_PORTABLE_H__
#define __ONEWIRE_PORTABLE_H__

#include "OneWire_hal.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 1-Wire设备句柄结构体
     */
    typedef struct
    {
        uint32_t pin;        ///< 使用的GPIO引脚号
        bool is_initialized; ///< 初始化状态标志
    } onewire_handle_t;

    /**
     * @brief 初始化1-Wire设备
     * @param handle 1-Wire设备句柄指针
     * @param pin 使用的GPIO引脚号
     * @return 0: 成功, 非0: 失败
     * @note   初始化过程：
     *         1. 主机拉低总线至少480us
     *         2. 主机释放总线
     *         3. 等待15-60us后，从机会拉低总线60-240us
     * @warning 每次与DS18B20通信前，需要先执行一次总线复位。
     */
    int onewire_init(onewire_handle_t *handle, uint32_t pin);

    /**
     * @brief 1-Wire总线复位
     * @param handle 1-Wire设备句柄指针
     * @return 从机响应位，0为响应，1为未响应
     */
    int onewire_reset(onewire_handle_t *handle);

    /**
     * @brief 单总线发送一位数据
     * @param handle 1-Wire设备句柄指针
     * @param bit 要发送的位，0或1
     * @return 0: 成功, 非0: 失败
     * @note   发送0：拉低总线至少60us
     *         发送1：拉低总线1-15us，然后释放总线
     */
    int onewire_send_bit(onewire_handle_t *handle, uint8_t bit);

    /**
     * @brief 单总线接收一位数据
     * @param handle 1-Wire设备句柄指针
     * @param bit 接收到的位指针
     * @return 0: 成功, 非0: 失败
     * @note   接收过程：
     *         1. 主机拉低总线1-15us
     *         2. 主机释放总线
     *         3. 在15us内读取总线状态
     */
    int onewire_receive_bit(onewire_handle_t *handle, uint8_t *bit);

    /**
     * @brief 单总线发送一个字节
     * @param handle 1-Wire设备句柄指针
     * @param byte 要发送的字节
     * @return 0: 成功, 非0: 失败
     * @note   从低位开始，依次发送8位数据
     */
    int onewire_send_byte(onewire_handle_t *handle, uint8_t byte);

    /**
     * @brief 单总线接收一个字节
     * @param handle 1-Wire设备句柄指针
     * @param byte 接收到的字节指针
     * @return 0: 成功, 非0: 失败
     * @note   从低位开始，依次接收8位数据
     */
    int onewire_receive_byte(onewire_handle_t *handle, uint8_t *byte);

    /**
     * @brief 发送1-Wire命令
     * @param handle 1-Wire设备句柄指针
     * @param command 要发送的命令
     * @return 0: 成功, 非0: 失败
     */
    int onewire_send_command(onewire_handle_t *handle, uint8_t command);

    /**
     * @brief 搜索1-Wire设备
     * @param handle 1-Wire设备句柄指针
     * @param rom_code 64位ROM码输出缓冲区
     * @return 0: 成功, 非0: 失败
     */
    int onewire_search_rom(onewire_handle_t *handle, uint8_t *rom_code);

#ifdef __cplusplus
}
#endif

#endif /* __ONEWIRE_PORTABLE_H__ */