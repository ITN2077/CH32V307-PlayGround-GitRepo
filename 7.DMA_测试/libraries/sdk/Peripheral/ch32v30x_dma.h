/********************************** (C) COPYRIGHT  *******************************
 * File Name          : ch32v30x_dma.h
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : 此文件包含了DMA固件库的所有函数原型
 *                      直接内存访问(DMA)用于在外设和存储器之间或者存储器和存储器之间提供高速数据传输
 *                      使用DMA可以减轻CPU负担，提高系统效率
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/
#ifndef __CH32V30x_DMA_H
#define __CH32V30x_DMA_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ch32v30x.h"

  /* DMA初始化结构体定义 */
  typedef struct
  {
    uint32_t DMA_PeripheralBaseAddr; /* 指定DMA通道的外设基地址 */

    uint32_t DMA_MemoryBaseAddr; /* 指定DMA通道的内存基地址 */

    uint32_t DMA_DIR; /* 指定外设是源还是目标
                         可选值见 @ref DMA_data_transfer_direction */

    uint32_t DMA_BufferSize; /* 指定DMA通道的缓冲区大小，单位为数据单元
                                数据单元大小取决于DMA_PeripheralDataSize
                                或DMA_MemoryDataSize的配置 */

    uint32_t DMA_PeripheralInc; /* 指定外设地址寄存器是否自增
                                   可选值见 @ref DMA_peripheral_incremented_mode */

    uint32_t DMA_MemoryInc; /* 指定内存地址寄存器是否自增
                               可选值见 @ref DMA_memory_incremented_mode */

    uint32_t DMA_PeripheralDataSize; /* 指定外设数据宽度
                                        可选值见 @ref DMA_peripheral_data_size */

    uint32_t DMA_MemoryDataSize; /* 指定内存数据宽度
                                    可选值见 @ref DMA_memory_data_size */

    uint32_t DMA_Mode; /* 指定DMA通道的操作模式
                          可选值见 @ref DMA_circular_normal_mode
                          注意：如果配置了内存到内存传输，不能使用循环缓冲区模式 */

    uint32_t DMA_Priority; /* 指定DMA通道的软件优先级
                              可选值见 @ref DMA_priority_level */

    uint32_t DMA_M2M; /* 指定是否使用DMA通道进行内存到内存传输
                         可选值见 @ref DMA_memory_to_memory */
  } DMA_InitTypeDef;

/* DMA数据传输方向定义 */
#define DMA_DIR_PeripheralDST ((uint32_t)0x00000010) /* 外设为目标 （数据从内存写入到外设）*/
#define DMA_DIR_PeripheralSRC ((uint32_t)0x00000000) /* 外设为源（数据从外设读取到内存） */

/* DMA外设地址自增模式定义 */
#define DMA_PeripheralInc_Enable ((uint32_t)0x00000040)  /* 外设地址自增 */
#define DMA_PeripheralInc_Disable ((uint32_t)0x00000000) /* 外设地址固定 */

/* DMA内存地址自增模式定义 */
#define DMA_MemoryInc_Enable ((uint32_t)0x00000080)  /* 内存地址自增 */
#define DMA_MemoryInc_Disable ((uint32_t)0x00000000) /* 内存地址固定 */

/* DMA外设数据宽度定义 */
#define DMA_PeripheralDataSize_Byte ((uint32_t)0x00000000)     /* 8位 */
#define DMA_PeripheralDataSize_HalfWord ((uint32_t)0x00000100) /* 16位 */
#define DMA_PeripheralDataSize_Word ((uint32_t)0x00000200)     /* 32位 */

/* DMA内存数据宽度定义 */
#define DMA_MemoryDataSize_Byte ((uint32_t)0x00000000)     /* 8位 */
#define DMA_MemoryDataSize_HalfWord ((uint32_t)0x00000400) /* 16位 */
#define DMA_MemoryDataSize_Word ((uint32_t)0x00000800)     /* 32位 */

/* DMA循环/普通模式定义 */
#define DMA_Mode_Circular ((uint32_t)0x00000020) /* 循环模式 */
#define DMA_Mode_Normal ((uint32_t)0x00000000)   /* 普通模式 */

/* DMA优先级定义 */
#define DMA_Priority_VeryHigh ((uint32_t)0x00003000) /* 最高优先级 */
#define DMA_Priority_High ((uint32_t)0x00002000)     /* 高优先级 */
#define DMA_Priority_Medium ((uint32_t)0x00001000)   /* 中等优先级 */
#define DMA_Priority_Low ((uint32_t)0x00000000)      /* 低优先级 */

