/**
 * @file    OneWire.c
 * @brief   1-Wire单总线协议驱动模块
 * @details 实现了1-Wire协议的基本通信功能，包括初始化、发送和接收数据
 * @note    使用PA0引脚作为数据线
 */
#include "OneWire.h"

/**
 * @brief  单总线初始化
 * @param  无
 * @retval 从机响应位，0为响应，1为未响应
 * @note   初始化过程：
 *         1. 主机拉低总线至少480us
 *         2. 主机释放总线
 *         3. 等待15-60us后，从机会拉低总线60-240us
 * @warning 每次与DS18B20通信前，需要先执行一次总线复位。
 */
unsigned char OneWire_Init(void)
{
	unsigned char AckBit;

	// 配置GPIO为开漏输出模式，默认高电平（释放总线）
	gpio_init(ONEWIRE_PIN, GPO, 1, GPO_OPEN_DTAIN);

	// 关闭总中断，保护1-wire通信时序
	__disable_irq();

	// 拉低总线
	gpio_set_level(ONEWIRE_PIN, 0);
	system_delay_us(500); // 延时500us

	// 释放总线
	gpio_set_level(ONEWIRE_PIN, 1);
	system_delay_us(70); // 延时70us

	// 切换为输入模式读取从机响应
	gpio_init(ONEWIRE_PIN, GPI, 1, GPI_PULL_UP);
	AckBit = gpio_get_level(ONEWIRE_PIN);

	// 恢复为开漏输出模式
	gpio_init(ONEWIRE_PIN, GPO, 1, GPO_OPEN_DTAIN);

	system_delay_us(500); // 延时500us

	// 恢复总中断
	__enable_irq();

	return AckBit;
}

/**
 * @brief  单总线发送一位数据
 * @param  Bit 要发送的位，0或1
 * @retval 无
 * @note   发送0：拉低总线至少60us
 *         发送1：拉低总线1-15us，然后释放总线
 */
void OneWire_SendBit(unsigned char Bit)
{
	// 关闭总中断，保护1-wire通信时序
	__disable_irq();

	// 拉低总线
	gpio_set_level(ONEWIRE_PIN, 0);

	if (Bit)
	{
		system_delay_us(10); // 延时10us
		gpio_set_level(ONEWIRE_PIN, 1);
		system_delay_us(50); // 延时50us
	}
	else
	{
		system_delay_us(60); // 延时60us
		gpio_set_level(ONEWIRE_PIN, 1);
	}

	// 恢复总中断
	__enable_irq();
}

/**
 * @brief  单总线接收一位数据
 * @param  无
 * @retval 读取的位，0或1
 * @note   接收过程：
 *         1. 主机拉低总线1-15us
 *         2. 主机释放总线
 *         3. 在15us内读取总线状态
 */
unsigned char OneWire_ReceiveBit(void)
{
	unsigned char Bit;

	// 关闭总中断，保护1-wire通信时序
	__disable_irq();

	// 拉低总线
	gpio_set_level(ONEWIRE_PIN, 0);
	system_delay_us(5); // 延时5us

	// 释放总线
	gpio_set_level(ONEWIRE_PIN, 1);
	system_delay_us(5); // 延时5us

	// 切换为输入模式读取数据位
	gpio_init(ONEWIRE_PIN, GPI, 1, GPI_PULL_UP);
	Bit = gpio_get_level(ONEWIRE_PIN);

	// 恢复为开漏输出模式
	gpio_init(ONEWIRE_PIN, GPO, 1, GPO_OPEN_DTAIN);

	system_delay_us(50); // 延时50us

	// 恢复总中断
	__enable_irq();

	return Bit;
}

/**
 * @brief  单总线发送一个字节
 * @param  Byte 要发送的字节
 * @retval 无
 * @note   从低位开始，依次发送8位数据
 */
void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for (i = 0; i < 8; i++)
	{
		OneWire_SendBit(Byte & (0x01 << i)); // 从低位开始发送
	}
}

/**
 * @brief  单总线接收一个字节
 * @param  无
 * @retval 接收的一个字节
 * @note   从低位开始，依次接收8位数据
 */
unsigned char OneWire_ReceiveByte(void)
{
	unsigned char i;
	unsigned char Byte = 0x00;
	for (i = 0; i < 8; i++)
	{
		if (OneWire_ReceiveBit())
		{
			Byte |= (0x01 << i); // 从低位开始接收
		}
	}
	return Byte;
}
