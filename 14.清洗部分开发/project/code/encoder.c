#include "encoder.h"

// 初始化编码器
void Encoder_Init(Encoder_t *enc)
{
    if (!enc || !enc->init)
        return;
    enc->init();
}

// 读取编码器计数值
int16_t Encoder_GetCount(Encoder_t *enc)
{
    if (!enc || !enc->read)
        return 0;
    return enc->read();
}

// 重置编码器计数值
void Encoder_Reset(Encoder_t *enc)
{
    if (!enc || !enc->reset)
        return;
    enc->reset();
}
