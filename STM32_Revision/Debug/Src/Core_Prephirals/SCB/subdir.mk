################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Core_Prephirals/SCB/scb.c 

OBJS += \
./Src/Core_Prephirals/SCB/scb.o 

C_DEPS += \
./Src/Core_Prephirals/SCB/scb.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Core_Prephirals/SCB/%.o Src/Core_Prephirals/SCB/%.su Src/Core_Prephirals/SCB/%.cyclo: ../Src/Core_Prephirals/SCB/%.c Src/Core_Prephirals/SCB/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Core_Prephirals-2f-SCB

clean-Src-2f-Core_Prephirals-2f-SCB:
	-$(RM) ./Src/Core_Prephirals/SCB/scb.cyclo ./Src/Core_Prephirals/SCB/scb.d ./Src/Core_Prephirals/SCB/scb.o ./Src/Core_Prephirals/SCB/scb.su

.PHONY: clean-Src-2f-Core_Prephirals-2f-SCB

