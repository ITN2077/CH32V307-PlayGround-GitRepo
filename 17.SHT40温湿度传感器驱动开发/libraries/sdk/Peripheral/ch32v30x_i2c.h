/********************************** (C) COPYRIGHT  *******************************
 * File Name          : ch32v30x_i2c.h
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : 该文件包含了I2C固件库的所有函数原型定义
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/
#ifndef __CH32V30x_I2C_H
#define __CH32V30x_I2C_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ch32v30x.h"

  /* I2C 初始化结构体定义 */
  typedef struct
  {
    uint32_t I2C_ClockSpeed; /* 指定时钟频率
                                该参数必须设置为低于400kHz的值 */

    uint16_t I2C_Mode; /* 指定I2C模式
                          该参数可以是 @ref I2C_mode 中的值 */

    uint16_t I2C_DutyCycle; /* 指定I2C快速模式下的占空比
                               该参数可以是 @ref I2C_duty_cycle_in_fast_mode 中的值 */

    uint16_t I2C_OwnAddress1; /* 指定第一个设备自身地址
                                 该参数可以是7位或10位地址 */

    uint16_t I2C_Ack; /* 使能或禁用应答
                         该参数可以是 @ref I2C_acknowledgement 中的值 */

    uint16_t I2C_AcknowledgedAddress; /* 指定是否确认7位或10位地址
                                         该参数可以是 @ref I2C_acknowledged_address 中的值 */
  } I2C_InitTypeDef;

/* I2C模式定义 */
#define I2C_Mode_I2C ((uint16_t)0x0000)         /* I2C模式 */
#define I2C_Mode_SMBusDevice ((uint16_t)0x0002) /* SMBus设备模式 */
#define I2C_Mode_SMBusHost ((uint16_t)0x000A)   /* SMBus主机模式 */

/* I2C快速模式下的占空比定义 */
#define I2C_DutyCycle_16_9 ((uint16_t)0x4000) /* I2C快速模式 Tlow/Thigh = 16/9 */
#define I2C_DutyCycle_2 ((uint16_t)0xBFFF)    /* I2C快速模式 Tlow/Thigh = 2 */

/* I2C应答定义 */
#define I2C_Ack_Enable ((uint16_t)0x0400)  /* 使能应答 */
#define I2C_Ack_Disable ((uint16_t)0x0000) /* 禁用应答 */

/* I2C传输方向定义 */
#define I2C_Direction_Transmitter ((uint8_t)0x00) /* 发送模式 */
#define I2C_Direction_Receiver ((uint8_t)0x01)    /* 接收模式 */

/* I2C确认地址定义 */
#define I2C_AcknowledgedAddress_7bit ((uint16_t)0x4000)  /* 7位地址 */
#define I2C_AcknowledgedAddress_10bit ((uint16_t)0xC000) /* 10位地址 */

/* I2C寄存器定义 */
#define I2C_Register_CTLR1 ((uint8_t)0x00)  /* 控制寄存器1 */
#define I2C_Register_CTLR2 ((uint8_t)0x04)  /* 控制寄存器2 */
#define I2C_Register_OADDR1 ((uint8_t)0x08) /* 自身地址寄存器1 */
#define I2C_Register_OADDR2 ((uint8_t)0x0C) /* 自身地址寄存器2 */
#define I2C_Register_DATAR ((uint8_t)0x10)  /* 数据寄存器 */
#define I2C_Register_STAR1 ((uint8_t)0x14)  /* 状态寄存器1 */
#define I2C_Register_STAR2 ((uint8_t)0x18)  /* 状态寄存器2 */
#define I2C_Register_CKCFGR ((uint8_t)0x1C) /* 时钟配置寄存器 */
#define I2C_Register_RTR ((uint8_t)0x20)    /* 重装寄存器 */

/* I2C SMBus告警引脚电平定义 */
#define I2C_SMBusAlert_Low ((uint16_t)0x2000)  /* 低电平告警 */
#define I2C_SMBusAlert_High ((uint16_t)0xDFFF) /* 高电平告警 */

