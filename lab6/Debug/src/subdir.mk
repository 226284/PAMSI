################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/IKolejka.cpp \
../src/ILista.cpp \
../src/IProgram.cpp \
../src/ISort_szybkie.cpp \
../src/IStos.cpp \
../src/ITablica_aso.cpp \
../src/Kolejka.cpp \
../src/Lista.cpp \
../src/Lista_Elem.cpp \
../src/Sort_szybkie.cpp \
../src/Stoper.cpp \
../src/Stos.cpp \
../src/Tablica.cpp \
../src/Tablica_aso.cpp \
../src/main.cpp 

OBJS += \
./src/IKolejka.o \
./src/ILista.o \
./src/IProgram.o \
./src/ISort_szybkie.o \
./src/IStos.o \
./src/ITablica_aso.o \
./src/Kolejka.o \
./src/Lista.o \
./src/Lista_Elem.o \
./src/Sort_szybkie.o \
./src/Stoper.o \
./src/Stos.o \
./src/Tablica.o \
./src/Tablica_aso.o \
./src/main.o 

CPP_DEPS += \
./src/IKolejka.d \
./src/ILista.d \
./src/IProgram.d \
./src/ISort_szybkie.d \
./src/IStos.d \
./src/ITablica_aso.d \
./src/Kolejka.d \
./src/Lista.d \
./src/Lista_Elem.d \
./src/Sort_szybkie.d \
./src/Stoper.d \
./src/Stos.d \
./src/Tablica.d \
./src/Tablica_aso.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


