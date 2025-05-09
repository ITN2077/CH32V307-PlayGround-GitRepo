#include "limit_switch_interface.h"

#define LS1U_PIN E0
#define LS1D_PIN E1
#define LS2D_PIN E2
#define LS3_PIN E3
#define LS4_PIN E4

// M1上限位开关平台接口实现
static void LS1U_Init(void)
{
    // 可选初始化 GPIO 为输入
    gpio_init(LS1U_PIN, GPI, 0, GPI_PULL_UP);
}
static bool LS1U_Read(void)
{
    return gpio_get_level(LS1U_PIN) == 0; // 按键按下为低电平，按下返回ture，没按下返回false
}
// 限位开关实例
LimitSwitch_t limit_ls1u = {
    .init = LS1U_Init,
    .read_pin = LS1U_Read,
    .stable_count_required = 3, // 3 个周期一致即为稳定（如 10ms ×3 = 30ms 消抖）
    .name = "LS1_U"};
//M1下限位开关平台接口实现
static void LS1D_Init(void)
{
    gpio_init(LS1D_PIN, GPI, 0, GPI_PULL_UP);
}
static bool LS1D_Read(void)
{
    return gpio_get_level(LS1D_PIN) == 0; // 按键按下为低电平，按下返回ture，没按下返回false
}
LimitSwitch_t limit_ls1d = {
    .init = LS1D_Init,
    .read_pin = LS1D_Read,
    .stable_count_required = 3, // 3 个周期一致即为稳定（如 10ms ×3 = 30ms 消抖）
    .name = "LS1_D"};

//M2下限位开关平台接口实现
static void LS2D_Init(void)
{
    gpio_init(LS2D_PIN, GPI, 0, GPI_PULL_UP);
}   
static bool LS2D_Read(void)
{
    return gpio_get_level(LS2D_PIN) == 0; // 按键按下为低电平，按下返回ture，没按下返回false
}
LimitSwitch_t limit_ls2d = {
    .init = LS2D_Init,
    .read_pin = LS2D_Read,
    .stable_count_required = 3, // 3 个周期一致即为稳定（如 10ms ×3 = 30ms 消抖）
    .name = "LS2_D"};
//M3零位限位开关平台接口实现
static void LS3_Init(void)
{
    gpio_init(LS3_PIN, GPI, 0, GPI_PULL_UP);
}
static bool LS3_Read(void)
{
    return gpio_get_level(LS3_PIN) == 0; // 按键按下为低电平，按下返回ture，没按下返回false
}
LimitSwitch_t limit_ls3 = {
    .init = LS3_Init,
    .read_pin = LS3_Read,
    .stable_count_required = 3, // 3 个周期一致即为稳定（如 10ms ×3 = 30ms 消抖）
    .name = "LS3"};
//M4零位限位开关平台接口实现
static void LS4_Init(void)
{
    gpio_init(LS4_PIN, GPI, 0, GPI_PULL_UP);
}
static bool LS4_Read(void)
{
    return gpio_get_level(LS4_PIN) == 0; // 按键按下为低电平，按下返回ture，没按下返回false
}
LimitSwitch_t limit_ls4 = {
    .init = LS4_Init,
    .read_pin = LS4_Read,
    .stable_count_required = 3, // 3 个周期一致即为稳定（如 10ms ×3 = 30ms 消抖）
    .name = "LS4"};

