/********************************** (C) COPYRIGHT  *******************************
 * 文件名             : ch32v30x_spi.h
 * 作者               : WCH
 * 版本               : V1.0.0
 * 日期               : 2021/06/06
 * 描述               : 本文件包含了所有SPI固件库的函数原型。
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/
#ifndef __CH32V30x_SPI_H
#define __CH32V30x_SPI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ch32v30x.h"

  /* SPI 初始化结构体定义 */
  typedef struct
  {
    uint16_t SPI_Direction; /* 指定SPI单向或双向数据模式。
                             该参数可以是 @ref SPI_data_direction 中的值 */

    uint16_t SPI_Mode; /* 指定SPI工作模式。
                        该参数可以是 @ref SPI_mode 中的值 */

    uint16_t SPI_DataSize; /* 指定SPI数据大小。
                            该参数可以是 @ref SPI_data_size 中的值 */

    uint16_t SPI_CPOL; /* 指定串行时钟稳态。
                        该参数可以是 @ref SPI_Clock_Polarity 中的值 */

    uint16_t SPI_CPHA; /* 指定位捕获的时钟有效边沿。
                        该参数可以是 @ref SPI_Clock_Phase 中的值 */

    uint16_t SPI_NSS; /* 指定NSS信号是由硬件(NSS引脚)管理还是由软件使用SSI位管理。
                       该参数可以是 @ref SPI_Slave_Select_management 中的值 */

    uint16_t SPI_BaudRatePrescaler; /* 指定用于配置发送和接收SCK时钟的波特率预分频值。
                                     该参数可以是 @ref SPI_BaudRate_Prescaler 中的值。
                                     注意：通信时钟来自主时钟。从时钟不需要设置。 */

    uint16_t SPI_FirstBit; /* 指定数据传输是从MSB位还是LSB位开始。
                            该参数可以是 @ref SPI_MSB_LSB_transmission 中的值 */

    uint16_t SPI_CRCPolynomial; /* 指定用于CRC计算的多项式。 */
  } SPI_InitTypeDef;

  /* I2S 初始化结构体定义 */
  typedef struct
  {
    uint16_t I2S_Mode; /* 指定I2S工作模式。
                       该参数可以是 @ref I2S_Mode 中的值 */

    uint16_t I2S_Standard; /* 指定用于I2S通信的标准。
                           该参数可以是 @ref I2S_Standard 中的值 */

    uint16_t I2S_DataFormat; /* 指定I2S通信的数据格式。
                             该参数可以是 @ref I2S_Data_Format 中的值 */

    uint16_t I2S_MCLKOutput; /* 指定是否启用I2S MCLK输出。
                             该参数可以是 @ref I2S_MCLK_Output 中的值 */

    uint32_t I2S_AudioFreq; /* 指定I2S通信选择的频率。
                            该参数可以是 @ref I2S_Audio_Frequency 中的值 */

    uint16_t I2S_CPOL; /* 指定I2S时钟的空闲状态。
                       该参数可以是 @ref I2S_Clock_Polarity 中的值 */
  } I2S_InitTypeDef;

/* SPI数据方向 */
#define SPI_Direction_2Lines_FullDuplex ((uint16_t)0x0000)
#define SPI_Direction_2Lines_RxOnly ((uint16_t)0x0400)
#define SPI_Direction_1Line_Rx ((uint16_t)0x8000)
#define SPI_Direction_1Line_Tx ((uint16_t)0xC000)

/* SPI模式 */
#define SPI_Mode_Master ((uint16_t)0x0104)
#define SPI_Mode_Slave ((uint16_t)0x0000)

/* SPI数据大小 */
#define SPI_DataSize_16b ((uint16_t)0x0800)
#define SPI_DataSize_8b ((uint16_t)0x0000)

/* SPI时钟极性 */
#define SPI_CPOL_Low ((uint16_t)0x0000)
#define SPI_CPOL_High ((uint16_t)0x0002)

/* SPI时钟相位 */
#define SPI_CPHA_1Edge ((uint16_t)0x0000)
#define SPI_CPHA_2Edge ((uint16_t)0x0001)

/* SPI从机选择管理 */
#define SPI_NSS_Soft ((uint16_t)0x0200)
#define SPI_NSS_Hard ((uint16_t)0x0000)

