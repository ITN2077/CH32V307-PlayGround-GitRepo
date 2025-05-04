#include "motor_step_controller.h"

static motor_step_instance_t motor_step_instances[MAX_MOTOR_INSTANCES];
static unsigned char motor_step_instance_count = 0;

static motor_recip_instance_t motor_recip_instances[MAX_MOTOR_INSTANCES];
static unsigned char motor_recip_instance_count = 0;

motor_step_instance_t *motor_step_instance_create(const void (*start_pwm)(unsigned short duty, motor_direction_et dir), const void (*stop_pwm)(void))
{
    if (motor_step_instance_count >= MAX_MOTOR_INSTANCES)
    {
        return (void *)0;
    }

    motor_step_instance_t *instance = &motor_step_instances[motor_step_instance_count++];
    instance->state = MOTOR_STEP_STATE_IDLE;
    instance->timer_ms = 0;
    instance->direction = MOTOR_DIR_FORWARD;
    instance->request_pending = 0;
    instance->pwm_duty = 0;
    instance->drive_duration_ms = 0;
    instance->cooldown_duration_ms = 0;
    instance->start_pwm = start_pwm;
    instance->stop_pwm = stop_pwm;

    return instance;
}

void motor_step_instance_start(motor_step_instance_t *instance, const unsigned short pwm_duty, const motor_direction_et direction, const unsigned short dirve_duration_ms, const unsigned short cooldown_duration_ms)
{
    // 空闲状态：直接启动
    if (instance->state == MOTOR_STEP_STATE_IDLE)
    {
        instance->request_pending = 1;
        instance->timer_ms = 0;
        instance->pwm_duty = pwm_duty;
        instance->direction = direction;
        instance->drive_duration_ms = dirve_duration_ms;
        instance->cooldown_duration_ms = cooldown_duration_ms;
    }
    // 驱动状态：检查方向
    else if (instance->state == MOTOR_STEP_STATE_DRIVING)
    {
        // 相同方向：刷新参数
        if (instance->direction == direction)
        {
            // 直接更新参数，继续当前驱动
            instance->pwm_duty = pwm_duty;
            instance->drive_duration_ms = dirve_duration_ms;
            instance->cooldown_duration_ms = cooldown_duration_ms;
            instance->timer_ms = 0; // 重置计时器，重新开始计时

            // 更新PWM占空比（不改变方向）
            if (instance->start_pwm != (void *)0)
            {
                instance->start_pwm(instance->pwm_duty, instance->direction);
            }
        }
        // 不同方向：立即进入冷却，等待执行新方向
        else
        {
            // 立即停止当前驱动
            if (instance->stop_pwm != (void *)0)
            {
                instance->stop_pwm();
            }

            // 进入冷却状态
            instance->state = MOTOR_STEP_STATE_COOLDOWN;
            instance->timer_ms = 0;

            // 保存新请求的参数，设置请求标志
            instance->request_pending = 1;
            instance->pwm_duty = pwm_duty;
            instance->direction = direction;
            instance->drive_duration_ms = dirve_duration_ms;
            instance->cooldown_duration_ms = cooldown_duration_ms;
        }
    }
}

void motor_step_instance_start_non_preemptive(motor_step_instance_t *instance, const unsigned short pwm_duty, const motor_direction_et direction, const unsigned short drive_duration_ms, const unsigned short cooldown_duration_ms)
{
    // 只在空闲状态下启动电机
    if (instance->state == MOTOR_STEP_STATE_IDLE)
    {
        instance->request_pending = 1;
        instance->timer_ms = 0;
        instance->pwm_duty = pwm_duty;
        instance->direction = direction;
        instance->drive_duration_ms = drive_duration_ms;
        instance->cooldown_duration_ms = cooldown_duration_ms;
    }
    // 其他状态不做任何操作，等待当前操作完成
}

/* 新增函数：创建电机往复运动控制实例 */
motor_recip_instance_t *motor_recip_instance_create(const void (*start_pwm)(unsigned short duty, motor_direction_et dir), const void (*stop_pwm)(void))
{
    if (motor_recip_instance_count >= MAX_MOTOR_INSTANCES)
    {
        return (void *)0;
    }

    motor_recip_instance_t *instance = &motor_recip_instances[motor_recip_instance_count++];
    instance->state = MOTOR_RECIP_STATE_IDLE;
    instance->timer_ms = 0;
    instance->request_pending = 0;
    instance->running = 0;
    instance->pwm_duty = 0;
    instance->forward_duration_ms = 0;
    instance->backward_duration_ms = 0;
    instance->cooldown_duration_ms = 0;
    instance->start_pwm = start_pwm;
    instance->stop_pwm = stop_pwm;

    return instance;
}

/* 新增函数：启动电机往复运动控制 */
void motor_recip_instance_start(motor_recip_instance_t *instance, const unsigned short pwm_duty, const unsigned short forward_move_duration_ms, const unsigned short backward_move_duration_ms, const unsigned short cooldown_duration_ms)
{
    // 空闲状态：直接启动
    if (instance->state == MOTOR_RECIP_STATE_IDLE)
    {
        instance->request_pending = 1;
        instance->running = 1;
        instance->timer_ms = 0;
        instance->pwm_duty = pwm_duty;
        instance->forward_duration_ms = forward_move_duration_ms;
        instance->backward_duration_ms = backward_move_duration_ms;
        instance->cooldown_duration_ms = cooldown_duration_ms;
    }
    // 运行状态：更新参数
    else if (instance->running)
    {
        // 更新参数
        instance->pwm_duty = pwm_duty;
        instance->forward_duration_ms = forward_move_duration_ms;
        instance->backward_duration_ms = backward_move_duration_ms;
        instance->cooldown_duration_ms = cooldown_duration_ms;

        // 立即停止当前动作
        if (instance->stop_pwm != (void *)0)
        {
            instance->stop_pwm();
        }

        // 重置到空闲状态，以便重新开始往复运动
        instance->state = MOTOR_RECIP_STATE_IDLE;
        instance->timer_ms = 0;
        instance->request_pending = 1;
    }
}

