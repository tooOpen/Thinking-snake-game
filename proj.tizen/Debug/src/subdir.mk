################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp 

OBJS += \
./src/main.o 

CPP_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: C++ Compiler'
	$(CXX) -I"pch" -std=c++0x -D_DEBUG -DTIZEN -I"D:\cocos2d-x-3.5-tizen\cocos2d-x-3.5-tizen\projects\AfterEarth\cocos2d\cocos" -O0 -g3 -Wall -c -fmessage-length=0 -fPIE --sysroot="$(SBI_SYSROOT)" -mthumb -I@system_includes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


