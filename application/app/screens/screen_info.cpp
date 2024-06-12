/**
 ******************************************************************************
 * @author: Nark
 * @date:   12/06/2024
 ******************************************************************************
**/

#include "screen_info.h"

#include "stk.h"
#include "message.h"
#include "timer.h"

#include "platform.h"
#include "screen_manager.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"
#include "task_display.h"

#include <math.h>

void screen_info_handler(stk_msg_t* msg) {
    switch (msg->sig) {
    case SCREEN_ENTRY:
        APP_PRINT("[SCREEN] SCREEN_IDLE_ENTRY\n");
        break;

    default:
        break;
    }
}