################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core/core_riscv.c 

C_DEPS += \
./sdk/Core/core_riscv.d 

OBJS += \
./sdk/Core/core_riscv.o 



# Each subdirectory must supply rules for building sources it contributes
sdk/Core/core_riscv.o: c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core/core_riscv.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_components" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Ld" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Peripheral" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Startup" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/user/inc" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_device" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

