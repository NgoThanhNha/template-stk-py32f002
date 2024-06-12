/**
 ******************************************************************************
 * @author: Nark
 * @date:   12/06/2024
 ******************************************************************************
**/

#ifndef __SCREEN_IDLE_H__
#define __SCREEN_IDLE_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

#include "message.h"

#define SCREEN_WIDTH                        (128)
#define SCREEN_HEIGHT                       (64)
#define NUM_BALL_MAX                        (5)

typedef struct {
    int x, y, axis_x, axis_y, radius, slope;
} ball_t;

extern uint8_t screen_idle_polling_state;
extern void screen_idle_handler(stk_msg_t* msg);

#ifdef __cplusplus
}
#endif

#endif /* __SCREEN_IDLE_H__ */