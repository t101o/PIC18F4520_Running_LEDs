#include "p18cxxx.h"

void delay();
void change_port(unsigned char *port);
__interrupt() void button_press(void);

volatile unsigned char direction = 0x01; // 0x01 Right, 0x00 Left

void delay() {
    int counter = 0;
    for (counter = 0; counter<25000; counter++) {
        ;
    }
}

__interrupt() void button_press(void) {
    if (INT0IF == 1) {
        direction ^= 0x01;
        INT0IF = 0;
    }
}

void change_port(unsigned char *port) {
    if (*port & 0x01) {
        PORTC = 0x00;
    } else {
        PORTD = 0x00;
    }
    *port ^= 0x01;
}
// ASSUMPTION: There are 16 LEDs connected to the uController
void main(void) {
    // Initialization
    TRISB = 1; // Set for input
    PORTB = 0x00;
    INTCONbits.GIE = 1; // Enabled global interrupts
    INTCONbits.INT0IF = 0; // Cleared INT0 interrupt flag
    INTCONbits.INT0IE = 1; // Enabled INT0 interrupts
    TRISC = 0; // Set for output
    TRISD = 0; // Set for output
    PORTC = 0x00;
    PORTD = 0x00;
    
    unsigned char i = 0x01; // cycles through the pins
    unsigned char port = 0x01; // 0x01 C ports, 0x00 D ports
    
    // Program loop
    while (1) {
        if (port & 0x01) {
            PORTC = i;
        } else {
            PORTD = i;
        }
        
        delay();
        
        if (direction & 0x01) {
            if (i & 0x80) { // last diode case
                change_port(&port);
                i = 0x01;
            } else {
                i = i << 1;
            }
        } else {
            if (i & 0x01) { // last diode case
                change_port(&port);
                i = 0x80;
            } else {
                i = i >> 1;
            }
        }
    }
}


