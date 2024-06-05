################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/sensors_read/sensors_read.c 

OBJS += \
./lib/sensors_read/sensors_read.o 

C_DEPS += \
./lib/sensors_read/sensors_read.d 


# Each subdirectory must supply rules for building sources it contributes
lib/sensors_read/%.o lib/sensors_read/%.su lib/sensors_read/%.cyclo: ../lib/sensors_read/%.c lib/sensors_read/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Kaique/OneDrive/Documentos 1/Programas/Microcontroladores/STM32/UPX-3/lib/data_tratament" -I"C:/Users/Kaique/OneDrive/Documentos 1/Programas/Microcontroladores/STM32/UPX-3/lib/sensors_read" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib-2f-sensors_read

clean-lib-2f-sensors_read:
	-$(RM) ./lib/sensors_read/sensors_read.cyclo ./lib/sensors_read/sensors_read.d ./lib/sensors_read/sensors_read.o ./lib/sensors_read/sensors_read.su

.PHONY: clean-lib-2f-sensors_read

