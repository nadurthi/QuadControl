avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega32u4 -c -o main.o main.c
avr-gcc -w -mmcu=atmega32u4 main.o -o main
avr-objcopy -O ihex -R .eeprom main main.hex
