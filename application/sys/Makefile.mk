CFLAGS 		+= -I./sys
CPPFLAGS 	+= -I./sys

VPATH += sys

#C source files 
SOURCES += sys/startup/startup_py32f002.c
SOURCES += sys/startup/io_cfg.c
SOURCES += sys/startup/system_irq.c
SOURCES += sys/startup/platform.c
SOURCES += sys/startup/sys_ctrl.c