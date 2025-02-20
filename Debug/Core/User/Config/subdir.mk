################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/Config/DEV_Config.c \
../Core/User/Config/Soft_IIC.c 

OBJS += \
./Core/User/Config/DEV_Config.o \
./Core/User/Config/Soft_IIC.o 

C_DEPS += \
./Core/User/Config/DEV_Config.d \
./Core/User/Config/Soft_IIC.d 


# Each subdirectory must supply rules for building sources it contributes
Core/User/Config/%.o Core/User/Config/%.su Core/User/Config/%.cyclo: ../Core/User/Config/%.c Core/User/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F042x6 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-User-2f-Config

clean-Core-2f-User-2f-Config:
	-$(RM) ./Core/User/Config/DEV_Config.cyclo ./Core/User/Config/DEV_Config.d ./Core/User/Config/DEV_Config.o ./Core/User/Config/DEV_Config.su ./Core/User/Config/Soft_IIC.cyclo ./Core/User/Config/Soft_IIC.d ./Core/User/Config/Soft_IIC.o ./Core/User/Config/Soft_IIC.su

.PHONY: clean-Core-2f-User-2f-Config

