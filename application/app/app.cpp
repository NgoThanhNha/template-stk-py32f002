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
#include "led.h"

/* libraris includes */
#include "ssd1306.h"

/* application includes */
#include "task_list.h"

Adafruit_SSD1306 view_render;

void app() {
    /* system tick init */
    system_tick_init();

    /* io init */
    io_init();

    /* led run */
    led_init_func(&led_life, led_life_on, led_life_off);
    led_blink_set(&led_life, 1000);

    /* stk init */
    msg_init();
    task_create((task_t*)&app_task_table);
    timer_init();

    view_render.initialize();
    view_render.clear();
    view_render.setCursor(10, 10);
    view_render.setTextColor(1);
    view_render.setTextSize(1);
    view_render.print("Hello EPCB!");
    view_render.update();
    
    /* kernel start */
    task_run();
}


 