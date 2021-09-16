
#include <avr/io.h>
#include <util/delay.h>
#include "LED.h"

/**
 * @brief A function to operate the button and heater sensor
 *
 */
void Buttons_LED_Init()
{
     /*Configure LED and Switch pins*/
    DDRD|=(1<<PD2);                                       //setting PD2=1 for led
    DDRD&=~(1<<PD0);                                           //making it 0
    PORTD|=(1<<PD0);                                         //matching bit
    DDRD&=~(1<<PD1);                                      //making 0
     PORTD|=(1<<PD1);                                         //setting bit
     while(1)
     {
         if(!(PIND&(1<<PD0)))
         {
             if(!(PIND&(1<<PD1)))
             {
                 PORTD|=(1<<PD2);
             }
             else
                {
                PORTD&=~(1<<PD2);
             }
         }
         else
            {
            PORTD&=~(1<<PD2);
         }
     }
}
