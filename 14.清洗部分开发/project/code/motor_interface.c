#include "zf_common_headfile.h" // 平台头文件

#include "motor.h" // 电机驱动模板头文件
#include "motor_interface.h" // 电机接口头文件

#define M1_IN1 D0
#define M1_IN2 D1
#define M1_EN  D2

#define M2_IN1 D3
#define M2_IN2 D4
#define M2_EN  D5

#define M3_IN1 D6
#define M3_IN2 D7
#define M3_PWM TIM4_PWM_MAP0_CH1_B6

#define M4_IN1 D8
#define M4_IN2 D9
#define M4_PWM TIM4_PWM_MAP0_CH2_B7

#define M5_IN1 D10
#define M5_IN2 D11
#define M5_EN  D12


/*  M1平台层实现，使用AQMH2407ND电机驱动
 * IN3、IN4、ENB分别控制电机的方向和使能。
 *  ------------------------------------------------------
 * | IN3 | IN4 |  ENB   |      电机状态（OUT3、OUT4输出） |
 * |-----|-----|--------|-------------------------------|
 * |  0  |  0  |   ×    | 剎车（Brake）                  |
 * |  1  |  1  |   ×    | 悬空（Coast）                  |
 * |  1  |  0  |  PWM   | 正转调速（Forward with speed） |
 * |  0  |  1  |  PWM   | 反转调速（Reverse with speed） |
 * |  1  |  0  |   1    | 全速正转（Full speed forward） |
 * |  0  |  1  |   1    | 全速反转（Full speed reverse） |
 *  ------------------------------------------------------
 */
