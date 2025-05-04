#include "sensors.h"
#include "i2c_driver.h"
#include "spi_driver.h"
#include "adc_driver.h"

void init_sensors(void) {
	//! [main_step_i2c_init]
	/* Initialize the I2C */
	i2c_init();
	//! [main_step_i2c_init]

	//! [main_step_init_spi]
	/* Initialize the SPI */
	init_spi();
	//! [main_step_init_spi]

	//! [main_step_init_adc]
	/* Initialize the ADC */
	init_adc();
	//! [main_step_init_adc]
}

float read_temperature_sensor(void) {
	// Read SPI thermocouple sensor (MAX31855)
	float temp;
	spi_master_transfer(&temp,0x01);
	return temp;
}

float read_pressure_sensor(void) {
	// Read from analog pressure sensor via ADC
	uint16_t adc_val = read_adc_channel(0);
	float pressure = ((float)adc_val / 1023.0) * 100.0;
	return pressure;
}

float read_vibration_sensor(void) {
	// Read acceleration from MPU6050 (I2C)
	int16_t accel_x = i2c_read_word(0x68, 0x3B);
	float vibration = accel_x / 16384.0;
	return vibration;
}

float read_pad_wear_sensor(void) {
	// Read magnetic field from MLX90393 (I2C)
	int16_t mag_x = i2c_read_word(0x0C, 0x10);
	float field_strength = mag_x * 0.1;
	return field_strength;
}
