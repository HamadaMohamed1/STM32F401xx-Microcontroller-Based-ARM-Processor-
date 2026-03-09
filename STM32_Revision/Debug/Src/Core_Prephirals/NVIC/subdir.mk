################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Core_Prephirals/NVIC/nvic.c 

OBJS += \
./Src/Core_Prephirals/NVIC/nvic.o 

C_DEPS += \
./Src/Core_Prephirals/NVIC/nvic.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Core_Prephirals/NVIC/%.o Src/Core_Prephirals/NVIC/%.su Src/Core_Prephirals/NVIC/%.cyclo: ../Src/Core_Prephirals/NVIC/%.c Src/Core_Prephirals/NVIC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Core_Prephirals-2f-NVIC

clean-Src-2f-Core_Prephirals-2f-NVIC:
	-$(RM) ./Src/Core_Prephirals/NVIC/nvic.cyclo ./Src/Core_Prephirals/NVIC/nvic.d ./Src/Core_Prephirals/NVIC/nvic.o ./Src/Core_Prephirals/NVIC/nvic.su

.PHONY: clean-Src-2f-Core_Prephirals-2f-NVIC

