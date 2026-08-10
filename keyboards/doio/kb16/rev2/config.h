#pragma once

#ifdef OLED_ENABLE
    /* Mapping I2C2 for OLED */
    #define I2C1_SCL_PIN B10
    #define I2C1_SDA_PIN B11
    #define I2C_DRIVER I2CD2
#endif

#ifdef RGB_MATRIX_ENABLE
  #undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 50
#endif

#define WS2812_SPI_USE_CIRCULAR_BUFFER
