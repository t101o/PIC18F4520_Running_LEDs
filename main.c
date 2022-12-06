#include "p18cxxx.h"

void delay();

void delay() {
    int counter = 0;
    for (counter = 0; counter<10000; counter++) {
        ;
    }
}
// ASSUMPTION: There are 16 LEDs connected to the uController
// TODO: Setup interrupts by the button to change direction of the glow.
// TODO: Do more than 8 diodes with other ports
//         IDEA: When one port reaches 0x80 use the next port pins.
//               State could be put in a flag.
void main(void) {
    TRISB = 0;
    PORTB = 0x00;
    unsigned char i = 0x01; // cycles through the pins
    unsigned char direction = 0x01; // 0x01 Right, 0x00 Left
    while (1) {
        PORTB = i;
        delay();
        if (direction & 0x01) {
            if (i & 0x80) { // last diode case
                i = 0x01; // TODO switch to next port
            } else {
                i = i << 1;
            }
        } else {
            if (i & 0x01) { // last diode case
                i = 0x80; // TODO switch to next port
            } else {
                i = i >> 1;
            }
        }
    }
}


