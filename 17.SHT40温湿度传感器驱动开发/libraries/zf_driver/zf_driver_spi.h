/*********************************************************************************************************************
 * CH32V307VCT6 Opensourec Library 即（CH32V307VCT6 开源库）是一个基于官方 SDK 接口的第三方开源库
 * Copyright (c) 2022 SEEKFREE 逐飞科技
 *
 * 本文件是CH32V307VCT6 开源库的一部分
 *
 * CH32V307VCT6 开源库 是免费软件
 * 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
 * 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
 *
 * 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
 * 甚至没有隐含的适销性或适合特定用途的保证
 * 更多细节请参见 GPL
 *
 * 您应该在收到本开源库的同时收到一份 GPL 的副本
 * 如果没有，请参阅<https://www.gnu.org/licenses/>
 *
 * 额外注明：
 * 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
 * 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
 * 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
 * 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
 *
 * 文件名称          zf_driver_spi
 * 公司名称          成都逐飞科技有限公司
 * 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
 * 开发环境          MounRiver Studio V1.8.1
 * 适用平台          CH32V307VCT6
 * 店铺链接          https://seekfree.taobao.com/
 *
 * 修改记录
 * 日期                                      作者                             备注
 * 2022-09-15        大W            first version
 ********************************************************************************************************************/

#ifndef _zf_driver_spi_h
#define _zf_driver_spi_h

#include "ch32v30x_spi.h"
#include "ch32v30x_rcc.h"
#include "ch32v30x_gpio.h"

#include "zf_common_debug.h"
#include "zf_common_clock.h"

#include "zf_driver_gpio.h"

// 定义SPI通信速度优先模式
#define SPI_SPEED_PRIORITY

// SPI模块选择枚举
typedef enum
{
    SPI_1 = 0x00, // SPI1模块
    SPI_2 = 0x01, // SPI2模块
    SPI_3 = 0x02  // SPI3模块
} spi_index_enum;

// SPI引脚映射枚举
typedef enum
{
    //----------SPI1----------
    // SPI1默认映射引脚组
    SPI1_MAP0_SCK_A5 = 0x0000 | A5,  // SPI1时钟引脚，默认映射到A5
    SPI1_MAP0_MISO_A6 = 0x0000 | A6, // SPI1主机输入引脚，默认映射到A6
    SPI1_MAP0_MOSI_A7 = 0x0000 | A7, // SPI1主机输出引脚，默认映射到A7

    // SPI1重映射引脚组
    SPI1_MAP1_SCK_B3 = 0x0100 | B3,  // SPI1时钟引脚，重映射到B3
    SPI1_MAP1_MISO_B4 = 0x0100 | B4, // SPI1主机输入引脚，重映射到B4
    SPI1_MAP1_MOSI_B5 = 0x0100 | B5, // SPI1主机输出引脚，重映射到B5

    //----------SPI2----------
    // SPI2默认映射引脚组
    SPI2_MAP0_SCK_B13 = 0x1000 | B13,  // SPI2时钟引脚，默认映射到B13
    SPI2_MAP0_MISO_B14 = 0x1000 | B14, // SPI2主机输入引脚，默认映射到B14
    SPI2_MAP0_MOSI_B15 = 0x1000 | B15, // SPI2主机输出引脚，默认映射到B15

    //----------SPI3----------
    // SPI3默认映射引脚组
    SPI3_MAP0_SCK_B3 = 0x2000 | B3,  // SPI3时钟引脚，默认映射到B3
    SPI3_MAP0_MISO_B4 = 0x2000 | B4, // SPI3主机输入引脚，默认映射到B4
    SPI3_MAP0_MOSI_B5 = 0x2000 | B5, // SPI3主机输出引脚，默认映射到B5

    // SPI3重映射引脚组
    SPI3_MAP1_SCK_C10 = 0x2100 | C10,  // SPI3时钟引脚，重映射到C10
    SPI3_MAP1_MISO_C11 = 0x2100 | C11, // SPI3主机输入引脚，重映射到C11
    SPI3_MAP1_MOSI_C12 = 0x2100 | C12, // SPI3主机输出引脚，重映射到C12

    SPI_MISO_NULL = 0xFFFE, // 不使用MISO引脚时的定义
    SPI_CS_NULL = 0xFF,     // 不使用CS引脚时的定义
} spi_pin_enum;

