/**
 ******************************************************************************
 * @author: Nark
 * @date:   29/05/2024
 ******************************************************************************
**/

#include "system_irq.h"

#include "message.h"
#include "stk.h"
#include "timer.h"

#include "io_cfg.h"
#include "platform.h"
#include "sys_ctrl.h"
#include "led.h"

void default_handler() {
	FATAL("SYSTEM", 0x01);
}

void nmi_handler() {
	FATAL("SYSTEM", 0x02);
}

void hardfault_handler() {
	FATAL("SYSTEM", 0x03);
}

void svc_handler() {
	FATAL("SYSTEM", 0x04);
}

void pendsv_handler() {
	FATAL("SYSTEM", 0x05);
}

void system_tick_handler() {
	timer_tick(1);
	system_tick_delay_counter++;
	led_polling(&led_life);
}