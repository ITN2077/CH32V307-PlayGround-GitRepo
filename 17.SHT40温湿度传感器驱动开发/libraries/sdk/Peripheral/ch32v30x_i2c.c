/********************************** (C) COPYRIGHT  *******************************
 * 文件名          : ch32v30x_i2c.c
 * 作者            : WCH
 * 版本            : V1.0.0
 * 日期            : 2021/06/06
 * 描述            : 本文件提供所有I2C固件功能函数。
 * 版权所有 (c) 2021 南京沁恒微电子股份有限公司。
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/
#include "ch32v30x_i2c.h"
#include "ch32v30x_rcc.h"

/* I2C SPE 掩码（外设使能） */
#define CTLR1_PE_Set ((uint16_t)0x0001)   // 使能I2C外设
#define CTLR1_PE_Reset ((uint16_t)0xFFFE) // 禁用I2C外设

/* I2C START 掩码（起始条件） */
#define CTLR1_START_Set ((uint16_t)0x0100)   // 生成起始条件
#define CTLR1_START_Reset ((uint16_t)0xFEFF) // 取消起始条件

/* I2C STOP 掩码（停止条件） */
#define CTLR1_STOP_Set ((uint16_t)0x0200)   // 生成停止条件
#define CTLR1_STOP_Reset ((uint16_t)0xFDFF) // 取消停止条件

/* I2C ACK 掩码（应答） */
#define CTLR1_ACK_Set ((uint16_t)0x0400)   // 使能应答
#define CTLR1_ACK_Reset ((uint16_t)0xFBFF) // 禁用应答

/* I2C ENGC 掩码（广播呼叫） */
#define CTLR1_ENGC_Set ((uint16_t)0x0040)   // 使能广播呼叫
#define CTLR1_ENGC_Reset ((uint16_t)0xFFBF) // 禁用广播呼叫

/* I2C SWRST 掩码（软件复位） */
#define CTLR1_SWRST_Set ((uint16_t)0x8000)   // 使能软件复位
#define CTLR1_SWRST_Reset ((uint16_t)0x7FFF) // 禁用软件复位

/* I2C PEC 掩码（PEC传输） */
#define CTLR1_PEC_Set ((uint16_t)0x1000)   // 使能PEC传输
#define CTLR1_PEC_Reset ((uint16_t)0xEFFF) // 禁用PEC传输

/* I2C ENPEC 掩码（PEC计算） */
#define CTLR1_ENPEC_Set ((uint16_t)0x0020)   // 使能PEC计算
#define CTLR1_ENPEC_Reset ((uint16_t)0xFFDF) // 禁用PEC计算

/* I2C ENARP 掩码（ARP使能） */
#define CTLR1_ENARP_Set ((uint16_t)0x0010)   // 使能ARP
#define CTLR1_ENARP_Reset ((uint16_t)0xFFEF) // 禁用ARP

/* I2C NOSTRETCH 掩码（禁止时钟延展） */
#define CTLR1_NOSTRETCH_Set ((uint16_t)0x0080)   // 禁止时钟延展
#define CTLR1_NOSTRETCH_Reset ((uint16_t)0xFF7F) // 允许时钟延展

/* I2C 寄存器清除掩码 */
#define CTLR1_CLEAR_Mask ((uint16_t)0xFBF5)

/* I2C DMAEN 掩码（DMA使能） */
#define CTLR2_DMAEN_Set ((uint16_t)0x0800)   // 使能DMA请求
#define CTLR2_DMAEN_Reset ((uint16_t)0xF7FF) // 禁用DMA请求

/* I2C LAST 掩码（DMA最后传输） */
#define CTLR2_LAST_Set ((uint16_t)0x1000)   // 设置为最后一次DMA传输
#define CTLR2_LAST_Reset ((uint16_t)0xEFFF) // 取消最后一次DMA传输

/* I2C FREQ 掩码（外设时钟频率） */
#define CTLR2_FREQ_Reset ((uint16_t)0xFFC0)

/* I2C ADD0 掩码（地址位0） */
#define OADDR1_ADD0_Set ((uint16_t)0x0001)
#define OADDR1_ADD0_Reset ((uint16_t)0xFFFE)

