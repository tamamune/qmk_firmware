#pragma once

#ifdef OLED_ENABLE
    /* Mapping I2C2 for OLED */
    #define I2C1_SCL_PIN B10
    #define I2C1_SDA_PIN B11
    #define I2C_DRIVER I2CD2
    #define OLED_UPDATE_INTERVAL 60
#endif

/* RGB Matrixの初期状態を「単色・黒（消灯）」に指定 */
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_STARTUP_HSV 0, 0, 0
#define RGB_MATRIX_STARTUP_VAL 0

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#define WS2812_TRST_US 300
