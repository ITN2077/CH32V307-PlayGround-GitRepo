################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_adc.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_delay.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_dvp.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_encoder.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_exti.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_flash.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_gpio.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_iic.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_pit.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_pwm.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_soft_iic.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_soft_spi.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_spi.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_timer.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_uart.c \
c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_usb_cdc.c 

C_DEPS += \
./zf_driver/zf_driver_adc.d \
./zf_driver/zf_driver_delay.d \
./zf_driver/zf_driver_dvp.d \
./zf_driver/zf_driver_encoder.d \
./zf_driver/zf_driver_exti.d \
./zf_driver/zf_driver_flash.d \
./zf_driver/zf_driver_gpio.d \
./zf_driver/zf_driver_iic.d \
./zf_driver/zf_driver_pit.d \
./zf_driver/zf_driver_pwm.d \
./zf_driver/zf_driver_soft_iic.d \
./zf_driver/zf_driver_soft_spi.d \
./zf_driver/zf_driver_spi.d \
./zf_driver/zf_driver_timer.d \
./zf_driver/zf_driver_uart.d \
./zf_driver/zf_driver_usb_cdc.d 

OBJS += \
./zf_driver/zf_driver_adc.o \
./zf_driver/zf_driver_delay.o \
./zf_driver/zf_driver_dvp.o \
./zf_driver/zf_driver_encoder.o \
./zf_driver/zf_driver_exti.o \
./zf_driver/zf_driver_flash.o \
./zf_driver/zf_driver_gpio.o \
./zf_driver/zf_driver_iic.o \
./zf_driver/zf_driver_pit.o \
./zf_driver/zf_driver_pwm.o \
./zf_driver/zf_driver_soft_iic.o \
./zf_driver/zf_driver_soft_spi.o \
./zf_driver/zf_driver_spi.o \
./zf_driver/zf_driver_timer.o \
./zf_driver/zf_driver_uart.o \
./zf_driver/zf_driver_usb_cdc.o 



# Each subdirectory must supply rules for building sources it contributes
zf_driver/zf_driver_adc.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_adc.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_delay.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_delay.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_dvp.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_dvp.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_encoder.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_encoder.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_exti.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_exti.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_flash.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_flash.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_gpio.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_gpio.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_iic.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_iic.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_pit.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_pit.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_pwm.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_pwm.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_soft_iic.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_soft_iic.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_soft_spi.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_soft_spi.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_spi.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_spi.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_timer.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_timer.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_uart.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_uart.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_usb_cdc.o: c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver/zf_driver_usb_cdc.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_components" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Core" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Ld" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Peripheral" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/sdk/Startup" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/user/inc" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_common" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_device" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/project/code" -I"c:/X��/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_����/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

