################################################################################
# MRS Version: 1.9.2
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_adc.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_delay.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_dvp.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_encoder.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_exti.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_flash.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_gpio.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_iic.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_pit.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_pwm.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_soft_iic.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_soft_spi.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_spi.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_timer.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_uart.c \
X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_usb_cdc.c 

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


# Each subdirectory must supply rules for building sources it contributes
zf_driver/zf_driver_adc.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_delay.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_delay.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_dvp.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_dvp.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_encoder.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_encoder.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_exti.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_exti.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_flash.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_gpio.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_iic.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_iic.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_pit.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_pit.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_pwm.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_pwm.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_soft_iic.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_soft_iic.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_soft_spi.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_soft_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_spi.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_timer.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_timer.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_uart.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_uart.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_usb_cdc.o: X:/300-软件技术/205-我写的MCU程序/CH32/4.\ 通过MA860H驱动步进电机/libraries/zf_driver/zf_driver_usb_cdc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\4. 通过MA860H驱动步进电机\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

