################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BufferCmds.cpp \
../BufferCmds_test.cpp \
../CircBuffer.cpp \
../CmdMenu.cpp \
../DynDataStore.cpp 

OBJS += \
./BufferCmds.o \
./BufferCmds_test.o \
./CircBuffer.o \
./CmdMenu.o \
./DynDataStore.o 

CPP_DEPS += \
./BufferCmds.d \
./BufferCmds_test.d \
./CircBuffer.d \
./CmdMenu.d \
./DynDataStore.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


