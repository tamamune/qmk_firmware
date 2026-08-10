#include "quantum.h"

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

#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    // RGBがOFFの時は全LED範囲を黒(0,0,0)にして強制消灯
    if (!rgb_matrix_is_enabled()) {
        for (uint8_t i = led_min; i < led_max; i++) {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
        return false;
    }
    return rgb_matrix_indicators_advanced_user(led_min, led_max);
}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_is_enabled()) {
        rgb_matrix_set_color_all(0, 0, 0);
        return false;
    }
    return rgb_matrix_indicators_user();
}
#endif
