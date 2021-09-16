#ifndef _LED_H
#define _LED_H

#define AVR_ATmega328

#include <avr/io.h>

/**
 * @brief A macro to check if the button is pressed or not.
 *
 */
#define sensor_on !(PIND&(1<<PD4))

/**
 * @brief A macro to check if the heater is pressed or not.
 *
 */
#define heater_on !(PIND&(1<<PD0))

/**
 * @brief A macro to turn on the LED
 *
 */
#define set_led PORTD|=(1<<PD2)

/**
 * @brief A macro to turn off the LED
 *
 */
#define clear_led PORTD&=~(1<<PD2)

void Buttons_LED_Init();


#endif //ACT1_H_INCLUDED
