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
 * 文件名称          zf_common_interrupt
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

#ifndef _zf_nvic_h
#define _zf_nvic_h

#include "ch32v30x.h"
#include "zf_common_typedef.h"

/**
 * @brief   初始化中断系统
 * @note    此函数用于初始化NVIC中断控制器，设置基本的中断配置
 */
void interrupt_init(void);

/**
 * @brief   全局使能中断
 * @param   primask    之前保存的PRIMASK值
 * @note    用于恢复之前被禁用的全局中断状态
 */
void interrupt_global_enable(uint32 primask);

/**
 * @brief   全局禁用中断
 * @return  返回当前的PRIMASK值，用于后续恢复中断状态
 * @note    此函数会禁用所有中断，返回当前的PRIMASK值供后续恢复使用
 */
uint32 interrupt_global_disable(void);

/**
 * @brief   使能指定中断
 * @param   irqn       要使能的中断号
 * @note    用于使能特定的中断源，使其能够响应中断请求
 */
void interrupt_enable(IRQn_Type irqn);

/**
 * @brief   禁用指定中断
 * @param   irqn       要禁用的中断号
 * @note    用于禁用特定的中断源，使其暂时不响应中断请求
 */
void interrupt_disable(IRQn_Type irqn);

/**
 * @brief   设置中断优先级
 * @param   irqn       要设置的中断号
 * @param   priority   优先级值(0-255)
 * @note    用于设置指定中断的优先级，数值越小优先级越高
 */
void interrupt_set_priority(IRQn_Type irqn, uint8 priority);

#endif
