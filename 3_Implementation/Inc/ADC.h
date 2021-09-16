#ifndef ADC_H
#define ADC_H

#include<avr/io.h>

/**
 * @brief to read the adc values
 *
 */
uint16_t ReadADC(uint8_t ch);

/**
 * @brief initialise the analog to digital converter
 *
 */
void InitADC();

#endif 
