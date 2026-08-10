#include "quantum.h"
#include "rgb_matrix.h"

// OLED animation
#include "./lib/logo.h"

// Default timeout for displaying boot logo.
#ifndef OLED_LOGO_TIMEOUT
    #define OLED_LOGO_TIMEOUT 5000
#endif

#ifdef OLED_ENABLE
    uint16_t startup_timer;

    oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
        startup_timer = timer_read();

        return rotation;
    }

    bool oled_task_kb(void) {
        static bool finished_logo = false;

        if ((timer_elapsed(startup_timer) < OLED_LOGO_TIMEOUT) && !finished_logo) {
            render_logo();
        } else {
            finished_logo = true;
            if (!oled_task_user()) {
                return false;
            }
        }
        return true;
    }
#endif

void matrix_scan_kb(void) {
#ifdef RGB_MATRIX_ENABLE
    // RGBがOFFの時は毎スキャンで全LEDへ黒(0,0,0)をセットし消灯を確定させる
    if (!rgb_matrix_is_enabled()) {
        rgb_matrix_set_color_all(0, 0, 0);
    }
#endif
    matrix_scan_user();
}

#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"

// 基板側での白色上書き処理を一切行わず、VIAやRGB_TOGの制御に任せる
bool rgb_matrix_indicators_kb(void) {
    return true;
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    return true;
}
#endif
