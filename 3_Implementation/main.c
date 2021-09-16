#include "LED.h"
#include "ADC.h"
#include "PWM.h"
#include "uart.h"
#include <util/delay.h>

int main(void){

    /**
    * @brief A function to setup timer1 with channel A for pulse width modulation with wave generation mode of 10 bits fast PWM and prescaling of 64.
    *
    */
    /*TCCR1A|=(1<<COM1A1)|(1<<WGM10)|(1<<WGM11);  //setting timer1 for PWM
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);     //8 prescalar
    DDRB|=(1<<PB1);*/                             //Setting PB1 as output pin

    Buttons_LED_Init();
    InitADC();                                        //Initialise the ADC
    Init_Timer(103);

    uint16_t temp;
    //char data;

    while(1)
    {
    if(sensor_on)                                          // Button Sensor ON
    {
            if(heater_on)                                  // Heater ON
            { 
                 set_led;                                  // LED is ON
                temp=ReadADC(0);
                PWM(temp);
                USARTWritecharacter(temp);
                _delay_ms(20);
            }
             else
            {
                _delay_ms(20);
                OCR1A = 0;           //make PWM output 0 if switch is off
                clear_led;           // LED is OFF
            }
        }
        else
        {
            clear_led;  // LED is OFF
            OCR1A = 0; //make PWM output 0 if switch is off
            _delay_ms(20);
        }
    }

    return 0;
}
