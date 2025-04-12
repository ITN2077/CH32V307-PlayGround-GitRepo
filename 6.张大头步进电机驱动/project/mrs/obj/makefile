################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################
-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include zf_driver/subdir.mk
-include zf_device/subdir.mk
-include zf_components/subdir.mk
-include zf_common/subdir.mk
-include user_c/subdir.mk
-include sdk/Startup/subdir.mk
-include sdk/Peripheral/subdir.mk
-include sdk/Core/subdir.mk
-include code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
ZDT_Stepper_Moter_Drive.hex \

SECONDARY_LIST += \
ZDT_Stepper_Moter_Drive.lst \

SECONDARY_SIZE += \
ZDT_Stepper_Moter_Drive.siz \


# All Target
all: 
	$(MAKE) --no-print-directory main-build 

main-build: ZDT_Stepper_Moter_Drive.elf secondary-outputs

# Tool invocations
ZDT_Stepper_Moter_Drive.elf: $(OBJS) $(USER_OBJS)
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -T "z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/sdk/Ld/Link.ld" -nostartfiles -Xlinker --gc-sections -L"z:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\6.张大头步进电机驱动\project\mrs" -L"z:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/6.张大头步进电机驱动/libraries/zf_device" -Wl,-Map,"ZDT_Stepper_Moter_Drive.map" --specs=nano.specs -u _printf_float --specs=nosys.specs -Wl,--print-memory-usage -o "ZDT_Stepper_Moter_Drive.elf" $(OBJS) $(USER_OBJS) $(LIBS)
ZDT_Stepper_Moter_Drive.hex: ZDT_Stepper_Moter_Drive.elf
	@	riscv-none-embed-objcopy -O ihex "ZDT_Stepper_Moter_Drive.elf" "ZDT_Stepper_Moter_Drive.hex"
ZDT_Stepper_Moter_Drive.lst: ZDT_Stepper_Moter_Drive.elf
	@	riscv-none-embed-objdump --source --all-headers --demangle --line-numbers --wide "ZDT_Stepper_Moter_Drive.elf" > "ZDT_Stepper_Moter_Drive.lst"
ZDT_Stepper_Moter_Drive.siz: ZDT_Stepper_Moter_Drive.elf
	riscv-none-embed-size --format=berkeley "ZDT_Stepper_Moter_Drive.elf"

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(S_DEPS)$(S_UPPER_DEPS)$(ASM_DEPS)$(ASM_UPPER_DEPS)$(C_DEPS) ZDT_Stepper_Moter_Drive.elf

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets