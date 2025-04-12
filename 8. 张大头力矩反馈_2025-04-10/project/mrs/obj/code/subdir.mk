################################################################################
# MRS Version: 1.9.2
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/code/Ring_Buffer.c \
X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/code/Task_Manager.c \
X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/code/UART_Data_Unpacker.c \
X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/code/XxxTimeSliceOffset.c \
X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/code/ZDT_X42_V2.c 

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
code/Ring_Buffer.o: X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/code/Ring_Buffer.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\Libraries\doc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_components" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Core" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Ld" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Peripheral" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Startup" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\user\inc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_common" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_device" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\code" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Task_Manager.o: X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/code/Task_Manager.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\Libraries\doc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_components" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Core" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Ld" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Peripheral" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Startup" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\user\inc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_common" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_device" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\code" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/UART_Data_Unpacker.o: X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/code/UART_Data_Unpacker.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\Libraries\doc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_components" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Core" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Ld" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Peripheral" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Startup" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\user\inc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_common" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_device" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\code" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/XxxTimeSliceOffset.o: X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/code/XxxTimeSliceOffset.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\Libraries\doc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_components" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Core" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Ld" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Peripheral" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Startup" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\user\inc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_common" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_device" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\code" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/ZDT_X42_V2.o: X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/code/ZDT_X42_V2.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\Libraries\doc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_components" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Core" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Ld" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Peripheral" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Startup" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\user\inc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_common" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_device" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\code" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