/* I2C ENDUAL 掩码（双地址使能） */
#define OADDR2_ENDUAL_Set ((uint16_t)0x0001)
#define OADDR2_ENDUAL_Reset ((uint16_t)0xFFFE)

/* I2C ADD2 掩码（第二地址） */
#define OADDR2_ADD2_Reset ((uint16_t)0xFF01)

/* I2C F/S 掩码（快速/标准模式） */
#define CKCFGR_FS_Set ((uint16_t)0x8000)

/* I2C CCR 掩码（时钟控制） */
#define CKCFGR_CCR_Set ((uint16_t)0x0FFF)

/* I2C 标志位掩码 */
#define FLAG_Mask ((uint32_t)0x00FFFFFF)

/* I2C 中断使能掩码 */
#define ITEN_Mask ((uint32_t)0x07000000)

/*********************************************************************
 * @fn      I2C_DeInit
 *
 * @brief   将I2Cx外设寄存器反初始化为默认复位值。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *
 * @return  无
 */
void I2C_DeInit(I2C_TypeDef *I2Cx)
{
    if (I2Cx == I2C1)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, DISABLE);
    }
    else
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C2, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C2, DISABLE);
    }
}

/*********************************************************************
 * @fn      I2C_Init
 *
 * @brief   根据I2C_InitStruct中指定的参数初始化I2Cx外设。
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          I2C_InitStruct - 指向I2C_InitTypeDef结构体的指针，包含指定I2C外设的配置信息。
 *
 * @return  无
 */
void I2C_Init(I2C_TypeDef *I2Cx, I2C_InitTypeDef *I2C_InitStruct)
{
    uint16_t tmpreg = 0, freqrange = 0;
    uint16_t result = 0x04;
    uint32_t pclk1 = 8000000;

    RCC_ClocksTypeDef rcc_clocks;

    tmpreg = I2Cx->CTLR2;
    tmpreg &= CTLR2_FREQ_Reset;
    RCC_GetClocksFreq(&rcc_clocks);
    pclk1 = rcc_clocks.PCLK1_Frequency;
    freqrange = (uint16_t)(pclk1 / 1000000);
    tmpreg |= freqrange;
    I2Cx->CTLR2 = tmpreg;

    I2Cx->CTLR1 &= CTLR1_PE_Reset;
    tmpreg = 0;

    if (I2C_InitStruct->I2C_ClockSpeed <= 100000)
    {
        result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed << 1));

        if (result < 0x04)
        {
            result = 0x04;
        }

        tmpreg |= result;
        I2Cx->RTR = freqrange + 1;
    }
    else
    {
        if (I2C_InitStruct->I2C_DutyCycle == I2C_DutyCycle_2)
        {
            result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed * 3));
        }
        else
        {
            result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed * 25));
            result |= I2C_DutyCycle_16_9;
        }

        if ((result & CKCFGR_CCR_Set) == 0)
        {
            result |= (uint16_t)0x0001;
        }

        tmpreg |= (uint16_t)(result | CKCFGR_FS_Set);
        I2Cx->RTR = (uint16_t)(((freqrange * (uint16_t)300) / (uint16_t)1000) + (uint16_t)1);
    }

    I2Cx->CKCFGR = tmpreg;
    I2Cx->CTLR1 |= CTLR1_PE_Set;

    tmpreg = I2Cx->CTLR1;
    tmpreg &= CTLR1_CLEAR_Mask;
    tmpreg |= (uint16_t)((uint32_t)I2C_InitStruct->I2C_Mode | I2C_InitStruct->I2C_Ack);
    I2Cx->CTLR1 = tmpreg;

    I2Cx->OADDR1 = (I2C_InitStruct->I2C_AcknowledgedAddress | I2C_InitStruct->I2C_OwnAddress1);
}

/*********************************************************************
 * @fn      I2C_StructInit
 *
 * @brief   用默认值填充I2C_InitStruct的每个成员。
 *
 * @param   I2C_InitStruct - 指向将被初始化的I2C_InitTypeDef结构体的指针。
 *
 * @return  无
 */
