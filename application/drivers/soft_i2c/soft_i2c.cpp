/**
 ******************************************************************************
 * @author: Nark
 * @date:   17/05/2024
 ******************************************************************************
**/

#include "soft_i2c.h"

#include "sys_ctrl.h"
#include "io_cfg.h"

void i2c_start() {
	ssd1306_clk_digital_write_high();
	ssd1306_data_digital_write_high();
	ssd1306_data_digital_write_low();
	ssd1306_clk_digital_write_low();
}

void i2c_stop() {
	ssd1306_clk_digital_write_low();
	ssd1306_data_digital_write_low();	
	ssd1306_clk_digital_write_high();
	ssd1306_data_digital_write_high();
}

void i2c_write_byte(uint8_t u8data) {
	for(uint8_t i = 0; i < 8; i++) {
        if ((u8data << i) & 0x80){
            ssd1306_data_digital_write_high();
        }
        else {
            ssd1306_data_digital_write_low();
        }
        ssd1306_clk_digital_write_high();
        ssd1306_clk_digital_write_low();
	}
    ssd1306_data_digital_write_high();
	ssd1306_clk_digital_write_high();

	ssd1306_clk_digital_write_low();
}