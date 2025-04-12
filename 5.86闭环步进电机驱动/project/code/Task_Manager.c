#include "Task_Manager.h"

//!----------------🍅🍅🍅🍅🍅🍅  START 🍒🍒🍒🍒🍒🍒---------串口数据包任务使用的⬇️⬇️⬇️⬇️⬇️⬇️
#define NumOfMsg 2 // 定义串口接收的数据要解析的数据的个数
int test_value_1 = 0;
float test_value_2 = 0.000;

PacketTag_TpDef_struct Test_packet[] = {
    {"1", UnpackData_Handle_Int_FireWater, &test_value_1},
    {"2", UnpackData_Handle_Float_FireWater, &test_value_2},
    // 添加更多的映射关系
};

//!------------------✨✨✨✨✨✨  END 🌸🌸🌸🌸🌸🌸---------串口数据包任务使用的⬆️⬆️⬆️⬆️⬆️⬆️

//!------------------🍅🍅🍅🍅🍅🍅   START  🍒🍒🍒🍒🍒🍒---------非时间片轮询任务调度函数⬇️⬇️⬇️⬇️⬇️⬇️
/**
 *  @brief 全部外设的初始化
 */
void PeripheraAll_Init()
{
    uart_init(DEBUG_UART_INDEX, DEBUG_UART_BAUDRATE, DEBUG_UART_TX_PIN, DEBUG_UART_RX_PIN); // 串口初始化
    uart_rx_interrupt(DEBUG_UART_INDEX, ENABLE);                                            // 开启接收中断
    interrupt_set_priority(UART8_IRQn, (0 << 5) || 1);                                      // 设置usart3的中断优先级
    ring_buffer_init(&ringbuffer_UART_DEBUG, ringbuffer_place_UART_DEBUG, RINGBUFFER_SIZE); // 环形缓冲区初始化 V1.1添加
    printf_USART_DEBUG("hello,WSY!");
    system_delay_ms(2000);
    printf_USART_DEBUG("hello,WSY!");

    pit_ms_init(TIM6_PIT, 10);            // 定时器6初始化，提供软实时任务调度系统节拍
    interrupt_set_priority(TIM6_IRQn, 0); // 最高中断优先级
    // pit_ms_init(TIM7_PIT, 50);            // 定时器七初始化，用于硬实时任务调度
    // interrupt_set_priority(TIM7_IRQn, 0);

    // 临时初始化
    gpio_init(A1, GPO, GPIO_HIGH, GPO_PUSH_PULL); // 旋转方向
    pwm_init(TIM9_PWM_MAP0_CH3_A4, 1, 0); //硬件pwm输出脉冲
    gpio_init(A3, GPO, GPIO_HIGH, GPO_PUSH_PULL); // 电机控制器使能

    // gpio_init(E2, GPI, GPIO_LOW, GPI_PULL_DOWN);//编码器CLK
    gpio_init(E4, GPI, GPIO_LOW, GPI_PULL_DOWN); // 编码器DT

    exti_enable(E2);
    exti_init(E2, EXTI_TRIGGER_BOTH);
                                
    key_init(20); // 按键初始化，20ms一次中断
    gpio_init(E0, GPI, GPIO_LOW, GPI_PULL_DOWN); // 按键

    oled_init(); // oled初始化
    // END

    // timer_init(TIM_5, TIMER_US); // 初始化定时器5用于计时

    // Task_Disable();  // 定时器中断失能。即所有实时任务停止

    oled_set_font(OLED_8X16_FONT);
    oled_show_string(0, 0, "RPM:");
    oled_show_string(4, 4, "Hi CZZ prince");
}