void I2C_StructInit(I2C_InitTypeDef *I2C_InitStruct)
{
    I2C_InitStruct->I2C_ClockSpeed = 5000;
    I2C_InitStruct->I2C_Mode = I2C_Mode_I2C;
    I2C_InitStruct->I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStruct->I2C_OwnAddress1 = 0;
    I2C_InitStruct->I2C_Ack = I2C_Ack_Disable;
    I2C_InitStruct->I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
}

/*********************************************************************
 * @fn      I2C_Cmd
 *
 * @brief   使能或禁用指定的I2C外设。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_Cmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR1 |= CTLR1_PE_Set;
    }
    else
    {
        I2Cx->CTLR1 &= CTLR1_PE_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_DMACmd
 *
 * @brief   使能或禁用指定的I2C DMA请求。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_DMACmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR2 |= CTLR2_DMAEN_Set;
    }
    else
    {
        I2Cx->CTLR2 &= CTLR2_DMAEN_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_DMALastTransferCmd
 *
 * @brief   指定下一个DMA传输是否为最后一次。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_DMALastTransferCmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR2 |= CTLR2_LAST_Set;
    }
    else
    {
        I2Cx->CTLR2 &= CTLR2_LAST_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_GenerateSTART
 *
 * @brief   生成I2Cx通信起始条件。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_GenerateSTART(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR1 |= CTLR1_START_Set;
    }
    else
    {
        I2Cx->CTLR1 &= CTLR1_START_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_GenerateSTOP
 *
 * @brief   生成I2Cx通信停止条件。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_GenerateSTOP(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR1 |= CTLR1_STOP_Set;
    }
    else
    {
        I2Cx->CTLR1 &= CTLR1_STOP_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_AcknowledgeConfig
 *
 * @brief   使能或禁用指定的I2C应答功能。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_AcknowledgeConfig(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR1 |= CTLR1_ACK_Set;
    }
    else
    {
        I2Cx->CTLR1 &= CTLR1_ACK_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_OwnAddress2Config
 *
 * @brief   配置指定的I2C自身地址2。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          Address - 指定7位I2C自身地址2。
 *
 * @return  无
 */
void I2C_OwnAddress2Config(I2C_TypeDef *I2Cx, uint8_t Address)
{
    uint16_t tmpreg = 0;

    tmpreg = I2Cx->OADDR2;
    tmpreg &= OADDR2_ADD2_Reset;
    tmpreg |= (uint16_t)((uint16_t)Address & (uint16_t)0x00FE);
    I2Cx->OADDR2 = tmpreg;
}

/*********************************************************************
 * @fn      I2C_DualAddressCmd
 *
 * @brief   使能或禁用指定的I2C双地址模式。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_DualAddressCmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->OADDR2 |= OADDR2_ENDUAL_Set;
    }
    else
    {
        I2Cx->OADDR2 &= OADDR2_ENDUAL_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_GeneralCallCmd
 *
 * @brief   使能或禁用指定的I2C广播呼叫功能。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_GeneralCallCmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR1 |= CTLR1_ENGC_Set;
    }
    else
    {
        I2Cx->CTLR1 &= CTLR1_ENGC_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_ITConfig
 *
 * @brief   使能或禁用指定的I2C中断。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          I2C_IT - 指定要使能或禁用的I2C中断源。
 *            I2C_IT_BUF - 缓冲区中断掩码。
 *            I2C_IT_EVT - 事件中断掩码。
 *            I2C_IT_ERR - 错误中断掩码。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_ITConfig(I2C_TypeDef *I2Cx, uint16_t I2C_IT, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR2 |= I2C_IT;
    }
    else
    {
        I2Cx->CTLR2 &= (uint16_t)~I2C_IT;
    }
}

/*********************************************************************
 * @fn      I2C_SendData
 *
 * @brief   通过I2Cx外设发送一个数据字节。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          Data - 要发送的字节。
 *
 * @return  无
 */
void I2C_SendData(I2C_TypeDef *I2Cx, uint8_t Data)
{
    I2Cx->DATAR = Data;
}

/*********************************************************************
 * @fn      I2C_ReceiveData
 *
 * @brief   返回I2Cx外设最近接收到的数据。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *
 * @return  接收到的数据值。
 */
