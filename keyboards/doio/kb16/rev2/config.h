#pragma once

/* Custom OLED Font */
#define OLED_FONT_H "./lib/glcdfont.c"

/* ★OLEDとRGBの更新周波数を下げてCPU割り込み（チラつき）を防ぐ */
#define OLED_UPDATE_INTERVAL 50   /* OLED更新頻度を抑える */
#define RGB_MATRIX_FPS 20         /* RGBフレームレートを抑える */
