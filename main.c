/*
 */

#include <avr/io.h>

int main(void)
{
    DDRD |= (1<<PD0);//set the bit PD0 output
    DDRB &= ~(1<<PB0);//clear the bit PB0 input
    DDRC &= ~(1<<PC0);//clear the bit PC0 input
    PORTB |= (1<<PB0);
    PORTC |= (1<<PC0);

    while(1){
            if(((PINB & (1<<PB0))) && ((PINC & (1<<PC0)))){
                PORTD &= ~(1<<PD0);
            }
            else if(((PINB & (1<<PB0))) && (!(PINC & (1<<PC0)))){
                PORTD &= ~(1<<PD0);
            }
            else if((!(PINB & (1<<PB0))) && ((PINC & (1<<PC0)))){
                PORTD &= ~(1<<PD0);
            }
            else if((!(PINB & (1<<PB0))) && (!(PINC & (1<<PC0)))){
                PORTD |= (1<<PD0);
            }

    }

    return 0;
}
