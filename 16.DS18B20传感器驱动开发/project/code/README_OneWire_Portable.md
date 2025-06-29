# 1-Wire模块平台解耦方案

## 概述

本项目实现了1-Wire单总线协议驱动的平台解耦，通过硬件抽象层（HAL）将1-Wire协议逻辑与具体硬件平台分离，提高了代码的可移植性和可维护性。

## 架构设计

### 分层结构

```
┌─────────────────────────────────────┐
│           应用层 (Application)       │
├─────────────────────────────────────┤
│        1-Wire协议层 (Protocol)      │
├─────────────────────────────────────┤
│        硬件抽象层 (HAL)             │
├─────────────────────────────────────┤
│        平台适配层 (Platform)        │
├─────────────────────────────────────┤
│        硬件驱动层 (Driver)          │
└─────────────────────────────────────┘
```

### 文件结构

```
OneWire_portable/
├── OneWire_hal.h              # 硬件抽象层接口定义
├── OneWire_hal.c              # 硬件抽象层管理实现
├── OneWire_portable.h         # 平台无关的1-Wire接口
├── OneWire_portable.c         # 平台无关的1-Wire实现
├── OneWire_platform_adapter.h # 平台适配层接口
├── OneWire_platform_adapter.c # 平台适配层实现
├── OneWire_example.c          # 使用示例
└── README_OneWire_Portable.md # 说明文档
```

## 核心特性

### 1. 硬件抽象层 (HAL)

- **平台无关接口**：定义了GPIO操作、延时、中断控制等通用接口
- **函数指针结构**：通过函数指针实现接口的动态绑定
- **类型安全**：使用标准C类型和自定义枚举确保类型安全

### 2. 平台适配层

- **接口映射**：将平台特定的接口映射到HAL接口
- **类型转换**：处理平台特定类型与HAL类型的转换
- **向后兼容**：保持与现有平台代码的兼容性

### 3. 协议层

- **设备句柄**：使用句柄管理多个1-Wire设备
- **错误处理**：统一的错误码和返回值处理
- **参数验证**：完善的参数检查和边界条件处理

## 使用方法

### 1. 初始化

```c
#include "OneWire_platform_adapter.h"
#include "OneWire_portable.h"

// 1-Wire设备句柄
onewire_handle_t onewire_dev;

// 初始化平台适配层
onewire_platform_init();

// 初始化1-Wire设备（使用PA0引脚）
onewire_init(&onewire_dev, A0);
```

### 2. 基本操作

```c
// 总线复位
int ret = onewire_reset(&onewire_dev);
if (ret == 0) {
    // 复位成功，有设备响应
} else if (ret == 1) {
    // 复位成功，但无设备响应
}

// 发送命令
onewire_send_command(&onewire_dev, 0xCC); // Skip ROM

// 接收数据
uint8_t data;
onewire_receive_byte(&onewire_dev, &data);

// 搜索设备
uint8_t rom_code[8];
onewire_search_rom(&onewire_dev, rom_code);
```

### 3. 完整通信流程

```c
int onewire_communication_example(void)
{
    int ret;
    uint8_t command = 0xCC; // Skip ROM command
    uint8_t data;
    
    // 1. 总线复位
    ret = onewire_reset(&onewire_dev);
    if (ret != 0) return ret;
    
    // 2. 发送命令
    ret = onewire_send_command(&onewire_dev, command);
    if (ret != 0) return ret;
    
    // 3. 接收数据
    ret = onewire_receive_byte(&onewire_dev, &data);
    if (ret != 0) return ret;
    
    return 0;
}
```

## 移植到新平台

### 1. 实现HAL接口

```c
// 新平台的HAL实现
static void new_platform_gpio_init(uint32_t pin, onewire_gpio_dir_t dir, 
                                  onewire_gpio_level_t level, onewire_gpio_mode_t mode)
{
    // 实现GPIO初始化
}

static void new_platform_gpio_set_level(uint32_t pin, onewire_gpio_level_t level)
{
    // 实现GPIO设置电平
}

static onewire_gpio_level_t new_platform_gpio_get_level(uint32_t pin)
{
    // 实现GPIO获取电平
}

static void new_platform_delay_us(uint32_t us)
{
    // 实现微秒延时
}

static void new_platform_disable_irq(void)
{
    // 实现中断禁用
}

static void new_platform_enable_irq(void)
{
    // 实现中断使能
}

// 新平台的HAL结构体
static const onewire_hal_t new_platform_hal = {
    .gpio_init = new_platform_gpio_init,
    .gpio_set_level = new_platform_gpio_set_level,
    .gpio_get_level = new_platform_gpio_get_level,
    .delay_us = new_platform_delay_us,
    .disable_irq = new_platform_disable_irq,
    .enable_irq = new_platform_enable_irq
};
```

### 2. 设置HAL接口

```c
// 在应用初始化时设置HAL接口
onewire_set_hal(&new_platform_hal);
```

## 优势

### 1. 可移植性
- **平台无关**：核心协议逻辑与硬件平台完全分离
- **易于移植**：只需实现HAL接口即可支持新平台
- **代码复用**：同一套协议代码可在多个平台使用

### 2. 可维护性
- **模块化设计**：清晰的层次结构和职责分离
- **接口稳定**：HAL接口稳定，减少对上层代码的影响
- **错误处理**：统一的错误处理机制

### 3. 可扩展性
- **多设备支持**：通过句柄支持多个1-Wire设备
- **功能扩展**：易于添加新的1-Wire协议功能
- **平台扩展**：支持添加新的硬件平台

### 4. 向后兼容
- **接口兼容**：保持与现有代码的兼容性
- **渐进迁移**：可以逐步迁移现有代码
- **风险可控**：降低迁移过程中的风险

## 注意事项

1. **初始化顺序**：必须先初始化平台适配层，再初始化1-Wire设备
2. **错误处理**：所有函数都有返回值，需要检查错误状态
3. **资源管理**：使用句柄管理设备，避免资源泄漏
4. **时序要求**：1-Wire协议对时序要求严格，HAL实现需要保证时序精度

## 总结

通过硬件抽象层实现平台解耦，1-Wire模块具备了良好的可移植性、可维护性和可扩展性。这种设计模式可以推广到其他硬件驱动模块，提高整个项目的代码质量。 