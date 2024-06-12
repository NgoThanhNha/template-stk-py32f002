CFLAGS += -I./drivers/peripherals/ll_drivers/inc
CPPFLAGS += -I./drivers/peripherals/ll_drivers/inc
CFLAGS += -I./drivers/peripherals/ll_drivers
CPPFLAGS += -I./drivers/peripherals/ll_drivers

VPATH += ./drivers/peripherals/ll_drivers/src

# C source files
SOURCES += ./drivers/peripherals/ll_drivers/src/py32f0xx_ll_gpio.c
SOURCES += ./drivers/peripherals/ll_drivers/src/py32f0xx_ll_rcc.c
SOURCES += ./drivers/peripherals/ll_drivers/src/py32f0xx_ll_usart.c