/* I2C PEC位置定义 */
#define I2C_PECPosition_Next ((uint16_t)0x0800)    /* PEC在下一个字节 */
#define I2C_PECPosition_Current ((uint16_t)0xF7FF) /* PEC在当前字节 */

/* I2C NACK位置定义 */
#define I2C_NACKPosition_Next ((uint16_t)0x0800)    /* NACK在下一个字节 */
#define I2C_NACKPosition_Current ((uint16_t)0xF7FF) /* NACK在当前字节 */

/* I2C中断定义 */
#define I2C_IT_BUF ((uint16_t)0x0400) /* 缓冲区中断 */
#define I2C_IT_EVT ((uint16_t)0x0200) /* 事件中断 */
#define I2C_IT_ERR ((uint16_t)0x0100) /* 错误中断 */

/* I2C中断定义（详细） */
#define I2C_IT_SMBALERT ((uint32_t)0x01008000) /* SMBus告警中断 */
#define I2C_IT_TIMEOUT ((uint32_t)0x01004000)  /* 超时中断 */
#define I2C_IT_PECERR ((uint32_t)0x01001000)   /* PEC错误中断 */
#define I2C_IT_OVR ((uint32_t)0x01000800)      /* 溢出中断 */
#define I2C_IT_AF ((uint32_t)0x01000400)       /* 应答失败中断 */
#define I2C_IT_ARLO ((uint32_t)0x01000200)     /* 仲裁丢失中断 */
#define I2C_IT_BERR ((uint32_t)0x01000100)     /* 总线错误中断 */
#define I2C_IT_TXE ((uint32_t)0x06000080)      /* 发送数据寄存器空中断 */
#define I2C_IT_RXNE ((uint32_t)0x06000040)     /* 接收数据寄存器非空中断 */
#define I2C_IT_STOPF ((uint32_t)0x02000010)    /* 停止检测中断 */
#define I2C_IT_ADD10 ((uint32_t)0x02000008)    /* 10位地址发送中断 */
#define I2C_IT_BTF ((uint32_t)0x02000004)      /* 字节传输完成中断 */
#define I2C_IT_ADDR ((uint32_t)0x02000002)     /* 地址匹配中断 */
#define I2C_IT_SB ((uint32_t)0x02000001)       /* 起始位中断 */

/* SR2寄存器标志位定义 */
#define I2C_FLAG_DUALF ((uint32_t)0x00800000)      /* 双地址标志 */
#define I2C_FLAG_SMBHOST ((uint32_t)0x00400000)    /* SMBus主机标志 */
#define I2C_FLAG_SMBDEFAULT ((uint32_t)0x00200000) /* SMBus默认标志 */
#define I2C_FLAG_GENCALL ((uint32_t)0x00100000)    /* 广播呼叫标志 */
#define I2C_FLAG_TRA ((uint32_t)0x00040000)        /* 发送/接收标志 */
#define I2C_FLAG_BUSY ((uint32_t)0x00020000)       /* 总线忙标志 */
#define I2C_FLAG_MSL ((uint32_t)0x00010000)        /* 主/从标志 */

/* SR1寄存器标志位定义 */
#define I2C_FLAG_SMBALERT ((uint32_t)0x10008000) /* SMBus告警标志 */
#define I2C_FLAG_TIMEOUT ((uint32_t)0x10004000)  /* 超时标志 */
#define I2C_FLAG_PECERR ((uint32_t)0x10001000)   /* PEC错误标志 */
#define I2C_FLAG_OVR ((uint32_t)0x10000800)      /* 溢出标志 */
#define I2C_FLAG_AF ((uint32_t)0x10000400)       /* 应答失败标志 */
#define I2C_FLAG_ARLO ((uint32_t)0x10000200)     /* 仲裁丢失标志 */
#define I2C_FLAG_BERR ((uint32_t)0x10000100)     /* 总线错误标志 */
#define I2C_FLAG_TXE ((uint32_t)0x10000080)      /* 发送数据寄存器空标志 */
#define I2C_FLAG_RXNE ((uint32_t)0x10000040)     /* 接收数据寄存器非空标志 */
#define I2C_FLAG_STOPF ((uint32_t)0x10000010)    /* 停止检测标志 */
#define I2C_FLAG_ADD10 ((uint32_t)0x10000008)    /* 10位地址发送标志 */
#define I2C_FLAG_BTF ((uint32_t)0x10000004)      /* 字节传输完成标志 */
#define I2C_FLAG_ADDR ((uint32_t)0x10000002)     /* 地址匹配标志 */
#define I2C_FLAG_SB ((uint32_t)0x10000001)       /* 起始位标志 */

