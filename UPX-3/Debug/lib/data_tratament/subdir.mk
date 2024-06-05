################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/data_tratament/data_tratament.c 

OBJS += \
./lib/data_tratament/data_tratament.o 

C_DEPS += \
./lib/data_tratament/data_tratament.d 


# Each subdirectory must supply rules for building sources it contributes
lib/data_tratament/%.o lib/data_tratament/%.su lib/data_tratament/%.cyclo: ../lib/data_tratament/%.c lib/data_tratament/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/kaiqu/Desktop/GIT/PowerPeak/UPX-3/lib/data_tratament" -I"C:/Users/kaiqu/Desktop/GIT/PowerPeak/UPX-3/lib/Sensores/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib-2f-data_tratament

clean-lib-2f-data_tratament:
	-$(RM) ./lib/data_tratament/data_tratament.cyclo ./lib/data_tratament/data_tratament.d ./lib/data_tratament/data_tratament.o ./lib/data_tratament/data_tratament.su

.PHONY: clean-lib-2f-data_tratament

