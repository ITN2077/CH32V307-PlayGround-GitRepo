#include "motor.h"

// 初始化
void Motor_Init(Motor_t *motor)
{
    if (!motor || !motor->init)
        return;
        
    motor->init(); // 真正初始化硬件（GPIO、PWM、方向等）
}

// 显式设置速度和方向
void Motor_SetPWM(Motor_t *motor, uint16_t pwm)
{
    if (!motor)
        return;

    if (pwm > motor->max_pwm)
        pwm = motor->max_pwm;

    motor->set_pwm(pwm);
}

// 适配无 PWM 的简易电机（如 M2）
void Motor_SetDir(Motor_t *motor, MotorDirection_t dir)
{
    if (!motor || !motor->set_dir)
        return;

    motor->set_dir(dir);
}

// 主动刹车（等价于停止）
void Motor_Brake(Motor_t *motor)
{
    if (!motor)
        return;

    motor->set_pwm(0);
    motor->brake();
}

// 隐式设置速度，方向由数值正负确定
void Motor_SetSpeed(Motor_t *motor, int16_t speed)
{
    if (!motor)
        return;

    if (speed > 0)
    {
        if (speed > motor->max_pwm)
            speed = motor->max_pwm;
        motor->set_dir(MOTOR_DIR_FORWARD);
        motor->set_pwm(speed);
    }
    else if (speed < 0)
    {
        if (speed < -motor->max_pwm)
            speed = -motor->max_pwm;
        motor->set_dir(MOTOR_DIR_REVERSE);
        motor->set_pwm(-speed);
    }
    else
        motor->brake();
}