#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    void (*init)(void);     // 初始化引脚
    bool (*read_pin)(void); // 读取原始 GPIO 电平（true = 按下）
    const char *name;       // 可选调试用名

    // 软件消抖参数
    uint8_t stable_count_required; // 稳定计数阈值
    uint8_t stable_counter;        // 当前稳定计数值
    bool last_stable_state;        // 上一次稳定状态（true = 按下）
} LimitSwitch_t;

// 接口函数
void LimitSwitch_Init(LimitSwitch_t *sw);
bool LimitSwitch_ReadRaw(LimitSwitch_t *sw);    // 直接读取 GPIO 电平
bool LimitSwitch_ReadStable(LimitSwitch_t *sw); // 消抖稳定读取（建议使用）
void LimitSwitch_Update(LimitSwitch_t *sw);     // 在定时器中周期调用以更新状态（10~20ms）

#endif
