################################################################################
# MRS Version: 1.9.2
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/300-软件技术/205-我写的MCU程序/CH32/6.张大头步进电机驱动/project/code/Ring_Buffer.c \
X:/300-软件技术/205-我写的MCU程序/CH32/6.张大头步进电机驱动/project/code/Task_Manager.c \
X:/300-软件技术/205-我写的MCU程序/CH32/6.张大头步进电机驱动/project/code/UART_Data_Unpacker.c \
X:/300-软件技术/205-我写的MCU程序/CH32/6.张大头步进电机驱动/project/code/XxxTimeSliceOffset.c \
X:/300-软件技术/205-我写的MCU程序/CH32/6.张大头步进电机驱动/project/code/ZDT_X42_V2.c 

OBJS += \
./code/Ring_Buffer.o \
./code/Task_Manager.o \
./code/UART_Data_Unpacker.o \
./code/XxxTimeSliceOffset.o \
./code/ZDT_X42_V2.o 

C_DEPS += \
./code/Ring_Buffer.d \
./code/Task_Manager.d \
./code/UART_Data_Unpacker.d \
./code/XxxTimeSliceOffset.d \
./code/ZDT_X42_V2.d 


# Each subdirectory must supply rules for building sources it contributes
code/Ring_Buffer.o: X:/300-软件技术/205-我写的MCU程序/CH32/6.张大头步进电机驱动/project/code/Ring_Buffer.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Task_Manager.o: X:/300-软件技术/205-我写的MCU程序/CH32/6.张大头步进电机驱动/project/code/Task_Manager.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/UART_Data_Unpacker.o: X:/300-软件技术/205-我写的MCU程序/CH32/6.张大头步进电机驱动/project/code/UART_Data_Unpacker.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/XxxTimeSliceOffset.o: X:/300-软件技术/205-我写的MCU程序/CH32/6.张大头步进电机驱动/project/code/XxxTimeSliceOffset.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/ZDT_X42_V2.o: X:/300-软件技术/205-我写的MCU程序/CH32/6.张大头步进电机驱动/project/code/ZDT_X42_V2.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\Libraries\doc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_components" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Core" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Ld" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Peripheral" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\sdk\Startup" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\project\user\inc" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_common" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_device" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\project\code" -I"X:\300-软件技术\205-我写的MCU程序\CH32\6.张大头步进电机驱动\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

