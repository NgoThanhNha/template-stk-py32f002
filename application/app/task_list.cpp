/**
 ******************************************************************************
 * @author: Nark
 * @date:   17/05/2024
 ******************************************************************************
**/

#include "task_list.h"

#include "stk.h"
#include "message.h"
#include "timer.h"

#include "console.h"

#include "app.h"

task_t app_task_table[] = {
    /*************************************************************************/
	/* SYSTEM TASKS */
	/*************************************************************************/
    {TASK_TIMER_TICK_ID,              	task_timer_handler},

    /*************************************************************************/
	/* APP TASKS */
	/*************************************************************************/

    /*************************************************************************/
	/* END OF TABLE TASK */
	/*************************************************************************/
	{STK_EOT_TASK_ID, 					(pf_task)0}
};