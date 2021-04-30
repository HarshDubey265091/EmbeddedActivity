/**
 * @file activity3.c
 * @author your name (you@domain.com)
 * @brief Used to analyze the output of the ADC
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */




#include<avr/io.h>
#include <avr/interrupt.h>

/**
 * @brief Used to provide delay to the function
 * 
 */
void delay(void){
    TCCR0B|=(1<<CS00);
    TCNT0=0;
    sei();
        if(TCNT0 >=191){
            TCNT0=0;
        }
}
/**
 * @brief Used to provide PWM
 * 
 */
void InitPWM(void)
{
    /*Configuring the registers and ports*/
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);
    DDRB|=(1<<PB1);

}
char OutPWM(uint16_t ADC_value)
{ char temprature;
    if((ADC_value>=0) && (ADC_value<=200)){

        OCR1A = 205; /*20% duty cycle*/
        temprature=20;

        delay();
    }
    else if((ADC_value>=210) && (ADC_value<=500)){

        OCR1A = 410; /*40% duty cycle*/
        temprature=25;

       delay();
    }
    else if((ADC_value>=510) && (ADC_value<=700)){

        OCR1A = 717;/*70% duty cycle*/
        temprature=29;

        delay();
    }
    else if((ADC_value>=710) && (ADC_value<=1024)){

        OCR1A = 973; /*95% duty cycle*/
        temprature=33;

        delay();
    }
    else{
        OCR1A = 0; /*0% output*/
        temprature=0;

    }
    return temprature;
}
