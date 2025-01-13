################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103_c6_drivers/inc/KEYPAD_DRIVER/keypad.c 

OBJS += \
./stm32f103_c6_drivers/inc/KEYPAD_DRIVER/keypad.o 

C_DEPS += \
./stm32f103_c6_drivers/inc/KEYPAD_DRIVER/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103_c6_drivers/inc/KEYPAD_DRIVER/keypad.o: ../stm32f103_c6_drivers/inc/KEYPAD_DRIVER/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/o0115/STM32CubeIDE/workspace_3/stm32f103c6_drivers2/stm32f103_c6_drivers/inc/KEYPAD_DRIVER" -I"C:/Users/o0115/STM32CubeIDE/workspace_3/stm32f103c6_drivers2/stm32f103_c6_drivers/inc/LCD_DRIVER" -I"C:/Users/o0115/STM32CubeIDE/workspace_3/stm32f103c6_drivers2/stm32f103_c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103_c6_drivers/inc/KEYPAD_DRIVER/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

