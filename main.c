/*
Copyright 2013 Olexiy Logvinov
License: http://creativecommons.org/licenses/by-nc-sa/3.0/
*/

/* test program - blink LED */
#define F_CPU 4800000 // internal clock frequency = 4.8 MHz (attiny13a)
#include <avr/io.h>
#include <util/delay.h>

/*  Nikon IR command
    high 2000 us -> low 28 ms -> high 400 us -> low 1580 us -> high 400 us -> low 3580 us -> high 400 us ->
    low 63.2 ms ->
    high 2000 us -> low 28 ms -> high 400 us -> low 1580 us -> high 400 us -> low 3580 us -> high 400 us -> low
*/

void carrier(cycles) {
    int i;
    for(i=0; i<cycles; i++) {
        PORTB |= (1<<PORTB0); //turn PB0 high
        _delay_us(13.0208);
        PORTB &= ~(1<<PORTB0); //turn PB0 low
        _delay_us(13.0208);
        // test
        /*
        PORTB |= (1<<PORTB0);
        _delay_ms(500);
        PORTB &= ~(1<<PORTB0);
        _delay_ms(500);
        */
    }
}

int main(void) {
    DDRB |= _BV(DDB0);
    while(1) {
        carrier(77);
        _delay_ms(28);
        carrier(16);
        _delay_us(1580);
        carrier(16);
        _delay_us(3580);
        carrier(16);
        
        _delay_us(63200);
        
        carrier(77);
        _delay_ms(28);
        carrier(16);
        _delay_us(1580);
        carrier(16);
        _delay_us(3580);
        carrier(16);        
        
        _delay_ms(300);
        
        // test
        /*
        carrier(3);
        _delay_ms(1000);
        */
    }
}
