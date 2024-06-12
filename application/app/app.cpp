/**
 ******************************************************************************
 * @author: Nark
 * @date:   29/05/2024
 ******************************************************************************
**/

#include "app.h"

/* kernel includes */
#include "message.h"
#include "stk.h"
#include "timer.h"

/* peripheral includes */
#include "io_cfg.h"
#include "sys_ctrl.h"

/* common includes */
#include "screen_manager.h"
#include "button.h"
#include "led.h"

/* libraris includes */
#include "ssd1306.h"

/* application includes */
#include "app_dbg.h"
#include "bsp.h"
#include "task_list.h"
#include "task_display.h"
#include "screen_idle.h"

void app() {
    /* system tick init */
    system_tick_init();

    /* io init */
    io_init();

    /* led life */
    led_init_func(&led_life, led_life_on, led_life_off);
    led_blink_set(&led_life, 1000);

    /* button init */
    button_init_func(&button_up, button_up_read, button_up_callback);
    button_init_func(&button_down, button_down_read, button_down_callback);
    button_init_func(&button_mode, button_mode_read, button_mode_callback);

    /* stk init */
    msg_init();
    task_create((task_t*)&app_task_table);
    timer_init();

    /* display init */
    view_render.initialize();

    /* screen manager init */
    scr_mng_init(&app_screen, screen_idle_handler);
    
    /* kernel start */
    task_run();
}


 