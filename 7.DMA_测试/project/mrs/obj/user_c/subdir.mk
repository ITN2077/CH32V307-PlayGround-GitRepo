################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/src/isr.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/src/main.c 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 

OBJS += \
./user_c/isr.o \
./user_c/main.o 



# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/src/isr.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
user_c/main.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/src/main.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

