/*********************************************************************************************************************
 * 本模块借助USART3实现
 * 
 * 
 *
 * 修改记录
 * 
 * 日期                                      作者                             备注
 * 2024-03-24                               Sxxx
 ********************************************************************************************************************/
#include "zf_common_headfile.h"

#define LOAD_QUANTITY 18                       // 载荷大小
uint8_t UART3_get_data[LOAD_QUANTITY];         // 串口3接收的数据
volatile bool UART3_data_packet_ready = false; // 串口3接收完数据包的标志位

int test_value_2 = 0;
float test_value_1 = 0.000;

typedef void (*Function_Unpack_Handler)(const char *, void *); // 定义一个函数指针类型，间接调用整形、浮点型解包函数
void Function_Unpack_Handle_Float(const char *packet, void *value);
void Function_Unpack_Handle_Int(const char *packet, void *value);


typedef struct // 定义一个结构体来封装标签和挂接函数以及存储数值
{
    const char tag[5];
    Function_Unpack_Handler function_handler;
    void *value_ptr;
} PacketTag_TpDef_struct;

void PacketTag_Analysis(PacketTag_TpDef_struct Tag_packet[], uint8_t tag_length);
void printf_USART3(char *format_str, ...);

// 查找表,存储在结构体，第一个是标签，必须四个字符
PacketTag_TpDef_struct Test_packet[] = {
    {"TEST", Function_Unpack_Handle_Float, &test_value_1},
    {"TES1", Function_Unpack_Handle_Int, &test_value_2},
    // 添加更多的映射关系
};

int main(void)
{
    clock_init(SYSTEM_CLOCK_120M);                                                          // 初始化芯片时钟 工作频率为 120MHz
    debug_init();                                                                           // 务必保留，本函数用于初始化MPU 时钟 调试串口
    uart_init(DEBUG_UART_INDEX, DEBUG_UART_BAUDRATE, DEBUG_UART_TX_PIN, DEBUG_UART_RX_PIN); // 串口初始化
    uart_rx_interrupt(DEBUG_UART_INDEX, ENABLE);                                            // 开启接收中断
    interrupt_set_priority(USART3_IRQn, (0 << 5) || 1);                                     // 设置usart3的中断优先级
    uart_write_string(DEBUG_UART_INDEX, "Hello,world,start.\r\n");

    // 此处编写用户代码 例如外设初始化代码等

    // 此处编写用户代码 例如外设初始化代码等

    while (1)
    {
        // 此处编写需要循环执行的代码
        if (UART3_data_packet_ready)
        {
            UART3_data_packet_ready = false;
            printf_USART3("\r\nReturn:%s\r\n", UART3_get_data);
            PacketTag_Analysis(Test_packet,2);
            printf_USART3("\r\ntestv1:%f\r\n", test_value_1);
            printf_USART3("\r\ntestv2:%d\r\n", test_value_2);
        }
        // 此处编写需要循环执行的代码
    }
}

/**
 *  @brief 使用USART3的printf
 *  @param 格式化字符串
 *  @return void
 *  @warning
 *  @note 例子： printf_USART3("text:%d", 1212); 串口接收到 text:1212
 */
void printf_USART3(char *format_str, ...)
{
    uint8_t buffer[32];
    va_list arg;
    va_start(arg, format_str);
    vsprintf(buffer, format_str, arg);
    va_end(arg);
    uart_write_string(DEBUG_UART_INDEX, buffer);
}

void USART3_IRQ_Function(void)
{
    static uint8_t UART3_get_data_index = 0; // 串口数据包数据索引
    uint8_t byte = 0;
    static bool start_load_packet_flag = false; // 开始接收数据包的标志
    if (uart_query_byte(DEBUG_UART_INDEX, &byte))
    {
        if (byte == '@')
        {
            // 检测到数据包开始
            start_load_packet_flag = true;
            UART3_get_data_index = 0; // 重置索引
        }
        else if (byte == '#' && start_load_packet_flag)
        {
            // 检测到数据包结束
            UART3_get_data[UART3_get_data_index] = '\0';
            UART3_data_packet_ready = true;
            start_load_packet_flag = false;
            // 在这里，您可以处理数据包，因为它已经结束
            // 处理完毕后，您可能需要根据需要重置data_index
        }
        else if (start_load_packet_flag)
        {
            // 如果处于数据包接收模式，并且没有达到数据包结尾
            if (UART3_get_data_index < LOAD_QUANTITY - 1)
            {
                // 存储数据并增加索引
                UART3_get_data[UART3_get_data_index++] = byte;
            }
            else
            {
                // 数据溢出，清空数据包
                memset(UART3_get_data, 0, LOAD_QUANTITY); // 清空接收缓冲区
                UART3_data_packet_ready = false;
                UART3_get_data_index = 0; // 重置索引
                start_load_packet_flag = false;
                printf_USART3("Error: Data packet overflow.\r\n"); // 错误处理
            }
        }
    }
}

// 数据处理函数,模块内使用
void Function_Unpack_Handle_Float(const char *packet, void *value)
{
    char numString[LOAD_QUANTITY];                     // Assuming the maximum length of the number string is 20
    strncpy(numString, packet + 4, LOAD_QUANTITY - 1); // Copy the number part of the special string
                                                       // Convert the number string to a float
    *((float *)value) = atof(numString);
}

void Function_Unpack_Handle_Int(const char *packet, void *value)
{
    char numString[LOAD_QUANTITY];                     // Assuming the maximum length of the number string is 20
    strncpy(numString, packet + 4, LOAD_QUANTITY - 1); // Copy the number part of the special string
                                                       // Convert the number string to a float
    *((int *)value) = atoi(numString);
}

/**
 * @brief 对缓存包处理，包括标签匹配和数据使用。
 * @note  所有的标签都在这里列举处理。
 *
 */
void PacketTag_Analysis(PacketTag_TpDef_struct Tag_packet[], uint8_t tag_length)
{
    uint8_t i = 0;
    for (i = 0; i < tag_length; i++)
    {
        // 检查标签是否匹配
        if (strncmp(UART3_get_data, Tag_packet[i].tag, 4) == 0)
        {
            // 调用关联的处理函数
            Tag_packet[i].function_handler(UART3_get_data, Tag_packet[i].value_ptr);
            return; // 找到匹配项后返回
        }
    }
    uint8_t error_tag[5] = {0};
    strncpy(error_tag, UART3_get_data, 4);
    error_tag[4] = '\0';                                 // 显式地设置空终止符
    printf_USART3("The \"%s\" is not find.", error_tag); // 错误处理
    // 如果没有找到任何匹配，可以在这里处理错误
    // U1_printf("The \"%s\" is not find.", Tag_packet[i].tag);
}