/* SPI波特率预分频器 */
#define SPI_BaudRatePrescaler_2 ((uint16_t)0x0000)
#define SPI_BaudRatePrescaler_4 ((uint16_t)0x0008)
#define SPI_BaudRatePrescaler_8 ((uint16_t)0x0010)
#define SPI_BaudRatePrescaler_16 ((uint16_t)0x0018)
#define SPI_BaudRatePrescaler_32 ((uint16_t)0x0020)
#define SPI_BaudRatePrescaler_64 ((uint16_t)0x0028)
#define SPI_BaudRatePrescaler_128 ((uint16_t)0x0030)
#define SPI_BaudRatePrescaler_256 ((uint16_t)0x0038)

/* SPI MSB/LSB传输 */
#define SPI_FirstBit_MSB ((uint16_t)0x0000)
#define SPI_FirstBit_LSB ((uint16_t)0x0080)

/* I2S模式 */
#define I2S_Mode_SlaveTx ((uint16_t)0x0000)
#define I2S_Mode_SlaveRx ((uint16_t)0x0100)
#define I2S_Mode_MasterTx ((uint16_t)0x0200)
#define I2S_Mode_MasterRx ((uint16_t)0x0300)

/* I2S标准 */
#define I2S_Standard_Phillips ((uint16_t)0x0000)
#define I2S_Standard_MSB ((uint16_t)0x0010)
#define I2S_Standard_LSB ((uint16_t)0x0020)
#define I2S_Standard_PCMShort ((uint16_t)0x0030)
#define I2S_Standard_PCMLong ((uint16_t)0x00B0)

/* I2S数据格式 */
#define I2S_DataFormat_16b ((uint16_t)0x0000)
#define I2S_DataFormat_16bextended ((uint16_t)0x0001)
#define I2S_DataFormat_24b ((uint16_t)0x0003)
#define I2S_DataFormat_32b ((uint16_t)0x0005)

/* I2S MCLK输出 */
#define I2S_MCLKOutput_Enable ((uint16_t)0x0200)
#define I2S_MCLKOutput_Disable ((uint16_t)0x0000)

/* I2S音频频率 */
#define I2S_AudioFreq_192k ((uint32_t)192000)
#define I2S_AudioFreq_96k ((uint32_t)96000)
#define I2S_AudioFreq_48k ((uint32_t)48000)
#define I2S_AudioFreq_44k ((uint32_t)44100)
#define I2S_AudioFreq_32k ((uint32_t)32000)
#define I2S_AudioFreq_22k ((uint32_t)22050)
#define I2S_AudioFreq_16k ((uint32_t)16000)
#define I2S_AudioFreq_11k ((uint32_t)11025)
#define I2S_AudioFreq_8k ((uint32_t)8000)
#define I2S_AudioFreq_Default ((uint32_t)2)

/* I2S时钟极性 */
#define I2S_CPOL_Low ((uint16_t)0x0000)
#define I2S_CPOL_High ((uint16_t)0x0008)

/* SPI/I2S DMA传输请求 */
#define SPI_I2S_DMAReq_Tx ((uint16_t)0x0002)
#define SPI_I2S_DMAReq_Rx ((uint16_t)0x0001)

/* SPI NSS内部软件管理 */
#define SPI_NSSInternalSoft_Set ((uint16_t)0x0100)
#define SPI_NSSInternalSoft_Reset ((uint16_t)0xFEFF)

/* SPI CRC发送/接收 */
#define SPI_CRC_Tx ((uint8_t)0x00)
#define SPI_CRC_Rx ((uint8_t)0x01)

/* SPI方向发送/接收 */
#define SPI_Direction_Rx ((uint16_t)0xBFFF)
#define SPI_Direction_Tx ((uint16_t)0x4000)

/* SPI/I2S中断定义 */
#define SPI_I2S_IT_TXE ((uint8_t)0x71)
#define SPI_I2S_IT_RXNE ((uint8_t)0x60)
#define SPI_I2S_IT_ERR ((uint8_t)0x50)
#define SPI_I2S_IT_OVR ((uint8_t)0x56)
#define SPI_IT_MODF ((uint8_t)0x55)
#define SPI_IT_CRCERR ((uint8_t)0x54)
#define I2S_IT_UDR ((uint8_t)0x53)

