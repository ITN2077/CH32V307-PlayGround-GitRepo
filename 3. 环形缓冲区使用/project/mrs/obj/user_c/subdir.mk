################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/Embedded\ folder/My\ programming\ files/CH32/3.\ 环形缓冲区使用/project/user/src/isr.c \
X:/Embedded\ folder/My\ programming\ files/CH32/3.\ 环形缓冲区使用/project/user/src/main.c 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: X:/Embedded\ folder/My\ programming\ files/CH32/3.\ 环形缓冲区使用/project/user/src/isr.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\Libraries\doc" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_components" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Core" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Ld" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Peripheral" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Startup" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\project\user\inc" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_common" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_device" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\project\code" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user_c/main.o: X:/Embedded\ folder/My\ programming\ files/CH32/3.\ 环形缓冲区使用/project/user/src/main.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\Libraries\doc" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_components" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Core" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Ld" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Peripheral" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\sdk\Startup" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\project\user\inc" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_common" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_device" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\project\code" -I"X:\Embedded folder\My programming files\CH32\3. 环形缓冲区使用\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

