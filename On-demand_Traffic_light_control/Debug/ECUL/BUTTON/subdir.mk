################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUL/BUTTON/button.c \
../ECUL/BUTTON/button_test.c 

OBJS += \
./ECUL/BUTTON/button.o \
./ECUL/BUTTON/button_test.o 

C_DEPS += \
./ECUL/BUTTON/button.d \
./ECUL/BUTTON/button_test.d 


# Each subdirectory must supply rules for building sources it contributes
ECUL/BUTTON/%.o: ../ECUL/BUTTON/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


