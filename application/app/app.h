/**
 ******************************************************************************
 * @author: Nark
 * @date:   29/05/2024
 ******************************************************************************
**/

#ifndef __APP_H__
#define __APP_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>

extern void app();

enum {
    /* TASK DISPLAY */
    SIG_SCREEN_UPDATE,
};

#ifdef __cplusplus
}
#endif

#endif /* __APP_H__ */
