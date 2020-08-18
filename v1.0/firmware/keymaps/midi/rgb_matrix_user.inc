RGB_MATRIX_EFFECT(LETTER01)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool LETTER01(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb = hsv_to_rgb(rgb_matrix_config.hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(3, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(4, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(9, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(10, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(13, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(14, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(17, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS

RGB_MATRIX_EFFECT(LETTER02)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool LETTER02(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb = hsv_to_rgb(rgb_matrix_config.hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(1, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(7, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(8, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(9, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(10, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(12, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(15, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(16, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(17, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
