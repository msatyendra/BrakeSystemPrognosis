#ifndef MCAN_DRIVER_H_
#define MCAN_DRIVER_H_

#include <asf.h>
#include <string.h>
#include <conf_mcan.h>

/* mcan_filter_setting */
#define MCAN_RX_STANDARD_FILTER_INDEX_0    0
#define MCAN_RX_STANDARD_FILTER_INDEX_1    1
#define MCAN_RX_STANDARD_FILTER_ID_0     0x45A
#define MCAN_RX_STANDARD_FILTER_ID_0_BUFFER_INDEX     2
#define MCAN_RX_STANDARD_FILTER_ID_1     0x469
#define MCAN_RX_EXTENDED_FILTER_INDEX_0    0
#define MCAN_RX_EXTENDED_FILTER_INDEX_1    1
#define MCAN_RX_EXTENDED_FILTER_ID_0     0x100000A5
#define MCAN_RX_EXTENDED_FILTER_ID_0_BUFFER_INDEX     1
#define MCAN_RX_EXTENDED_FILTER_ID_1     0x10000096

/* mcan_receive_message_setting */
static volatile uint32_t standard_receive_index = 0;
static volatile uint32_t extended_receive_index = 0;
static struct mcan_rx_element_fifo_0 rx_element_fifo_0;
static struct mcan_rx_element_fifo_1 rx_element_fifo_1;
static struct mcan_rx_element_buffer rx_element_buffer;

/* mcan_transfer_message_setting */
#define MCAN_TX_BUFFER_INDEX    0

void configure_mcan(void);
void mcan_set_standard_filter_0(void);
void mcan_set_standard_filter_1(void);
void mcan_set_extended_filter_0(void);
void mcan_set_extended_filter_1(void);
void mcan_send_standard_message(uint32_t id_value, uint8_t *data);
void mcan_fd_send_standard_message(uint32_t id_value, uint8_t *data);
void mcan_fd_send_extended_message(uint32_t id_value, uint8_t *data);

void MCAN1_INT0_Handler(void);

#endif /* MCAN_DRIVER_H_ */