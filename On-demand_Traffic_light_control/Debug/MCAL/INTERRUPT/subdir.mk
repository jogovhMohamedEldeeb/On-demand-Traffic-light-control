################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/INTERRUPT/Interrupt_program.c \
../MCAL/INTERRUPT/Interrupt_test.c 

OBJS += \
./MCAL/INTERRUPT/Interrupt_program.o \
./MCAL/INTERRUPT/Interrupt_test.o 

C_DEPS += \
./MCAL/INTERRUPT/Interrupt_program.d \
./MCAL/INTERRUPT/Interrupt_test.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/INTERRUPT/%.o: ../MCAL/INTERRUPT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


