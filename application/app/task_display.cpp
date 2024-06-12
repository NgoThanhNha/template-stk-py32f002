/**
 ******************************************************************************
 * @author: Nark
 * @date:   17/05/2024
 ******************************************************************************
**/

#include "task_display.h"

#include "stk.h"
#include "message.h"
#include "timer.h"

#include "io_cfg.h"
#include "screen_manager.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"

scr_mng_t app_screen;
Adafruit_SSD1306 view_render;

void task_display_handler(stk_msg_t* msg) {
    screen_mng_dispatch(msg);
}