/* 新增函数：启动电机往复运动控制（非抢占式） */
void motor_recip_instance_start_non_preemptive(motor_recip_instance_t *instance, const unsigned short pwm_duty, const unsigned short forward_move_duration_ms, const unsigned short backward_move_duration_ms, const unsigned short cooldown_duration_ms)
{
    // 只在空闲状态下启动电机
    if (instance->state == MOTOR_RECIP_STATE_IDLE && !instance->running)
    {
        instance->request_pending = 1;
        instance->running = 1;
        instance->timer_ms = 0;
        instance->pwm_duty = pwm_duty;
        instance->forward_duration_ms = forward_move_duration_ms;
        instance->backward_duration_ms = backward_move_duration_ms;
        instance->cooldown_duration_ms = cooldown_duration_ms;
    }
    // 其他状态不做任何操作，等待当前操作完成
}

/* 新增函数：停止电机往复运动 */
void motor_recip_instance_stop(motor_recip_instance_t *instance)
{
    if (instance->running)
    {
        // 停止电机
        if (instance->stop_pwm != (void *)0)
        {
            instance->stop_pwm();
        }

        // 重置状态
        instance->running = 0;
        instance->state = MOTOR_RECIP_STATE_IDLE;
        instance->timer_ms = 0;
        instance->request_pending = 0;
    }
}

void motor_step_update(unsigned short elapse_ms)
{
    // 更新步进电机控制实例
    for (unsigned char i = 0; i < motor_step_instance_count; i++)
    {
        motor_step_instance_t *instance = &motor_step_instances[i];
        if (instance == (void *)0 || instance->start_pwm == (void *)0 || instance->stop_pwm == (void *)0)
        {
            continue; // 跳过无效的实例或驱动
        }

        switch (instance->state)
        {
        case MOTOR_STEP_STATE_IDLE:
            if (instance->request_pending)
            {
                instance->start_pwm(instance->pwm_duty, instance->direction);
                instance->state = MOTOR_STEP_STATE_DRIVING;
                instance->timer_ms = 0;
                instance->request_pending = 0;
            }
            break;
        case MOTOR_STEP_STATE_DRIVING:
            instance->timer_ms += elapse_ms;
            if (instance->timer_ms >= instance->drive_duration_ms)
            {
                instance->stop_pwm();
                instance->state = MOTOR_STEP_STATE_COOLDOWN;
                instance->timer_ms = 0;
            }
            break;
        case MOTOR_STEP_STATE_COOLDOWN:
            instance->timer_ms += elapse_ms;
            if (instance->timer_ms >= instance->cooldown_duration_ms)
            {
                instance->state = MOTOR_STEP_STATE_IDLE;
                instance->timer_ms = 0;
            }
            break;
        default:
            break;
        }
    }

    // 更新往复运动电机控制实例
    for (unsigned char i = 0; i < motor_recip_instance_count; i++)
    {
        motor_recip_instance_t *instance = &motor_recip_instances[i];
        if (instance == (void *)0 || instance->start_pwm == (void *)0 || instance->stop_pwm == (void *)0 || !instance->running)
        {
            continue; // 跳过无效的实例或驱动或未运行的实例
        }

        switch (instance->state)
        {
        case MOTOR_RECIP_STATE_IDLE:
            if (instance->request_pending)
            {
                // 开始正向驱动
                instance->start_pwm(instance->pwm_duty, MOTOR_DIR_FORWARD);
                instance->state = MOTOR_RECIP_STATE_FORWARD;
                instance->timer_ms = 0;
                instance->request_pending = 0;
            }
            break;
        case MOTOR_RECIP_STATE_FORWARD:
            instance->timer_ms += elapse_ms;
            if (instance->timer_ms >= instance->forward_duration_ms)
            {
                // 正向驱动结束，进入冷却
                instance->stop_pwm();
                instance->state = MOTOR_RECIP_STATE_FORWARD_COOLDOWN;
                instance->timer_ms = 0;
            }
            break;
        case MOTOR_RECIP_STATE_FORWARD_COOLDOWN:
            instance->timer_ms += elapse_ms;
            if (instance->timer_ms >= instance->cooldown_duration_ms)
            {
                // 冷却结束，开始反向驱动
                instance->start_pwm(instance->pwm_duty, MOTOR_DIR_BACKWARD);
                instance->state = MOTOR_RECIP_STATE_BACKWARD;
                instance->timer_ms = 0;
            }
            break;
        case MOTOR_RECIP_STATE_BACKWARD:
            instance->timer_ms += elapse_ms;
            if (instance->timer_ms >= instance->backward_duration_ms)
            {
                // 反向驱动结束，进入冷却
                instance->stop_pwm();
                instance->state = MOTOR_RECIP_STATE_BACKWARD_COOLDOWN;
                instance->timer_ms = 0;
            }
            break;
        case MOTOR_RECIP_STATE_BACKWARD_COOLDOWN:
            instance->timer_ms += elapse_ms;
            if (instance->timer_ms >= instance->cooldown_duration_ms)
            {
                // 一个完整往复周期结束，回到正向驱动
                instance->start_pwm(instance->pwm_duty, MOTOR_DIR_FORWARD);
                instance->state = MOTOR_RECIP_STATE_FORWARD;
                instance->timer_ms = 0;
            }
            break;
        default:
            break;
        }
    }
}
