/**
 ******************************************************************************
 * @author: Nark
 * @date:   29/05/2024
 ******************************************************************************
**/

#ifndef __SYSTEM_IRQ_H__
#define __SYSTEM_IRQ_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>

/* system interrupt functions */
extern void default_handler();
extern void nmi_handler();
extern void hardfault_handler();
extern void svc_handler();
extern void pendsv_handler();
extern void system_tick_handler();

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_IRQ_H */
