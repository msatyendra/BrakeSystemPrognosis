#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "asf.h"

#include "adc_driver.h"

/** The conversion data is done flag */
volatile bool is_conversion_done = false;

/** The conversion data value */
volatile uint32_t g_ul_value = 0;

void init_adc(void) {
	afec_enable(AFEC0);

	struct afec_config afec_cfg;

	afec_get_config_defaults(&afec_cfg);

	afec_init(AFEC0, &afec_cfg);

	afec_set_trigger(AFEC0, AFEC_TRIG_SW);

	struct afec_ch_config afec_ch_cfg;
	afec_ch_get_config_defaults(&afec_ch_cfg);
	afec_ch_cfg.gain = AFEC_GAINVALUE_0;
	afec_ch_set_config(AFEC0, AFEC_TEMPERATURE_SENSOR, &afec_ch_cfg);

	afec_channel_set_analog_offset(AFEC0, AFEC_PRESSURE_SENSOR, 0x200);
	
	afec_set_callback(AFEC0, AFEC_INTERRUPT_EOC_11, afec_press_sensor_end_conversion, 1);
}

void afec_press_sensor_end_conversion(void)
{
	g_ul_value = afec_channel_get_value(AFEC0, AFEC_PRESSURE_SENSOR);
	is_conversion_done = true;
}

uint16_t read_adc_channel(uint8_t channel) {
	if(is_conversion_done == true) {
		g_ul_value = afec_channel_get_value(AFEC0, AFEC_PRESSURE_SENSOR);
	}
	is_conversion_done = false;
	return g_ul_value;
}