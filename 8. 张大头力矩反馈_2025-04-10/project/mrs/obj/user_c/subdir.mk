################################################################################
# MRS Version: 1.9.2
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/user/src/isr.c \
X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/user/src/main.c 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/user/src/isr.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\Libraries\doc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_components" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Core" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Ld" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Peripheral" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Startup" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\user\inc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_common" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_device" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\code" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user_c/main.o: X:/200-计算机科学/1嵌入式系统/100-MCU嵌入式系统/6WCH-CH32V307VCT6/1.项目集/8.\ 张大头力矩反馈_2025-04-10/project/user/src/main.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\Libraries\doc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_components" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Core" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Ld" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Peripheral" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\sdk\Startup" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\user\inc" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_common" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_device" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\project\code" -I"X:\200-计算机科学\1嵌入式系统\100-MCU嵌入式系统\6WCH-CH32V307VCT6\1.项目集\8. 张大头力矩反馈_2025-04-10\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

