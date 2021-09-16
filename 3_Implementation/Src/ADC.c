#include<avr/io.h>
#include "ADC.h"
/**
 * @brief A function to initialise the analog to digital converter
 *
 */
void InitADC()
{
    ADMUX=(1<<REFS0);   //AVCC = +5V
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}


/**
 * @brief A funciton to receive temperature sensor inputs from analog pin and output it to a register ADC which has 2 8 bit registers ADCL and ADCH.
 *
 * @param ch
 * @return uint16_t
 */
uint16_t ReadADC(uint8_t ch)
{
    //Select ADC Channel(ch) which must be from 0-7
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;

    //start single Conversion
    ADCSRA|=(1<<ADSC);

    //wait for conversion to complete
    while(!(ADCSRA & (1<<ADIF)));

    //Clear ADIF by writing one to it
    ADCSRA|=(1<<ADIF);
    return(ADC);
}
