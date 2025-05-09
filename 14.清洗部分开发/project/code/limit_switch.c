#include "limit_switch.h"

void LimitSwitch_Init(LimitSwitch_t *sw)
{
    if (!sw || !sw->init)
        return;
    sw->init();
    sw->stable_counter = 0;
    sw->last_stable_state = false;
}

bool LimitSwitch_ReadRaw(LimitSwitch_t *sw)
{
    if (!sw || !sw->read_pin)
        return false;
    return sw->read_pin(); // true = 按下
}

// 每周期调用（建议 10ms 周期）进行消抖处理
void LimitSwitch_Update(LimitSwitch_t *sw)
{
    if (!sw || !sw->read_pin)
        return;

    bool current = sw->read_pin();

    if (current == sw->last_stable_state)
    {
        sw->stable_counter = 0;
    }
    else
    {
        sw->stable_counter++;
        if (sw->stable_counter >= sw->stable_count_required)
        {
            sw->last_stable_state = current;
            sw->stable_counter = 0;
        }
    }
}

// 读取消抖后的稳定状态（true = 按下）
bool LimitSwitch_ReadStable(LimitSwitch_t *sw)
{
    if (!sw)
        return false;
    return sw->last_stable_state;
}