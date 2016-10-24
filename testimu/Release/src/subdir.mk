################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/EKF.cpp \
../src/I2Cdev.cpp \
../src/MPU6050.cpp \
../src/State_data_manager.cpp \
../src/quaternion_operations.cpp \
../src/testimu.cpp 

OBJS += \
./src/EKF.o \
./src/I2Cdev.o \
./src/MPU6050.o \
./src/State_data_manager.o \
./src/quaternion_operations.o \
./src/testimu.o 

CPP_DEPS += \
./src/EKF.d \
./src/I2Cdev.d \
./src/MPU6050.d \
./src/State_data_manager.d \
./src/quaternion_operations.d \
./src/testimu.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabi-g++ -I/usr/arm-linux-gnueabi/include/c++/4.6.3 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