// SPI工作模式枚举
typedef enum
{
    SPI_MODE0, // CPOL=0, CPHA=0
    SPI_MODE1, // CPOL=0, CPHA=1
    SPI_MODE2, // CPOL=1, CPHA=0
    SPI_MODE3, // CPOL=1, CPHA=1
} spi_mode_enum;

// 8位数据写入函数
void spi_write_8bit(spi_index_enum spi_n, const uint8 data);
// 8位数据数组写入函数
void spi_write_8bit_array(spi_index_enum spi_n, const uint8 *data, uint32 len);

// 16位数据写入函数
void spi_write_16bit(spi_index_enum spi_n, const uint16 data);
// 16位数据数组写入函数
void spi_write_16bit_array(spi_index_enum spi_n, const uint16 *data, uint32 len);

// 8位寄存器写入函数
void spi_write_8bit_register(spi_index_enum spi_n, const uint8 register_name, const uint8 data);
// 8位寄存器数组写入函数
void spi_write_8bit_registers(spi_index_enum spi_n, const uint8 register_name, const uint8 *data, uint32 len);

// 16位寄存器写入函数
void spi_write_16bit_register(spi_index_enum spi_n, const uint16 register_name, const uint16 data);
// 16位寄存器数组写入函数
void spi_write_16bit_registers(spi_index_enum spi_n, const uint16 register_name, const uint16 *data, uint32 len);

// 8位数据读取函数
uint8 spi_read_8bit(spi_index_enum spi_n);
// 8位数据数组读取函数
void spi_read_8bit_array(spi_index_enum spi_n, uint8 *data, uint32 len);

// 16位数据读取函数
uint16 spi_read_16bit(spi_index_enum spi_n);
// 16位数据数组读取函数
void spi_read_16bit_array(spi_index_enum spi_n, uint16 *data, uint32 len);

// 8位寄存器读取函数
uint8 spi_read_8bit_register(spi_index_enum spi_n, const uint8 register_name);
// 8位寄存器数组读取函数
void spi_read_8bit_registers(spi_index_enum spi_n, const uint8 register_name, uint8 *data, uint32 len);

// 16位寄存器读取函数
uint16 spi_read_16bit_register(spi_index_enum spi_n, const uint16 register_name);
// 16位寄存器数组读取函数
void spi_read_16bit_registers(spi_index_enum spi_n, const uint16 register_name, uint16 *data, uint32 len);

// 8位数据收发函数
void spi_transfer_8bit(spi_index_enum spi_n, const uint8 *write_buffer, uint8 *read_buffer, uint32 len);
// 16位数据收发函数
void spi_transfer_16bit(spi_index_enum spi_n, const uint16 *write_buffer, uint16 *read_buffer, uint32 len);

// SPI初始化函数
// 参数说明：
// spi_n: SPI模块选择（SPI_1/SPI_2/SPI_3）
// mode: SPI工作模式（SPI_MODE0/SPI_MODE1/SPI_MODE2/SPI_MODE3）
// baud: SPI通信波特率
// sck_pin: 时钟引脚选择
// mosi_pin: 主机输出引脚选择
// miso_pin: 主机输入引脚选择
// cs_pin: 片选引脚选择
void spi_init(spi_index_enum spi_n, spi_mode_enum mode, uint32 baud, spi_pin_enum sck_pin, spi_pin_enum mosi_pin, spi_pin_enum miso_pin, gpio_pin_enum cs_pin);

#endif
