/********************************** (C) COPYRIGHT  *******************************
 * File Name          : ch32v30x_dma.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : CH32V30x系列单片机的DMA驱动文件
 *                     本文件提供了DMA外设的所有固件函数
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/
#include "ch32v30x_dma.h"
#include "ch32v30x_rcc.h"

/* DMA1通道中断标志位掩码定义 */
#define DMA1_Channel1_IT_Mask ((uint32_t)(DMA_GIF1 | DMA_TCIF1 | DMA_HTIF1 | DMA_TEIF1))
#define DMA1_Channel2_IT_Mask ((uint32_t)(DMA_GIF2 | DMA_TCIF2 | DMA_HTIF2 | DMA_TEIF2))
#define DMA1_Channel3_IT_Mask ((uint32_t)(DMA_GIF3 | DMA_TCIF3 | DMA_HTIF3 | DMA_TEIF3))
#define DMA1_Channel4_IT_Mask ((uint32_t)(DMA_GIF4 | DMA_TCIF4 | DMA_HTIF4 | DMA_TEIF4))
#define DMA1_Channel5_IT_Mask ((uint32_t)(DMA_GIF5 | DMA_TCIF5 | DMA_HTIF5 | DMA_TEIF5))
#define DMA1_Channel6_IT_Mask ((uint32_t)(DMA_GIF6 | DMA_TCIF6 | DMA_HTIF6 | DMA_TEIF6))
#define DMA1_Channel7_IT_Mask ((uint32_t)(DMA_GIF7 | DMA_TCIF7 | DMA_HTIF7 | DMA_TEIF7))

/* DMA2通道中断标志位掩码定义 */
#define DMA2_Channel1_IT_Mask ((uint32_t)(DMA_GIF1 | DMA_TCIF1 | DMA_HTIF1 | DMA_TEIF1))
#define DMA2_Channel2_IT_Mask ((uint32_t)(DMA_GIF2 | DMA_TCIF2 | DMA_HTIF2 | DMA_TEIF2))
#define DMA2_Channel3_IT_Mask ((uint32_t)(DMA_GIF3 | DMA_TCIF3 | DMA_HTIF3 | DMA_TEIF3))
#define DMA2_Channel4_IT_Mask ((uint32_t)(DMA_GIF4 | DMA_TCIF4 | DMA_HTIF4 | DMA_TEIF4))
#define DMA2_Channel5_IT_Mask ((uint32_t)(DMA_GIF5 | DMA_TCIF5 | DMA_HTIF5 | DMA_TEIF5))
#define DMA2_Channel6_IT_Mask ((uint32_t)(DMA_GIF6 | DMA_TCIF6 | DMA_HTIF6 | DMA_TEIF6))
#define DMA2_Channel7_IT_Mask ((uint32_t)(DMA_GIF7 | DMA_TCIF7 | DMA_HTIF7 | DMA_TEIF7))
#define DMA2_Channel8_IT_Mask ((uint32_t)(DMA_GIF8 | DMA_TCIF8 | DMA_HTIF8 | DMA_TEIF8))
#define DMA2_Channel9_IT_Mask ((uint32_t)(DMA_GIF9 | DMA_TCIF9 | DMA_HTIF9 | DMA_TEIF9))
#define DMA2_Channel10_IT_Mask ((uint32_t)(DMA_GIF10 | DMA_TCIF10 | DMA_HTIF10 | DMA_TEIF10))
#define DMA2_Channel11_IT_Mask ((uint32_t)(DMA_GIF11 | DMA_TCIF11 | DMA_HTIF11 | DMA_TEIF11))

/* DMA2标志位掩码定义 */
#define FLAG_Mask ((uint32_t)0x10000000)
#define DMA2_EXTEN_FLAG_Mask ((uint32_t)0x20000000)

/* DMA配置寄存器清除掩码 */
#define CFGR_CLEAR_Mask ((uint32_t)0xFFFF800F)

/*********************************************************************
 * @fn      DMA_DeInit
 *
 * @brief   将DMA通道寄存器恢复到默认复位值
 *
 * @param   DMAy_Channelx - 选择DMA通道
 *          y可以是1或2来选择DMA1或DMA2
 *          x可以是1-7(DMA1)或1-11(DMA2)来选择具体的通道
 *
 * @return  无
 *
 * @note    使用示例:
 *          DMA_DeInit(DMA1_Channel1);  // 复位DMA1通道1
 */
