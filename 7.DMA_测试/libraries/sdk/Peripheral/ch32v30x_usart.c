/********************************** (C) COPYRIGHT *******************************
 * File Name          : ch32v30x_usart.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : 此文件提供所有USART固件功能函数
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/
#include "ch32v30x_usart.h"
#include "ch32v30x_rcc.h"

/* USART_Private_Defines */
#define CTLR1_UE_Set ((uint16_t)0x2000)   /* USART使能掩码 */
#define CTLR1_UE_Reset ((uint16_t)0xDFFF) /* USART禁用掩码 */

#define CTLR1_WAKE_Mask ((uint16_t)0xF7FF) /* USART唤醒方式掩码 */

#define CTLR1_RWU_Set ((uint16_t)0x0002)      /* USART静默模式使能掩码 */
#define CTLR1_RWU_Reset ((uint16_t)0xFFFD)    /* USART静默模式禁用掩码 */
#define CTLR1_SBK_Set ((uint16_t)0x0001)      /* USART发送断开字符掩码 */
#define CTLR1_CLEAR_Mask ((uint16_t)0xE9F3)   /* USART CR1掩码 */
#define CTLR2_Address_Mask ((uint16_t)0xFFF0) /* USART地址掩码 */

#define CTLR2_LINEN_Set ((uint16_t)0x4000)   /* USART LIN使能掩码 */
#define CTLR2_LINEN_Reset ((uint16_t)0xBFFF) /* USART LIN禁用掩码 */

#define CTLR2_LBDL_Mask ((uint16_t)0xFFDF)        /* USART LIN断开检测掩码 */
#define CTLR2_STOP_CLEAR_Mask ((uint16_t)0xCFFF)  /* USART CR2停止位掩码 */
#define CTLR2_CLOCK_CLEAR_Mask ((uint16_t)0xF0FF) /* USART CR2时钟掩码 */

#define CTLR3_SCEN_Set ((uint16_t)0x0020)   /* USART SC使能掩码 */
#define CTLR3_SCEN_Reset ((uint16_t)0xFFDF) /* USART SC禁用掩码 */

#define CTLR3_NACK_Set ((uint16_t)0x0010)   /* USART SC NACK使能掩码 */
#define CTLR3_NACK_Reset ((uint16_t)0xFFEF) /* USART SC NACK禁用掩码 */

#define CTLR3_HDSEL_Set ((uint16_t)0x0008)   /* USART半双工使能掩码 */
#define CTLR3_HDSEL_Reset ((uint16_t)0xFFF7) /* USART半双工禁用掩码 */

#define CTLR3_IRLP_Mask ((uint16_t)0xFFFB)  /* USART IrDA低功耗模式掩码 */
#define CTLR3_CLEAR_Mask ((uint16_t)0xFCFF) /* USART CR3掩码 */

#define CTLR3_IREN_Set ((uint16_t)0x0002)   /* USART IrDA使能掩码 */
#define CTLR3_IREN_Reset ((uint16_t)0xFFFD) /* USART IrDA禁用掩码 */
#define GPR_LSB_Mask ((uint16_t)0x00FF)     /* 保护时间寄存器低字节掩码 */
#define GPR_MSB_Mask ((uint16_t)0xFF00)     /* 保护时间寄存器高字节掩码 */
#define IT_Mask ((uint16_t)0x001F)          /* USART中断掩码 */

/* USART 8倍过采样掩码 */
#define CTLR1_OVER8_Set ((uint16_t)0x8000)   /* USART OVER8模式使能掩码 */
#define CTLR1_OVER8_Reset ((uint16_t)0x7FFF) /* USART OVER8模式禁用掩码 */

/* USART单比特采样掩码 */
#define CTLR3_ONEBITE_Set ((uint16_t)0x0800)   /* USART ONEBITE模式使能掩码 */
#define CTLR3_ONEBITE_Reset ((uint16_t)0xF7FF) /* USART ONEBITE模式禁用掩码 */

/*********************************************************************
 * @fn      USART_DeInit
 *
 * @brief   将USARTx外设寄存器恢复到默认复位值
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *
 * @return  无
 */
