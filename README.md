# Running LEDs program for PIC18F4520 PDIP microcontroller

## Compiler
[MPLAB XC8 Compiler] (https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/downloads-documentation#XC8)

## Development environment
I used MPLAB X IDE. Only part where the IDE helped me was to debug the program using the simulator and generating the Makefile. Everything else was written by hand.

## Description
It is assumed that 16 LEDs are connected to the MCU C and D ports. A button is connected to the INT0 port. If the button is pressed, the direction of LED running is changed to the opposite.

## Building
Simply use the Makefile by executing `make`
Built files are located in `dist/default/production/` directory.