void DMA_DeInit(DMA_Channel_TypeDef *DMAy_Channelx)
{
    DMAy_Channelx->CFGR &= (uint16_t)(~DMA_CFGR1_EN);
    DMAy_Channelx->CFGR = 0;
    DMAy_Channelx->CNTR = 0;
    DMAy_Channelx->PADDR = 0;
    DMAy_Channelx->MADDR = 0;
    if (DMAy_Channelx == DMA1_Channel1)
    {
        DMA1->INTFCR |= DMA1_Channel1_IT_Mask;
    }
    else if (DMAy_Channelx == DMA1_Channel2)
    {
        DMA1->INTFCR |= DMA1_Channel2_IT_Mask;
    }
    else if (DMAy_Channelx == DMA1_Channel3)
    {
        DMA1->INTFCR |= DMA1_Channel3_IT_Mask;
    }
    else if (DMAy_Channelx == DMA1_Channel4)
    {
        DMA1->INTFCR |= DMA1_Channel4_IT_Mask;
    }
    else if (DMAy_Channelx == DMA1_Channel5)
    {
        DMA1->INTFCR |= DMA1_Channel5_IT_Mask;
    }
    else if (DMAy_Channelx == DMA1_Channel6)
    {
        DMA1->INTFCR |= DMA1_Channel6_IT_Mask;
    }
    else if (DMAy_Channelx == DMA1_Channel7)
    {
        DMA1->INTFCR |= DMA1_Channel7_IT_Mask;
    }
    else if (DMAy_Channelx == DMA2_Channel1)
    {
        DMA2->INTFCR |= DMA2_Channel1_IT_Mask;
    }
    else if (DMAy_Channelx == DMA2_Channel2)
    {
        DMA2->INTFCR |= DMA2_Channel2_IT_Mask;
    }
    else if (DMAy_Channelx == DMA2_Channel3)
    {
        DMA2->INTFCR |= DMA2_Channel3_IT_Mask;
    }
    else if (DMAy_Channelx == DMA2_Channel4)
    {
        DMA2->INTFCR |= DMA2_Channel4_IT_Mask;
    }
    else if (DMAy_Channelx == DMA2_Channel5)
    {
        DMA2->INTFCR |= DMA2_Channel5_IT_Mask;
    }
    else if (DMAy_Channelx == DMA2_Channel6)
    {
        DMA2->INTFCR |= DMA2_Channel6_IT_Mask;
    }
    else if (DMAy_Channelx == DMA2_Channel7)
    {
        DMA2->INTFCR |= DMA2_Channel7_IT_Mask;
    }
    else if (DMAy_Channelx == DMA2_Channel8)
    {
        DMA2_EXTEN->INTFCR |= DMA2_Channel8_IT_Mask;
    }
    else if (DMAy_Channelx == DMA2_Channel9)
    {
        DMA2_EXTEN->INTFCR |= DMA2_Channel9_IT_Mask;
    }
    else if (DMAy_Channelx == DMA2_Channel10)
    {
        DMA2_EXTEN->INTFCR |= DMA2_Channel10_IT_Mask;
    }
    else if (DMAy_Channelx == DMA2_Channel11)
    {
        DMA2_EXTEN->INTFCR |= DMA2_Channel11_IT_Mask;
    }
}

/*********************************************************************
 * @fn      DMA_Init
 *
 * @brief   根据DMA_InitStruct中指定的参数初始化DMA通道
 *
 * @param   DMAy_Channelx - 选择DMA通道
 *          y可以是1或2来选择DMA1或DMA2
 *          x可以是1-7(DMA1)或1-11(DMA2)来选择具体的通道
 *          DMA_InitStruct - 指向DMA_InitTypeDef结构体的指针,包含DMA通道的配置信息
 *
 * @return  无
 *
 * @note    使用示例:
 *          DMA_InitTypeDef DMA_InitStructure;
 *          DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
 *          DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&ADC_ConvertedValue;
 *          DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
 *          DMA_InitStructure.DMA_BufferSize = 1;
 *          DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
 *          DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
 *          DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
 *          DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
 *          DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
 *          DMA_InitStructure.DMA_Priority = DMA_Priority_High;
 *          DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
 *          DMA_Init(DMA1_Channel1, &DMA_InitStructure);
 */
void DMA_Init(DMA_Channel_TypeDef *DMAy_Channelx, DMA_InitTypeDef *DMA_InitStruct)
{
    uint32_t tmpreg = 0;

    tmpreg = DMAy_Channelx->CFGR;
    tmpreg &= CFGR_CLEAR_Mask;
    tmpreg |= DMA_InitStruct->DMA_DIR | DMA_InitStruct->DMA_Mode |
              DMA_InitStruct->DMA_PeripheralInc | DMA_InitStruct->DMA_MemoryInc |
              DMA_InitStruct->DMA_PeripheralDataSize | DMA_InitStruct->DMA_MemoryDataSize |
              DMA_InitStruct->DMA_Priority | DMA_InitStruct->DMA_M2M;

    DMAy_Channelx->CFGR = tmpreg;
    DMAy_Channelx->CNTR = DMA_InitStruct->DMA_BufferSize;
    DMAy_Channelx->PADDR = DMA_InitStruct->DMA_PeripheralBaseAddr;
    DMAy_Channelx->MADDR = DMA_InitStruct->DMA_MemoryBaseAddr;
}

/*********************************************************************
 * @fn      DMA_StructInit
 *
 * @brief   将DMA_InitStruct结构体成员设置为默认值
 *
 * @param   DMA_InitStruct - 指向DMA_InitTypeDef结构体的指针
 *
 * @return  无
 *
 * @note    使用示例:
 *          DMA_InitTypeDef DMA_InitStructure;
 *          DMA_StructInit(&DMA_InitStructure);
 */
void DMA_StructInit(DMA_InitTypeDef *DMA_InitStruct)
{
    DMA_InitStruct->DMA_PeripheralBaseAddr = 0;
    DMA_InitStruct->DMA_MemoryBaseAddr = 0;
    DMA_InitStruct->DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStruct->DMA_BufferSize = 0;
    DMA_InitStruct->DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStruct->DMA_MemoryInc = DMA_MemoryInc_Disable;
    DMA_InitStruct->DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStruct->DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStruct->DMA_Mode = DMA_Mode_Normal;
    DMA_InitStruct->DMA_Priority = DMA_Priority_Low;
    DMA_InitStruct->DMA_M2M = DMA_M2M_Disable;
}

