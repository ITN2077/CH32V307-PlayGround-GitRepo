#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

#include "zf_common_headfile.h"

// 引脚定义
#define ONEWIRE_PIN A8

unsigned char OneWire_Init(void);
void OneWire_SendBit(unsigned char Bit);
unsigned char OneWire_ReceiveBit(void);
void OneWire_SendByte(unsigned char Byte);
unsigned char OneWire_ReceiveByte(void);

#endif
