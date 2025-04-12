/*********************************************************************************************************************
默认DEBUG串口是UART8

 ********************************************************************************************************************/
#include "zf_common_headfile.h"

int test_value_1 = 0;
float test_value_2 = 0.000;

PacketTag_TpDef_struct Test_packet[] = {
    {"1", UnpackData_Handle_Int_FireWater, &test_value_1},
    {"2", UnpackData_Handle_Float_FireWater, &test_value_2},
    // 添加更多的映射关系
};


int main(void)
{
    clock_init(SYSTEM_CLOCK_120M);                                                          // 初始化芯片时钟 工作频率为 120MHz
    debug_init();                                                                           // 务必保留，本函数用于初始化MPU 时钟 调试串口
    uart_init(DEBUG_UART_INDEX, DEBUG_UART_BAUDRATE, DEBUG_UART_TX_PIN, DEBUG_UART_RX_PIN); // 串口初始化
    uart_rx_interrupt(DEBUG_UART_INDEX, ENABLE);                                            // 开启接收中断
    interrupt_set_priority(UART8_IRQn, (0 << 5) || 1);                                      // 设置uart的中断优先级
    ring_buffer_init(&ringbuffer_UART_DEBUG, ringbuffer_place_UART_DEBUG, RINGBUFFER_SIZE); // 环形缓冲区初始化 V1.1添加
    printf_USART_DEBUG("hello,WSY!");
    system_delay_ms(2000);
    printf_USART_DEBUG("hello,WSY!");

    // 用户初始化
    gpio_init(A1, GPO, GPIO_HIGH, GPO_PUSH_PULL); // 旋转方向
    gpio_init(A5, GPO, GPIO_LOW, GPO_PUSH_PULL);  // 脉冲
    gpio_init(A3, GPO, GPIO_HIGH, GPO_PUSH_PULL); // 电机控制器使能
    // END

    while (1)
    {
        // 此处编写需要循环执行的代码
        UART_DEBUG_Ringbuffer_Processer();
        if (UART_DEBUG_data_packet_ready)
        {
            UART_DEBUG_data_packet_ready = false;
            PacketTag_Analysis(Test_packet, 2);
            DebugPrint(); // 输出接收的数据
            printf_USART_DEBUG("\r\ntestv1:%d\r\n", test_value_1);
            printf_USART_DEBUG("\r\ntestv2:%f\r\n", test_value_2);
        }

        // pulse(test_value_1);

        gpio_set_level(A5, 1);
        system_delay_us(650);
        gpio_set_level(A5, 0);
        system_delay_us(650);

        // 此处编写需要循环执行的代码
    }
}
