CC        = avr-gcc
CXX       = avr-g++

MCU      ?= atmega328p 
CPU_SPEED = 16000000UL

CFLAGS    = -I. -mmcu=$(MCU) -DF_CPU=$(CPU_SPEED) -Os -w -std=c++0x -DARDUINO=157
BOARD     = arduino
LIBNAME   = lib$(BOARD).a

INCDIR    = ../apps/include/$(BOARD)
LIBDIR    = ../apps/lib

OBJECTS   = \
	new.o \
	hooks.o \
	WInterrupts.o \
	wiring_analog.o \
	wiring.o \
	wiring_digital.o \
	wiring_pulse.o \
	wiring_shift.o \
	CDC.o \
	HardwareSerial.o \
	HardwareSerial0.o \
	HardwareSerial1.o \
	HardwareSerial2.o \
	HardwareSerial3.o \
	HID.o \
	IPAddress.o \
	Print.o \
	Stream.o \
	Tone.o \
	USBCore.o \
	WMath.o \
	WString.o

#OBJECTS  += \
	timer/Time/DateStrings.o \
	timer/Time/Time.o \
	timer/TimeAlarms/TimeAlarms.o \
	NewSoftSerial/NewSoftSerial.o

#CP_HEADERS += \
	timer/Time/Time.h \
	timer/TimeAlarms/TimeAlarms.h \
	NewSoftSerial/NewSoftSerial.h

#CFLAGS += \
	-DARDUINO=157 \
	-Itimer/Time \
	-Itimer/TimeAlarms \
	-INewSoftSerial

default: $(OBJECTS)
	avr-ar rcs $(LIBNAME) $^
	mkdir -p $(INCDIR) $(LIBDIR)
	@cp *.h $(CP_HEADERS) $(INCDIR)/
	@mv $(LIBNAME) $(LIBDIR)
	@rm $(OBJECTS)
clean:
	@rm -rf ../apps/include ../apps/lib

%.o : %.c
	$(CC) $< $(CFLAGS) -c -o $@
%.o : %.cpp
	$(CXX) $< $(CFLAGS) -c -o $@
