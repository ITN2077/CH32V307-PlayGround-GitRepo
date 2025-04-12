################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code/Ring_Buffer.c \
c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code/Task_Manager.c \
c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code/UART_Data_Unpacker.c \
c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code/XxxTimeSliceOffset.c 

C_DEPS += \
./code/Ring_Buffer.d \
./code/Task_Manager.d \
./code/UART_Data_Unpacker.d \
./code/XxxTimeSliceOffset.d 

OBJS += \
./code/Ring_Buffer.o \
./code/Task_Manager.o \
./code/UART_Data_Unpacker.o \
./code/XxxTimeSliceOffset.o 



# Each subdirectory must supply rules for building sources it contributes
code/Ring_Buffer.o: c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code/Ring_Buffer.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_components" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Ld" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Peripheral" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Startup" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/user/inc" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_device" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
code/Task_Manager.o: c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code/Task_Manager.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_components" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Ld" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Peripheral" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Startup" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/user/inc" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_device" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
code/UART_Data_Unpacker.o: c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code/UART_Data_Unpacker.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_components" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Ld" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Peripheral" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Startup" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/user/inc" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_device" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
code/XxxTimeSliceOffset.o: c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code/XxxTimeSliceOffset.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_components" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Core" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Ld" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Peripheral" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/sdk/Startup" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/user/inc" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_common" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_device" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/project/code" -I"c:/X≈Ã/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_≤‚ ‘/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