/* DMA内存到内存传输定义 */
#define DMA_M2M_Enable ((uint32_t)0x00004000)  /* 启用内存到内存传输 */
#define DMA_M2M_Disable ((uint32_t)0x00000000) /* 禁用内存到内存传输 */

/* DMA中断定义 */
#define DMA_IT_TC ((uint32_t)0x00000002) /* 传输完成中断 */
#define DMA_IT_HT ((uint32_t)0x00000004) /* 半传输中断 */
#define DMA_IT_TE ((uint32_t)0x00000008) /* 传输错误中断 */

#define DMA1_IT_GL1 ((uint32_t)0x00000001)
#define DMA1_IT_TC1 ((uint32_t)0x00000002)
#define DMA1_IT_HT1 ((uint32_t)0x00000004)
#define DMA1_IT_TE1 ((uint32_t)0x00000008)
#define DMA1_IT_GL2 ((uint32_t)0x00000010)
#define DMA1_IT_TC2 ((uint32_t)0x00000020)
#define DMA1_IT_HT2 ((uint32_t)0x00000040)
#define DMA1_IT_TE2 ((uint32_t)0x00000080)
#define DMA1_IT_GL3 ((uint32_t)0x00000100)
#define DMA1_IT_TC3 ((uint32_t)0x00000200)
#define DMA1_IT_HT3 ((uint32_t)0x00000400)
#define DMA1_IT_TE3 ((uint32_t)0x00000800)
#define DMA1_IT_GL4 ((uint32_t)0x00001000)
#define DMA1_IT_TC4 ((uint32_t)0x00002000)
#define DMA1_IT_HT4 ((uint32_t)0x00004000)
#define DMA1_IT_TE4 ((uint32_t)0x00008000)
#define DMA1_IT_GL5 ((uint32_t)0x00010000)
#define DMA1_IT_TC5 ((uint32_t)0x00020000)
#define DMA1_IT_HT5 ((uint32_t)0x00040000)
#define DMA1_IT_TE5 ((uint32_t)0x00080000)
#define DMA1_IT_GL6 ((uint32_t)0x00100000)
#define DMA1_IT_TC6 ((uint32_t)0x00200000)
#define DMA1_IT_HT6 ((uint32_t)0x00400000)
#define DMA1_IT_TE6 ((uint32_t)0x00800000)
#define DMA1_IT_GL7 ((uint32_t)0x01000000)
#define DMA1_IT_TC7 ((uint32_t)0x02000000)
#define DMA1_IT_HT7 ((uint32_t)0x04000000)
#define DMA1_IT_TE7 ((uint32_t)0x08000000)

#define DMA2_IT_GL1 ((uint32_t)0x10000001)
#define DMA2_IT_TC1 ((uint32_t)0x10000002)
#define DMA2_IT_HT1 ((uint32_t)0x10000004)
#define DMA2_IT_TE1 ((uint32_t)0x10000008)
#define DMA2_IT_GL2 ((uint32_t)0x10000010)
#define DMA2_IT_TC2 ((uint32_t)0x10000020)
#define DMA2_IT_HT2 ((uint32_t)0x10000040)
#define DMA2_IT_TE2 ((uint32_t)0x10000080)
#define DMA2_IT_GL3 ((uint32_t)0x10000100)
#define DMA2_IT_TC3 ((uint32_t)0x10000200)
#define DMA2_IT_HT3 ((uint32_t)0x10000400)
#define DMA2_IT_TE3 ((uint32_t)0x10000800)
#define DMA2_IT_GL4 ((uint32_t)0x10001000)
#define DMA2_IT_TC4 ((uint32_t)0x10002000)
#define DMA2_IT_HT4 ((uint32_t)0x10004000)
#define DMA2_IT_TE4 ((uint32_t)0x10008000)
#define DMA2_IT_GL5 ((uint32_t)0x10010000)
#define DMA2_IT_TC5 ((uint32_t)0x10020000)
#define DMA2_IT_HT5 ((uint32_t)0x10040000)
#define DMA2_IT_TE5 ((uint32_t)0x10080000)
#define DMA2_IT_GL6 ((uint32_t)0x10100000)
#define DMA2_IT_TC6 ((uint32_t)0x10200000)
#define DMA2_IT_HT6 ((uint32_t)0x10400000)
#define DMA2_IT_TE6 ((uint32_t)0x10800000)
#define DMA2_IT_GL7 ((uint32_t)0x11000000)
#define DMA2_IT_TC7 ((uint32_t)0x12000000)
#define DMA2_IT_HT7 ((uint32_t)0x14000000)
#define DMA2_IT_TE7 ((uint32_t)0x18000000)

