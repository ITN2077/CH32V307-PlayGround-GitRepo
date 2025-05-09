#include "weight_sensor_ttl.h"

#define CMD_READ_AD 0xA1
#define CMD_READ_WEIGHT 0xA3
#define CMD_ZERO 0xAA
#define CMD_TARE 0xAB

#define CMD_START_BYTE 0xAA
#define CMD_END_BYTE 0xFF
#define CMD_RSP_LEN 10

static uint8_t calc_checksum(const uint8_t *data, uint8_t len)
{
    uint8_t checksum = 0;
    for (uint8_t i = 0; i < len; i++)
    {
        checksum ^= data[i];
    }
    return checksum;
}

static char send_command(WeightSensor_t *sensor, uint8_t cmd)
{
    uint8_t buf[5];
    buf[0] = cmd;
    buf[1] = sensor->address;
    buf[2] = cmd - 1;
    buf[3] = cmd + 1;
    buf[4] = calc_checksum(buf, 4);
    return sensor->send(buf, sizeof(buf)) == sizeof(buf) ? 0 : -1;
}

char WeightSensor_ReadAD(WeightSensor_t *sensor)
{
    return send_command(sensor, CMD_READ_AD);
}

char WeightSensor_ReadWeight(WeightSensor_t *sensor)
{
    return send_command(sensor, CMD_READ_WEIGHT);
}

char WeightSensor_Tare(WeightSensor_t *sensor)
{
    return send_command(sensor, CMD_TARE);
}

char WeightSensor_Zero(WeightSensor_t *sensor)
{
    return send_command(sensor, CMD_ZERO);
}

// 解析数据帧
// 返回0：解析成功
// 返回-1：解析失败
static char parse_frame(const char *frame, WeightSensor_t *sensor)
{
    const uint8_t *data = (const uint8_t *)frame;
    uint16_t checksum, calc = 0;

    if (!frame || !sensor)
        return -1;

    sensor->data.is_valid = false; // 初始化is_valid为false

    if (data[0] != CMD_START_BYTE || data[CMD_RSP_LEN - 1] != CMD_END_BYTE)
        return -1;

    for (int i = 1; i < 7; i++)
        calc += data[i];
    checksum = (data[7] << 8) | data[8];
    if (calc != checksum)
        return -1;

    sensor->data.command = data[1];
    sensor->address = data[2];
    sensor->data.is_negative = (data[3] == 1);
    sensor->data.value = ((uint32_t)data[4] << 16) | ((uint32_t)data[5] << 8) | data[6];
    if (sensor->data.is_negative)
        sensor->data.value = -sensor->data.value;
    if (sensor->data.command == 0xA1)
    {
        // 计算压力值
        // TODO：需要优化，当前步进21
        int32_t v = sensor->data.value >> 13;
        int32_t v_result = -((v << 4) + (v << 2) + v); // 代替 *(20)，纯整数，无乘法、无浮点
        int32_t v_zero = sensor->zero_value >> 13;
        int32_t v_result_zero = -((v_zero << 4) + (v_zero << 2) + v_zero); // 代替 *(20)，纯整数，无乘法、无浮点
        sensor->data.pressure = v_result - v_result_zero;
    }
    sensor->data.is_valid = true;
    return 0;
}

// 从环形缓冲区中解析数据帧
// 返回0：环形缓冲区中没有数据
// 返回-1：解析失败
// 返回1：解析成功
char WeightSensor_ParseFromRingBuffer(ring_buffer_t *buffer, WeightSensor_t *sensor)
{
    uint8_t frame[CMD_RSP_LEN], byte;
    ring_buffer_size_t count = ring_buffer_num_items(buffer);
    int i, j;
    if (!buffer || !sensor || count < CMD_RSP_LEN)
        return -1;

    for (i = 0; i <= count - CMD_RSP_LEN; i++)
    {
        if (ring_buffer_peek(buffer, &byte, i) == 0 || byte != CMD_START_BYTE)
            continue;
        if (ring_buffer_peek(buffer, &byte, i + CMD_RSP_LEN - 1) == 0 || byte != CMD_END_BYTE)
            continue;

        for (j = 0; j < CMD_RSP_LEN; j++)
        {
            if (ring_buffer_peek(buffer, &frame[j], i + j) == 0)
                return -1;
        }

        if (parse_frame((const char *)frame, sensor) == 0)
        {
            for (j = 0; j <= i + CMD_RSP_LEN - 1; j++)
                ring_buffer_dequeue(buffer, &byte);
            return 1;
        }
        else
        {
            ring_buffer_dequeue(buffer, &byte);
            return -1;
        }
    }

    return 0;
}

// /* 处理传感器数据的函数 */
// void handle_sensor_data(WeightSensor_t *sensor)
// {
//     if (!sensor->data.is_valid)
//     {
//         return;
//     }
//     switch (sensor->data.command)
//     {
//     case 0xA1: /* 读取AD值响应 */
//         printf_USART_DEBUG("  ad: %d\n", sensor->data.value);
//         break;

//     case 0xA3: /* 读取重量响应 */

//         printf_USART_DEBUG("  weight: %d\n", sensor->data.value);
//         break;

//     case 0xAA: /* 零点校准响应 */

//         printf_USART_DEBUG("  zero: %d\n", sensor->data.value);
//         break;

//     case 0xAB: /* 去皮操作响应 */

//         printf_USART_DEBUG("  tare: %d\n", sensor->data.value);
//         break;

//     default:

//         break;
//     }
// }

