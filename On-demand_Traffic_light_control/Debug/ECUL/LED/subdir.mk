################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUL/LED/led.c \
../ECUL/LED/led_test.c 

OBJS += \
./ECUL/LED/led.o \
./ECUL/LED/led_test.o 

C_DEPS += \
./ECUL/LED/led.d \
./ECUL/LED/led_test.d 


# Each subdirectory must supply rules for building sources it contributes
ECUL/LED/%.o: ../ECUL/LED/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


