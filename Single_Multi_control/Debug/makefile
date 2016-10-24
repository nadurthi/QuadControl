################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
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
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Single_Multi_control.lss \

FLASH_IMAGE += \
Single_Multi_control.hex \

EEPROM_IMAGE += \
Single_Multi_control.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Single_Multi_control.elf secondary-outputs

# Tool invocations
Single_Multi_control.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Single_Multi_control.map -mmcu=atmega16 -o "Single_Multi_control.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Single_Multi_control.lss: Single_Multi_control.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Single_Multi_control.elf  >"Single_Multi_control.lss"
	@echo 'Finished building: $@'
	@echo ' '

Single_Multi_control.hex: Single_Multi_control.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Single_Multi_control.elf  "Single_Multi_control.hex"
	@echo 'Finished building: $@'
	@echo ' '

Single_Multi_control.eep: Single_Multi_control.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Single_Multi_control.elf  "Single_Multi_control.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Single_Multi_control.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Single_Multi_control.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Single_Multi_control.elf
	@echo 'Invoking: AVRDude'
	/usr/bin/avrdude -pm16 -cusbasp -Uflash:w:Single_Multi_control.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Single_Multi_control.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