void USART_DeInit(USART_TypeDef *USARTx)
{
    if (USARTx == USART1)
    {
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_USART1, ENABLE);
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_USART1, DISABLE);
    }
    else if (USARTx == USART2)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART2, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART2, DISABLE);
    }
    else if (USARTx == USART3)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART3, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART3, DISABLE);
    }
    else if (USARTx == UART4)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART4, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART4, DISABLE);
    }
    else if (USARTx == UART5)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART5, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART5, DISABLE);
    }
    else if (USARTx == UART6)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART6, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART6, DISABLE);
    }
    else if (USARTx == UART7)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART7, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART7, DISABLE);
    }
    else if (USARTx == UART8)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART8, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART8, DISABLE);
    }
}

/*********************************************************************
 * @fn      USART_Init
 *
 * @brief   根据USART_InitStruct中指定的参数初始化USARTx外设
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_InitStruct - 指向USART_InitTypeDef结构的指针，包含指定USART外设的配置信息
 *
 * @return  无
 */
void USART_Init(USART_TypeDef *USARTx, USART_InitTypeDef *USART_InitStruct)
{
    uint32_t tmpreg = 0x00, apbclock = 0x00;
    uint32_t integerdivider = 0x00;
    uint32_t fractionaldivider = 0x00;
    uint32_t usartxbase = 0;
    RCC_ClocksTypeDef RCC_ClocksStatus;

    if (USART_InitStruct->USART_HardwareFlowControl != USART_HardwareFlowControl_None)
    {
    }

    usartxbase = (uint32_t)USARTx;
    tmpreg = USARTx->CTLR2;
    tmpreg &= CTLR2_STOP_CLEAR_Mask;
    tmpreg |= (uint32_t)USART_InitStruct->USART_StopBits;

    USARTx->CTLR2 = (uint16_t)tmpreg;
    tmpreg = USARTx->CTLR1;
    tmpreg &= CTLR1_CLEAR_Mask;
    tmpreg |= (uint32_t)USART_InitStruct->USART_WordLength | USART_InitStruct->USART_Parity |
              USART_InitStruct->USART_Mode;
    USARTx->CTLR1 = (uint16_t)tmpreg;

    tmpreg = USARTx->CTLR3;
    tmpreg &= CTLR3_CLEAR_Mask;
    tmpreg |= USART_InitStruct->USART_HardwareFlowControl;
    USARTx->CTLR3 = (uint16_t)tmpreg;

    RCC_GetClocksFreq(&RCC_ClocksStatus);

    if (usartxbase == USART1_BASE)
    {
        apbclock = RCC_ClocksStatus.PCLK2_Frequency;
    }
    else
    {
        apbclock = RCC_ClocksStatus.PCLK1_Frequency;
    }

    if ((USARTx->CTLR1 & CTLR1_OVER8_Set) != 0)
    {
        integerdivider = ((25 * apbclock) / (2 * (USART_InitStruct->USART_BaudRate)));
    }
    else
    {
        integerdivider = ((25 * apbclock) / (4 * (USART_InitStruct->USART_BaudRate)));
    }
    tmpreg = (integerdivider / 100) << 4;

    fractionaldivider = integerdivider - (100 * (tmpreg >> 4));

    if ((USARTx->CTLR1 & CTLR1_OVER8_Set) != 0)
    {
        tmpreg |= ((((fractionaldivider * 8) + 50) / 100)) & ((uint8_t)0x07);
    }
    else
    {
        tmpreg |= ((((fractionaldivider * 16) + 50) / 100)) & ((uint8_t)0x0F);
    }

    USARTx->BRR = (uint16_t)tmpreg;
}

/*********************************************************************
 * @fn      USART_StructInit
 *
 * @brief   用默认值填充USART_InitStruct的每个成员
 *
 * @param   USART_InitStruct - 指向USART_InitTypeDef结构的指针，将被初始化
 *
 * @return  无
 */
void USART_StructInit(USART_InitTypeDef *USART_InitStruct)
{
    USART_InitStruct->USART_BaudRate = 9600;
    USART_InitStruct->USART_WordLength = USART_WordLength_8b;
    USART_InitStruct->USART_StopBits = USART_StopBits_1;
    USART_InitStruct->USART_Parity = USART_Parity_No;
    USART_InitStruct->USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct->USART_HardwareFlowControl = USART_HardwareFlowControl_None;
}

