/**
 * @file activity2.c
 * @author your name (you@domain.com)
 * @brief Used for the ADC value through the Potentiometer
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#include <avr/io.h>

void InitADC()
{
    ADMUX = (1<<REFS0);//Aref=AVcc;
    ADCSRA=(1<<ADEN)|(7<<ADPS0);//For Enable ADC & FCPU/128
}

// For Selecting the ADC Channel
uint16_t ReadADC(uint8_t ch)
{
    //Select ADC Channel ch must be 0-7
    ADMUX &= 0Xf8;
    ch&=0b00000111;
    ADMUX|=ch;
    //start single conversion
    ADCSRA|=(1<<ADSC);
    //wait for the conversion to conplete
    while(!(ADCSRA & (1<<ADIF)));
    //clear ADIF by writing on to it

    ADCSRA|=(1<<ADIF);
    return(ADC);
}