void M1_Init(void)
{
    // 初始化gpio PD0, PD1, PD2为输出
    gpio_init(M1_IN1, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(M1_IN2, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(M1_EN, GPO, 0, GPIO_PIN_CONFIG); // EN
}
void M1_SetPWM(uint16_t pwm)
{
    return;
}
void M1_SetDir(MotorDirection_t dir)
{
    if (dir == MOTOR_DIR_FORWARD)
    {
        gpio_set_level(M1_IN1, GPIO_HIGH);
        gpio_set_level(M1_IN2, GPIO_LOW);
        gpio_set_level(M1_EN, GPIO_HIGH);
    }
    else
    {
        gpio_set_level(M1_IN1, GPIO_LOW);
        gpio_set_level(M1_IN2, GPIO_HIGH);
        gpio_set_level(M1_EN, GPIO_HIGH);
    }
}
void M1_Brake(void)
{
    gpio_set_level(M1_IN1, GPIO_LOW);
    gpio_set_level(M1_IN2, GPIO_LOW);
    gpio_set_level(M1_EN, GPIO_LOW);
}
Motor_t motor_m1 = {
    .init = M1_Init,
    .set_pwm = M1_SetPWM,
    .set_dir = M1_SetDir,
    .brake = M1_Brake,
    .max_pwm = 1,
    .name = "M1"};


/* M2平台层实现，使用AQMH2407ND电机驱动
 * IN3、IN4、ENB分别控制电机的方向和使能。
 *  ------------------------------------------------------
 * | IN3 | IN4 |  ENB   |      电机状态（OUT3、OUT4输出） |
 * |-----|-----|--------|-------------------------------|
 * |  0  |  0  |   ×    | 剎车（Brake）                  |
 * |  1  |  1  |   ×    | 悬空（Coast）                  |
 * |  1  |  0  |  PWM   | 正转调速（Forward with speed） |
 * |  0  |  1  |  PWM   | 反转调速（Reverse with speed） |
 * |  1  |  0  |   1    | 全速正转（Full speed forward） |
 * |  0  |  1  |   1    | 全速反转（Full speed reverse） |
 *  ------------------------------------------------------
 */
void M2_Init(void)
{
    // 初始化PD3, PD4, PD5为输出
    gpio_init(M2_IN1, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(M2_IN2, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(M2_EN, GPO, 0, GPIO_PIN_CONFIG); // EN
}
void M2_SetPWM(uint16_t pwm)
{
    return;
}
void M2_SetDir(MotorDirection_t dir)
{
    if (dir == MOTOR_DIR_FORWARD)
    {
        gpio_set_level(M2_IN1, GPIO_HIGH);
        gpio_set_level(M2_IN2, GPIO_LOW);
        gpio_set_level(M2_EN, GPIO_HIGH);
    }
    else
    {
        gpio_set_level(M2_IN1, GPIO_LOW);
        gpio_set_level(M2_IN2, GPIO_HIGH);
        gpio_set_level(M2_EN, GPIO_HIGH);
    }
}
void M2_Brake(void)
{
    gpio_set_level(M2_IN1, GPIO_LOW);
    gpio_set_level(M2_IN2, GPIO_LOW);
    gpio_set_level(M2_EN, GPIO_LOW);
}
Motor_t motor_m2 = {
    .init = M2_Init,
    .set_pwm = M2_SetPWM,
    .set_dir = M2_SetDir,
    .brake = M2_Brake,
    .max_pwm = 1,
    .name = "M2"};

/* M3平台层实现，使用TB6612FNG电机驱动
 *  -----------------------------------------------------
 * | BIN1 | BIN2 | PWMB |      电机状态（B端口 A02/A01） |
 * |------|------|------|-------------------------------|
 * |  1   |  0   |  1   | 正转（Forward）                |
 * |  0   |  1   |  1   | 反转（Reverse）                |
 * |  1   |  1   |  1   | 刹车（Brake，输出短接）        |
 * |  0   |  0   |  1   | 自由停车（Coast，高阻状态）    |
 * |  X   |  X   |  0   | 强制刹车（Brake）              |
 *  -----------------------------------------------------
 */
void M3_Init(void)
{
    // 初始化gpio PD6、PD7为输出
    gpio_init(M3_IN1, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(M3_IN2, GPO, 0, GPIO_PIN_CONFIG);
    // 初始化pwm PB6
    pwm_init(M3_PWM, 1000, 0);
}
void M3_SetPWM(uint16_t pwm)
{
    pwm_set_duty(M3_PWM, pwm);
}
void M3_SetDir(MotorDirection_t dir)
{
    if (dir == MOTOR_DIR_FORWARD)
    {
        gpio_set_level(M3_IN1, GPIO_HIGH);
        gpio_set_level(M3_IN2, GPIO_LOW);
    }
    else
    {
        gpio_set_level(M3_IN1, GPIO_LOW);
        gpio_set_level(M3_IN2, GPIO_HIGH);
    }
}
void M3_Brake(void)
{
    //TB6612FNG刹车
    gpio_set_level(M3_IN1, GPIO_HIGH);
    gpio_set_level(M3_IN2, GPIO_HIGH);
    pwm_set_duty(M3_PWM, 0); 
}
Motor_t motor_m3 = {
    .init = M3_Init,
    .set_pwm = M3_SetPWM,
    .set_dir = M3_SetDir,
    .brake = M3_Brake,
    .max_pwm = 10000,
    .name = "M3"};

/* M4平台层实现，使用TB6612FNG电机驱动
 *  -----------------------------------------------------
 * | BIN1 | BIN2 | PWMB |      电机状态（B端口 A02/A01） |
 * |------|------|------|-------------------------------|
 * |  1   |  0   |  1   | 正转（Forward）                |
 * |  0   |  1   |  1   | 反转（Reverse）                |
 * |  1   |  1   |  1   | 刹车（Brake，输出短接）        |
 * |  0   |  0   |  1   | 自由停车（Coast，高阻状态）    |
 * |  X   |  X   |  0   | 强制刹车（Brake）              |
 *  -----------------------------------------------------
 */
void M4_Init(void)
{
    // 初始化gpio PD8、PD9为输出
    gpio_init(M4_IN1, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(M4_IN2, GPO, 0, GPIO_PIN_CONFIG);
    // 初始化pwm PB7
    pwm_init(M4_PWM, 1000, 0);
}
void M4_SetPWM(uint16_t pwm)
{
    pwm_set_duty(M4_PWM, pwm);
}
void M4_SetDir(MotorDirection_t dir)
{
    if (dir == MOTOR_DIR_FORWARD)
    {
        gpio_set_level(M4_IN1, GPIO_HIGH);
        gpio_set_level(M4_IN2, GPIO_LOW);   
    }
    else
    {
        gpio_set_level(M4_IN1, GPIO_LOW);
        gpio_set_level(M4_IN2, GPIO_HIGH);
    }
}
void M4_Brake(void)
{
    gpio_set_level(M4_IN1, GPIO_HIGH);
    gpio_set_level(M4_IN2, GPIO_HIGH);
    pwm_set_duty(M4_PWM, 0);
}
Motor_t motor_m4 = {
    .init = M4_Init,
    .set_pwm = M4_SetPWM,
    .set_dir = M4_SetDir,
    .brake = M4_Brake,
    .max_pwm = 10000,
    .name = "M4"};

/* M5平台层实现，使用AQMH2407ND电机驱动
 * IN3、IN4、ENB分别控制电机的方向和使能。
 *  ------------------------------------------------------
 * | IN3 | IN4 |  ENB   |      电机状态（OUT3、OUT4输出） |
 * |-----|-----|--------|-------------------------------|
 * |  0  |  0  |   ×    | 剎车（Brake）                  |
 * |  1  |  1  |   ×    | 悬空（Coast）                  |
 * |  1  |  0  |  PWM   | 正转调速（Forward with speed） |
 * |  0  |  1  |  PWM   | 反转调速（Reverse with speed） |
 * |  1  |  0  |   1    | 全速正转（Full speed forward） |
 * |  0  |  1  |   1    | 全速反转（Full speed reverse） |
 *  ------------------------------------------------------
 */
void M5_Init(void)
{
    // 初始化gpio PD10、PD11、PD12为输出
    gpio_init(M5_IN1, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(M5_IN2, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(M5_EN, GPO, 0, GPIO_PIN_CONFIG); // EN
}
void M5_SetPWM(uint16_t pwm)
{
    return;
}
void M5_SetDir(MotorDirection_t dir)
{
    if (dir == MOTOR_DIR_FORWARD)
    {
        gpio_set_level(M5_IN1, GPIO_HIGH);
        gpio_set_level(M5_IN2, GPIO_LOW);
        gpio_set_level(M5_EN, GPIO_HIGH);
    }   
    else
    {
        gpio_set_level(M5_IN1, GPIO_LOW);
        gpio_set_level(M5_IN2, GPIO_HIGH);
        gpio_set_level(M5_EN, GPIO_HIGH);
    }
}
void M5_Brake(void)
{
    gpio_set_level(M5_IN1, GPIO_LOW);
    gpio_set_level(M5_IN2, GPIO_LOW);
    gpio_set_level(M5_EN, GPIO_LOW);
}  
Motor_t motor_m5 = {
    .init = M5_Init,
    .set_pwm = M5_SetPWM,
    .set_dir = M5_SetDir,
    .brake = M5_Brake,
    .max_pwm = 1,
    .name = "M5"};

