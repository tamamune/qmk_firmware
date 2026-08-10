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
