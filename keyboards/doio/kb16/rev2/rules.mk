SRC += ./lib/layer_status/layer_status.c
SRC += ./lib/logo.c

# Configure for 128K flash
MCU_LDSCRIPT = STM32F103xB

WS2812_DRIVER = vendor
EEPROM_DRIVER = vendor
