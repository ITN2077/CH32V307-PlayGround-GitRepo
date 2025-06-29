/**
 * @file    DS18B20.c
 * @brief   DS18B20温度传感器驱动模块
 * @details 实现DS18B20温度传感器的初始化和数据读取功能
 */

#include "DS18B20.h"
#include "OneWire.h"

// DS18B20指令定义
#define DS18B20_SKIP_ROM 0xCC		 // 跳过ROM匹配
#define DS18B20_CONVERT_T 0x44		 // 开始温度转换
#define DS18B20_READ_SCRATCHPAD 0xBE // 读取暂存器

/**
 * @brief  DS18B20开始温度变换
 * @param  无
 * @retval 无
 * @note   发送温度转换命令，DS18B20开始进行温度转换
 */
void DS18B20_ConvertT(void)
{
	OneWire_Init();						 // 初始化单总线
	OneWire_SendByte(DS18B20_SKIP_ROM);	 // 跳过ROM匹配
	OneWire_SendByte(DS18B20_CONVERT_T); // 发送温度转换命令
}

/**
 * @brief  DS18B20读取温度
 * @param  无
 * @retval float 返回温度值，单位为摄氏度
 * @note   读取DS18B20的温度数据并转换为实际温度值
 *         温度值 = 原始数据 / 16.0
 */
float DS18B20_ReadT(void)
{
	unsigned char TLSB, TMSB;
	int16_t Temp; // 使用有符号16位整数
	float T;

	// 初始化检查
	if (OneWire_Init() != 0)
	{
		return 0.0f; // 初始化失败返回0
	}

	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);

	TLSB = OneWire_ReceiveByte();
	TMSB = OneWire_ReceiveByte();

	// 合并高低字节，直接使用有符号整数
	Temp = (int16_t)((TMSB << 8) | TLSB);

	// 直接转换为浮点数，int16_t会自动处理符号
	T = Temp * 0.0625f; // 12位分辨率，每个LSB为0.0625℃
	return T;
}
