#include "microdrumpad.h"

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    matrix_init_user();
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // put your per-action keyboard code here
    // runs for every action, just before processing by the firmware

    return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

    led_set_user(usb_led);
}

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config ={ {
    // Key Matrix to LED Index
    {NO_LED , NO_LED,  0,  1},
    {5      ,      4,  3,  2},
    {6      ,      7,  8,  9},
    {13     ,     12, 11, 10},
    {14     ,     15, 16, 17}  
}, {
    // LED Index to Physical Postion
                                    { 150,  0 },    { 224,  0 },
    { 224,  16 },   { 150,  16 },   { 75,  16 },    { 0,  16 },
    { 0,  32 },     { 75,  32 },    { 150,  32 },   { 224,  32 },
    { 224, 48  },   { 150,  48 },   { 75,  48 },    { 0,  48 },
    { 0, 64},       { 75, 64},      { 150, 64 },    { 224, 64 }    
}, {
    //LED Index to Flag
          4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4
}};
#endif