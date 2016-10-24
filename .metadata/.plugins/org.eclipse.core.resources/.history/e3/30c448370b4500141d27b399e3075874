################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/EKF.cpp \
../src/I2Cdev.cpp \
../src/MPU6050.cpp \
../src/SerialcommGroundOnboard.cpp \
../src/State_data_manager.cpp \
../src/UDPcommGroundOnboard.cpp \
../src/kinematic_estimators.cpp \
../src/matrix_operations.cpp \
../src/quaternion_operations.cpp \
../src/serialib.cpp \
../src/testimu.cpp \
../src/udpPort.cpp 

OBJS += \
./src/EKF.o \
./src/I2Cdev.o \
./src/MPU6050.o \
./src/SerialcommGroundOnboard.o \
./src/State_data_manager.o \
./src/UDPcommGroundOnboard.o \
./src/kinematic_estimators.o \
./src/matrix_operations.o \
./src/quaternion_operations.o \
./src/serialib.o \
./src/testimu.o \
./src/udpPort.o 

CPP_DEPS += \
./src/EKF.d \
./src/I2Cdev.d \
./src/MPU6050.d \
./src/SerialcommGroundOnboard.d \
./src/State_data_manager.d \
./src/UDPcommGroundOnboard.d \
./src/kinematic_estimators.d \
./src/matrix_operations.d \
./src/quaternion_operations.d \
./src/serialib.d \
./src/testimu.d \
./src/udpPort.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -I/usr/arm-linux-gnueabihf/include/c++/4.8.2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


