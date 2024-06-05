################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/Sensores/Scr/sensores.c 

OBJS += \
./lib/Sensores/Scr/sensores.o 

C_DEPS += \
./lib/Sensores/Scr/sensores.d 


# Each subdirectory must supply rules for building sources it contributes
lib/Sensores/Scr/%.o lib/Sensores/Scr/%.su lib/Sensores/Scr/%.cyclo: ../lib/Sensores/Scr/%.c lib/Sensores/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/kaiqu/OneDrive/Documentos 1/Programas/Microcontroladores/STM32/UPX-3/lib/data_tratament" -I"C:/Users/kaiqu/OneDrive/Documentos 1/Programas/Microcontroladores/STM32/UPX-3/lib/Sensores/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib-2f-Sensores-2f-Scr

clean-lib-2f-Sensores-2f-Scr:
	-$(RM) ./lib/Sensores/Scr/sensores.cyclo ./lib/Sensores/Scr/sensores.d ./lib/Sensores/Scr/sensores.o ./lib/Sensores/Scr/sensores.su

.PHONY: clean-lib-2f-Sensores-2f-Scr

