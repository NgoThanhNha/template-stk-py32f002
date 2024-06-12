/**
 ******************************************************************************
 * @author: Nark
 * @date:   29/05/2024
 ******************************************************************************
**/

#include "startup_py32f002.h"

/* peripheral driver */
#include "system_py32f0xx.h"
#include "system_irq.h"
#include "io_cfg.h"

/* application */
#include "app.h"
#include "app_dbg.h"

/* define the addresses of data and bss sections */
extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss, _estack;
extern void (*__preinit_array_start[])();
extern void (*__preinit_array_end[])();
extern void (*__init_array_start[])();
extern void (*__init_array_end[])();

static void sys_banner();

/* reset handler */
void reset_handler(void) {
    /* call the system init function */
    SystemInit();

    uint32_t *src, *dest;

    /*------------------------------------------------------------------*/
    /*      copy the data segment initializers from flash to SRAM       */
    /*------------------------------------------------------------------*/
    /* pointer start address in flash */
    src = &_sidata;
    /* pointer start address in sram */
    dest = &_sdata;
    while (dest < &_edata) {
        *dest++ = *src++;
    }

    /* zero fill to .bss section */
    dest = &_sbss;
    while (dest < &_ebss) {
        *dest++ = 0;
    }

    volatile unsigned i, cnt;
    
	/* invoke all static constructors */
	cnt = __preinit_array_end - __preinit_array_start;
	for (i = 0; i < cnt; i++)
		__preinit_array_start[i]();

	cnt = __init_array_end - __init_array_start;
	for (i = 0; i < cnt; i++)
		__init_array_start[i]();

    /* uart1 init */
    usart1_init();

    /* system banner */
    sys_banner();
    
    /* go to the main application */
    app();
}

/* PY32F002 cortex-M0+ processor exception vector table */
__attribute__((section(".isr_vector"))) void (*const g_pfnVectors[])(void) = {
    (void (*)(void))&_estack,                       // Stack pointer
    reset_handler,                                  // Reset Handler
    nmi_handler,                                    // NMI Handler
    hardfault_handler,                              // Hard Fault Handler
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    svc_handler,                                    // SVCall Handler
    0,                                              // Debug Monitor Handler
    0,                                              // Reserved
    pendsv_handler,                                 // PendSV Handler
    system_tick_handler,                            // SysTick Handler

    0,                                              // Reserved
    0,                                              // Reserved 
    0,                                              // Reserved
    0,                                              // FLASH
    0,                                              // RCC
    0,                                              // EXTI Line 0 and 1
    0,                                              // EXTI Line 2 and 3 
    0,                                              // EXTI Line 4 to 15
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // ADC & COMP1
    0,                                              // TIM1 Break, Update, Trigger and Commutation
    0,                                              // TIM1 Capture Compare
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // LPTIM1
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // TIM16
    0,                                              // Reserved
    0,                                              // I2C1
    0,                                              // Reserved
    0,                                              // SPI1
    0,                                              // Reserved
    default_handler,                                // USART1
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
    0,                                              // Reserved
};

void sys_banner() {
    SYS_PRINTLN("\n");
    SYS_PRINTLN(" ___  ____  _  _ ");
    SYS_PRINTLN("/ __)(_  _)( )/ )");
    SYS_PRINTLN("\\__ \\  )(  (   (");
    SYS_PRINTLN("(___/ (__) (_)\\_)");
    SYS_PRINTLN("\n");
}