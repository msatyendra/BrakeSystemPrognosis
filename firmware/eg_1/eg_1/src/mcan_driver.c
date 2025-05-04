#include <asf.h>
#include <string.h>
#include <conf_mcan.h>

#include "mcan_driver.h"

/* module_inst */
static struct mcan_module mcan_instance;

void configure_mcan(void)
{
	/* Initialize the module. */
	struct mcan_config config_mcan;
	mcan_get_config_defaults(&config_mcan);
	mcan_init(&mcan_instance, MCAN_MODULE, &config_mcan);

	mcan_enable_fd_mode(&mcan_instance);
	mcan_start(&mcan_instance);

	/* Enable interrupts for this MCAN module */
	irq_register_handler(MCAN1_INT0_IRQn, 1);
	mcan_enable_interrupt(&mcan_instance, MCAN_FORMAT_ERROR | MCAN_ACKNOWLEDGE_ERROR
	| MCAN_BUS_OFF);
}

void mcan_set_standard_filter_0(void)
{
	struct mcan_standard_message_filter_element sd_filter;

	mcan_get_standard_message_filter_element_default(&sd_filter);
	sd_filter.S0.bit.SFID2 = MCAN_RX_STANDARD_FILTER_ID_0_BUFFER_INDEX;
	sd_filter.S0.bit.SFID1 = MCAN_RX_STANDARD_FILTER_ID_0;
	sd_filter.S0.bit.SFEC =
	MCAN_STANDARD_MESSAGE_FILTER_ELEMENT_S0_SFEC_STRXBUF_Val;

	mcan_set_rx_standard_filter(&mcan_instance, &sd_filter,
	MCAN_RX_STANDARD_FILTER_INDEX_0);
	mcan_enable_interrupt(&mcan_instance, MCAN_RX_BUFFER_NEW_MESSAGE);
}

void mcan_set_standard_filter_1(void)
{
	struct mcan_standard_message_filter_element sd_filter;

	mcan_get_standard_message_filter_element_default(&sd_filter);
	sd_filter.S0.bit.SFID1 = MCAN_RX_STANDARD_FILTER_ID_1;

	mcan_set_rx_standard_filter(&mcan_instance, &sd_filter,
	MCAN_RX_STANDARD_FILTER_INDEX_1);
	mcan_enable_interrupt(&mcan_instance, MCAN_RX_FIFO_0_NEW_MESSAGE);
}

void mcan_set_extended_filter_0(void)
{
	struct mcan_extended_message_filter_element et_filter;

	mcan_get_extended_message_filter_element_default(&et_filter);
	et_filter.F0.bit.EFID1 = MCAN_RX_EXTENDED_FILTER_ID_0;
	et_filter.F0.bit.EFEC =
	MCAN_EXTENDED_MESSAGE_FILTER_ELEMENT_F0_EFEC_STRXBUF_Val;
	et_filter.F1.bit.EFID2 = MCAN_RX_EXTENDED_FILTER_ID_0_BUFFER_INDEX;

	mcan_set_rx_extended_filter(&mcan_instance, &et_filter,
	MCAN_RX_EXTENDED_FILTER_INDEX_0);
	mcan_enable_interrupt(&mcan_instance, MCAN_RX_BUFFER_NEW_MESSAGE);
}

void mcan_set_extended_filter_1(void)
{
	struct mcan_extended_message_filter_element et_filter;

	mcan_get_extended_message_filter_element_default(&et_filter);
	et_filter.F0.bit.EFID1 = MCAN_RX_EXTENDED_FILTER_ID_1;

	mcan_set_rx_extended_filter(&mcan_instance, &et_filter,
	MCAN_RX_EXTENDED_FILTER_INDEX_1);
	mcan_enable_interrupt(&mcan_instance, MCAN_RX_FIFO_1_NEW_MESSAGE);
}

void mcan_send_standard_message(uint32_t id_value, uint8_t *data)
{
	uint32_t i;
	struct mcan_tx_element tx_element;

	mcan_get_tx_buffer_element_defaults(&tx_element);
	tx_element.T0.reg |= MCAN_TX_ELEMENT_T0_STANDARD_ID(id_value);
	tx_element.T1.bit.DLC = 8;
	for (i = 0; i < 8; i++) {
		tx_element.data[i] = *data;
		data++;
	}

	mcan_set_tx_buffer_element(&mcan_instance, &tx_element,
	MCAN_TX_BUFFER_INDEX);
	mcan_tx_transfer_request(&mcan_instance, 1 << MCAN_TX_BUFFER_INDEX);
}

void mcan_fd_send_standard_message(uint32_t id_value, uint8_t *data)
{
	uint32_t i;
	struct mcan_tx_element tx_element;

	mcan_get_tx_buffer_element_defaults(&tx_element);
	tx_element.T0.reg |= MCAN_TX_ELEMENT_T0_STANDARD_ID(id_value);
	tx_element.T1.reg = (MCAN_TX_ELEMENT_T1_DLC(MCAN_TX_ELEMENT_T1_DLC_DATA64_Val) |
	MCAN_TX_ELEMENT_T1_FDF | MCAN_TX_ELEMENT_T1_BRS);
	for (i = 0; i < CONF_MCAN_ELEMENT_DATA_SIZE; i++) {
		tx_element.data[i] = *data;
		data++;
	}

	mcan_set_tx_buffer_element(&mcan_instance, &tx_element,
	MCAN_TX_BUFFER_INDEX);
	mcan_tx_transfer_request(&mcan_instance, 1 << MCAN_TX_BUFFER_INDEX);
}

