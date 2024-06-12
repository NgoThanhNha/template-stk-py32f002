CFLAGS += -I./drivers/peripherals/CMSIS/Include
CFLAGS += -I./drivers/peripherals/CMSIS/Include

CPPFLAGS += -I./drivers/peripherals/CMSIS/Include
CPPFLAGS += -I./drivers/peripherals/CMSIS/Include

CFLAGS += -I./drivers/peripherals/CMSIS/Device/PY32F0xx/Include
CFLAGS += -I./drivers/peripherals/CMSIS/Device/PY32F0xx/Include

CPPFLAGS += -I./drivers/peripherals/CMSIS/Device/PY32F0xx/Include
CPPFLAGS += -I./drivers/peripherals/CMSIS/Device/PY32F0xx/Include

VPATH += drivers/peripherals/CMSIS/Device/PY32F0xx/Source

# C SOURCE FILES 
SOURCES += ./drivers/peripherals/CMSIS/Device/PY32F0xx/Source/system_py32f0xx.c