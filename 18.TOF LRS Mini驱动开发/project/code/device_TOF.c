// ========================= device_TOF.c =========================
// TOF激光测距模块 数据解析实现文件
// 实现数据帧解析与滤波输出
// ===============================================================

#include "device_TOF.h"

#define TOF_FRAME_LENGTH 16        // 定义TOF数据帧长度
#define TOF_UART_RX_BUFFER_SIZE 64 // 环形缓冲区大小

// ========================= 环形缓冲区定义（内部实现） =========================
static ring_buffer_t TOF_UART_RX_BUFFER;                         // 环形缓冲区结构体
static uint8_t TOF_UART_RX_BUFFER_DATA[TOF_UART_RX_BUFFER_SIZE]; // 环形缓冲区数据存储
// ===============================================================

// ========================= 静态变量定义 =========================
static uint8_t frame_buffer[TOF_FRAME_LENGTH];            // TOF数据帧缓冲区
static uint8_t frame_index = 0;                           // TOF数据帧索引
static TOF_ParseState_t parse_state = WAIT_FOR_HEADER_57; // TOF数据帧解析状态
// ==============================================================

/**
 * @brief 初始化TOF设备层环形缓冲区
 */
void TOF_device_Init(void)
{
    ring_buffer_init(&TOF_UART_RX_BUFFER, TOF_UART_RX_BUFFER_DATA, TOF_UART_RX_BUFFER_SIZE);
}

/**
 * @brief 将接收到的字节存入环形缓冲区
 * @param byte 接收到的字节数据
 */
void TOF_device_Queue_Byte(uint8_t byte)
{
    ring_buffer_queue(&TOF_UART_RX_BUFFER, byte);
}

/**
 * @brief 阻塞式采集TOF激光测距模块数据，满10个有效值后滤波输出平均距离（单位mm）
 *
 * 本函数基于状态机逐字节解析TOF模块串口数据，采用阻塞式设计，会一直等待直到从环形缓冲区
 * 采集到10个有效距离（distance_status==1）数据。当累计到10个有效距离后，自动进行滤波
 * （去掉最大和最小各3个，剩余4个取平均），并返回平均值（单位mm）。
 *
 * 典型用法：在需要获取稳定距离数据的场景中调用，函数会阻塞直到获得滤波后的结果。
 *
 * @return uint32_t 经过滤波的平均距离（mm），如未采集满10个有效数据则返回0
 *
 * @note 本函数为阻塞式设计，调用后会等待直到收集到足够的有效数据。
 * @attention 调用前确保环形缓冲区已正确初始化并与串口接收机制配合使用。
 * @warning 函数会阻塞执行，不适合在实时性要求高的主循环中频繁调用。
 */
uint32_t TOF_device_Parse_Data(void)
{
    uint32_t distances[10] = {0}; // 有效距离缓存，每次调用都清空
    uint8_t count = 0;            // 有效数据计数器
    uint32_t result = 0;
    uint8_t byte;
    // 阻塞采集10个有效数据
    while (count < 10)
    {
        // 阻塞等待直到有数据可读
        while (ring_buffer_is_empty(&TOF_UART_RX_BUFFER))
        {
            ; // 忙等，可根据实际平台替换为低功耗等待
        }
        ring_buffer_dequeue(&TOF_UART_RX_BUFFER, (char *)&byte);

        switch (parse_state) // 根据当前帧解析状态执行不同的操作
        {
        case WAIT_FOR_HEADER_57: // 等待帧头57
            if (byte == 0x57)
                parse_state = WAIT_FOR_HEADER_00;
            break;

        case WAIT_FOR_HEADER_00: // 等待帧头00
            if (byte == 0x00)
                parse_state = WAIT_FOR_HEADER_FF;
            else if (byte == 0x57) // 可能是新帧头开始
                parse_state = WAIT_FOR_HEADER_00;
            else
                parse_state = WAIT_FOR_HEADER_57;
            break;

        case WAIT_FOR_HEADER_FF: // 等待帧头FF
            if (byte == 0xFF)
                parse_state = WAIT_FOR_HEADER_ID;
            else if (byte == 0x57) // 可能是新帧头开始
                parse_state = WAIT_FOR_HEADER_00;
            else
                parse_state = WAIT_FOR_HEADER_57;
            break;
        case WAIT_FOR_HEADER_ID:
            if (byte == 0x00)
            {
                frame_buffer[0] = 0x57;
                frame_buffer[1] = 0x00;
                frame_buffer[2] = 0xFF;
                frame_buffer[3] = 0x00;
                frame_index = 4;
                parse_state = READ_FRAME;
            }
            else if (byte == 0x57) // 可能是新帧头开始
                parse_state = WAIT_FOR_HEADER_00;
            else
                parse_state = WAIT_FOR_HEADER_57;
            break;

        case READ_FRAME:
            frame_buffer[frame_index++] = byte;
            if (frame_index == TOF_FRAME_LENGTH)
            {
                uint8_t checksum = 0;
                for (int i = 0; i < TOF_FRAME_LENGTH - 1; i++)
                    checksum += frame_buffer[i]; // 计算校验和

                if (checksum == frame_buffer[15]) // 如果校验和匹配
                {
                    uint32_t distance_mm = frame_buffer[8] | (frame_buffer[9] << 8) | (frame_buffer[10] << 16);
                    uint8_t distance_status = frame_buffer[11];
                    if (distance_status == 1)
                    {
                        distances[count++] = distance_mm;
                    }
                }
                parse_state = WAIT_FOR_HEADER_57;
                frame_index = 0;
            }
            break;
        default:
            parse_state = WAIT_FOR_HEADER_57;
            frame_index = 0;
            break;
        }
    }
    // 排序
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (distances[i] > distances[j])
            {
                uint32_t tmp = distances[i];
                distances[i] = distances[j];
                distances[j] = tmp;
            }
        }
    }
    // 去掉最大最小各3个，剩下4个求平均
    uint32_t sum = 0;
    for (int i = 3; i < 7; i++)
    {
        sum += distances[i];
    }
    result = sum / 4;
    return result;
}
// ==============================================================
