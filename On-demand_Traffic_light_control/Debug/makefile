################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/INTERRUPT/subdir.mk
-include MCAL/DIO/subdir.mk
-include ECUL/LED/subdir.mk
-include ECUL/BUTTON/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
LSS += \
On-demand_Traffic_light_control.lss \

FLASH_IMAGE += \
On-demand_Traffic_light_control.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: On-demand_Traffic_light_control.elf secondary-outputs

# Tool invocations
On-demand_Traffic_light_control.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,On-demand_Traffic_light_control.map -mmcu=atmega32 -o "On-demand_Traffic_light_control.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

On-demand_Traffic_light_control.lss: On-demand_Traffic_light_control.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S On-demand_Traffic_light_control.elf  >"On-demand_Traffic_light_control.lss"
	@echo 'Finished building: $@'
	@echo ' '

On-demand_Traffic_light_control.hex: On-demand_Traffic_light_control.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex On-demand_Traffic_light_control.elf  "On-demand_Traffic_light_control.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: On-demand_Traffic_light_control.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 On-demand_Traffic_light_control.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: On-demand_Traffic_light_control.elf
	@echo 'Invoking: AVRDude'
	C:\Users\m7md\Downloads\SDK_Win_64\SDK_Win_64\SDK_Win_64\WinAVR\bin\avrdude -pm32 -Uflash:w:On-demand_Traffic_light_control.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) On-demand_Traffic_light_control.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
