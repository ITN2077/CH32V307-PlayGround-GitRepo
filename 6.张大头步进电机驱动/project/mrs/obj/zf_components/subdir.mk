################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_components/seekfree_assistant.c \
z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_components/seekfree_assistant_interface.c 

C_DEPS += \
./zf_components/seekfree_assistant.d \
./zf_components/seekfree_assistant_interface.d 

OBJS += \
./zf_components/seekfree_assistant.o \
./zf_components/seekfree_assistant_interface.o 



# Each subdirectory must supply rules for building sources it contributes
zf_components/seekfree_assistant.o: z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_components/seekfree_assistant.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_components" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Core" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Ld" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Peripheral" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Startup" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/user/inc" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_common" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_device" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_components/seekfree_assistant_interface.o: z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_components/seekfree_assistant_interface.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_components" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Core" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Ld" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Peripheral" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Startup" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/user/inc" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_common" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_device" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/project/code" -I"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