/*********************************************************************
 * @fn      DMA_Cmd
 *
 * @brief   使能或禁用指定的DMA通道
 *
 * @param   DMAy_Channelx - 选择DMA通道
 *          y可以是1或2来选择DMA1或DMA2
 *          x可以是1-7(DMA1)或1-11(DMA2)来选择具体的通道
 *          NewState - DMA通道的新状态(ENABLE或DISABLE)
 *
 * @return  无
 *
 * @note    使用示例:
 *          DMA_Cmd(DMA1_Channel1, ENABLE);  // 使能DMA1通道1
 */
void DMA_Cmd(DMA_Channel_TypeDef *DMAy_Channelx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        DMAy_Channelx->CFGR |= DMA_CFGR1_EN;
    }
    else
    {
        DMAy_Channelx->CFGR &= (uint16_t)(~DMA_CFGR1_EN);
    }
}

/*********************************************************************
 * @fn      DMA_ITConfig
 *
 * @brief   使能或禁用指定的DMA通道中断
 *
 * @param   DMAy_Channelx - 选择DMA通道
 *          y可以是1或2来选择DMA1或DMA2
 *          x可以是1-7(DMA1)或1-11(DMA2)来选择具体的通道
 *          DMA_IT - 指定要配置的DMA中断源
 *            DMA_IT_TC - 传输完成中断
 *            DMA_IT_HT - 半传输中断
 *            DMA_IT_TE - 传输错误中断
 *          NewState - 中断的新状态(ENABLE或DISABLE)
 *
 * @return  无
 *
 * @note    使用示例:
 *          DMA_ITConfig(DMA1_Channel1, DMA_IT_TC, ENABLE);  // 使能DMA1通道1的传输完成中断
 */
void DMA_ITConfig(DMA_Channel_TypeDef *DMAy_Channelx, uint32_t DMA_IT, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        DMAy_Channelx->CFGR |= DMA_IT;
    }
    else
    {
        DMAy_Channelx->CFGR &= ~DMA_IT;
    }
}

/*********************************************************************
 * @fn      DMA_SetCurrDataCounter
 *
 * @brief   设置当前DMA通道传输的数据单元数量
 *
 * @param   DMAy_Channelx - 选择DMA通道
 *          y可以是1或2来选择DMA1或DMA2
 *          x可以是1-7(DMA1)或1-11(DMA2)来选择具体的通道
 *          DataNumber - 当前DMA通道传输的数据单元数量
 *
 * @return  无
 *
 * @note    使用示例:
 *          DMA_SetCurrDataCounter(DMA1_Channel1, 100);  // 设置DMA1通道1传输100个数据单元
 */
void DMA_SetCurrDataCounter(DMA_Channel_TypeDef *DMAy_Channelx, uint16_t DataNumber)
{
    DMAy_Channelx->CNTR = DataNumber;
}

/*********************************************************************
 * @fn      DMA_GetCurrDataCounter
 *
 * @brief   获取当前DMA通道剩余的数据单元数量
 *
 * @param   DMAy_Channelx - 选择DMA通道
 *          y可以是1或2来选择DMA1或DMA2
 *          x可以是1-7(DMA1)或1-11(DMA2)来选择具体的通道
 *
 * @return  当前DMA通道剩余的数据单元数量
 *
 * @note    使用示例:
 *          uint16_t remaining = DMA_GetCurrDataCounter(DMA1_Channel1);
 */
uint16_t DMA_GetCurrDataCounter(DMA_Channel_TypeDef *DMAy_Channelx)
{
    return ((uint16_t)(DMAy_Channelx->CNTR));
}

