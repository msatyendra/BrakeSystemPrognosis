/**
 * Satyendra Maurya
 * 2023ht65067
 * 27 March 2025
 * Brake System Prognosis - Firmware
 */

/* System Includes */
#include "asf.h"
#include "stdio_serial.h"
#include "conf_board.h"
#include "conf_clock.h"

/* FreeRTOS Includes */
#include <FreeRTOS.h>
#include <task.h>
#include <timers.h>
#include <queue.h>
#include <semphr.h>
#include <string.h>

/* Application Includes */
#include "sensors.h"

/* Prototypes for the standard FreeRTOS callback/hook functions implemented
within this file. */
void vApplicationMallocFailedHook( void );
void vApplicationIdleHook( void );
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );
void vApplicationTickHook( void );


/* Application Prototypes */
void vLEDTask(void *);

/** LED0 blink time, LED1 blink half this time, in ms */
#define BLINK_PERIOD     1000

#define STRING_EOL    "\r"
#define STRING_HEADER "\n-- Brake System Prognosis --\r\n" \
		"-- "BOARD_NAME" --\r\n" \
		"-- Satyendra Maurya - 2023ht65067 --\r\n" \
		"-- Compiled: "__DATE__" "__TIME__" --"STRING_EOL

/**
 *  Configure UART console.
 */
// [main_console_configure]
static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
#ifdef CONF_UART_CHAR_LENGTH
		.charlength = CONF_UART_CHAR_LENGTH,
#endif
		.paritytype = CONF_UART_PARITY,
#ifdef CONF_UART_STOP_BITS
		.stopbits = CONF_UART_STOP_BITS,
#endif
	};

	/* Configure console UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
}

// [main_console_configure]

/**
 *  \brief getting-started Application entry point.
 *
 *  \return Unused (ANSI-C compatibility).
 */
// [main]
int main(void)
{
//! [main_step_sys_init]
	/* Initialize the SAM system */
	sysclk_init();
	board_init();
//! [main_step_sys_init]

//! [main_step_console_init]
	/* Initialize the console uart */
	configure_console();
//! [main_step_console_init]
	
	/* Output example information */
	puts(STRING_HEADER);

//! [main_step_init_sensors]
	/* Initialize the sensors */	
	init_sensors();
//! [main_step_init_sensors]

	/* Configure FreeRTOS */
	puts("Configured FreeRTOS.\r");
	
	xTaskCreate(vLEDTask, "LED_Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	
	vTaskStartScheduler();
	
	while(1);
}

void vApplicationTickHook(void) {
	//will define later
}

void vApplicationMallocFailedHook( void )
{
	/* Called if a call to pvPortMalloc() fails because there is insufficient
	free memory available in the FreeRTOS heap.  pvPortMalloc() is called
	internally by FreeRTOS API functions that create tasks, queues, software
	timers, and semaphores.  The size of the FreeRTOS heap is set by the
	configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */

	/* Force an assert. */
	configASSERT( ( volatile void * ) NULL );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */

	/* Force an assert. */
	configASSERT( ( volatile void * ) NULL );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
volatile size_t xFreeHeapSpace;

	/* This is just a trivial example of an idle hook.  It is called on each
	cycle of the idle task.  It must *NOT* attempt to block.  In this case the
	idle task just queries the amount of FreeRTOS heap that remains.  See the
	memory management section on the http://www.FreeRTOS.org web site for memory
	management options.  If there is a lot of heap memory free then the
	configTOTAL_HEAP_SIZE value in FreeRTOSConfig.h can be reduced to free up
	RAM. */
	xFreeHeapSpace = xPortGetFreeHeapSize();

	/* Remove compiler warning about xFreeHeapSpace being set but never used. */
	( void ) xFreeHeapSpace;
}
/*-----------------------------------------------------------*/

void vLEDTask(void *pvParameters) {
	float temprature,pressure,vibration,pad_wear;
	uint32_t canfd_id;
	uint8_t can_data[64];
	while (1)
	{
		temprature = read_temperature_sensor();
		pressure = read_pressure_sensor();
		vibration = read_vibration_sensor();
		pad_wear = read_pad_wear_sensor();
		vTaskDelay(pdMS_TO_TICKS(100));
		memcpy(&can_data[TEMP_BASE],&temprature,sizeof(float));
		memcpy(&can_data[PRES_BASE],&pressure,sizeof(float));
		memcpy(&can_data[VIBR_BASE],&vibration,sizeof(float));
		memcpy(&can_data[PADW_BASE],&pad_wear,sizeof(float));
	}
}
