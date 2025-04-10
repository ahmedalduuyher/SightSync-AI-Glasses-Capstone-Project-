################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/Example/ImageData.c \
../Core/User/Example/OLED_0in96_test.c 

OBJS += \
./Core/User/Example/ImageData.o \
./Core/User/Example/OLED_0in96_test.o 

C_DEPS += \
./Core/User/Example/ImageData.d \
./Core/User/Example/OLED_0in96_test.d 


# Each subdirectory must supply rules for building sources it contributes
Core/User/Example/%.o Core/User/Example/%.su Core/User/Example/%.cyclo: ../Core/User/Example/%.c Core/User/Example/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F042x6 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-User-2f-Example

clean-Core-2f-User-2f-Example:
	-$(RM) ./Core/User/Example/ImageData.cyclo ./Core/User/Example/ImageData.d ./Core/User/Example/ImageData.o ./Core/User/Example/ImageData.su ./Core/User/Example/OLED_0in96_test.cyclo ./Core/User/Example/OLED_0in96_test.d ./Core/User/Example/OLED_0in96_test.o ./Core/User/Example/OLED_0in96_test.su

.PHONY: clean-Core-2f-User-2f-Example