/*********************************************************************
 * @fn      USART_ClockInit
 *
 * @brief   根据USART_ClockInitStruct中指定的参数初始化USARTx外设时钟
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_ClockInitStruct - 指向USART_ClockInitTypeDef结构的指针，包含指定USART外设的配置信息
 *
 * @return  无
 */
void USART_ClockInit(USART_TypeDef *USARTx, USART_ClockInitTypeDef *USART_ClockInitStruct)
{
    uint32_t tmpreg = 0x00;

    tmpreg = USARTx->CTLR2;
    tmpreg &= CTLR2_CLOCK_CLEAR_Mask;
    tmpreg |= (uint32_t)USART_ClockInitStruct->USART_Clock | USART_ClockInitStruct->USART_CPOL |
              USART_ClockInitStruct->USART_CPHA | USART_ClockInitStruct->USART_LastBit;
    USARTx->CTLR2 = (uint16_t)tmpreg;
}

/*********************************************************************
 * @fn      USART_ClockStructInit
 *
 * @brief   用默认值填充USART_ClockStructInit的每个成员
 *
 * @param   USART_ClockInitStruct - 指向USART_ClockInitTypeDef结构的指针，将被初始化
 *
 * @return  无
 */
void USART_ClockStructInit(USART_ClockInitTypeDef *USART_ClockInitStruct)
{
    USART_ClockInitStruct->USART_Clock = USART_Clock_Disable;
    USART_ClockInitStruct->USART_CPOL = USART_CPOL_Low;
    USART_ClockInitStruct->USART_CPHA = USART_CPHA_1Edge;
    USART_ClockInitStruct->USART_LastBit = USART_LastBit_Disable;
}

/*********************************************************************
 * @fn      USART_Cmd
 *
 * @brief   使能或禁用指定的USART外设
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          NewState - ENABLE或DISABLE
 *
 * @return  无
 */
void USART_Cmd(USART_TypeDef *USARTx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        USARTx->CTLR1 |= CTLR1_UE_Set;
    }
    else
    {
        USARTx->CTLR1 &= CTLR1_UE_Reset;
    }
}

/*********************************************************************
 * @fn      USART_ITConfig
 *
 * @brief   使能或禁用指定的USART中断
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_IT - 指定要使能或禁用的USART中断源
 *            USART_IT_CTS - CTS变化中断
 *            USART_IT_LBD - LIN断开检测中断
 *            USART_IT_TXE - 发送数据寄存器空中断
 *            USART_IT_TC - 发送完成中断
 *            USART_IT_RXNE - 接收数据寄存器非空中断
 *            USART_IT_IDLE - 空闲线检测中断
 *            USART_IT_PE - 奇偶校验错误中断
 *            USART_IT_ERR - 错误中断
 *          NewState - ENABLE或DISABLE
 *
 * @return  无
 */
void USART_ITConfig(USART_TypeDef *USARTx, uint16_t USART_IT, FunctionalState NewState)
{
    uint32_t usartreg = 0x00, itpos = 0x00, itmask = 0x00;
    uint32_t usartxbase = 0x00;

    if (USART_IT == USART_IT_CTS)
    {
    }

    usartxbase = (uint32_t)USARTx;
    usartreg = (((uint8_t)USART_IT) >> 0x05);
    itpos = USART_IT & IT_Mask;
    itmask = (((uint32_t)0x01) << itpos);

    if (usartreg == 0x01)
    {
        usartxbase += 0x0C;
    }
    else if (usartreg == 0x02)
    {
        usartxbase += 0x10;
    }
    else
    {
        usartxbase += 0x14;
    }

    if (NewState != DISABLE)
    {
        *(__IO uint32_t *)usartxbase |= itmask;
    }
    else
    {
        *(__IO uint32_t *)usartxbase &= ~itmask;
    }
}

/*********************************************************************
 * @fn      USART_DMACmd
 *
 * @brief   使能或禁用USART DMA接口
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_DMAReq - 指定DMA请求
 *            USART_DMAReq_Tx - USART DMA发送请求
 *            USART_DMAReq_Rx - USART DMA接收请求
 *          NewState - ENABLE或DISABLE
 *
 * @return  无
 */
