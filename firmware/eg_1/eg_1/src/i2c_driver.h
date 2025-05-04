#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_


#include <asf.h>

#define TWIHS_CLK     400000
#define SENSORS_ID_TWIHS         ID_TWIHS0
#define SENSORS_BASE_TWIHS       TWIHS0

void i2c_init();
void i2c_scan();
uint8_t i2c_read_byte(uint8_t dev_addr, uint8_t reg_addr);
int16_t i2c_read_word(uint8_t dev_addr, uint8_t reg_addr);
void i2c_write_byte(uint8_t dev_addr, uint8_t reg_addr, uint8_t data);


#endif /* I2C_DRIVER_H_ */