/**
 ******************************************************************************
 * @author: Nark
 * @date:   29/02/2024
 ******************************************************************************
**/

#include "console.h"
#include "io_cfg.h"
#include "xprintf.h"

void console_init() {
    #if DBG_EN
        xfunc_output = (void(*)(int))usart1_put_char;
    #endif
}