################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103_c6_drivers/gpio/stm32f103c6_gpio.c 

OBJS += \
./stm32f103_c6_drivers/gpio/stm32f103c6_gpio.o 

C_DEPS += \
./stm32f103_c6_drivers/gpio/stm32f103c6_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103_c6_drivers/gpio/stm32f103c6_gpio.o: ../stm32f103_c6_drivers/gpio/stm32f103c6_gpio.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/o0115/STM32CubeIDE/workspace_3/stm32f103c6_drivers/stm32f103_c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103_c6_drivers/gpio/stm32f103c6_gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
