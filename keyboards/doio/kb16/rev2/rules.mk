SRC += ./lib/layer_status/layer_status.c
SRC += ./lib/logo.c

# Configure for 128K flash
/*MCU_LDSCRIPT = STM32F103xB*/
/*上はデフォルト*/

/*下は書き換え部分*/
# MCU name
MCU = STM32F103

# OLED enabled
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

# RGB Matrix enabled
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
