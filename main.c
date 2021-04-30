/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief Accumulation of the all the activities
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

uint16_t temp;
char temprature_data;
int main(void)
{
InitADC();
InitPWM();
USARTInit(103);
while(1)
{
    activity1();
    temp=ReadADC(1);
    temprature_data=OutPWM(temp);
    USARTWriteChar(temprature_data);
}

    return 0;
}