uint8_t I2C_ReceiveData(I2C_TypeDef *I2Cx)
{
    return (uint8_t)I2Cx->DATAR;
}

/*********************************************************************
 * @fn      I2C_Send7bitAddress
 *
 * @brief   发送地址字节以选择从设备。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          Address - 指定要发送的从设备地址。
 *          I2C_Direction - 指定I2C设备是发送器还是接收器。
 *            I2C_Direction_Transmitter - 发送器模式。
 *            I2C_Direction_Receiver - 接收器模式。
 *
 * @return  无
 */
void I2C_Send7bitAddress(I2C_TypeDef *I2Cx, uint8_t Address, uint8_t I2C_Direction)
{
    if (I2C_Direction != I2C_Direction_Transmitter)
    {
        Address |= OADDR1_ADD0_Set;
    }
    else
    {
        Address &= OADDR1_ADD0_Reset;
    }

    I2Cx->DATAR = Address;
}

/*********************************************************************
 * @fn      I2C_ReadRegister
 *
 * @brief   读取指定的I2C寄存器并返回其值。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          I2C_Register - 指定要读取的寄存器。
 *            I2C_Register_CTLR1.
 *            I2C_Register_CTLR2.
 *            I2C_Register_OADDR1.
 *            I2C_Register_OADDR2.
 *            I2C_Register_DATAR.
 *            I2C_Register_STAR1.
 *            I2C_Register_STAR2.
 *            I2C_Register_CKCFGR.
 *            I2C_Register_RTR.
 *
 * @return  无
 */
uint16_t I2C_ReadRegister(I2C_TypeDef *I2Cx, uint8_t I2C_Register)
{
    __IO uint32_t tmp = 0;

    tmp = (uint32_t)I2Cx;
    tmp += I2C_Register;

    return (*(__IO uint16_t *)tmp);
}

/*********************************************************************
 * @fn      I2C_SoftwareResetCmd
 *
 * @brief   使能或禁用指定的I2C软件复位。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_SoftwareResetCmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR1 |= CTLR1_SWRST_Set;
    }
    else
    {
        I2Cx->CTLR1 &= CTLR1_SWRST_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_NACKPositionConfig
 *
 * @brief   在主接收器模式下选择指定的I2C NACK位置。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          I2C_NACKPosition - 指定NACK位置。
 *            I2C_NACKPosition_Next - 表示下一个字节将是最后接收的字节。
 *            I2C_NACKPosition_Current - 表示当前字节是最后接收的字节。
 *
 * @return  无
 */
void I2C_NACKPositionConfig(I2C_TypeDef *I2Cx, uint16_t I2C_NACKPosition)
{
    if (I2C_NACKPosition == I2C_NACKPosition_Next)
    {
        I2Cx->CTLR1 |= I2C_NACKPosition_Next;
    }
    else
    {
        I2Cx->CTLR1 &= I2C_NACKPosition_Current;
    }
}

/*********************************************************************
 * @fn      I2C_SMBusAlertConfig
 *
 * @brief   为指定的I2C驱动SMBusAlert引脚为高电平或低电平。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          I2C_SMBusAlert - 指定SMBAlert引脚电平。
 *            I2C_SMBusAlert_Low - SMBAlert引脚驱动为低电平。
 *            I2C_SMBusAlert_High - SMBAlert引脚驱动为高电平。
 *
 * @return  无
 */
void I2C_SMBusAlertConfig(I2C_TypeDef *I2Cx, uint16_t I2C_SMBusAlert)
{
    if (I2C_SMBusAlert == I2C_SMBusAlert_Low)
    {
        I2Cx->CTLR1 |= I2C_SMBusAlert_Low;
    }
    else
    {
        I2Cx->CTLR1 &= I2C_SMBusAlert_High;
    }
}

/*********************************************************************
 * @fn      I2C_TransmitPEC
 *
 * @brief   使能或禁用指定的I2C PEC传输。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_TransmitPEC(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR1 |= CTLR1_PEC_Set;
    }
    else
    {
        I2Cx->CTLR1 &= CTLR1_PEC_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_PECPositionConfig
 *
 * @brief   选择指定的I2C PEC位置。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          I2C_PECPosition - 指定PEC位置。
 *            I2C_PECPosition_Next - 表示下一个字节是PEC。
 *            I2C_PECPosition_Current - 表示当前字节是PEC。
 *
 * @return  无
 */
