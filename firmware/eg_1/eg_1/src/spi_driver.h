#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include <stdint.h>

void init_spi(void);
void spi_set_clock_configuration(uint8_t configuration);
void spi_master_transfer(void *p_buf, uint32_t size);

#endif /* SPI_DRIVER_H_ */