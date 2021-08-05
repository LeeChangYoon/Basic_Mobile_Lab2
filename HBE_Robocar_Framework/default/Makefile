###############################################################################
# Makefile for the project HBE_Robocar_Framework
###############################################################################

## General Flags
PROJECT = HBE_Robocar_Framework
MCU = atmega128
TARGET = HBE_Robocar_Framework.elf
CC = 

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -Os -std=gnu99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=HBE_Robocar_Framework.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = MotionEngine.o PIDControl.o Ports.o PSD.o RBC_Ultra.o Robot.o Timers.o UART.o Utilities.o avr_lib.o CommandExecutor.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) HBE_Robocar_Framework.hex HBE_Robocar_Framework.eep HBE_Robocar_Framework.lss## Compile
MotionEngine.o: ../../Desktop/Codes/MotionEngine.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

PIDControl.o: ../../Desktop/Codes/PIDControl.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Ports.o: ../../Desktop/Codes/Ports.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

PSD.o: ../../Desktop/Codes/PSD.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

RBC_Ultra.o: ../../Desktop/Codes/RBC_Ultra.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Robot.o: ../../Desktop/Codes/Robot.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Timers.o: ../../Desktop/Codes/Timers.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

UART.o: ../../Desktop/Codes/UART.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Utilities.o: ../../Desktop/Codes/Utilities.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

avr_lib.o: ../../Desktop/Codes/avr_lib.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CommandExecutor.o: ../../Desktop/Codes/CommandExecutor.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) HBE_Robocar_Framework.elf dep/* HBE_Robocar_Framework.hex HBE_Robocar_Framework.eep HBE_Robocar_Framework.lss HBE_Robocar_Framework.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

