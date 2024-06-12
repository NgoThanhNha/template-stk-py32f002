/**
 ******************************************************************************
 * @author: Nark
 * @date:   29/05/2024
 ******************************************************************************
**/

#ifndef __SYS_CTRL_H__
#define __SYS_CTRL_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

extern volatile uint32_t system_tick_delay_counter;
extern uint32_t system_tick_init();
extern void delay_ms(uint32_t milliseconds);

#ifdef __cplusplus
}
#endif

#endif /* __SYS_CTRL_H__ */