void USART_DMACmd(USART_TypeDef *USARTx, uint16_t USART_DMAReq, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        USARTx->CTLR3 |= USART_DMAReq;
    }
    else
    {
        USARTx->CTLR3 &= (uint16_t)~USART_DMAReq;
    }
}

/*********************************************************************
 * @fn      USART_SetAddress
 *
 * @brief   设置USART节点的地址
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_Address - 指示USART节点的地址
 *
 * @return  无
 */
void USART_SetAddress(USART_TypeDef *USARTx, uint8_t USART_Address)
{
    USARTx->CTLR2 &= CTLR2_Address_Mask;
    USARTx->CTLR2 |= USART_Address;
}

/*********************************************************************
 * @fn      USART_WakeUpConfig
 *
 * @brief   选择USART唤醒方式
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_WakeUp - 指定USART唤醒方式
 *            USART_WakeUp_IdleLine - 通过空闲线检测唤醒
 *            USART_WakeUp_AddressMark - 通过地址标记唤醒
 *
 * @return  无
 */
void USART_WakeUpConfig(USART_TypeDef *USARTx, uint16_t USART_WakeUp)
{
    USARTx->CTLR1 &= CTLR1_WAKE_Mask;
    USARTx->CTLR1 |= USART_WakeUp;
}

/*********************************************************************
 * @fn      USART_ReceiverWakeUpCmd
 *
 * @brief   确定USART是否处于静默模式
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          NewState - ENABLE或DISABLE
 *
 * @return  无
 */
void USART_ReceiverWakeUpCmd(USART_TypeDef *USARTx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        USARTx->CTLR1 |= CTLR1_RWU_Set;
    }
    else
    {
        USARTx->CTLR1 &= CTLR1_RWU_Reset;
    }
}

/*********************************************************************
 * @fn      USART_LINBreakDetectLengthConfig
 *
 * @brief   设置USART LIN断开检测长度
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_LINBreakDetectLength - 指定LIN断开检测长度
 *            USART_LINBreakDetectLength_10b - 10位断开检测
 *            USART_LINBreakDetectLength_11b - 11位断开检测
 *
 * @return  无
 */
void USART_LINBreakDetectLengthConfig(USART_TypeDef *USARTx, uint16_t USART_LINBreakDetectLength)
{
    USARTx->CTLR2 &= CTLR2_LBDL_Mask;
    USARTx->CTLR2 |= USART_LINBreakDetectLength;
}

/*********************************************************************
 * @fn      USART_LINCmd
 *
 * @brief   使能或禁用USART LIN模式
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          NewState - ENABLE或DISABLE
 *
 * @return  无
 */
void USART_LINCmd(USART_TypeDef *USARTx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        USARTx->CTLR2 |= CTLR2_LINEN_Set;
    }
    else
    {
        USARTx->CTLR2 &= CTLR2_LINEN_Reset;
    }
}

/*********************************************************************
 * @fn      USART_SendData
 *
 * @brief   通过USARTx外设发送单个数据
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          Data - 要发送的数据
 *
 * @return  无
 */
void USART_SendData(USART_TypeDef *USARTx, uint16_t Data)
{
    USARTx->DATAR = (Data & (uint16_t)0x01FF);
}

/*********************************************************************
 * @fn      USART_ReceiveData
 *
 * @brief   返回USARTx外设最近接收到的数据
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *
 * @return  接收到的数据
 */
uint16_t USART_ReceiveData(USART_TypeDef *USARTx)
{
    return (uint16_t)(USARTx->DATAR & (uint16_t)0x01FF);
}

/*********************************************************************
 * @fn      USART_SendBreak
 *
 * @brief   发送断开字符
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *
 * @return  无
 */
void USART_SendBreak(USART_TypeDef *USARTx)
{
    USARTx->CTLR1 |= CTLR1_SBK_Set;
}

/*********************************************************************
 * @fn      USART_SetGuardTime
 *
 * @brief   设置指定的USART保护时间
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_GuardTime - 指定保护时间
 *
 * @return  无
 */
void USART_SetGuardTime(USART_TypeDef *USARTx, uint8_t USART_GuardTime)
{
    USARTx->GPR &= GPR_LSB_Mask;
    USARTx->GPR |= (uint16_t)((uint16_t)USART_GuardTime << 0x08);
}

