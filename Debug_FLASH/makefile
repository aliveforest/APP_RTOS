################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sources/HardwareLib/subdir.mk
-include Sources/subdir.mk
-include SDK/rtos/FreeRTOS_S32K/Source/portable/MemMang/subdir.mk
-include SDK/rtos/FreeRTOS_S32K/Source/portable/GCC/ARM_CM4F/subdir.mk
-include SDK/rtos/FreeRTOS_S32K/Source/subdir.mk
-include SDK/platform/drivers/src/pins/subdir.mk
-include SDK/platform/drivers/src/interrupt/subdir.mk
-include SDK/platform/drivers/src/flash/subdir.mk
-include SDK/platform/drivers/src/clock/S32K1xx/subdir.mk
-include SDK/platform/devices/S32K144/startup/subdir.mk
-include SDK/platform/devices/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Generated_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
APP_RTOS.bin \

SECONDARY_SIZE += \
APP_RTOS.siz \


# All Target
all: APP_RTOS.elf secondary-outputs

# Tool invocations
APP_RTOS.elf: $(OBJS) D:/dengtongbei/workspaceS32DS.ARM.2.2/APP_RTOS/Project_Settings/Linker_Files/S32K144_64_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "APP_RTOS.elf" "@APP_RTOS.args"  $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

APP_RTOS.bin: APP_RTOS.elf
	@echo 'Invoking: Standard S32DS Create Flash Image'
	arm-none-eabi-objcopy -O binary APP_RTOS.elf  "APP_RTOS.bin"
	@echo 'Finished building: $@'
	@echo ' '

APP_RTOS.siz: APP_RTOS.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley APP_RTOS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