void mcan_fd_send_extended_message(uint32_t id_value, uint8_t *data)
{
	uint32_t i;
	struct mcan_tx_element tx_element;

	mcan_get_tx_buffer_element_defaults(&tx_element);
	tx_element.T0.reg |= MCAN_TX_ELEMENT_T0_EXTENDED_ID(id_value) |
	MCAN_TX_ELEMENT_T0_XTD;
	tx_element.T1.reg = (MCAN_TX_ELEMENT_T1_EFC |
	MCAN_TX_ELEMENT_T1_DLC(MCAN_TX_ELEMENT_T1_DLC_DATA64_Val) |
	MCAN_TX_ELEMENT_T1_FDF | MCAN_TX_ELEMENT_T1_BRS);
	for (i = 0; i < CONF_MCAN_ELEMENT_DATA_SIZE; i++) {
		tx_element.data[i] = *data;
		data++;
	}

	mcan_set_tx_buffer_element(&mcan_instance, &tx_element,
	MCAN_TX_BUFFER_INDEX);
	mcan_tx_transfer_request(&mcan_instance, 1 << MCAN_TX_BUFFER_INDEX);
}

void MCAN1_INT0_Handler(void)
{
	volatile uint32_t status, i, rx_buffer_index;
	status = mcan_read_interrupt_status(&mcan_instance);

	if (status & MCAN_RX_BUFFER_NEW_MESSAGE) {
		mcan_clear_interrupt_status(&mcan_instance, MCAN_RX_BUFFER_NEW_MESSAGE);
		for (i = 0; i < CONF_MCAN0_RX_BUFFER_NUM; i++) {
			if (mcan_rx_get_buffer_status(&mcan_instance, i)) {
				rx_buffer_index = i;
				mcan_rx_clear_buffer_status(&mcan_instance, i);
				mcan_get_rx_buffer_element(&mcan_instance, &rx_element_buffer,
				rx_buffer_index);
				if (rx_element_buffer.R0.bit.XTD) {
					printf("\n\r Extended FD message received in Rx buffer. The received data is: \r\n");
					} else {
					printf("\n\r Standard FD message received in Rx buffer. The received data is: \r\n");
				}
				for (i = 0; i < CONF_MCAN_ELEMENT_DATA_SIZE; i++) {
					printf("  %d",rx_element_buffer.data[i]);
				}
				printf("\r\n\r\n");
			}
		}
	}

	if (status & MCAN_RX_FIFO_0_NEW_MESSAGE) {
		mcan_clear_interrupt_status(&mcan_instance, MCAN_RX_FIFO_0_NEW_MESSAGE);
		mcan_get_rx_fifo_0_element(&mcan_instance, &rx_element_fifo_0,
		standard_receive_index);
		mcan_rx_fifo_acknowledge(&mcan_instance, 0,
		standard_receive_index);
		standard_receive_index++;
		if (standard_receive_index == CONF_MCAN0_RX_FIFO_0_NUM) {
			standard_receive_index = 0;
		}
		if (rx_element_fifo_0.R1.bit.EDL) {
			printf("\n\r Standard FD message received in FIFO 0. The received data is: \r\n");
			for (i = 0; i < CONF_MCAN_ELEMENT_DATA_SIZE; i++) {
				printf("  %d",rx_element_fifo_0.data[i]);
			}
			} else {
			printf("\n\r Standard normal message received in FIFO 0. The received data is: \r\n");
			for (i = 0; i < rx_element_fifo_0.R1.bit.DLC; i++) {
				printf("  %d",rx_element_fifo_0.data[i]);
			}
		}
		printf("\r\n\r\n");
	}

	if (status & MCAN_RX_FIFO_1_NEW_MESSAGE) {
		mcan_clear_interrupt_status(&mcan_instance, MCAN_RX_FIFO_1_NEW_MESSAGE);
		mcan_get_rx_fifo_1_element(&mcan_instance, &rx_element_fifo_1,
		extended_receive_index);
		mcan_rx_fifo_acknowledge(&mcan_instance, 0,
		extended_receive_index);
		extended_receive_index++;
		if (extended_receive_index == CONF_MCAN0_RX_FIFO_1_NUM) {
			extended_receive_index = 0;
		}

		printf("\n\r Extended FD message received in FIFO 1. The received data is: \r\n");
		for (i = 0; i < CONF_MCAN_ELEMENT_DATA_SIZE; i++) {
			printf("  %d",rx_element_fifo_1.data[i]);
		}
		printf("\r\n\r\n");
	}

	if ((status & MCAN_ACKNOWLEDGE_ERROR)
	|| (status & MCAN_FORMAT_ERROR)) {
		mcan_clear_interrupt_status(&mcan_instance, MCAN_ACKNOWLEDGE_ERROR
		| MCAN_FORMAT_ERROR);
		printf("Protocol error, please double check the clock in two boards. \r\n\r\n");
	}

	if (status & MCAN_BUS_OFF) {
		mcan_clear_interrupt_status(&mcan_instance, MCAN_BUS_OFF);
		mcan_stop(&mcan_instance);
		printf(": MCAN bus off error, re-initialization. \r\n\r\n");
		configure_mcan();
	}
}