/*********************************************************************
 * @fn      USART_SetPrescaler
 *
 * @brief   设置系统时钟预分频器
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_Prescaler - 指定预分频器时钟
 *
 * @return  无
 */
void USART_SetPrescaler(USART_TypeDef *USARTx, uint8_t USART_Prescaler)
{
    USARTx->GPR &= GPR_MSB_Mask;
    USARTx->GPR |= USART_Prescaler;
}

/*********************************************************************
 * @fn      USART_SmartCardCmd
 *
 * @brief   使能或禁用USART智能卡模式
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          NewState - ENABLE或DISABLE
 *
 * @return  无
 */
void USART_SmartCardCmd(USART_TypeDef *USARTx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        USARTx->CTLR3 |= CTLR3_SCEN_Set;
    }
    else
    {
        USARTx->CTLR3 &= CTLR3_SCEN_Reset;
    }
}

/*********************************************************************
 * @fn      USART_SmartCardNACKCmd
 *
 * @brief   使能或禁用NACK传输
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          NewState - ENABLE或DISABLE
 *
 * @return  无
 */
void USART_SmartCardNACKCmd(USART_TypeDef *USARTx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        USARTx->CTLR3 |= CTLR3_NACK_Set;
    }
    else
    {
        USARTx->CTLR3 &= CTLR3_NACK_Reset;
    }
}

/*********************************************************************
 * @fn      USART_HalfDuplexCmd
 *
 * @brief   使能或禁用USART半双工通信
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          NewState - ENABLE或DISABLE
 *
 * @return  无
 */
void USART_HalfDuplexCmd(USART_TypeDef *USARTx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        USARTx->CTLR3 |= CTLR3_HDSEL_Set;
    }
    else
    {
        USARTx->CTLR3 &= CTLR3_HDSEL_Reset;
    }
}

/*********************************************************************
 * @fn      USART_OverSampling8Cmd
 *
 * @brief   使能或禁用USART的8倍过采样模式
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          NewState - ENABLE或DISABLE
 *
 * @return  无
 */
void USART_OverSampling8Cmd(USART_TypeDef *USARTx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        USARTx->CTLR1 |= CTLR1_OVER8_Set;
    }
    else
    {
        USARTx->CTLR1 &= CTLR1_OVER8_Reset;
    }
}

/*********************************************************************
 * @fn      USART_OneBitMethodCmd
 *
 * @brief   使能或禁用USART的单比特采样方法
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          NewState - ENABLE或DISABLE
 *
 * @return  无
 */
void USART_OneBitMethodCmd(USART_TypeDef *USARTx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        USARTx->CTLR3 |= CTLR3_ONEBITE_Set;
    }
    else
    {
        USARTx->CTLR3 &= CTLR3_ONEBITE_Reset;
    }
}

/*********************************************************************
 * @fn      USART_IrDAConfig
 *
 * @brief   配置USART的IrDA接口
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_IrDAMode - 指定IrDA模式
 *            USART_IrDAMode_LowPower - 低功耗模式
 *            USART_IrDAMode_Normal - 正常模式
 *
 * @return  无
 */
void USART_IrDAConfig(USART_TypeDef *USARTx, uint16_t USART_IrDAMode)
{
    USARTx->CTLR3 &= CTLR3_IRLP_Mask;
    USARTx->CTLR3 |= USART_IrDAMode;
}

/*********************************************************************
 * @fn      USART_IrDACmd
 *
 * @brief   使能或禁用USART的IrDA接口
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          NewState - ENABLE或DISABLE
 *
 * @return  无
 */
void USART_IrDACmd(USART_TypeDef *USARTx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        USARTx->CTLR3 |= CTLR3_IREN_Set;
    }
    else
    {
        USARTx->CTLR3 &= CTLR3_IREN_Reset;
    }
}

/*********************************************************************
 * @fn      USART_GetFlagStatus
 *
 * @brief   检查指定的USART标志是否置位
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_FLAG - 指定要检查的标志
 *            USART_FLAG_CTS - CTS变化标志
 *            USART_FLAG_LBD - LIN断开检测标志
 *            USART_FLAG_TXE - 发送数据寄存器空标志
 *            USART_FLAG_TC - 发送完成标志
 *            USART_FLAG_RXNE - 接收数据寄存器非空标志
 *            USART_FLAG_IDLE - 空闲线检测标志
 *            USART_FLAG_ORE - 过载错误标志
 *            USART_FLAG_NE - 噪声错误标志
 *            USART_FLAG_FE - 帧错误标志
 *            USART_FLAG_PE - 奇偶校验错误标志
 *
 * @return  FlagStatus - SET或RESET
 */
