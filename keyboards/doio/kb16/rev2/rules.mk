SRC += ./lib/layer_status/layer_status.c
SRC += ./lib/logo.c

# Configure for 128K flash
# MCU_LDSCRIPT = STM32F103xB
# 上はデフォルト

# 下は書き換え部分
# MCU name
MCU = STM32F103

# Bootloader selection
# Cannot use `BOOTLOADER = stm32duino` due to the need to override
# `MCU_LDSCRIPT`, therefore all parameters need to be specified here manually.
OPT_DEFS += -DBOOTLOADER_STM32DUINO
MCU_LDSCRIPT = STM32F103xB_stm32duino_bootloader
BOARD = STM32_F103_STM32DUINO
BOOTLOADER_TYPE = stm32duino
DFU_ARGS = -d 1EAF:0003 -a 2 -R
DFU_SUFFIX_ARGS = -v 1EAF -p 0003

# OLED enabled
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

# RGB Matrix enabled
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
