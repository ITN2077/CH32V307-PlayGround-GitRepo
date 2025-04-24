/********************************** (C) COPYRIGHT  *******************************
 * File Name          : ch32v30x_usart.h
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : 该文件包含了USART固件库的所有函数原型。
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/
#ifndef __CH32V30x_USART_H
#define __CH32V30x_USART_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ch32v30x.h"

  /* USART初始化结构体定义 */
  typedef struct
  {
    uint32_t USART_BaudRate; /* 配置USART通信波特率。
                                波特率计算公式：
                                - 整数分频 = ((PCLKx) / (16 * (USART_InitStruct->USART_BaudRate)))
                                - 小数分频 = ((整数分频 - ((u32) 整数分频)) * 16) + 0.5 */

    uint16_t USART_WordLength; /* 指定一帧中传输或接收的数据位数。
                                  该参数可以是@ref USART_Word_Length的值 */

    uint16_t USART_StopBits; /* 指定传输的停止位数。
                                该参数可以是@ref USART_Stop_Bits的值 */

    uint16_t USART_Parity; /* 指定校验模式。
                              该参数可以是@ref USART_Parity的值
                              注意：当启用校验时，计算的校验位会被插入到
                                    传输数据的最高位（当字长为9位时在第9位；
                                    当字长为8位时在第8位）。 */

    uint16_t USART_Mode; /* 指定接收或发送模式是否启用。
                            该参数可以是@ref USART_Mode的值 */

    uint16_t USART_HardwareFlowControl; /* 指定是否启用硬件流控制模式。
                                           该参数可以是@ref USART_Hardware_Flow_Control的值 */
  } USART_InitTypeDef;

  /* USART时钟初始化结构体定义 */
  typedef struct
  {
    uint16_t USART_Clock; /* 指定USART时钟是否启用。
                             该参数可以是@ref USART_Clock的值 */

    uint16_t USART_CPOL; /* 指定串行时钟的稳态值。
                            该参数可以是@ref USART_Clock_Polarity的值 */

    uint16_t USART_CPHA; /* 指定进行位捕获的时钟边沿。
                            该参数可以是@ref USART_Clock_Phase的值 */

    uint16_t USART_LastBit; /* 指定在同步模式下，是否需要在SCLK引脚上输出
                               与最后传输的数据位（MSB）对应的时钟脉冲。
                               该参数可以是@ref USART_Last_Bit的值 */
  } USART_ClockInitTypeDef;

/* USART字长定义 */
#define USART_WordLength_8b ((uint16_t)0x0000) /* 8位数据 */
#define USART_WordLength_9b ((uint16_t)0x1000) /* 9位数据 */

/* USART停止位定义 */
#define USART_StopBits_1 ((uint16_t)0x0000)   /* 1个停止位 */
#define USART_StopBits_0_5 ((uint16_t)0x1000) /* 0.5个停止位 */
#define USART_StopBits_2 ((uint16_t)0x2000)   /* 2个停止位 */
#define USART_StopBits_1_5 ((uint16_t)0x3000) /* 1.5个停止位 */

/* USART校验位定义 */
#define USART_Parity_No ((uint16_t)0x0000)   /* 无校验 */
#define USART_Parity_Even ((uint16_t)0x0400) /* 偶校验 */
#define USART_Parity_Odd ((uint16_t)0x0600)  /* 奇校验 */

/* USART模式定义 */
#define USART_Mode_Rx ((uint16_t)0x0004) /* 接收模式 */
#define USART_Mode_Tx ((uint16_t)0x0008) /* 发送模式 */

/* USART硬件流控制定义 */
#define USART_HardwareFlowControl_None ((uint16_t)0x0000)    /* 无硬件流控制 */
#define USART_HardwareFlowControl_RTS ((uint16_t)0x0100)     /* RTS流控制 */
#define USART_HardwareFlowControl_CTS ((uint16_t)0x0200)     /* CTS流控制 */
#define USART_HardwareFlowControl_RTS_CTS ((uint16_t)0x0300) /* RTS和CTS流控制 */

/* USART时钟定义 */
#define USART_Clock_Disable ((uint16_t)0x0000) /* 禁用时钟 */
#define USART_Clock_Enable ((uint16_t)0x0800)  /* 启用时钟 */

