################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code/Ring_Buffer.c \
z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code/Task_Manager.c \
z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code/UART_Data_Unpacker.c \
z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code/XxxTimeSliceOffset.c \
z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code/ZDT_X42_V2.c 

C_DEPS += \
./code/Ring_Buffer.d \
./code/Task_Manager.d \
./code/UART_Data_Unpacker.d \
./code/XxxTimeSliceOffset.d \
./code/ZDT_X42_V2.d 

OBJS += \
./code/Ring_Buffer.o \
./code/Task_Manager.o \
./code/UART_Data_Unpacker.o \
./code/XxxTimeSliceOffset.o \
./code/ZDT_X42_V2.o 



# Each subdirectory must supply rules for building sources it contributes
code/Ring_Buffer.o: z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code/Ring_Buffer.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_components" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Core" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Ld" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Peripheral" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Startup" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/user/inc" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_common" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_device" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
code/Task_Manager.o: z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code/Task_Manager.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_components" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Core" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Ld" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Peripheral" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Startup" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/user/inc" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_common" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_device" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
code/UART_Data_Unpacker.o: z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code/UART_Data_Unpacker.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_components" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Core" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Ld" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Peripheral" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Startup" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/user/inc" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_common" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_device" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
code/XxxTimeSliceOffset.o: z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code/XxxTimeSliceOffset.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_components" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Core" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Ld" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Peripheral" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Startup" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/user/inc" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_common" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_device" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
code/ZDT_X42_V2.o: z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code/ZDT_X42_V2.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_components" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Core" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Ld" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Peripheral" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Startup" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/user/inc" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_common" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_device" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

