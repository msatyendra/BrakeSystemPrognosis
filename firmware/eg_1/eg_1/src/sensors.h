#ifndef SENSORS_H_
#define SENSORS_H_


#include <stdint.h>

#define TEMP_BASE 0
#define PRES_BASE 16
#define VIBR_BASE 32
#define PADW_BASE 48

void init_sensors(void);

float read_temperature_sensor(void);
float read_pressure_sensor(void);
float read_vibration_sensor(void);
float read_pad_wear_sensor(void);


#endif /* SENSORS_H_ */