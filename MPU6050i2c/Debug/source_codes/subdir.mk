################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/I2Cdev.cpp \
/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/MPU6050.cpp \
/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/SimpleGPIO.cpp \
/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/quaternion_operations.cpp \
/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/timeSeqFilters.cpp 

OBJS += \
./source_codes/I2Cdev.o \
./source_codes/MPU6050.o \
./source_codes/SimpleGPIO.o \
./source_codes/quaternion_operations.o \
./source_codes/timeSeqFilters.o 

CPP_DEPS += \
./source_codes/I2Cdev.d \
./source_codes/MPU6050.d \
./source_codes/SimpleGPIO.d \
./source_codes/quaternion_operations.d \
./source_codes/timeSeqFilters.d 


# Each subdirectory must supply rules for building sources it contributes
source_codes/I2Cdev.o: /home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/I2Cdev.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabi-g++ -I/usr/arm-linux-gnueabi/include/c++/4.6.3 -I/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes -include/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/I2Cdev.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source_codes/MPU6050.o: /home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/MPU6050.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabi-g++ -I/usr/arm-linux-gnueabi/include/c++/4.6.3 -I/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes -include/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/I2Cdev.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source_codes/SimpleGPIO.o: /home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/SimpleGPIO.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabi-g++ -I/usr/arm-linux-gnueabi/include/c++/4.6.3 -I/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes -include/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/I2Cdev.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source_codes/quaternion_operations.o: /home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/quaternion_operations.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabi-g++ -I/usr/arm-linux-gnueabi/include/c++/4.6.3 -I/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes -include/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/I2Cdev.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source_codes/timeSeqFilters.o: /home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/timeSeqFilters.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabi-g++ -I/usr/arm-linux-gnueabi/include/c++/4.6.3 -I/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes -include/home/nagnanamus/Dropbox/BBB/codes/quad_control/source_codes/I2Cdev.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


