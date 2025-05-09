#ifndef ENCODER_H
#define ENCODER_H

#include <stdint.h>

// 通用编码器结构体
typedef struct
{
    void (*init)(void);    // 初始化定时器、GPIO
    int16_t (*read)(void); // 读取当前计数值（返回相对位置）
    void (*reset)(void);   // 重置计数器为 0
    int32_t count;         // 计数值
    const char *name;      // 调试名
} Encoder_t;

// 通用接口
void Encoder_Init(Encoder_t *enc);
int16_t Encoder_GetCount(Encoder_t *enc);
void Encoder_Reset(Encoder_t *enc);

#endif