/* USART时钟极性定义 */
#define USART_CPOL_Low ((uint16_t)0x0000)  /* 时钟低电平 */
#define USART_CPOL_High ((uint16_t)0x0400) /* 时钟高电平 */

/* USART时钟相位定义 */
#define USART_CPHA_1Edge ((uint16_t)0x0000) /* 第一个边沿 */
#define USART_CPHA_2Edge ((uint16_t)0x0200) /* 第二个边沿 */

/* USART最后一位定义 */
#define USART_LastBit_Disable ((uint16_t)0x0000) /* 禁用最后一位时钟 */
#define USART_LastBit_Enable ((uint16_t)0x0100)  /* 启用最后一位时钟 */

/* USART中断定义 */
#define USART_IT_PE ((uint16_t)0x0028)     /* 奇偶校验错误中断 */
#define USART_IT_TXE ((uint16_t)0x0727)    /* 发送数据寄存器空中断 */
#define USART_IT_TC ((uint16_t)0x0626)     /* 发送完成中断 */
#define USART_IT_RXNE ((uint16_t)0x0525)   /* 接收数据寄存器非空中断 */
#define USART_IT_ORE_RX ((uint16_t)0x0325) /* 接收溢出错误中断 */
#define USART_IT_IDLE ((uint16_t)0x0424)   /* 空闲线路检测中断 */
#define USART_IT_LBD ((uint16_t)0x0846)    /* LIN中断检测中断 */
#define USART_IT_CTS ((uint16_t)0x096A)    /* CTS中断 */
#define USART_IT_ERR ((uint16_t)0x0060)    /* 错误中断 */
#define USART_IT_ORE_ER ((uint16_t)0x0360) /* 溢出错误中断 */
#define USART_IT_NE ((uint16_t)0x0260)     /* 噪声错误中断 */
#define USART_IT_FE ((uint16_t)0x0160)     /* 帧错误中断 */
#define USART_IT_ORE USART_IT_ORE_ER       /* 溢出错误中断（别名） */

/* USART DMA请求定义 */
#define USART_DMAReq_Tx ((uint16_t)0x0080) /* 发送DMA请求 */
#define USART_DMAReq_Rx ((uint16_t)0x0040) /* 接收DMA请求 */

/* USART唤醒方法定义 */
#define USART_WakeUp_IdleLine ((uint16_t)0x0000)    /* 空闲线路唤醒 */
#define USART_WakeUp_AddressMark ((uint16_t)0x0800) /* 地址标记唤醒 */

/* USART LIN中断检测长度定义 */
#define USART_LINBreakDetectLength_10b ((uint16_t)0x0000) /* 10位中断检测 */
#define USART_LINBreakDetectLength_11b ((uint16_t)0x0020) /* 11位中断检测 */

/* USART IrDA低功耗模式定义 */
#define USART_IrDAMode_LowPower ((uint16_t)0x0004) /* 低功耗模式 */
#define USART_IrDAMode_Normal ((uint16_t)0x0000)   /* 普通模式 */

