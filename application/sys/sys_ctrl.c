/**
 ******************************************************************************
 * @author: Nark
 * @date:   29/05/2024
 ******************************************************************************
**/

#include "sys_ctrl.h"

#include "py32f002ax5.h"
#include "system_py32f0xx.h"

volatile uint32_t system_tick_delay_counter = 0;

uint32_t system_tick_init() {
    SystemCoreClockUpdate();
    if (((SystemCoreClock / 1000) - 1UL) > SysTick_LOAD_RELOAD_Msk) {
        return (1);                                                   /* Reload value impossible */
    }

    SysTick->LOAD  = (uint32_t)((SystemCoreClock / 1000) - 1UL);                         /* set reload register */
    NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */
    SysTick->VAL   = 0UL;                                             /* Load the SysTick Counter Value */
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk   |
                    SysTick_CTRL_ENABLE_Msk;                         /* Enable SysTick IRQ and SysTick Timer */
    return (0);
}

void delay_ms(uint32_t milliseconds) {
    uint32_t start_tick = system_tick_delay_counter;
    while ((system_tick_delay_counter - start_tick) < milliseconds);
    system_tick_delay_counter = 0;
}