/*********************************************************************
 * @fn      DMA_GetFlagStatus
 *
 * @brief   检查指定的DMA通道标志位是否置位
 *
 * @param   DMAy_FLAG - specifies the flag to check.
 *            DMA1_FLAG_GL1 - DMA1 Channel1 global flag.
 *            DMA1_FLAG_TC1 - DMA1 Channel1 transfer complete flag.
 *            DMA1_FLAG_HT1 - DMA1 Channel1 half transfer flag.
 *            DMA1_FLAG_TE1 - DMA1 Channel1 transfer error flag.
 *            DMA1_FLAG_GL2 - DMA1 Channel2 global flag.
 *            DMA1_FLAG_TC2 - DMA1 Channel2 transfer complete flag.
 *            DMA1_FLAG_HT2 - DMA1 Channel2 half transfer flag.
 *            DMA1_FLAG_TE2 - DMA1 Channel2 transfer error flag.
 *            DMA1_FLAG_GL3 - DMA1 Channel3 global flag.
 *            DMA1_FLAG_TC3 - DMA1 Channel3 transfer complete flag.
 *            DMA1_FLAG_HT3 - DMA1 Channel3 half transfer flag.
 *            DMA1_FLAG_TE3 - DMA1 Channel3 transfer error flag.
 *            DMA1_FLAG_GL4 - DMA1 Channel4 global flag.
 *            DMA1_FLAG_TC4 - DMA1 Channel4 transfer complete flag.
 *            DMA1_FLAG_HT4 - DMA1 Channel4 half transfer flag.
 *            DMA1_FLAG_TE4 - DMA1 Channel4 transfer error flag.
 *            DMA1_FLAG_GL5 - DMA1 Channel5 global flag.
 *            DMA1_FLAG_TC5 - DMA1 Channel5 transfer complete flag.
 *            DMA1_FLAG_HT5 - DMA1 Channel5 half transfer flag.
 *            DMA1_FLAG_TE5 - DMA1 Channel5 transfer error flag.
 *            DMA1_FLAG_GL6 - DMA1 Channel6 global flag.
 *            DMA1_FLAG_TC6 - DMA1 Channel6 transfer complete flag.
 *            DMA1_FLAG_HT6 - DMA1 Channel6 half transfer flag.
 *            DMA1_FLAG_TE6 - DMA1 Channel6 transfer error flag.
 *            DMA1_FLAG_GL7 - DMA1 Channel7 global flag.
 *            DMA1_FLAG_TC7 - DMA1 Channel7 transfer complete flag.
 *            DMA1_FLAG_HT7 - DMA1 Channel7 half transfer flag.
 *            DMA1_FLAG_TE7 - DMA1 Channel7 transfer error flag.
 *            DMA2_FLAG_GL1 - DMA2 Channel1 global flag.
 *            DMA2_FLAG_TC1 - DMA2 Channel1 transfer complete flag.
 *            DMA2_FLAG_HT1 - DMA2 Channel1 half transfer flag.
 *            DMA2_FLAG_TE1 - DMA2 Channel1 transfer error flag.
 *            DMA2_FLAG_GL2 - DMA2 Channel2 global flag.
 *            DMA2_FLAG_TC2 - DMA2 Channel2 transfer complete flag.
 *            DMA2_FLAG_HT2 - DMA2 Channel2 half transfer flag.
 *            DMA2_FLAG_TE2 - DMA2 Channel2 transfer error flag.
 *            DMA2_FLAG_GL3 - DMA2 Channel3 global flag.
 *            DMA2_FLAG_TC3 - DMA2 Channel3 transfer complete flag.
 *            DMA2_FLAG_HT3 - DMA2 Channel3 half transfer flag.
 *            DMA2_FLAG_TE3 - DMA2 Channel3 transfer error flag.
 *            DMA2_FLAG_GL4 - DMA2 Channel4 global flag.
 *            DMA2_FLAG_TC4 - DMA2 Channel4 transfer complete flag.
 *            DMA2_FLAG_HT4 - DMA2 Channel4 half transfer flag.
 *            DMA2_FLAG_TE4 - DMA2 Channel4 transfer error flag.
 *            DMA2_FLAG_GL5 - DMA2 Channel5 global flag.
 *            DMA2_FLAG_TC5 - DMA2 Channel5 transfer complete flag.
 *            DMA2_FLAG_HT5 - DMA2 Channel5 half transfer flag.
 *            DMA2_FLAG_TE5 - DMA2 Channel5 transfer error flag.
 *            DMA2_FLAG_GL6 - DMA2 Channel6 global flag.
 *            DMA2_FLAG_TC6 - DMA2 Channel6 transfer complete flag.
 *            DMA2_FLAG_HT6 - DMA2 Channel6 half transfer flag.
 *            DMA2_FLAG_TE6 - DMA2 Channel6 transfer error flag.
 *            DMA2_FLAG_GL7 - DMA2 Channel7 global flag.
 *            DMA2_FLAG_TC7 - DMA2 Channel7 transfer complete flag.
 *            DMA2_FLAG_HT7 - DMA2 Channel7 half transfer flag.
 *            DMA2_FLAG_TE7 - DMA2 Channel7 transfer error flag.
 *            DMA2_FLAG_GL8 - DMA2 Channel8 global flag.
 *            DMA2_FLAG_TC8 - DMA2 Channel8 transfer complete flag.
 *            DMA2_FLAG_HT8 - DMA2 Channel8 half transfer flag.
 *            DMA2_FLAG_TE8 - DMA2 Channel8 transfer error flag.
 *            DMA2_FLAG_GL9 - DMA2 Channel9 global flag.
 *            DMA2_FLAG_TC9 - DMA2 Channel9 transfer complete flag.
 *            DMA2_FLAG_HT9 - DMA2 Channel9 half transfer flag.
 *            DMA2_FLAG_TE9 - DMA2 Channel9 transfer error flag.
 *            DMA2_FLAG_GL10 - DMA2 Channel10 global flag.
 *            DMA2_FLAG_TC10 - DMA2 Channel10 transfer complete flag.
 *            DMA2_FLAG_HT10 - DMA2 Channel10 half transfer flag.
 *            DMA2_FLAG_TE10 - DMA2 Channel10 transfer error flag.
 *            DMA2_FLAG_GL11 - DMA2 Channel11 global flag.
 *            DMA2_FLAG_TC11 - DMA2 Channel11 transfer complete flag.
 *            DMA2_FLAG_HT11 - DMA2 Channel11 half transfer flag.
 *            DMA2_FLAG_TE11 - DMA2 Channel11 transfer error flag.
 *
 * @return  标志位状态(SET或RESET)
 *
 * @note    使用示例:
 *          if(DMA_GetFlagStatus(DMA1_FLAG_TC1) == SET)
 *          {
 *              // 传输完成
 *          }
 */
