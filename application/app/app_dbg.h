/**
 ******************************************************************************
 * @author: Nark
 * @date:   12/06/2024
 ******************************************************************************
**/

#ifndef __APP_DBG_H__
#define __APP_DBG_H__

#ifdef __cplusplus
 extern "C" {
#endif 

#include "io_cfg.h"

#define DBG_EN          (1)

#if DBG_EN
    #define APP_PRINT(str)         usart1_put_string(str)
    #define APP_PRINTLN(str)       usart1_put_string(str"\n\r")
    #define SYS_PRINT(str)         usart1_put_string(str)
    #define SYS_PRINTLN(str)       usart1_put_string(str"\n\r")
#else
    #define APP_PRINT(fmt, ...)    
    #define SYS_PRINT(fmt, ...)             
#endif

#ifdef __cplusplus
}
#endif

#endif /* __APP_DBG_H__ */