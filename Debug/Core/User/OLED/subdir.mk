################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/OLED/OLED_0in49.c \
../Core/User/OLED/OLED_0in91.c \
../Core/User/OLED/OLED_0in95_rgb.c \
../Core/User/OLED/OLED_0in96.c \
../Core/User/OLED/OLED_0in96_rgb.c \
../Core/User/OLED/OLED_1in27_rgb.c \
../Core/User/OLED/OLED_1in3.c \
../Core/User/OLED/OLED_1in32.c \
../Core/User/OLED/OLED_1in3_c.c \
../Core/User/OLED/OLED_1in5.c \
../Core/User/OLED/OLED_1in51.c \
../Core/User/OLED/OLED_1in54.c \
../Core/User/OLED/OLED_1in5_b.c \
../Core/User/OLED/OLED_1in5_rgb.c \
../Core/User/OLED/OLED_2in42.c 

OBJS += \
./Core/User/OLED/OLED_0in49.o \
./Core/User/OLED/OLED_0in91.o \
./Core/User/OLED/OLED_0in95_rgb.o \
./Core/User/OLED/OLED_0in96.o \
./Core/User/OLED/OLED_0in96_rgb.o \
./Core/User/OLED/OLED_1in27_rgb.o \
./Core/User/OLED/OLED_1in3.o \
./Core/User/OLED/OLED_1in32.o \
./Core/User/OLED/OLED_1in3_c.o \
./Core/User/OLED/OLED_1in5.o \
./Core/User/OLED/OLED_1in51.o \
./Core/User/OLED/OLED_1in54.o \
./Core/User/OLED/OLED_1in5_b.o \
./Core/User/OLED/OLED_1in5_rgb.o \
./Core/User/OLED/OLED_2in42.o 

C_DEPS += \
./Core/User/OLED/OLED_0in49.d \
./Core/User/OLED/OLED_0in91.d \
./Core/User/OLED/OLED_0in95_rgb.d \
./Core/User/OLED/OLED_0in96.d \
./Core/User/OLED/OLED_0in96_rgb.d \
./Core/User/OLED/OLED_1in27_rgb.d \
./Core/User/OLED/OLED_1in3.d \
./Core/User/OLED/OLED_1in32.d \
./Core/User/OLED/OLED_1in3_c.d \
./Core/User/OLED/OLED_1in5.d \
./Core/User/OLED/OLED_1in51.d \
./Core/User/OLED/OLED_1in54.d \
./Core/User/OLED/OLED_1in5_b.d \
./Core/User/OLED/OLED_1in5_rgb.d \
./Core/User/OLED/OLED_2in42.d 


# Each subdirectory must supply rules for building sources it contributes
Core/User/OLED/%.o Core/User/OLED/%.su Core/User/OLED/%.cyclo: ../Core/User/OLED/%.c Core/User/OLED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F042x6 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-User-2f-OLED

clean-Core-2f-User-2f-OLED:
	-$(RM) ./Core/User/OLED/OLED_0in49.cyclo ./Core/User/OLED/OLED_0in49.d ./Core/User/OLED/OLED_0in49.o ./Core/User/OLED/OLED_0in49.su ./Core/User/OLED/OLED_0in91.cyclo ./Core/User/OLED/OLED_0in91.d ./Core/User/OLED/OLED_0in91.o ./Core/User/OLED/OLED_0in91.su ./Core/User/OLED/OLED_0in95_rgb.cyclo ./Core/User/OLED/OLED_0in95_rgb.d ./Core/User/OLED/OLED_0in95_rgb.o ./Core/User/OLED/OLED_0in95_rgb.su ./Core/User/OLED/OLED_0in96.cyclo ./Core/User/OLED/OLED_0in96.d ./Core/User/OLED/OLED_0in96.o ./Core/User/OLED/OLED_0in96.su ./Core/User/OLED/OLED_0in96_rgb.cyclo ./Core/User/OLED/OLED_0in96_rgb.d ./Core/User/OLED/OLED_0in96_rgb.o ./Core/User/OLED/OLED_0in96_rgb.su ./Core/User/OLED/OLED_1in27_rgb.cyclo ./Core/User/OLED/OLED_1in27_rgb.d ./Core/User/OLED/OLED_1in27_rgb.o ./Core/User/OLED/OLED_1in27_rgb.su ./Core/User/OLED/OLED_1in3.cyclo ./Core/User/OLED/OLED_1in3.d ./Core/User/OLED/OLED_1in3.o ./Core/User/OLED/OLED_1in3.su ./Core/User/OLED/OLED_1in32.cyclo ./Core/User/OLED/OLED_1in32.d ./Core/User/OLED/OLED_1in32.o ./Core/User/OLED/OLED_1in32.su ./Core/User/OLED/OLED_1in3_c.cyclo ./Core/User/OLED/OLED_1in3_c.d ./Core/User/OLED/OLED_1in3_c.o ./Core/User/OLED/OLED_1in3_c.su ./Core/User/OLED/OLED_1in5.cyclo ./Core/User/OLED/OLED_1in5.d ./Core/User/OLED/OLED_1in5.o ./Core/User/OLED/OLED_1in5.su ./Core/User/OLED/OLED_1in51.cyclo ./Core/User/OLED/OLED_1in51.d ./Core/User/OLED/OLED_1in51.o ./Core/User/OLED/OLED_1in51.su ./Core/User/OLED/OLED_1in54.cyclo ./Core/User/OLED/OLED_1in54.d ./Core/User/OLED/OLED_1in54.o ./Core/User/OLED/OLED_1in54.su ./Core/User/OLED/OLED_1in5_b.cyclo ./Core/User/OLED/OLED_1in5_b.d ./Core/User/OLED/OLED_1in5_b.o ./Core/User/OLED/OLED_1in5_b.su ./Core/User/OLED/OLED_1in5_rgb.cyclo ./Core/User/OLED/OLED_1in5_rgb.d ./Core/User/OLED/OLED_1in5_rgb.o ./Core/User/OLED/OLED_1in5_rgb.su ./Core/User/OLED/OLED_2in42.cyclo ./Core/User/OLED/OLED_2in42.d ./Core/User/OLED/OLED_2in42.o ./Core/User/OLED/OLED_2in42.su

.PHONY: clean-Core-2f-User-2f-OLED

