/**
 ******************************************************************************
 * @author: Nark
 * @date:   17/05/2024
 ******************************************************************************
**/

#ifndef __TASK_DISPLAY_H__
#define __TASK_DISPLAY_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

#include "message.h"

#include "ssd1306.h"
#include "screen_manager.h"


extern scr_mng_t app_screen;
extern Adafruit_SSD1306 view_render;
extern void task_display_handler(stk_msg_t* msg);

#ifdef __cplusplus
}
#endif

#endif /* __TASK_DISPLAY_H_ */