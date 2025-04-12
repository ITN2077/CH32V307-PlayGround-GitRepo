################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/Embedded\ folder/My\ programming\ files/CH32/2.环形缓冲区/project/code/UART_Data_Unpacker.c \
X:/Embedded\ folder/My\ programming\ files/CH32/2.环形缓冲区/project/code/ringbuffer.c 

OBJS += \
./code/UART_Data_Unpacker.o \
./code/ringbuffer.o 

C_DEPS += \
./code/UART_Data_Unpacker.d \
./code/ringbuffer.d 


# Each subdirectory must supply rules for building sources it contributes
code/UART_Data_Unpacker.o: X:/Embedded\ folder/My\ programming\ files/CH32/2.环形缓冲区/project/code/UART_Data_Unpacker.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\Libraries\doc" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\zf_components" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\sdk\Core" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\sdk\Ld" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\sdk\Peripheral" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\sdk\Startup" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\project\user\inc" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\zf_common" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\zf_device" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\project\code" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/ringbuffer.o: X:/Embedded\ folder/My\ programming\ files/CH32/2.环形缓冲区/project/code/ringbuffer.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\Libraries\doc" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\zf_components" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\sdk\Core" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\sdk\Ld" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\sdk\Peripheral" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\sdk\Startup" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\project\user\inc" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\zf_common" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\zf_device" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\project\code" -I"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

