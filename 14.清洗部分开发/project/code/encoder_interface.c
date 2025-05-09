#include "zf_common_headfile.h"


#include "encoder_interface.h"
#include "encoder.h"

#define E3_ENCODER TIM2_ENCOEDER
#define E4_ENCODER TIM3_ENCOEDER

#define E3_ENCODER_CH1 TIM2_ENCOEDER_MAP1_CH1_A15
#define E3_ENCODER_CH2 TIM2_ENCOEDER_MAP1_CH2_B3
#define E4_ENCODER_CH1 TIM3_ENCOEDER_MAP0_CH1_A6
#define E4_ENCODER_CH2 TIM3_ENCOEDER_MAP0_CH2_A7

// ---------- E3 编码器平台函数实现 ----------
static void E3_Init(void)
{
    encoder_quad_init(E3_ENCODER, E3_ENCODER_CH1, E3_ENCODER_CH2);
}
static int16_t E3_Read(void)
{
    return encoder_get_count(E3_ENCODER);
}
static void E3_Reset(void)
{
    encoder_clear_count(E3_ENCODER);
}
// ---------- 编码器句柄 ----------
Encoder_t encoder_e3 = {
    .init = E3_Init,
    .read = E3_Read,
    .reset = E3_Reset,
    .count = 0,
    .name = "E3"};


// ---------- E4 编码器平台函数实现 ----------
static void E4_Init(void)
{
    encoder_quad_init(E4_ENCODER, E4_ENCODER_CH1, E4_ENCODER_CH2);
}
static int16_t E4_Read(void)
{
    return encoder_get_count(E4_ENCODER);
}
static void E4_Reset(void)
{
    encoder_clear_count(E4_ENCODER);
}
// ---------- 编码器句柄 ----------
Encoder_t encoder_e4 = {
    .init = E4_Init,
    .read = E4_Read,
    .reset = E4_Reset,
    .count = 0,
    .name = "E4"};




