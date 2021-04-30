/**
 * @file activity4.c
 * @author your name (you@domain.com)
 * @brief Used to send the value to the Serial Monitor
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */




#include<avr/io.h>
/**
 * @brief Used to initialize the UART
 * 
 * @param ubrr_value 
 */

void USARTInit(uint16_t ubrr_value)
{
    /*set Baud Rate*/
    UBRR0L=ubrr_value;
    UBRR0H=(ubrr_value>>8)& 0X00ff;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    /*Enable the reciever and Transmitter*/

    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

void USARTWriteChar(char data)
{
    /*Wait untill the transmission is Ready*/

    while(!(UCSR0A & (1<<UDRE0)))
    {
        /*Do Nothing*/
    }
    /*Now write the data to the USART buffer*/

    UDR0=data;
}



