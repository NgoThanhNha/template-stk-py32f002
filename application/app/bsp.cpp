/**
 ******************************************************************************
 * @author: Nark
 * @date:   25/05/2024
 ******************************************************************************
**/

#include "bsp.h"

#include "stk.h"
#include "message.h"
#include "timer.h"

#include "io_cfg.h"

#include "button.h"
#include "screen_manager.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"
#include "task_display.h"

button_t button_mode;
button_t button_up;
button_t button_down;

void button_up_callback(void* _button) {

    button_t* button = (button_t*)(_button);

    switch (button->state) {
    case BUTTON_STATE_PRESSED:
        APP_PRINTLN("[BUTTON_CALLBACK] BUTTON_UP_PRESSED");
        break;

    case BUTTON_STATE_LONG_PRESSED:
        APP_PRINTLN("[BUTTON_CALLBACK] BUTTON_UP_LONG_PRESSED");
        break;

    case BUTTON_STATE_RELEASED:
        APP_PRINTLN("[BUTTON_CALLBACK] BUTTON_UP_RELEASED");
        break;

    default:
        break;
    }
}

void button_down_callback(void* _button) {

    button_t* button = (button_t*)(_button);

    switch (button->state) {
    case BUTTON_STATE_PRESSED:
        APP_PRINTLN("[BUTTON_CALLBACK] BUTTON_DOWN_PRESSED");
        break;

    case BUTTON_STATE_LONG_PRESSED:
        APP_PRINTLN("[BUTTON_CALLBACK] BUTTON_DOWN_LONG_PRESSED");
        break;

    case BUTTON_STATE_RELEASED:
        APP_PRINTLN("[BUTTON_CALLBACK] BUTTON_DOWN_RELEASED");
        break;

    default:
        break;
    }
}

void button_mode_callback(void* _button) {

    button_t* button = (button_t*)(_button);

    switch (button->state) {
    case BUTTON_STATE_PRESSED:
        APP_PRINTLN("[BUTTON_CALLBACK] BUTTON_MODE_PRESSED");
        break;

    case BUTTON_STATE_LONG_PRESSED:
        APP_PRINTLN("[BUTTON_CALLBACK] BUTTON_MODE_LONG_PRESSED");
        break;

    case BUTTON_STATE_RELEASED:
        APP_PRINTLN("[BUTTON_CALLBACK] BUTTON_MODE_RELEASED");
        break;

    default:
        break;
    }
}