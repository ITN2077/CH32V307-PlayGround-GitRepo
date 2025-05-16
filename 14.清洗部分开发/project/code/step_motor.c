#include "stepper_motor.h"

void Stepper_Init(StepperMotor_t *motor)
{
    if (motor && motor->init)
    {
        motor->init();
        motor->stop_pwm();
        motor->is_busy = false;
        motor->counter = 0;
        motor->total_steps = 0;
    }
}

void Stepper_SetEnable(StepperMotor_t *motor, bool enable)
{
    if (motor && motor->set_enable)
    {
        motor->set_enable(enable);
    }
}

void Stepper_SetDirection(StepperMotor_t *motor, StepperDirection_t dir)
{
    if (motor && motor->set_dir)
    {
        motor->set_dir(dir);
    }
}

void Stepper_SetSpeed(StepperMotor_t *motor, uint32_t freq_hz)
{
    if (motor && motor->set_pwm_freq)
    {
        motor->set_pwm_freq(freq_hz);
    }
}

void Stepper_Start(StepperMotor_t *motor, uint32_t steps)
{
    if (!motor || steps == 0)
        return;

    motor->total_steps = steps;
    motor->counter = steps;
    motor->is_busy = true;

    if (motor->start_pwm)
    {
        motor->start_pwm();
    }
}

void Stepper_IRQHandler(StepperMotor_t *motor)
{
    if (!motor || !motor->is_busy)
        return;

    if (--motor->counter == 0)
    {
        if (motor->stop_pwm)
        {
            motor->stop_pwm();
        }
        motor->is_busy = false;
    }
}

bool Stepper_IsBusy(StepperMotor_t *motor)
{
    return motor && motor->is_busy;
}