#define DMA2_IT_GL8 ((uint32_t)0x20000001)
#define DMA2_IT_TC8 ((uint32_t)0x20000002)
#define DMA2_IT_HT8 ((uint32_t)0x20000004)
#define DMA2_IT_TE8 ((uint32_t)0x20000008)
#define DMA2_IT_GL9 ((uint32_t)0x20000010)
#define DMA2_IT_TC9 ((uint32_t)0x20000020)
#define DMA2_IT_HT9 ((uint32_t)0x20000040)
#define DMA2_IT_TE9 ((uint32_t)0x20000080)
#define DMA2_IT_GL10 ((uint32_t)0x20000100)
#define DMA2_IT_TC10 ((uint32_t)0x20000200)
#define DMA2_IT_HT10 ((uint32_t)0x20000400)
#define DMA2_IT_TE10 ((uint32_t)0x20000800)
#define DMA2_IT_GL11 ((uint32_t)0x20001000)
#define DMA2_IT_TC11 ((uint32_t)0x20002000)
#define DMA2_IT_HT11 ((uint32_t)0x20004000)
#define DMA2_IT_TE11 ((uint32_t)0x20008000)

/* DMA_flags_definition 标志位定义 */
#define DMA1_FLAG_GL1 ((uint32_t)0x00000001)
#define DMA1_FLAG_TC1 ((uint32_t)0x00000002)
#define DMA1_FLAG_HT1 ((uint32_t)0x00000004)
#define DMA1_FLAG_TE1 ((uint32_t)0x00000008)
#define DMA1_FLAG_GL2 ((uint32_t)0x00000010)
#define DMA1_FLAG_TC2 ((uint32_t)0x00000020)
#define DMA1_FLAG_HT2 ((uint32_t)0x00000040)
#define DMA1_FLAG_TE2 ((uint32_t)0x00000080)
#define DMA1_FLAG_GL3 ((uint32_t)0x00000100)
#define DMA1_FLAG_TC3 ((uint32_t)0x00000200)
#define DMA1_FLAG_HT3 ((uint32_t)0x00000400)
#define DMA1_FLAG_TE3 ((uint32_t)0x00000800)
#define DMA1_FLAG_GL4 ((uint32_t)0x00001000)
#define DMA1_FLAG_TC4 ((uint32_t)0x00002000)
#define DMA1_FLAG_HT4 ((uint32_t)0x00004000)
#define DMA1_FLAG_TE4 ((uint32_t)0x00008000)
#define DMA1_FLAG_GL5 ((uint32_t)0x00010000)
#define DMA1_FLAG_TC5 ((uint32_t)0x00020000)
#define DMA1_FLAG_HT5 ((uint32_t)0x00040000)
#define DMA1_FLAG_TE5 ((uint32_t)0x00080000)
#define DMA1_FLAG_GL6 ((uint32_t)0x00100000)
#define DMA1_FLAG_TC6 ((uint32_t)0x00200000)
#define DMA1_FLAG_HT6 ((uint32_t)0x00400000)
#define DMA1_FLAG_TE6 ((uint32_t)0x00800000)
#define DMA1_FLAG_GL7 ((uint32_t)0x01000000)
#define DMA1_FLAG_TC7 ((uint32_t)0x02000000)
#define DMA1_FLAG_HT7 ((uint32_t)0x04000000)
#define DMA1_FLAG_TE7 ((uint32_t)0x08000000)

