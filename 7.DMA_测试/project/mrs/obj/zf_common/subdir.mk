################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_clock.c \
c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_debug.c \
c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_fifo.c \
c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_font.c \
c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_function.c \
c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_interrupt.c 

C_DEPS += \
./zf_common/zf_common_clock.d \
./zf_common/zf_common_debug.d \
./zf_common/zf_common_fifo.d \
./zf_common/zf_common_font.d \
./zf_common/zf_common_function.d \
./zf_common/zf_common_interrupt.d 

OBJS += \
./zf_common/zf_common_clock.o \
./zf_common/zf_common_debug.o \
./zf_common/zf_common_fifo.o \
./zf_common/zf_common_font.o \
./zf_common/zf_common_function.o \
./zf_common/zf_common_interrupt.o 



# Each subdirectory must supply rules for building sources it contributes
zf_common/zf_common_clock.o: c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_clock.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_components" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Ld" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Peripheral" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Startup" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/user/inc" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_device" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_debug.o: c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_debug.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_components" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Ld" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Peripheral" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Startup" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/user/inc" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_device" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_fifo.o: c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_fifo.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_components" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Ld" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Peripheral" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Startup" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/user/inc" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_device" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_font.o: c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_font.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_components" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Ld" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Peripheral" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Startup" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/user/inc" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_device" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_function.o: c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_function.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_components" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Ld" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Peripheral" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Startup" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/user/inc" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_device" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_interrupt.o: c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common/zf_common_interrupt.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_components" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Ld" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Peripheral" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Startup" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/user/inc" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_device" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

