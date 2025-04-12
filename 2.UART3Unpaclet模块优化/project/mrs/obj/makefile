################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
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
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
环形缓冲区.hex \

SECONDARY_LIST += \
环形缓冲区.lst \

SECONDARY_SIZE += \
环形缓冲区.siz \


# 所有目标
all: 环形缓冲区.elf secondary-outputs

# 工具调用
环形缓冲区.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -T "X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\sdk\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -L"../" -L"X:\Embedded folder\My programming files\CH32\2.环形缓冲区\libraries\zf_device" -Wl,-Map,"环形缓冲区.map" --specs=nano.specs -u _printf_float --specs=nosys.specs -Wl,--print-memory-usage -o "环形缓冲区.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
环形缓冲区.hex: 环形缓冲区.elf
	@	riscv-none-embed-objcopy -O ihex "环形缓冲区.elf"  "环形缓冲区.hex"
	@	@
环形缓冲区.lst: 环形缓冲区.elf
	@	riscv-none-embed-objdump --source --all-headers --demangle --line-numbers --wide "环形缓冲区.elf" > "环形缓冲区.lst"
	@	@
环形缓冲区.siz: 环形缓冲区.elf
	@	riscv-none-embed-size --format=berkeley "环形缓冲区.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) 环形缓冲区.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
