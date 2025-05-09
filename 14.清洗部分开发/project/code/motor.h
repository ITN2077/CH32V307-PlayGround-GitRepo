#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>

// 电机方向
typedef enum
{
    MOTOR_DIR_FORWARD = 0,
    MOTOR_DIR_REVERSE
} MotorDirection_t;

// 电机控制结构体（平台独立）
typedef struct
{
    void (*init)(void);                    // 硬件初始化函数（必须实现）
    void (*set_pwm)(uint16_t pwm);     // 设置 PWM
    void (*set_dir)(MotorDirection_t dir); // 设置方向
    void (*brake)(void);                   // 主动刹车

    uint16_t max_pwm;
    const char *name;
} Motor_t;

// 初始化
void Motor_Init(Motor_t *motor);

// 设置pwm
void Motor_SetPWM(Motor_t *motor, uint16_t pwm);

// 设置方向，适配无 PWM 的简易电机
void Motor_SetDir(Motor_t *motor, MotorDirection_t dir);

// 主动刹车（等价于停止）
void Motor_Brake(Motor_t *motor);

// 隐式设置速度，方向由数值正负确定
void Motor_SetSpeed(Motor_t *motor, int16_t speed);

#endif
