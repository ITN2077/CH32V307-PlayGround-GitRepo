################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components/seekfree_assistant.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components/seekfree_assistant_interface.c 

C_DEPS += \
./zf_components/seekfree_assistant.d \
./zf_components/seekfree_assistant_interface.d 

OBJS += \
./zf_components/seekfree_assistant.o \
./zf_components/seekfree_assistant_interface.o 



# Each subdirectory must supply rules for building sources it contributes
zf_components/seekfree_assistant.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components/seekfree_assistant.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_components/seekfree_assistant_interface.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components/seekfree_assistant_interface.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

