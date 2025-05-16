#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    Forward = 0,
    Backward = 1
} StepperDirection_t;

typedef struct
{
    void (*init)(void);                     // 初始化硬件
    void (*set_pwm_freq)(uint32_t freq_hz); // 设置PWM频率
    void (*start_pwm)(void);                // 启动PWM
    void (*stop_pwm)(void);                 // 停止PWM
    void (*set_dir)(StepperDirection_t dir); // 设置方向（true = CW，false = CCW）
    void (*set_enable)(bool enable);        // 设置使能（true = enable）

    uint32_t total_steps;      // 设置的目标步数
    volatile uint32_t counter; // 当前剩余步数（在中断中减）
    bool is_busy;              // 电机是否正在运行
} StepperMotor_t;

void Stepper_Init(StepperMotor_t *motor); // 初始化电机
void Stepper_SetEnable(StepperMotor_t *motor, bool enable); // 设置使能
void Stepper_SetDirection(StepperMotor_t *motor, StepperDirection_t dir); // 设置方向
void Stepper_SetSpeed(StepperMotor_t *motor, uint32_t freq_hz);           // 设置速度
void Stepper_Start(StepperMotor_t *motor, uint32_t steps);               // 启动电机
void Stepper_IRQHandler(StepperMotor_t *motor);                           // 中断处理
bool Stepper_IsBusy(StepperMotor_t *motor);                               // 判断电机是否正在运行

#endif
