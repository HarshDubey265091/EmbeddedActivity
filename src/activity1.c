/**
 * @file activity1.c
 * @author your name (you@domain.com)
 * @brief Used for analyzing the heater and button sensor and LED
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#include <avr/io.h>
#include "activity1.h"

void activity1(){
    DDRB |= (1<<PB0);/*set the bit PB0 output*/
    DDRD &= ~(1<<PD0);/*clear the bit PD0 input*/
    DDRD &= ~(1<<PD1);/*clear the bit PD1 input*/
    PORTD |= (1<<PD0);
    PORTD |= (1<<PD1);

            if(((PIND & (1<<PD0))) && ((PIND & (1<<PD1)))){
                PORTB &= ~(1<<PB0);
            }
            else if(((PIND & (1<<PD0))) && (!(PIND & (1<<PD1)))){
                PORTB &= ~(1<<PB0);
            }
            else if((!(PIND & (1<<PD0))) && ((PIND & (1<<PD1)))){
                PORTB &= ~(1<<PB0);
            }
            else if((!(PIND & (1<<PD0))) && (!(PIND & (1<<PD1)))){
                PORTB |= (1<<PB0);
            }

    }

