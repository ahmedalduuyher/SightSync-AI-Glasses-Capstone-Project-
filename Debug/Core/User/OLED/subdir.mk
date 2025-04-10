################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/OLED/OLED_0in96.c 

OBJS += \
./Core/User/OLED/OLED_0in96.o 

C_DEPS += \
./Core/User/OLED/OLED_0in96.d 


# Each subdirectory must supply rules for building sources it contributes
Core/User/OLED/%.o Core/User/OLED/%.su Core/User/OLED/%.cyclo: ../Core/User/OLED/%.c Core/User/OLED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F042x6 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-User-2f-OLED

clean-Core-2f-User-2f-OLED:
	-$(RM) ./Core/User/OLED/OLED_0in96.cyclo ./Core/User/OLED/OLED_0in96.d ./Core/User/OLED/OLED_0in96.o ./Core/User/OLED/OLED_0in96.su

.PHONY: clean-Core-2f-User-2f-OLED

