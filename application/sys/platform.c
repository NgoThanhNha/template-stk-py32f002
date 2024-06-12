/**
 ******************************************************************************
 * @author: Nark
 * @date:   02/05/2024
 ******************************************************************************
**/

#include "platform.h"

#include "py32f0xx.h"
#include "core_cm0plus.h"
#include "core_cmFunc.h"
#include "cmsis_gcc.h"

#include "io_cfg.h"
#include "sys_ctrl.h"

#include "app_dbg.h"

void enable_interrupts() {
	__enable_irq();
}

void disable_interrupts() {
	__disable_irq();
}

void sys_ctrl_delay_ms(volatile uint32_t count) {
    __IO uint32_t currentTicks = SysTick->VAL;

    /* number of ticks per millisecond */
    const uint32_t tickPerMs = SysTick->LOAD + 1;

    /* number of ticks to count */
    const uint32_t nbTicks = ((count - ((count > 0) ? 1 : 0)) * tickPerMs);

    /* number of elapsed ticks */
    uint32_t elapsedTicks = 0;
    __IO uint32_t oldTicks = currentTicks;
    do {
        currentTicks = SysTick->VAL;
        elapsedTicks += (oldTicks < currentTicks) ? tickPerMs + oldTicks - currentTicks :
                                                    oldTicks - currentTicks;
        oldTicks = currentTicks;
    } while (nbTicks > elapsedTicks);
}

void fatal_error(const char* fatal_info, uint8_t fatal_id) {
    disable_interrupts();
    SYS_PRINT("\n");
    SYS_PRINTLN("************************ FATAL_ERROR ************************");
    SYS_PRINT("[FATAL_TYPE]: ");
    SYS_PRINT(fatal_info);
    SYS_PRINT(" -> ");
    SYS_PRINT("[FATAL_ID]: ");
    switch (fatal_id) {
    case 0x01:
        SYS_PRINTLN("0x01");
        break;

    case 0x02:
        SYS_PRINTLN("0x02");
        break;

    case 0x03:
        SYS_PRINTLN("0x03");
        break;

    case 0x04:
        SYS_PRINTLN("0x04");
        break;

    case 0x05:
        SYS_PRINTLN("0x05");
        break;

    default:
        break;
    }

    SYS_PRINT("\n");
    while (1) {
        led_life_on();
        sys_ctrl_delay_ms(100);
        led_life_off();
        sys_ctrl_delay_ms(100); 
    }
}