/* USART标志位定义 */
#define USART_FLAG_CTS ((uint16_t)0x0200)  /* CTS标志 */
#define USART_FLAG_LBD ((uint16_t)0x0100)  /* LIN中断检测标志 */
#define USART_FLAG_TXE ((uint16_t)0x0080)  /* 发送数据寄存器空标志 */
#define USART_FLAG_TC ((uint16_t)0x0040)   /* 发送完成标志 */
#define USART_FLAG_RXNE ((uint16_t)0x0020) /* 接收数据寄存器非空标志 */
#define USART_FLAG_IDLE ((uint16_t)0x0010) /* 空闲线路检测标志 */
#define USART_FLAG_ORE ((uint16_t)0x0008)  /* 溢出错误标志 */
#define USART_FLAG_NE ((uint16_t)0x0004)   /* 噪声错误标志 */
#define USART_FLAG_FE ((uint16_t)0x0002)   /* 帧错误标志 */
#define USART_FLAG_PE ((uint16_t)0x0001)   /* 奇偶校验错误标志 */

  /* 函数声明 */
  void USART_DeInit(USART_TypeDef *USARTx);                                                          /* 将USART外设寄存器恢复为默认值 */
  void USART_Init(USART_TypeDef *USARTx, USART_InitTypeDef *USART_InitStruct);                       /* 根据USART_InitStruct中的指定参数初始化USART外设 */
  void USART_StructInit(USART_InitTypeDef *USART_InitStruct);                                        /* 将USART_InitStruct的每个成员填充默认值 */
  void USART_ClockInit(USART_TypeDef *USARTx, USART_ClockInitTypeDef *USART_ClockInitStruct);        /* 根据USART_ClockInitStruct中的指定参数初始化USART时钟 */
  void USART_ClockStructInit(USART_ClockInitTypeDef *USART_ClockInitStruct);                         /* 将USART_ClockInitStruct的每个成员填充默认值 */
  void USART_Cmd(USART_TypeDef *USARTx, FunctionalState NewState);                                   /* 启用或禁用指定的USART外设 */
  void USART_ITConfig(USART_TypeDef *USARTx, uint16_t USART_IT, FunctionalState NewState);           /* 启用或禁用指定的USART中断 */
  void USART_DMACmd(USART_TypeDef *USARTx, uint16_t USART_DMAReq, FunctionalState NewState);         /* 启用或禁用USART的DMA请求 */
  void USART_SetAddress(USART_TypeDef *USARTx, uint8_t USART_Address);                               /* 设置USART节点地址 */
  void USART_WakeUpConfig(USART_TypeDef *USARTx, uint16_t USART_WakeUp);                             /* 选择USART唤醒方法 */
  void USART_ReceiverWakeUpCmd(USART_TypeDef *USARTx, FunctionalState NewState);                     /* 启用或禁用USART接收器唤醒功能 */
  void USART_LINBreakDetectLengthConfig(USART_TypeDef *USARTx, uint16_t USART_LINBreakDetectLength); /* 设置USART LIN中断检测长度 */
  void USART_LINCmd(USART_TypeDef *USARTx, FunctionalState NewState);                                /* 启用或禁用USART LIN模式 */
  void USART_SendData(USART_TypeDef *USARTx, uint16_t Data);                                         /* 通过USARTx外设发送单个数据 */
  uint16_t USART_ReceiveData(USART_TypeDef *USARTx);                                                 /* 返回USARTx最近接收到的数据 */
  void USART_SendBreak(USART_TypeDef *USARTx);                                                       /* 发送中断字符 */
  void USART_SetGuardTime(USART_TypeDef *USARTx, uint8_t USART_GuardTime);                           /* 设置指定的USART保护时间 */
  void USART_SetPrescaler(USART_TypeDef *USARTx, uint8_t USART_Prescaler);                           /* 设置USART预分频器 */
  void USART_SmartCardCmd(USART_TypeDef *USARTx, FunctionalState NewState);                          /* 启用或禁用USART智能卡模式 */
  void USART_SmartCardNACKCmd(USART_TypeDef *USARTx, FunctionalState NewState);                      /* 启用或禁用USART智能卡NACK传输 */
  void USART_HalfDuplexCmd(USART_TypeDef *USARTx, FunctionalState NewState);                         /* 启用或禁用USART半双工模式 */
  void USART_OverSampling8Cmd(USART_TypeDef *USARTx, FunctionalState NewState);                      /* 启用或禁用USART 8倍过采样模式 */
  void USART_OneBitMethodCmd(USART_TypeDef *USARTx, FunctionalState NewState);                       /* 启用或禁用USART一位采样方法 */
  void USART_IrDAConfig(USART_TypeDef *USARTx, uint16_t USART_IrDAMode);                             /* 配置USART IrDA模式 */
  void USART_IrDACmd(USART_TypeDef *USARTx, FunctionalState NewState);                               /* 启用或禁用USART IrDA模式 */
  FlagStatus USART_GetFlagStatus(USART_TypeDef *USARTx, uint16_t USART_FLAG);                        /* 检查指定的USART标志位是否设置 */
  void USART_ClearFlag(USART_TypeDef *USARTx, uint16_t USART_FLAG);                                  /* 清除USARTx的待处理标志位 */
  ITStatus USART_GetITStatus(USART_TypeDef *USARTx, uint16_t USART_IT);                              /* 检查指定的USART中断是否发生 */
  void USART_ClearITPendingBit(USART_TypeDef *USARTx, uint16_t USART_IT);                            /* 清除USARTx的中断待处理位 */

#ifdef __cplusplus
}
#endif

#endif