void I2C_PECPositionConfig(I2C_TypeDef *I2Cx, uint16_t I2C_PECPosition)
{
    if (I2C_PECPosition == I2C_PECPosition_Next)
    {
        I2Cx->CTLR1 |= I2C_PECPosition_Next;
    }
    else
    {
        I2Cx->CTLR1 &= I2C_PECPosition_Current;
    }
}

/*********************************************************************
 * @fn      I2C_CalculatePEC
 *
 * @brief   使能或禁用传输字节的PEC值计算。
 *
 * @param   I2Cx- x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_CalculatePEC(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR1 |= CTLR1_ENPEC_Set;
    }
    else
    {
        I2Cx->CTLR1 &= CTLR1_ENPEC_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_GetPEC
 *
 * @brief   返回指定I2C的PEC值。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *
 * @return  PEC值。
 */
uint8_t I2C_GetPEC(I2C_TypeDef *I2Cx)
{
    return ((I2Cx->STAR2) >> 8);
}

/*********************************************************************
 * @fn      I2C_ARPCmd
 *
 * @brief   使能或禁用指定的I2C ARP。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_ARPCmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->CTLR1 |= CTLR1_ENARP_Set;
    }
    else
    {
        I2Cx->CTLR1 &= CTLR1_ENARP_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_StretchClockCmd
 *
 * @brief   使能或禁用指定的I2C时钟延展。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          NewState - ENABLE或DISABLE。
 *
 * @return  无
 */
void I2C_StretchClockCmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    if (NewState == DISABLE)
    {
        I2Cx->CTLR1 |= CTLR1_NOSTRETCH_Set;
    }
    else
    {
        I2Cx->CTLR1 &= CTLR1_NOSTRETCH_Reset;
    }
}

/*********************************************************************
 * @fn      I2C_FastModeDutyCycleConfig
 *
 * @brief   选择指定的I2C快速模式占空比。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          I2C_DutyCycle - 指定快速模式占空比。
 *            I2C_DutyCycle_2 - I2C快速模式Tlow/Thigh = 2。
 *            I2C_DutyCycle_16_9 - I2C快速模式Tlow/Thigh = 16/9。
 *
 * @return  无
 */
void I2C_FastModeDutyCycleConfig(I2C_TypeDef *I2Cx, uint16_t I2C_DutyCycle)
{
    if (I2C_DutyCycle != I2C_DutyCycle_16_9)
    {
        I2Cx->CKCFGR &= I2C_DutyCycle_2;
    }
    else
    {
        I2Cx->CKCFGR |= I2C_DutyCycle_16_9;
    }
}

/*********************************************************************
 * @fn      I2C_CheckEvent
 *
 * @brief   检查最后一个I2Cx事件是否等于传入的事件参数。
 *
 * @param   I2Cx- x可以为1或2，用于选择I2C外设。
 *          I2C_EVENT: 指定要检查的事件。
 *             I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED - EV1。
 *             I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED - EV1。
 *             I2C_EVENT_SLAVE_TRANSMITTER_SECONDADDRESS_MATCHED - EV1。
 *             I2C_EVENT_SLAVE_RECEIVER_SECONDADDRESS_MATCHED - EV1。
 *             I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED - EV1。
 *             I2C_EVENT_SLAVE_BYTE_RECEIVED - EV2。
 *             (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_DUALF) - EV2。
 *             (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_GENCALL) - EV2。
 *             I2C_EVENT_SLAVE_BYTE_TRANSMITTED - EV3。
 *             (I2C_EVENT_SLAVE_BYTE_TRANSMITTED | I2C_FLAG_DUALF) - EV3。
 *             (I2C_EVENT_SLAVE_BYTE_TRANSMITTED | I2C_FLAG_GENCALL) - EV3。
 *             I2C_EVENT_SLAVE_ACK_FAILURE - EV3_2。
 *             I2C_EVENT_SLAVE_STOP_DETECTED - EV4。
 *             I2C_EVENT_MASTER_MODE_SELECT - EV5。
 *             I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED - EV6。
 *             I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED - EV6。
 *             I2C_EVENT_MASTER_BYTE_RECEIVED - EV7。
 *             I2C_EVENT_MASTER_BYTE_TRANSMITTING - EV8。
 *             I2C_EVENT_MASTER_BYTE_TRANSMITTED - EV8_2。
 *             I2C_EVENT_MASTER_MODE_ADDRESS10 - EV9。
 *
 * @return  无
 */
