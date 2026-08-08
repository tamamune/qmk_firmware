#pragma once

#ifdef OLED_ENABLE
    /* Mapping I2C2 for OLED */
    #define I2C1_SCL_PIN B10
    #define I2C1_SDA_PIN B11
    #define I2C_DRIVER I2CD2
#endif

#define RGB_MATRIX_STARTUP_VAL 0
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
