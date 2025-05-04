#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_


#include <stdint.h>

/** Reference voltage for AFEC,in mv. */
#define VOLT_REF        (3300)

/** The maximal digital value */
#define MAX_DIGITAL     (4095UL)

#define AFEC_PRESSURE_SENSOR 0x68
void init_adc(void);
void afec_press_sensor_end_conversion(void);
uint16_t read_adc_channel(uint8_t channel);


#endif /* ADC_DRIVER_H_ */