ErrorStatus I2C_CheckEvent(I2C_TypeDef *I2Cx, uint32_t I2C_EVENT)
{
    uint32_t lastevent = 0;
    uint32_t flag1 = 0, flag2 = 0;
    ErrorStatus status = ERROR;

    flag1 = I2Cx->STAR1;
    flag2 = I2Cx->STAR2;
    flag2 = flag2 << 16;

    lastevent = (flag1 | flag2) & FLAG_Mask;

    if ((lastevent & I2C_EVENT) == I2C_EVENT)
    {
        status = SUCCESS;
    }
    else
    {
        status = ERROR;
    }

    return status;
}

/*********************************************************************
 * @fn      I2C_GetLastEvent
 *
 * @brief   返回最后一个I2Cx事件。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *
 * @return  无
 */
uint32_t I2C_GetLastEvent(I2C_TypeDef *I2Cx)
{
    uint32_t lastevent = 0;
    uint32_t flag1 = 0, flag2 = 0;

    flag1 = I2Cx->STAR1;
    flag2 = I2Cx->STAR2;
    flag2 = flag2 << 16;
    lastevent = (flag1 | flag2) & FLAG_Mask;

    return lastevent;
}

/*********************************************************************
 * @fn      I2C_GetFlagStatus
 *
 * @brief   检查最后一个I2Cx事件是否等于传入的参数。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          I2C_FLAG - 指定要检查的标志位。
 *            I2C_FLAG_DUALF - 双地址标志（从模式）。
 *            I2C_FLAG_SMBHOST - SMBus主机头（从模式）。
 *            I2C_FLAG_SMBDEFAULT - SMBus默认头（从模式）。
 *            I2C_FLAG_GENCALL - 广播呼叫头标志（从模式）。
 *            I2C_FLAG_TRA - 发送/接收标志。
 *            I2C_FLAG_BUSY - 总线忙标志。
 *            I2C_FLAG_MSL - 主/从标志。
 *            I2C_FLAG_SMBALERT - SMBus警报标志。
 *            I2C_FLAG_TIMEOUT - 超时或Tlow错误标志。
 *            I2C_FLAG_PECERR - 接收时PEC错误标志。
 *            I2C_FLAG_OVR - 溢出/下溢标志（从模式）。
 *            I2C_FLAG_AF - 应答失败标志。
 *            I2C_FLAG_ARLO - 仲裁丢失标志（主模式）。
 *            I2C_FLAG_BERR - 总线错误标志。
 *            I2C_FLAG_TXE - 数据寄存器空标志（发送器）。
 *            I2C_FLAG_RXNE- 数据寄存器非空（接收器）标志。
 *            I2C_FLAG_STOPF - 停止检测标志（从模式）。
 *            I2C_FLAG_ADD10 - 10位头已发送标志（主模式）。
 *            I2C_FLAG_BTF - 字节传输完成标志。
 *            I2C_FLAG_ADDR - 地址已发送标志（主模式）"ADSL"，地址匹配标志（从模式）"ENDA"。
 *            I2C_FLAG_SB - 起始位标志（主模式）。
 *
 * @return  无
 */