#define DMA2_FLAG_GL1 ((uint32_t)0x10000001)
#define DMA2_FLAG_TC1 ((uint32_t)0x10000002)
#define DMA2_FLAG_HT1 ((uint32_t)0x10000004)
#define DMA2_FLAG_TE1 ((uint32_t)0x10000008)
#define DMA2_FLAG_GL2 ((uint32_t)0x10000010)
#define DMA2_FLAG_TC2 ((uint32_t)0x10000020)
#define DMA2_FLAG_HT2 ((uint32_t)0x10000040)
#define DMA2_FLAG_TE2 ((uint32_t)0x10000080)
#define DMA2_FLAG_GL3 ((uint32_t)0x10000100)
#define DMA2_FLAG_TC3 ((uint32_t)0x10000200)
#define DMA2_FLAG_HT3 ((uint32_t)0x10000400)
#define DMA2_FLAG_TE3 ((uint32_t)0x10000800)
#define DMA2_FLAG_GL4 ((uint32_t)0x10001000)
#define DMA2_FLAG_TC4 ((uint32_t)0x10002000)
#define DMA2_FLAG_HT4 ((uint32_t)0x10004000)
#define DMA2_FLAG_TE4 ((uint32_t)0x10008000)
#define DMA2_FLAG_GL5 ((uint32_t)0x10010000)
#define DMA2_FLAG_TC5 ((uint32_t)0x10020000)
#define DMA2_FLAG_HT5 ((uint32_t)0x10040000)
#define DMA2_FLAG_TE5 ((uint32_t)0x10080000)
#define DMA2_FLAG_GL6 ((uint32_t)0x10100000)
#define DMA2_FLAG_TC6 ((uint32_t)0x10200000)
#define DMA2_FLAG_HT6 ((uint32_t)0x10400000)
#define DMA2_FLAG_TE6 ((uint32_t)0x10800000)
#define DMA2_FLAG_GL7 ((uint32_t)0x11000000)
#define DMA2_FLAG_TC7 ((uint32_t)0x12000000)
#define DMA2_FLAG_HT7 ((uint32_t)0x14000000)
#define DMA2_FLAG_TE7 ((uint32_t)0x18000000)

#define DMA2_FLAG_GL8 ((uint32_t)0x20000001)
#define DMA2_FLAG_TC8 ((uint32_t)0x20000002)
#define DMA2_FLAG_HT8 ((uint32_t)0x20000004)
#define DMA2_FLAG_TE8 ((uint32_t)0x20000008)
#define DMA2_FLAG_GL9 ((uint32_t)0x20000010)
#define DMA2_FLAG_TC9 ((uint32_t)0x20000020)
#define DMA2_FLAG_HT9 ((uint32_t)0x20000040)
#define DMA2_FLAG_TE9 ((uint32_t)0x20000080)
#define DMA2_FLAG_GL10 ((uint32_t)0x20000100)
#define DMA2_FLAG_TC10 ((uint32_t)0x20000200)
#define DMA2_FLAG_HT10 ((uint32_t)0x20000400)
#define DMA2_FLAG_TE10 ((uint32_t)0x20000800)
#define DMA2_FLAG_GL11 ((uint32_t)0x20001000)
#define DMA2_FLAG_TC11 ((uint32_t)0x20002000)
#define DMA2_FLAG_HT11 ((uint32_t)0x20004000)
#define DMA2_FLAG_TE11 ((uint32_t)0x20008000)

  void DMA_DeInit(DMA_Channel_TypeDef *DMAy_Channelx);                                              /* 将DMA通道寄存器恢复为默认值 */
  void DMA_Init(DMA_Channel_TypeDef *DMAy_Channelx, DMA_InitTypeDef *DMA_InitStruct);               /* 根据DMA_InitStruct中指定的参数初始化DMA通道 */
  void DMA_StructInit(DMA_InitTypeDef *DMA_InitStruct);                                             /* 将DMA_InitStruct的每个成员填充其默认值 */
  void DMA_Cmd(DMA_Channel_TypeDef *DMAy_Channelx, FunctionalState NewState);                       /* 使能或禁用指定的DMA通道 */
  void DMA_ITConfig(DMA_Channel_TypeDef *DMAy_Channelx, uint32_t DMA_IT, FunctionalState NewState); /* 使能或禁用指定的DMA通道中断 */
  void DMA_SetCurrDataCounter(DMA_Channel_TypeDef *DMAy_Channelx, uint16_t DataNumber);             /* 设置DMA通道当前数据计数器 */
  uint16_t DMA_GetCurrDataCounter(DMA_Channel_TypeDef *DMAy_Channelx);                              /* 返回DMA通道当前数据计数器的值 */
  FlagStatus DMA_GetFlagStatus(uint32_t DMAy_FLAG);                                                 /* 检查指定的DMA标志位是否设置 */
  void DMA_ClearFlag(uint32_t DMAy_FLAG);                                                           /* 清除DMA标志位 */
  ITStatus DMA_GetITStatus(uint32_t DMAy_IT);                                                       /* 检查指定的DMA中断是否发生 */
  void DMA_ClearITPendingBit(uint32_t DMAy_IT);                                                     /* 清除DMA中断挂起位 */


#ifdef __cplusplus
}
#endif

#endif