/* SPI/I2S标志定义 */
#define SPI_I2S_FLAG_RXNE ((uint16_t)0x0001)
#define SPI_I2S_FLAG_TXE ((uint16_t)0x0002)
#define I2S_FLAG_CHSIDE ((uint16_t)0x0004)
#define I2S_FLAG_UDR ((uint16_t)0x0008)
#define SPI_FLAG_CRCERR ((uint16_t)0x0010)
#define SPI_FLAG_MODF ((uint16_t)0x0020)
#define SPI_I2S_FLAG_OVR ((uint16_t)0x0040)
#define SPI_I2S_FLAG_BSY ((uint16_t)0x0080)

  /* 函数声明 */
  void SPI_I2S_DeInit(SPI_TypeDef *SPIx);                                                    /* 将SPI/I2S外设寄存器重置为默认值 */
  void SPI_Init(SPI_TypeDef *SPIx, SPI_InitTypeDef *SPI_InitStruct);                         /* 根据SPI_InitStruct中的指定参数初始化SPI */
  void I2S_Init(SPI_TypeDef *SPIx, I2S_InitTypeDef *I2S_InitStruct);                         /* 根据I2S_InitStruct中的指定参数初始化I2S */
  void SPI_StructInit(SPI_InitTypeDef *SPI_InitStruct);                                      /* 用默认值填充SPI_InitStruct */
  void I2S_StructInit(I2S_InitTypeDef *I2S_InitStruct);                                      /* 用默认值填充I2S_InitStruct */
  void SPI_Cmd(SPI_TypeDef *SPIx, FunctionalState NewState);                                 /* 启用或禁用指定的SPI外设 */
  void I2S_Cmd(SPI_TypeDef *SPIx, FunctionalState NewState);                                 /* 启用或禁用指定的I2S外设 */
  void SPI_I2S_ITConfig(SPI_TypeDef *SPIx, uint8_t SPI_I2S_IT, FunctionalState NewState);    /* 启用或禁用指定的SPI/I2S中断 */
  void SPI_I2S_DMACmd(SPI_TypeDef *SPIx, uint16_t SPI_I2S_DMAReq, FunctionalState NewState); /* 启用或禁用指定的SPI/I2S DMA请求 */
  void SPI_I2S_SendData(SPI_TypeDef *SPIx, uint16_t Data);                                   /* 通过SPI/I2S发送数据 */
  uint16_t SPI_I2S_ReceiveData(SPI_TypeDef *SPIx);                                           /* 返回SPI/I2S最近接收的数据 */
  void SPI_NSSInternalSoftwareConfig(SPI_TypeDef *SPIx, uint16_t SPI_NSSInternalSoft);       /* 配置SPI内部NSS信号 */
  void SPI_SSOutputCmd(SPI_TypeDef *SPIx, FunctionalState NewState);                         /* 启用或禁用SPI SS输出 */
  void SPI_DataSizeConfig(SPI_TypeDef *SPIx, uint16_t SPI_DataSize);                         /* 配置SPI数据大小 */
  void SPI_TransmitCRC(SPI_TypeDef *SPIx);                                                   /* 传输SPI CRC值 */
  void SPI_CalculateCRC(SPI_TypeDef *SPIx, FunctionalState NewState);                        /* 启用或禁用SPI CRC计算 */
  uint16_t SPI_GetCRC(SPI_TypeDef *SPIx, uint8_t SPI_CRC);                                   /* 返回SPI CRC值 */
  uint16_t SPI_GetCRCPolynomial(SPI_TypeDef *SPIx);                                          /* 返回SPI CRC多项式值 */
  void SPI_BiDirectionalLineConfig(SPI_TypeDef *SPIx, uint16_t SPI_Direction);               /* 配置SPI双向线路 */
  FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef *SPIx, uint16_t SPI_I2S_FLAG);                /* 检查指定的SPI/I2S标志是否设置 */
  void SPI_I2S_ClearFlag(SPI_TypeDef *SPIx, uint16_t SPI_I2S_FLAG);                          /* 清除SPI/I2S的待处理标志 */
  ITStatus SPI_I2S_GetITStatus(SPI_TypeDef *SPIx, uint8_t SPI_I2S_IT);                       /* 检查指定的SPI/I2S中断是否发生 */
  void SPI_I2S_ClearITPendingBit(SPI_TypeDef *SPIx, uint8_t SPI_I2S_IT);                     /* 清除SPI/I2S的待处理中断位 */

#ifdef __cplusplus
}
#endif

#endif
