#include "step_motor_interface.h"

// 平台接口实现
void sm1_hw_init(void)
{
    pwm_init(TIM8_PWM_MAP0_CH1_C6, 1, 5000);
    gpio_init(C7, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(C8, GPO, 0, GPIO_PIN_CONFIG);
}

void sm1_set_freq(uint32_t freq_hz)
{
    pwm_set_freq(TIM8_PWM_MAP0_CH1_C6, freq_hz, 5000);
}

void sm1_start_pwm(void)
{
    timer_start(TIM8);
}

void sm1_stop_pwm(void)
{
    timer_stop(TIM8);
}

void sm1_set_dir(StepperDirection_t dir)
{
    gpio_set_level(C7, dir ? GPIO_HIGH : GPIO_LOW);
}

void sm1_set_enable(bool en)
{
    gpio_set_level(C8, en ? GPIO_LOW : GPIO_HIGH); // 低电平有效
}

StepperMotor_t sm1_motor = {
    .init = sm1_hw_init,
    .set_pwm_freq = sm1_set_freq,
    .start_pwm = sm1_start_pwm,
    .stop_pwm = sm1_stop_pwm,
    .set_dir = sm1_set_dir,
    .set_enable = sm1_set_enable};
