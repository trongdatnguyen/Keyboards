#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 			0x0044
#define PRODUCT_ID 			0x0001
#define DEVICE_VER 			0x0001
#define MANUFACTURER 		Four By Four
#define PRODUCT 			Micro Drumpad
#define DESCRIPTION 		A 18 - key micro how swappable mechanical keyboard with a rotary encoder
#define DIODE_DIRECTION 	COL2ROW


/* Key Matrix Size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/* Key Matrix Pins */
#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F7 }
#define ENCODER_RESOLUTION 4
#define MATRIX_ROW_PINS { F4, B3, B2, B6, B4 }
#define MATRIX_COL_PINS { B1, B5, E6, D7 }
#define UNUSED_PINS

/* Bootloader */
#define CATERINA_BOOTLOADER

#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
#   define RGBLED_NUM 18
#	define DRIVER_LED_TOTAL 18
#   ifdef RGBLIGHT_ENABLE
#    	define RGBLIGHT_HUE_STEP 8
#    	define RGBLIGHT_SAT_STEP 8
#    	define RGBLIGHT_VAL_STEP 8
#    	define RGBLIGHT_LIMIT_VAL 150 /* The maximum brightness level */
#    	define RGBLIGHT_SLEEP         /* If defined, the RGB lighting will be switched off when the host goes to sleep */
                                   /*== all animations enable ==*/
// #    define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
//   #define RGBLIGHT_EFFECT_BREATHING
#   define RGBLIGHT_EFFECT_RAINBOW_MOOD
//   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
//   #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
#   define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING
#	elif defined RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES   // reacts to keypresses
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS  // reacts to keyreleases (instead of keypresses)
#	define RGB_MATRIX_DUAL_BEACON
#	endif
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE



/* Prevent use of disabled MIDI features in the keymap */
#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/
#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
#define MIDI_TONE_KEYCODE_OCTAVES 2

#define TAPPING_TERM 200 