FlagStatus DMA_GetFlagStatus(uint32_t DMAy_FLAG)
{
    FlagStatus bitstatus = RESET;
    uint32_t tmpreg = 0;

    if ((DMAy_FLAG & FLAG_Mask) == FLAG_Mask)
    {
        tmpreg = DMA2->INTFR;
    }
    else if ((DMAy_FLAG & DMA2_EXTEN_FLAG_Mask) == DMA2_EXTEN_FLAG_Mask)
    {
        tmpreg = DMA2_EXTEN->INTFR;
    }
    else
    {
        tmpreg = DMA1->INTFR;
    }

    if ((tmpreg & DMAy_FLAG) != (uint32_t)RESET)
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
 * @fn      DMA_ClearFlag
 *
 * @brief   清除DMA通道的待处理标志位
 *
 * @param   DMAy_FLAG - specifies the flag to check.
 *            DMA1_FLAG_GL1 - DMA1 Channel1 global flag.
 *            DMA1_FLAG_TC1 - DMA1 Channel1 transfer complete flag.
 *            DMA1_FLAG_HT1 - DMA1 Channel1 half transfer flag.
 *            DMA1_FLAG_TE1 - DMA1 Channel1 transfer error flag.
 *            DMA1_FLAG_GL2 - DMA1 Channel2 global flag.
 *            DMA1_FLAG_TC2 - DMA1 Channel2 transfer complete flag.
 *            DMA1_FLAG_HT2 - DMA1 Channel2 half transfer flag.
 *            DMA1_FLAG_TE2 - DMA1 Channel2 transfer error flag.
 *            DMA1_FLAG_GL3 - DMA1 Channel3 global flag.
 *            DMA1_FLAG_TC3 - DMA1 Channel3 transfer complete flag.
 *            DMA1_FLAG_HT3 - DMA1 Channel3 half transfer flag.
 *            DMA1_FLAG_TE3 - DMA1 Channel3 transfer error flag.
 *            DMA1_FLAG_GL4 - DMA1 Channel4 global flag.
 *            DMA1_FLAG_TC4 - DMA1 Channel4 transfer complete flag.
 *            DMA1_FLAG_HT4 - DMA1 Channel4 half transfer flag.
 *            DMA1_FLAG_TE4 - DMA1 Channel4 transfer error flag.
 *            DMA1_FLAG_GL5 - DMA1 Channel5 global flag.
 *            DMA1_FLAG_TC5 - DMA1 Channel5 transfer complete flag.
 *            DMA1_FLAG_HT5 - DMA1 Channel5 half transfer flag.
 *            DMA1_FLAG_TE5 - DMA1 Channel5 transfer error flag.
 *            DMA1_FLAG_GL6 - DMA1 Channel6 global flag.
 *            DMA1_FLAG_TC6 - DMA1 Channel6 transfer complete flag.
 *            DMA1_FLAG_HT6 - DMA1 Channel6 half transfer flag.
 *            DMA1_FLAG_TE6 - DMA1 Channel6 transfer error flag.
 *            DMA1_FLAG_GL7 - DMA1 Channel7 global flag.
 *            DMA1_FLAG_TC7 - DMA1 Channel7 transfer complete flag.
 *            DMA1_FLAG_HT7 - DMA1 Channel7 half transfer flag.
 *            DMA1_FLAG_TE7 - DMA1 Channel7 transfer error flag.
 *            DMA2_FLAG_GL1 - DMA2 Channel1 global flag.
 *            DMA2_FLAG_TC1 - DMA2 Channel1 transfer complete flag.
 *            DMA2_FLAG_HT1 - DMA2 Channel1 half transfer flag.
 *            DMA2_FLAG_TE1 - DMA2 Channel1 transfer error flag.
 *            DMA2_FLAG_GL2 - DMA2 Channel2 global flag.
 *            DMA2_FLAG_TC2 - DMA2 Channel2 transfer complete flag.
 *            DMA2_FLAG_HT2 - DMA2 Channel2 half transfer flag.
 *            DMA2_FLAG_TE2 - DMA2 Channel2 transfer error flag.
 *            DMA2_FLAG_GL3 - DMA2 Channel3 global flag.
 *            DMA2_FLAG_TC3 - DMA2 Channel3 transfer complete flag.
 *            DMA2_FLAG_HT3 - DMA2 Channel3 half transfer flag.
 *            DMA2_FLAG_TE3 - DMA2 Channel3 transfer error flag.
 *            DMA2_FLAG_GL4 - DMA2 Channel4 global flag.
 *            DMA2_FLAG_TC4 - DMA2 Channel4 transfer complete flag.
 *            DMA2_FLAG_HT4 - DMA2 Channel4 half transfer flag.
 *            DMA2_FLAG_TE4 - DMA2 Channel4 transfer error flag.
 *            DMA2_FLAG_GL5 - DMA2 Channel5 global flag.
 *            DMA2_FLAG_TC5 - DMA2 Channel5 transfer complete flag.
 *            DMA2_FLAG_HT5 - DMA2 Channel5 half transfer flag.
 *            DMA2_FLAG_TE5 - DMA2 Channel5 transfer error flag.
 *            DMA2_FLAG_GL6 - DMA2 Channel6 global flag.
 *            DMA2_FLAG_TC6 - DMA2 Channel6 transfer complete flag.
 *            DMA2_FLAG_HT6 - DMA2 Channel6 half transfer flag.
 *            DMA2_FLAG_TE6 - DMA2 Channel6 transfer error flag.
 *            DMA2_FLAG_GL7 - DMA2 Channel7 global flag.
 *            DMA2_FLAG_TC7 - DMA2 Channel7 transfer complete flag.
 *            DMA2_FLAG_HT7 - DMA2 Channel7 half transfer flag.
 *            DMA2_FLAG_TE7 - DMA2 Channel7 transfer error flag.
 *            DMA2_FLAG_GL8 - DMA2 Channel8 global flag.
 *            DMA2_FLAG_TC8 - DMA2 Channel8 transfer complete flag.
 *            DMA2_FLAG_HT8 - DMA2 Channel8 half transfer flag.
 *            DMA2_FLAG_TE8 - DMA2 Channel8 transfer error flag.
 *            DMA2_FLAG_GL9 - DMA2 Channel9 global flag.
 *            DMA2_FLAG_TC9 - DMA2 Channel9 transfer complete flag.
 *            DMA2_FLAG_HT9 - DMA2 Channel9 half transfer flag.
 *            DMA2_FLAG_TE9 - DMA2 Channel9 transfer error flag.
 *            DMA2_FLAG_GL10 - DMA2 Channel10 global flag.
 *            DMA2_FLAG_TC10 - DMA2 Channel10 transfer complete flag.
 *            DMA2_FLAG_HT10 - DMA2 Channel10 half transfer flag.
 *            DMA2_FLAG_TE10 - DMA2 Channel10 transfer error flag.
 *            DMA2_FLAG_GL11 - DMA2 Channel11 global flag.
 *            DMA2_FLAG_TC11 - DMA2 Channel11 transfer complete flag.
 *            DMA2_FLAG_HT11 - DMA2 Channel11 half transfer flag.
 *            DMA2_FLAG_TE11 - DMA2 Channel11 transfer error flag.
 *
 * @note    使用示例:
 *          DMA_ClearFlag(DMA1_FLAG_TC1);  // 清除DMA1通道1的传输完成标志
 */
void DMA_ClearFlag(uint32_t DMAy_FLAG)
{
    if ((DMAy_FLAG & FLAG_Mask) == FLAG_Mask)
    {
        DMA2->INTFCR = DMAy_FLAG;
    }
    else if ((DMAy_FLAG & DMA2_EXTEN_FLAG_Mask) == DMA2_EXTEN_FLAG_Mask)
    {
        DMA2_EXTEN->INTFCR = DMAy_FLAG;
    }
    else
    {
        DMA1->INTFCR = DMAy_FLAG;
    }
}

/*********************************************************************
 * @fn      DMA_GetITStatus
 *
 * @brief   检查指定的DMA通道中断是否发生
 *
 * @param   DMAy_IT - 指定要检查的DMA中断源
 *          可以是DMA1_IT_GL1到DMA1_IT_TE7或DMA2_IT_GL1到DMA2_IT_TE11
 *
 * @param   DMAy_IT - specifies the DMAy interrupt source to check.
 *            DMA1_IT_GL1 - DMA1 Channel1 global flag.
 *            DMA1_IT_TC1 - DMA1 Channel1 transfer complete flag.
 *            DMA1_IT_HT1 - DMA1 Channel1 half transfer flag.
 *            DMA1_IT_TE1 - DMA1 Channel1 transfer error flag.
 *            DMA1_IT_GL2 - DMA1 Channel2 global flag.
 *            DMA1_IT_TC2 - DMA1 Channel2 transfer complete flag.
 *            DMA1_IT_HT2 - DMA1 Channel2 half transfer flag.
 *            DMA1_IT_TE2 - DMA1 Channel2 transfer error flag.
 *            DMA1_IT_GL3 - DMA1 Channel3 global flag.
 *            DMA1_IT_TC3 - DMA1 Channel3 transfer complete flag.
 *            DMA1_IT_HT3 - DMA1 Channel3 half transfer flag.
 *            DMA1_IT_TE3 - DMA1 Channel3 transfer error flag.
 *            DMA1_IT_GL4 - DMA1 Channel4 global flag.
 *            DMA1_IT_TC4 - DMA1 Channel4 transfer complete flag.
 *            DMA1_IT_HT4 - DMA1 Channel4 half transfer flag.
 *            DMA1_IT_TE4 - DMA1 Channel4 transfer error flag.
 *            DMA1_IT_GL5 - DMA1 Channel5 global flag.
 *            DMA1_IT_TC5 - DMA1 Channel5 transfer complete flag.
 *            DMA1_IT_HT5 - DMA1 Channel5 half transfer flag.
 *            DMA1_IT_TE5 - DMA1 Channel5 transfer error flag.
 *            DMA1_IT_GL6 - DMA1 Channel6 global flag.
 *            DMA1_IT_TC6 - DMA1 Channel6 transfer complete flag.
 *            DMA1_IT_HT6 - DMA1 Channel6 half transfer flag.
 *            DMA1_IT_TE6 - DMA1 Channel6 transfer error flag.
 *            DMA1_IT_GL7 - DMA1 Channel7 global flag.
 *            DMA1_IT_TC7 - DMA1 Channel7 transfer complete flag.
 *            DMA1_IT_HT7 - DMA1 Channel7 half transfer flag.
 *            DMA1_IT_TE7 - DMA1 Channel7 transfer error flag.
 *            DMA2_IT_GL1 - DMA2 Channel1 global flag.
 *            DMA2_IT_TC1 - DMA2 Channel1 transfer complete flag.
 *            DMA2_IT_HT1 - DMA2 Channel1 half transfer flag.
 *            DMA2_IT_TE1 - DMA2 Channel1 transfer error flag.
 *            DMA2_IT_GL2 - DMA2 Channel2 global flag.
 *            DMA2_IT_TC2 - DMA2 Channel2 transfer complete flag.
 *            DMA2_IT_HT2 - DMA2 Channel2 half transfer flag.
 *            DMA2_IT_TE2 - DMA2 Channel2 transfer error flag.
 *            DMA2_IT_GL3 - DMA2 Channel3 global flag.
 *            DMA2_IT_TC3 - DMA2 Channel3 transfer complete flag.
 *            DMA2_IT_HT3 - DMA2 Channel3 half transfer flag.
 *            DMA2_IT_TE3 - DMA2 Channel3 transfer error flag.
 *            DMA2_IT_GL4 - DMA2 Channel4 global flag.
 *            DMA2_IT_TC4 - DMA2 Channel4 transfer complete flag.
 *            DMA2_IT_HT4 - DMA2 Channel4 half transfer flag.
 *            DMA2_IT_TE4 - DMA2 Channel4 transfer error flag.
 *            DMA2_IT_GL5 - DMA2 Channel5 global flag.
 *            DMA2_IT_TC5 - DMA2 Channel5 transfer complete flag.
 *            DMA2_IT_HT5 - DMA2 Channel5 half transfer flag.
 *            DMA2_IT_TE5 - DMA2 Channel5 transfer error flag.
 *            DMA2_IT_GL6 - DMA2 Channel6 global flag.
 *            DMA2_IT_TC6 - DMA2 Channel6 transfer complete flag.
 *            DMA2_IT_HT6 - DMA2 Channel6 half transfer flag.
 *            DMA2_IT_TE6 - DMA2 Channel6 transfer error flag.
 *            DMA2_IT_GL7 - DMA2 Channel7 global flag.
 *            DMA2_IT_TC7 - DMA2 Channel7 transfer complete flag.
 *            DMA2_IT_HT7 - DMA2 Channel7 half transfer flag.
 *            DMA2_IT_TE7 - DMA2 Channel7 transfer error flag.
 *            DMA2_IT_GL8 - DMA2 Channel8 global flag.
 *            DMA2_IT_TC8 - DMA2 Channel8 transfer complete flag.
 *            DMA2_IT_HT8 - DMA2 Channel8 half transfer flag.
 *            DMA2_IT_TE8 - DMA2 Channel8 transfer error flag.
 *            DMA2_IT_GL9 - DMA2 Channel9 global flag.
 *            DMA2_IT_TC9 - DMA2 Channel9 transfer complete flag.
 *            DMA2_IT_HT9 - DMA2 Channel9 half transfer flag.
 *            DMA2_IT_TE9 - DMA2 Channel9 transfer error flag.
 *            DMA2_IT_GL10 - DMA2 Channel10 global flag.
 *            DMA2_IT_TC10 - DMA2 Channel10 transfer complete flag.
 *            DMA2_IT_HT10 - DMA2 Channel10 half transfer flag.
 *            DMA2_IT_TE10 - DMA2 Channel10 transfer error flag.
 *            DMA2_IT_GL11 - DMA2 Channel11 global flag.
 *            DMA2_IT_TC11 - DMA2 Channel11 transfer complete flag.
 *            DMA2_IT_HT11 - DMA2 Channel11 half transfer flag.
 *            DMA2_IT_TE11 - DMA2 Channel11 transfer error flag.
 *
 * @note    使用示例:
 *          if(DMA_GetITStatus(DMA1_IT_TC1) == SET)
 *          {
 *              // 传输完成中断发生
 *          }
 */
ITStatus DMA_GetITStatus(uint32_t DMAy_IT)
{
    ITStatus bitstatus = RESET;
    uint32_t tmpreg = 0;

    if ((DMAy_IT & FLAG_Mask) == FLAG_Mask)
    {
        tmpreg = DMA2->INTFR;
    }
    else if ((DMAy_IT & DMA2_EXTEN_FLAG_Mask) == DMA2_EXTEN_FLAG_Mask)
    {
        tmpreg = DMA2_EXTEN->INTFR;
    }
    else
    {
        tmpreg = DMA1->INTFR;
    }

    if ((tmpreg & DMAy_IT) != (uint32_t)RESET)
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
 * @fn      DMA_ClearITPendingBit
 *
 * @brief   清除DMA通道的待处理中断位
 *
 * @param   DMAy_IT - 指定要清除的DMA中断源
 *          可以是DMA1_IT_GL1到DMA1_IT_TE7或DMA2_IT_GL1到DMA2_IT_TE11
 *
 * @param   DMAy_IT - specifies the DMAy interrupt source to check.
 *            DMA1_IT_GL1 - DMA1 Channel1 global flag.
 *            DMA1_IT_TC1 - DMA1 Channel1 transfer complete flag.
 *            DMA1_IT_HT1 - DMA1 Channel1 half transfer flag.
 *            DMA1_IT_TE1 - DMA1 Channel1 transfer error flag.
 *            DMA1_IT_GL2 - DMA1 Channel2 global flag.
 *            DMA1_IT_TC2 - DMA1 Channel2 transfer complete flag.
 *            DMA1_IT_HT2 - DMA1 Channel2 half transfer flag.
 *            DMA1_IT_TE2 - DMA1 Channel2 transfer error flag.
 *            DMA1_IT_GL3 - DMA1 Channel3 global flag.
 *            DMA1_IT_TC3 - DMA1 Channel3 transfer complete flag.
 *            DMA1_IT_HT3 - DMA1 Channel3 half transfer flag.
 *            DMA1_IT_TE3 - DMA1 Channel3 transfer error flag.
 *            DMA1_IT_GL4 - DMA1 Channel4 global flag.
 *            DMA1_IT_TC4 - DMA1 Channel4 transfer complete flag.
 *            DMA1_IT_HT4 - DMA1 Channel4 half transfer flag.
 *            DMA1_IT_TE4 - DMA1 Channel4 transfer error flag.
 *            DMA1_IT_GL5 - DMA1 Channel5 global flag.
 *            DMA1_IT_TC5 - DMA1 Channel5 transfer complete flag.
 *            DMA1_IT_HT5 - DMA1 Channel5 half transfer flag.
 *            DMA1_IT_TE5 - DMA1 Channel5 transfer error flag.
 *            DMA1_IT_GL6 - DMA1 Channel6 global flag.
 *            DMA1_IT_TC6 - DMA1 Channel6 transfer complete flag.
 *            DMA1_IT_HT6 - DMA1 Channel6 half transfer flag.
 *            DMA1_IT_TE6 - DMA1 Channel6 transfer error flag.
 *            DMA1_IT_GL7 - DMA1 Channel7 global flag.
 *            DMA1_IT_TC7 - DMA1 Channel7 transfer complete flag.
 *            DMA1_IT_HT7 - DMA1 Channel7 half transfer flag.
 *            DMA1_IT_TE7 - DMA1 Channel7 transfer error flag.
 *            DMA2_IT_GL1 - DMA2 Channel1 global flag.
 *            DMA2_IT_TC1 - DMA2 Channel1 transfer complete flag.
 *            DMA2_IT_HT1 - DMA2 Channel1 half transfer flag.
 *            DMA2_IT_TE1 - DMA2 Channel1 transfer error flag.
 *            DMA2_IT_GL2 - DMA2 Channel2 global flag.
 *            DMA2_IT_TC2 - DMA2 Channel2 transfer complete flag.
 *            DMA2_IT_HT2 - DMA2 Channel2 half transfer flag.
 *            DMA2_IT_TE2 - DMA2 Channel2 transfer error flag.
 *            DMA2_IT_GL3 - DMA2 Channel3 global flag.
 *            DMA2_IT_TC3 - DMA2 Channel3 transfer complete flag.
 *            DMA2_IT_HT3 - DMA2 Channel3 half transfer flag.
 *            DMA2_IT_TE3 - DMA2 Channel3 transfer error flag.
 *            DMA2_IT_GL4 - DMA2 Channel4 global flag.
 *            DMA2_IT_TC4 - DMA2 Channel4 transfer complete flag.
 *            DMA2_IT_HT4 - DMA2 Channel4 half transfer flag.
 *            DMA2_IT_TE4 - DMA2 Channel4 transfer error flag.
 *            DMA2_IT_GL5 - DMA2 Channel5 global flag.
 *            DMA2_IT_TC5 - DMA2 Channel5 transfer complete flag.
 *            DMA2_IT_HT5 - DMA2 Channel5 half transfer flag.
 *            DMA2_IT_TE5 - DMA2 Channel5 transfer error flag.
 *            DMA2_IT_GL6 - DMA2 Channel6 global flag.
 *            DMA2_IT_TC6 - DMA2 Channel6 transfer complete flag.
 *            DMA2_IT_HT6 - DMA2 Channel6 half transfer flag.
 *            DMA2_IT_TE6 - DMA2 Channel6 transfer error flag.
 *            DMA2_IT_GL7 - DMA2 Channel7 global flag.
 *            DMA2_IT_TC7 - DMA2 Channel7 transfer complete flag.
 *            DMA2_IT_HT7 - DMA2 Channel7 half transfer flag.
 *            DMA2_IT_TE7 - DMA2 Channel7 transfer error flag.
 *            DMA2_IT_GL8 - DMA2 Channel8 global flag.
 *            DMA2_IT_TC8 - DMA2 Channel8 transfer complete flag.
 *            DMA2_IT_HT8 - DMA2 Channel8 half transfer flag.
 *            DMA2_IT_TE8 - DMA2 Channel8 transfer error flag.
 *            DMA2_IT_GL9 - DMA2 Channel9 global flag.
 *            DMA2_IT_TC9 - DMA2 Channel9 transfer complete flag.
 *            DMA2_IT_HT9 - DMA2 Channel9 half transfer flag.
 *            DMA2_IT_TE9 - DMA2 Channel9 transfer error flag.
 *            DMA2_IT_GL10 - DMA2 Channel10 global flag.
 *            DMA2_IT_TC10 - DMA2 Channel10 transfer complete flag.
 *            DMA2_IT_HT10 - DMA2 Channel10 half transfer flag.
 *            DMA2_IT_TE10 - DMA2 Channel10 transfer error flag.
 *            DMA2_IT_GL11 - DMA2 Channel11 global flag.
 *            DMA2_IT_TC11 - DMA2 Channel11 transfer complete flag.
 *            DMA2_IT_HT11 - DMA2 Channel11 half transfer flag.
 *            DMA2_IT_TE11 - DMA2 Channel11 transfer error flag.
 *
 * @note    使用示例:
 *          DMA_ClearITPendingBit(DMA1_IT_TC1);  // 清除DMA1通道1的传输完成中断
 */
void DMA_ClearITPendingBit(uint32_t DMAy_IT)
{
    if ((DMAy_IT & FLAG_Mask) == FLAG_Mask)
    {
        DMA2->INTFCR = DMAy_IT;
    }
    else if ((DMAy_IT & DMA2_EXTEN_FLAG_Mask) == DMA2_EXTEN_FLAG_Mask)
    {
        DMA2_EXTEN->INTFCR = DMAy_IT;
    }
    else
    {
        DMA1->INTFCR = DMAy_IT;
    }
}
