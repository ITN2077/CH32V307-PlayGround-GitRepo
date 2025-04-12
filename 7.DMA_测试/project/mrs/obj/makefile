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
DMA_Testing.hex \

SECONDARY_LIST += \
DMA_Testing.lst \

SECONDARY_SIZE += \
DMA_Testing.siz \


# All Target
all: 
	$(MAKE) --no-print-directory main-build 

main-build: DMA_Testing.elf secondary-outputs

# Tool invocations
DMA_Testing.elf: $(OBJS) $(USER_OBJS)
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -T "c:/XÅÌ/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_²âÊÔ/libraries/sdk/Ld/Link.ld" -nostartfiles -Xlinker --gc-sections -L"c:\XÅÌ\8-CodeProjects\1.MCU\CH32V307-PlayGround\7.DMA_²âÊÔ\project\mrs" -L"c:/XÅÌ/8-CodeProjects/1.MCU/CH32V307-PlayGround/7.DMA_²âÊÔ/libraries/zf_device" -Wl,-Map,"DMA_Testing.map" --specs=nano.specs -u _printf_float --specs=nosys.specs -Wl,--print-memory-usage -o "DMA_Testing.elf" $(OBJS) $(USER_OBJS) $(LIBS)
DMA_Testing.hex: DMA_Testing.elf
	@	riscv-none-embed-objcopy -O ihex "DMA_Testing.elf" "DMA_Testing.hex"
DMA_Testing.lst: DMA_Testing.elf
	@	riscv-none-embed-objdump --source --all-headers --demangle --line-numbers --wide "DMA_Testing.elf" > "DMA_Testing.lst"
DMA_Testing.siz: DMA_Testing.elf
	riscv-none-embed-size --format=berkeley "DMA_Testing.elf"

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(S_DEPS)$(S_UPPER_DEPS)$(ASM_DEPS)$(ASM_UPPER_DEPS)$(C_DEPS) DMA_Testing.elf

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets