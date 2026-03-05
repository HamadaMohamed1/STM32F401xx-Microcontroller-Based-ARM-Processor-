################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Core_Prephirals/systick.c 

OBJS += \
./Src/Core_Prephirals/systick.o 

C_DEPS += \
./Src/Core_Prephirals/systick.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Core_Prephirals/%.o Src/Core_Prephirals/%.su Src/Core_Prephirals/%.cyclo: ../Src/Core_Prephirals/%.c Src/Core_Prephirals/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Core_Prephirals

clean-Src-2f-Core_Prephirals:
	-$(RM) ./Src/Core_Prephirals/systick.cyclo ./Src/Core_Prephirals/systick.d ./Src/Core_Prephirals/systick.o ./Src/Core_Prephirals/systick.su

.PHONY: clean-Src-2f-Core_Prephirals