// 更新转速及脉冲间隔
void update_speed(int set_num)
{
    set_num = set_num * 6.67;
    // 根据正负决定方向
    if (set_num < 0)
    {
        gpio_set_level(A1, 0); // 反转
        set_num = -set_num;
        pwm_set_freq(TIM9_PWM_MAP0_CH3_A4, set_num, 5000);
    }
    else if (set_num == 0)
    {
        pwm_set_freq(TIM9_PWM_MAP0_CH3_A4, 1, 0);
    }
    else
    {
        gpio_set_level(A1, 1); // 正转
        pwm_set_freq(TIM9_PWM_MAP0_CH3_A4, set_num, 5000);
    }
}
//!------------------✨✨✨✨✨✨  END 🌸🌸🌸🌸🌸🌸---------非时间片轮询任务调度函数⬆️⬆️⬆️⬆️⬆️⬆️

//!------------------🍅🍅🍅🍅🍅🍅  START 🍒🍒🍒🍒🍒🍒---------时间片轮询任务调度⬇️⬇️⬇️⬇️⬇️⬇️
STR_XxxTimeSliceOffset While_task, Uart_task, Speed_task, Key_task; // 创建任务句柄
/**
 * @brief While 循环，无定时任务，全速运行。
 *
 */
void While_Task(void)
{
    //写入while循环任务
}
/**
 *  @brief 串口数据包处理任务函数
 *  @note  务必设置为无定时任务，全速运行防止缓冲区溢出。全部注释就不运行。
 */
void UART_packet_TASKhandler(void)
{
    UART_DEBUG_Ringbuffer_Processer();
    if (UART_DEBUG_data_packet_ready)
    {
        UART_DEBUG_data_packet_ready = false;
        PacketTag_Analysis(Test_packet, NumOfMsg); // 此处NumOfMsg在串口数据包初始化处定义。
        DebugPrint();                              // 输出接收的数据
        printf_USART_DEBUG("\r\ntestv1:%d\r\n", test_value_1);
        printf_USART_DEBUG("\r\ntestv2:%f\r\n", test_value_2);
    }
}
/**
 * @brief 转速调控应用函数
 *
 */
void control_Speed(void)
{
    oled_show_int(35, 0, test_value_1, 6);
    update_speed(test_value_1);
}
/**
 *  @brief 按键扫描、处理任务
 *  @param
 *  @return
 *  @note
 *  @warning
 */
void key_Processing(void)
{
    key_scanner();
    if (KEY_SHORT_PRESS == key_get_state(KEY_1)) // 按键1短按
    {
        if (test_value_1 > 0)
        {
            for (int i = test_value_1; i > 0; i -= 10)
            {
                test_value_1 -= 10; // 每步减少10
                if (test_value_1 < 0)
                {
                    test_value_1 = 0; // 避免负数
                }
                control_Speed();
                system_delay_ms(30); // 30 次/秒
            }
        }
        else
        {
            for (int i = test_value_1; i < 0; i += 10)
            {
                test_value_1 += 10; // 每步减少10
                if (test_value_1 > 0)
                {
                    test_value_1 = 0; // 避免
                }
                control_Speed();
                system_delay_ms(30); // 30 次/秒
            }
        }
    }
}

//!------------------✨✨✨✨✨✨  END 🌸🌸🌸🌸🌸🌸---------时间片轮询任务调度⬆️⬆️⬆️⬆️⬆️⬆️
// 外部中断回调函数（当 CLK 变化时触发）
void EXTI_Handler(void)
{
    // 上升沿
    //  if (gpio_get_level(E4) == 1)
    //  {
    //      test_value_1++; // 顺时针旋转
    //  }
    //  else
    //  {
    //      test_value_1--; // 逆时针旋转
    //  }
    // 双边
    static int lastCLK = 0;
    int currentCLK = gpio_get_level(E2);

    if (currentCLK == 1 && lastCLK == 0)
    { // 检测 CLK 上升沿
        if (gpio_get_level(E4) == 1)
        {
            test_value_1 = test_value_1 - 10; // 顺时针
        }
        else
        {
            test_value_1 = test_value_1 + 10; // 逆时针
        }
    }

    lastCLK = currentCLK; // 记录上次状态
    // oled_show_int(0, 0, test_value_1, 5);
}
