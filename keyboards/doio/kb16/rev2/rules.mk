SRC += ./lib/layer_status/layer_status.c
SRC += ./lib/logo.c

# Configure for 128K flash
MCU_LDSCRIPT = STM32F103xB

EEPROM_DRIVER = vendor

# ★WS2812制御にPWM(DMA)ドライバを指定
WS2812_DRIVER = pwm
