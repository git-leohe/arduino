CXX = avr-g++
CC  = avr-gcc

INCLUDE   = -Iinclude/arduino -I../include
LIBS      = -Llib -lm -larduino
MCU       = -mmcu=atmega328p
CPU_SPEED = -DF_CPU=16000000UL

CFLAGS = $(MCU) $(CPU_SPEED) -Os -w -Wl,--gc-sections -ffunction-sections -fdata-sections

default: main.hex

main.hex: main.elf
	avr-objcopy -O ihex $< $@
main.elf: main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@ $(LIBS)

upload:
	avrdude -V -F -p m328p -c arduino -b 115200 -U flash:w:main.hex -P /dev/ttyUSB0

clean:
	@rm -f *.elf *.hex *.o

%.o: %.c
	$(CC) $< $(CFLAGS) $(INCLUDE) -c -o $@
%.o: %.cpp
	$(CXX) $< $(CFLAGS) $(INCLUDE) -c -o $@
