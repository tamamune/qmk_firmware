#pragma once

/* Custom OLED Font */
#define OLED_FONT_H "./lib/glcdfont.c"

/* ★親設定の定義を一度解除してから再定義する */
#undef RGB_MATRIX_FPS
#define RGB_MATRIX_FPS 20

#define OLED_UPDATE_INTERVAL 50
