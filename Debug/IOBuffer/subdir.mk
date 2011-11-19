################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../IOBuffer/ArrayReader.cpp \
../IOBuffer/Block.cpp \
../IOBuffer/BufferedIHandler.cpp \
../IOBuffer/BufferedOHandler.cpp \
../IOBuffer/ConsoleWriter.cpp \
../IOBuffer/DBuffIHandler.cpp \
../IOBuffer/IBlock.cpp \
../IOBuffer/IHandler.cpp \
../IOBuffer/IOBuffer.cpp \
../IOBuffer/OBlock.cpp \
../IOBuffer/OHandler.cpp \
../IOBuffer/Reader.cpp \
../IOBuffer/SimpleIHandler.cpp \
../IOBuffer/SimpleOHandler.cpp \
../IOBuffer/UnixFileReader.cpp \
../IOBuffer/UnixFileWriter.cpp \
../IOBuffer/Writer.cpp 

OBJS += \
./IOBuffer/ArrayReader.o \
./IOBuffer/Block.o \
./IOBuffer/BufferedIHandler.o \
./IOBuffer/BufferedOHandler.o \
./IOBuffer/ConsoleWriter.o \
./IOBuffer/DBuffIHandler.o \
./IOBuffer/IBlock.o \
./IOBuffer/IHandler.o \
./IOBuffer/IOBuffer.o \
./IOBuffer/OBlock.o \
./IOBuffer/OHandler.o \
./IOBuffer/Reader.o \
./IOBuffer/SimpleIHandler.o \
./IOBuffer/SimpleOHandler.o \
./IOBuffer/UnixFileReader.o \
./IOBuffer/UnixFileWriter.o \
./IOBuffer/Writer.o 

CPP_DEPS += \
./IOBuffer/ArrayReader.d \
./IOBuffer/Block.d \
./IOBuffer/BufferedIHandler.d \
./IOBuffer/BufferedOHandler.d \
./IOBuffer/ConsoleWriter.d \
./IOBuffer/DBuffIHandler.d \
./IOBuffer/IBlock.d \
./IOBuffer/IHandler.d \
./IOBuffer/IOBuffer.d \
./IOBuffer/OBlock.d \
./IOBuffer/OHandler.d \
./IOBuffer/Reader.d \
./IOBuffer/SimpleIHandler.d \
./IOBuffer/SimpleOHandler.d \
./IOBuffer/UnixFileReader.d \
./IOBuffer/UnixFileWriter.d \
./IOBuffer/Writer.d 


# Each subdirectory must supply rules for building sources it contributes
IOBuffer/%.o: ../IOBuffer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


