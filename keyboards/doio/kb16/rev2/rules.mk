# OLED用カスタムファイルの読み込みを無効化（行頭に # を追加）
# SRC += ./lib/layer_status/layer_status.c
# SRC += ./lib/logo.c

# Configure for 128K flash
MCU_LDSCRIPT = STM32F103xB

OLED_ENABLE = no
RGB_MATRIX_ENABLE = yes
