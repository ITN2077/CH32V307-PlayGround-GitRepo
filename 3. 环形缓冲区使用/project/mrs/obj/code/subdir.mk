################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/Embedded\ folder/My\ programming\ files/CH32/3.\ 环形缓冲区使用/project/code/Ring_Buffer.c \
X:/Embedded\ folder/My\ programming\ files/CH32/3.\ 环形缓冲区使用/project/code/UART_Data_Unpacker.c 

OBJS += \
./code/Ring_Buffer.o \
./code/UART_Data_Unpacker.o 

C_DEPS += \
./code/Ring_Buffer.d \
./code/UART_Data_Unpacker.d 


# Each subdirectory must supply rules for building sources it contributes
code/Ring_Buffer.o: X:/Embedded\ folder/My\ programming\ files/CH32/3.\ 环形缓冲区使用/project/code/Ring_Buffer.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\Libraries\doc" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_components" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Core" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Ld" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Peripheral" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Startup" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\project\user\inc" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_common" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_device" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\project\code" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/UART_Data_Unpacker.o: X:/Embedded\ folder/My\ programming\ files/CH32/3.\ 环形缓冲区使用/project/code/UART_Data_Unpacker.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\Libraries\doc" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_components" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Core" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Ld" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Peripheral" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Startup" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\project\user\inc" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_common" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_device" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\project\code" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