FlagStatus USART_GetFlagStatus(USART_TypeDef *USARTx, uint16_t USART_FLAG)
{
    FlagStatus bitstatus = RESET;

    if (USART_FLAG == USART_FLAG_CTS)
    {
    }

    if ((USARTx->STATR & USART_FLAG) != (uint16_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
}

/*********************************************************************
 * @fn      USART_ClearFlag
 *
 * @brief   清除USARTx的待处理标志
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_FLAG - 指定要清除的标志
 *            USART_FLAG_CTS - CTS变化标志
 *            USART_FLAG_LBD - LIN断开检测标志
 *            USART_FLAG_TC - 发送完成标志
 *            USART_FLAG_RXNE - 接收数据寄存器非空标志
 *
 * @return  无
 */
void USART_ClearFlag(USART_TypeDef *USARTx, uint16_t USART_FLAG)
{
    if ((USART_FLAG & USART_FLAG_CTS) == USART_FLAG_CTS)
    {
    }

    USARTx->STATR = (uint16_t)~USART_FLAG;
}

/*********************************************************************
 * @fn      USART_GetITStatus
 *
 * @brief   检查指定的USART中断是否发生
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_IT - 指定要检查的USART中断源
 *            USART_IT_CTS - CTS变化中断
 *            USART_IT_LBD - LIN断开检测中断
 *            USART_IT_TXE - 发送数据寄存器空中断
 *            USART_IT_TC - 发送完成中断
 *            USART_IT_RXNE - 接收数据寄存器非空中断
 *            USART_IT_IDLE - 空闲线检测中断
 *            USART_IT_ORE_RX - 如果RXNEIE位设置，则过载错误中断
 *            USART_IT_ORE_ER - 如果EIE位设置，则过载错误中断
 *            USART_IT_NE - 噪声错误中断
 *            USART_IT_FE - 帧错误中断
 *            USART_IT_PE - 奇偶校验错误中断
 *
 * @return  ITStatus - SET或RESET
 */
ITStatus USART_GetITStatus(USART_TypeDef *USARTx, uint16_t USART_IT)
{
    uint32_t bitpos = 0x00, itmask = 0x00, usartreg = 0x00;
    ITStatus bitstatus = RESET;

    if (USART_IT == USART_IT_CTS)
    {
    }

    usartreg = (((uint8_t)USART_IT) >> 0x05);
    itmask = USART_IT & IT_Mask;
    itmask = (uint32_t)0x01 << itmask;

    if (usartreg == 0x01)
    {
        itmask &= USARTx->CTLR1;
    }
    else if (usartreg == 0x02)
    {
        itmask &= USARTx->CTLR2;
    }
    else
    {
        itmask &= USARTx->CTLR3;
    }

    bitpos = USART_IT >> 0x08;
    bitpos = (uint32_t)0x01 << bitpos;
    bitpos &= USARTx->STATR;

    if ((itmask != (uint16_t)RESET) && (bitpos != (uint16_t)RESET))
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    return bitstatus;
}

/*********************************************************************
 * @fn      USART_ClearITPendingBit
 *
 * @brief   清除USARTx的中断待处理位
 *
 * @param   USARTx - 选择USART外设，x可以是1、2或3
 *          USART_IT - 指定要清除的中断待处理位
 *            USART_IT_CTS - CTS变化中断
 *            USART_IT_LBD - LIN断开检测中断
 *            USART_IT_TC - 发送完成中断
 *            USART_IT_RXNE - 接收数据寄存器非空中断
 *
 * @return  无
 */
void USART_ClearITPendingBit(USART_TypeDef *USARTx, uint16_t USART_IT)
{
    uint16_t bitpos = 0x00, itmask = 0x00;

    if (USART_IT == USART_IT_CTS)
    {
    }

    bitpos = USART_IT >> 0x08;
    itmask = ((uint16_t)0x01 << (uint16_t)bitpos);
    USARTx->STATR = (uint16_t)~itmask;
}
