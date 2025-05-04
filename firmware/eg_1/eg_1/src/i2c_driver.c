#include "asf.h"
#include "stdio_serial.h"
#include "conf_board.h"
#include "i2c_driver.h"

void i2c_init()
{
	twihs_options_t opt;
	
	/* Enable the peripheral clock for TWI */
	pmc_enable_periph_clk(SENSORS_ID_TWIHS);
	
	/* Configure the options of TWI driver */
	opt.master_clk = sysclk_get_peripheral_hz();
	opt.speed      = TWIHS_CLK;
	
	if (twihs_master_init(SENSORS_BASE_TWIHS, &opt) != TWIHS_SUCCESS)
	{
		puts("-E-\tTWI master initialization failed.\r");
		while (1);
	}
	puts("i2c init successful.\r");
}

void i2c_scan()
{
	uint8_t address;
	for(address = 0x60; address <= 0x90; address++)
	{
		twihs_packet_t test_packet = {.chip = address, .buffer = NULL, .length = 0 };
		if(twihs_master_write(SENSORS_BASE_TWIHS, &test_packet) == TWIHS_SUCCESS)
		{
			printf("Device found at 0x%X\n",address);
		}
	}
	puts("No i2c sensor found.\r");
}

uint8_t i2c_read_byte(uint8_t dev_addr, uint8_t reg_addr) {
	twihs_packet_t packet_rx;
	
	packet_rx.chip        = dev_addr;
	packet_rx.addr[0]     = reg_addr;
	packet_rx.addr_length = 1;
	packet_rx.length      = 1;
	
	if (twihs_master_read(SENSORS_BASE_TWIHS, &packet_rx) != TWIHS_SUCCESS) {
		puts("-E-\tTWI master read packet failed.\r");
		while (1) {
			/* Capture error */
		}
	}
	return *((uint8_t *)packet_rx.buffer);
}

int16_t i2c_read_word(uint8_t dev_addr, uint8_t reg_addr) {
	twihs_packet_t packet_rx;
	
	packet_rx.chip        = dev_addr;
	packet_rx.addr[0]     = reg_addr;
	packet_rx.addr_length = 1;
	packet_rx.length      = 2;
	
	if (twihs_master_read(SENSORS_BASE_TWIHS, &packet_rx) != TWIHS_SUCCESS) {
		puts("-E-\tTWI master read packet failed.\r");
		while (1) {
			/* Capture error */
		}
	}
	return *((uint16_t *)packet_rx.buffer);
}

void i2c_write_byte(uint8_t dev_addr, uint8_t reg_addr, uint8_t data) {
	twihs_packet_t packet_tx;
	
	/* Configure the data packet to be transmitted */
	packet_tx.chip        = dev_addr;
	packet_tx.addr[0]     = reg_addr;
	packet_tx.addr_length = 1;
	packet_tx.buffer      = (uint8_t *) data;
	packet_tx.length      = sizeof(data);
	
	if (twihs_master_write(SENSORS_BASE_TWIHS, &packet_tx) != TWIHS_SUCCESS) {
		puts("-E-\tTWI master write packet failed.\r");
		while (1) {
			/* Capture error */
		}
	}
}