FlagStatus I2C_GetFlagStatus(I2C_TypeDef *I2Cx, uint32_t I2C_FLAG)
{
    FlagStatus bitstatus = RESET;
    __IO uint32_t i2creg = 0, i2cxbase = 0;

    i2cxbase = (uint32_t)I2Cx;
    i2creg = I2C_FLAG >> 28;
    I2C_FLAG &= FLAG_Mask;

    if (i2creg != 0)
    {
        i2cxbase += 0x14;
    }
    else
    {
        I2C_FLAG = (uint32_t)(I2C_FLAG >> 16);
        i2cxbase += 0x18;
    }

    if (((*(__IO uint32_t *)i2cxbase) & I2C_FLAG) != (uint32_t)RESET)
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
 * @fn      I2C_ClearFlag
 *
 * @brief   清除I2Cx的待处理标志位。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          I2C_FLAG - 指定要清除的标志位。
 *            I2C_FLAG_SMBALERT - SMBus警报标志。
 *            I2C_FLAG_TIMEOUT - 超时或Tlow错误标志。
 *            I2C_FLAG_PECERR - 接收时PEC错误标志。
 *            I2C_FLAG_OVR - 溢出/下溢标志（从模式）。
 *            I2C_FLAG_AF - 应答失败标志。
 *            I2C_FLAG_ARLO - 仲裁丢失标志（主模式）。
 *            I2C_FLAG_BERR - 总线错误标志。
 *
 * @return  无
 */
void I2C_ClearFlag(I2C_TypeDef *I2Cx, uint32_t I2C_FLAG)
{
    uint32_t flagpos = 0;

    flagpos = I2C_FLAG & FLAG_Mask;
    I2Cx->STAR1 = (uint16_t)~flagpos;
}

/*********************************************************************
 * @fn      I2C_GetITStatus
 *
 * @brief   检查指定的I2C中断是否发生。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          II2C_IT - 指定要检查的中断源。
 *            I2C_IT_SMBALERT - SMBus警报标志。
 *            I2C_IT_TIMEOUT - 超时或Tlow错误标志。
 *            I2C_IT_PECERR - 接收时PEC错误标志。
 *            I2C_IT_OVR - 溢出/下溢标志（从模式）。
 *            I2C_IT_AF - 应答失败标志。
 *            I2C_IT_ARLO - 仲裁丢失标志（主模式）。
 *            I2C_IT_BERR - 总线错误标志。
 *            I2C_IT_TXE - 数据寄存器空标志（发送器）。
 *            I2C_IT_RXNE - 数据寄存器非空（接收器）标志。
 *            I2C_IT_STOPF - 停止检测标志（从模式）。
 *            I2C_IT_ADD10 - 10位头已发送标志（主模式）。
 *            I2C_IT_BTF - 字节传输完成标志。
 *            I2C_IT_ADDR - 地址已发送标志（主模式）"ADSL"，地址匹配标志（从模式）"ENDAD"。
 *            I2C_IT_SB - 起始位标志（主模式）。
 *
 * @return  无
 */
ITStatus I2C_GetITStatus(I2C_TypeDef *I2Cx, uint32_t I2C_IT)
{
    ITStatus bitstatus = RESET;
    uint32_t enablestatus = 0;

    enablestatus = (uint32_t)(((I2C_IT & ITEN_Mask) >> 16) & (I2Cx->CTLR2));
    I2C_IT &= FLAG_Mask;

    if (((I2Cx->STAR1 & I2C_IT) != (uint32_t)RESET) && enablestatus)
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
 * @fn      I2C_ClearITPendingBit
 *
 * @brief   清除I2Cx中断挂起位。
 *
 * @param   I2Cx - x可以为1或2，用于选择I2C外设。
 *          I2C_IT - 指定要清除的中断挂起位。
 *            I2C_IT_SMBALERT - SMBus警报中断。
 *            I2C_IT_TIMEOUT - 超时或Tlow错误中断。
 *            I2C_IT_PECERR - 接收时PEC错误中断。
 *            I2C_IT_OVR - 溢出/下溢中断（从模式）。
 *            I2C_IT_AF - 应答失败中断。
 *            I2C_IT_ARLO - 仲裁丢失中断（主模式）。
 *            I2C_IT_BERR - 总线错误中断。
 *
 * @return  无
 */
void I2C_ClearITPendingBit(I2C_TypeDef *I2Cx, uint32_t I2C_IT)
{
    uint32_t flagpos = 0;

    flagpos = I2C_IT & FLAG_Mask;
    I2Cx->STAR1 = (uint16_t)~flagpos;
}