/* I2C主机事件定义（按通信顺序分组） */
#define I2C_EVENT_MASTER_MODE_SELECT ((uint32_t)0x00030001)               /* 主机模式选择事件 */
#define I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ((uint32_t)0x00070082) /* 主机发送模式选择事件 */
#define I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED ((uint32_t)0x00030002)    /* 主机接收模式选择事件 */
#define I2C_EVENT_MASTER_MODE_ADDRESS10 ((uint32_t)0x00030008)            /* 主机10位地址模式事件 */
#define I2C_EVENT_MASTER_BYTE_RECEIVED ((uint32_t)0x00030040)             /* 主机接收字节事件 */
#define I2C_EVENT_MASTER_BYTE_TRANSMITTING ((uint32_t)0x00070080)         /* 主机发送字节事件 */
#define I2C_EVENT_MASTER_BYTE_TRANSMITTED ((uint32_t)0x00070084)          /* 主机字节发送完成事件 */

/* I2C从机事件定义（按通信顺序分组） */
#define I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED ((uint32_t)0x00020002)          /* 从机接收地址匹配事件 */
#define I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED ((uint32_t)0x00060082)       /* 从机发送地址匹配事件 */
#define I2C_EVENT_SLAVE_RECEIVER_SECONDADDRESS_MATCHED ((uint32_t)0x00820000)    /* 从机第二地址接收匹配事件 */
#define I2C_EVENT_SLAVE_TRANSMITTER_SECONDADDRESS_MATCHED ((uint32_t)0x00860080) /* 从机第二地址发送匹配事件 */
#define I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED ((uint32_t)0x00120000)        /* 从机广播呼叫地址匹配事件 */
#define I2C_EVENT_SLAVE_BYTE_RECEIVED ((uint32_t)0x00020040)                     /* 从机接收字节事件 */
#define I2C_EVENT_SLAVE_STOP_DETECTED ((uint32_t)0x00000010)                     /* 从机检测到停止事件 */
#define I2C_EVENT_SLAVE_BYTE_TRANSMITTED ((uint32_t)0x00060084)                  /* 从机字节发送完成事件 */
#define I2C_EVENT_SLAVE_BYTE_TRANSMITTING ((uint32_t)0x00060080)                 /* 从机发送字节事件 */
#define I2C_EVENT_SLAVE_ACK_FAILURE ((uint32_t)0x00000400)                       /* 从机应答失败事件 */

  /* I2C函数声明 */
  void I2C_DeInit(I2C_TypeDef *I2Cx);                                                  /* I2C外设反初始化 */
  void I2C_Init(I2C_TypeDef *I2Cx, I2C_InitTypeDef *I2C_InitStruct);                   /* I2C初始化 */
  void I2C_StructInit(I2C_InitTypeDef *I2C_InitStruct);                                /* I2C结构体初始化 */
  void I2C_Cmd(I2C_TypeDef *I2Cx, FunctionalState NewState);                           /* I2C使能/禁用 */
  void I2C_DMACmd(I2C_TypeDef *I2Cx, FunctionalState NewState);                        /* I2C DMA使能/禁用 */
  void I2C_DMALastTransferCmd(I2C_TypeDef *I2Cx, FunctionalState NewState);            /* I2C DMA最后传输命令 */
  void I2C_GenerateSTART(I2C_TypeDef *I2Cx, FunctionalState NewState);                 /* 生成起始条件 */
  void I2C_GenerateSTOP(I2C_TypeDef *I2Cx, FunctionalState NewState);                  /* 生成停止条件 */
  void I2C_AcknowledgeConfig(I2C_TypeDef *I2Cx, FunctionalState NewState);             /* 应答配置 */
  void I2C_OwnAddress2Config(I2C_TypeDef *I2Cx, uint8_t Address);                      /* 配置第二个自身地址 */
  void I2C_DualAddressCmd(I2C_TypeDef *I2Cx, FunctionalState NewState);                /* 双地址命令 */
  void I2C_GeneralCallCmd(I2C_TypeDef *I2Cx, FunctionalState NewState);                /* 广播呼叫命令 */
  void I2C_ITConfig(I2C_TypeDef *I2Cx, uint16_t I2C_IT, FunctionalState NewState);     /* I2C中断配置 */
  void I2C_SendData(I2C_TypeDef *I2Cx, uint8_t Data);                                  /* 发送数据 */
  uint8_t I2C_ReceiveData(I2C_TypeDef *I2Cx);                                          /* 接收数据 */
  void I2C_Send7bitAddress(I2C_TypeDef *I2Cx, uint8_t Address, uint8_t I2C_Direction); /* 发送7位地址 */
  uint16_t I2C_ReadRegister(I2C_TypeDef *I2Cx, uint8_t I2C_Register);                  /* 读取寄存器 */
  void I2C_SoftwareResetCmd(I2C_TypeDef *I2Cx, FunctionalState NewState);              /* 软件复位命令 */
  void I2C_NACKPositionConfig(I2C_TypeDef *I2Cx, uint16_t I2C_NACKPosition);           /* NACK位置配置 */
  void I2C_SMBusAlertConfig(I2C_TypeDef *I2Cx, uint16_t I2C_SMBusAlert);               /* SMBus告警配置 */
  void I2C_TransmitPEC(I2C_TypeDef *I2Cx, FunctionalState NewState);                   /* 传输PEC */
  void I2C_PECPositionConfig(I2C_TypeDef *I2Cx, uint16_t I2C_PECPosition);             /* PEC位置配置 */
  void I2C_CalculatePEC(I2C_TypeDef *I2Cx, FunctionalState NewState);                  /* 计算PEC */
  uint8_t I2C_GetPEC(I2C_TypeDef *I2Cx);                                               /* 获取PEC */
  void I2C_ARPCmd(I2C_TypeDef *I2Cx, FunctionalState NewState);                        /* ARP命令 */
  void I2C_StretchClockCmd(I2C_TypeDef *I2Cx, FunctionalState NewState);               /* 时钟延展命令 */
  void I2C_FastModeDutyCycleConfig(I2C_TypeDef *I2Cx, uint16_t I2C_DutyCycle);         /* 快速模式占空比配置 */

  /* I2C状态监控函数 */
  ErrorStatus I2C_CheckEvent(I2C_TypeDef *I2Cx, uint32_t I2C_EVENT);  /* 检查事件 */
  uint32_t I2C_GetLastEvent(I2C_TypeDef *I2Cx);                       /* 获取最后事件 */
  FlagStatus I2C_GetFlagStatus(I2C_TypeDef *I2Cx, uint32_t I2C_FLAG); /* 获取标志状态 */
  void I2C_ClearFlag(I2C_TypeDef *I2Cx, uint32_t I2C_FLAG);           /* 清除标志 */
  ITStatus I2C_GetITStatus(I2C_TypeDef *I2Cx, uint32_t I2C_IT);       /* 获取中断状态 */
  void I2C_ClearITPendingBit(I2C_TypeDef *I2Cx, uint32_t I2C_IT);     /* 清除中断挂起位 */

#ifdef __cplusplus
}
#endif

#endif
