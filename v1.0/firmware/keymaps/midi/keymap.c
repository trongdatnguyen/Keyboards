
#include QMK_KEYBOARD_H
#include "microdrumpad.h"
#include "midi.h"

extern MidiDevice midi_device;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Layer Declarations
enum layer_number { _MIDI = 0, _LED};

// Tap Dance Declarations
enum {TD_MIDI = 0, TD_LED,          // Layer Tap Dance
      TD_RESET                      // Reset Tap Dance
};
uint8_t last_stayed_layer = 0;

// Encoder Declarations
int encoder_val = 0;

// RGB Matrix
enum custom_keycodes {
    FX01 = SAFE_RANGE,
    FX02,
    FX03,
    FX04,
    FX05,
    FX06,
    MOD01,
    MOD02,
    MIDI_CC_80,
    MIDI_CC_81
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FX01:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case FX02:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case FX03:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case FX04:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            rgb_matrix_mode(RGB_MATRIX_RAINBOW_PINWHEELS);
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case FX05:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_LETTER01);
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case FX06:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_LETTER02);
        } else {
            // when keycode QMKBEST is released
        }
        break;                                                 
    case MOD01:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            rgb_matrix_increase_hue();
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case MOD02:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            rgb_matrix_decrease_hue();
        } else {
            // when keycode QMKBEST is released
        }
        break;          
    case MIDI_CC_80: //General Purpose MIDI CC Controller
        if (record->event.pressed) {
            static bool a  = false;
            if (a == true)
            {// when keycode QMKBEST is pressed
            midi_send_cc(&midi_device, 0, 80, 0);
            }
            else
            {
            midi_send_cc(&midi_device, 0, 80,127);  
            }
            a = !a; 
        } else {
            //midi_send_cc(&midi_device, 0, 10, 127);
        }
        break;
    case MIDI_CC_81: //General Purpose MIDI CC Controller
        if (record->event.pressed) {
            static bool b  = false;
            if (b == true)
            {// when keycode QMKBEST is pressed
            midi_send_cc(&midi_device, 0, 81, 0);
            }
            else
            {
            midi_send_cc(&midi_device, 0, 81,127);  
            }
            b = !b; 
        } else {
            //midi_send_cc(&midi_device, 0, 10, 127);
        }
        break;               
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap _MIDI: MIDI Layer (Advanced)
   * ,-------------------------------.
   * |   CC80|      |  To LED|   CC81|
   * |-------------------------------|
   * |      C|    C#|       D|      E|
   * |-------------------------------|
   * |     G#|     A|      A#|      B|  
   * |-------------------------------|
   * |      E|     F|      F#|      G|
   * |-------------------------------|
   * |      C|    C#|       D|     D#|
   * `-------------------------------'
   */ 
    [_MIDI] = LAYOUT_full(
        MIDI_CC_80, _______,        TD(TD_MIDI),    MIDI_CC_81, 
        MI_C_1,     MI_Cs_1,        MI_D_1,         MI_Ds_1, 
        MI_Gs,      MI_A,           MI_As,          MI_B,    
        MI_E,       MI_F,           MI_Fs,          MI_G,    
        MI_C,       MI_Cs,          MI_D,           MI_Ds),

  /* Keymap _: LED Layer (Advanced)
   * ,-------------------------------.
   * |   Br+-|      | To MIDI|  Reset|
   * |-------------------------------|
   * |       |      |        |       |
   * |-------------------------------|
   * |   HUE+|  HUE-|        |       |  
   * |-------------------------------|
   * |   FX05|  FX06|        |       |
   * |-------------------------------|
   * |   FX01|  FX02|    FX03|   FX04|
   * `-------------------------------'
   */ 
    [_LED] = LAYOUT_full(
        KC_MPLY,          _______,            TD(TD_LED),         TD(TD_RESET), 
        _______,          _______,            _______,            _______, 
        MOD01,            MOD02,               _______,            _______, 
        FX05,             FX06,               _______,            _______, 
        FX01,             FX02,               FX03,               FX04),

};

// Tap Dance Layer
// To LED Layer
void dance_layer_MIDI(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {  // TAP ONCE
        layer_on(_LED);
    } else {  // TAP TWICE OR MORE
        layer_on(last_stayed_layer);
    }
}

void dance_layer_reset_MIDI(qk_tap_dance_state_t *state, void *user_data) { layer_off(_MIDI); }

// To MIDI Layer
void dance_layer_LED(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {  // TAP ONCE
        layer_on(_MIDI);
    } else {  // TAP TWICE OR MORE
        layer_on(last_stayed_layer);
        last_stayed_layer = _LED;
    }
}

void dance_layer_reset_LED(qk_tap_dance_state_t *state, void *user_data) { layer_off(_LED); }

// Tap Dance Reset
void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 4) {
    // Reset the keyboard if you tap the key more than three times
    reset_keyboard();
    reset_tap_dance(state);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MIDI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layer_MIDI, dance_layer_reset_MIDI), 
  [TD_LED]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layer_LED, dance_layer_reset_LED),
  [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset)
};


// Encoder
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case _MIDI:
                if (clockwise) {
                    encoder_val++;
                    midi_send_cc(&midi_device, 0, 80, encoder_val);
                } else {
                    encoder_val--;
                    midi_send_cc(&midi_device, 0, 80, encoder_val);
                }
                break;
            // case _MIDI:
            //     if (clockwise) {
            //         midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 65);
            //     } else {
            //         midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 63);
            //     }
            //     break;
            //     https://nickfever.com/Music/midi-cc-list
            case _LED:
                if (clockwise) {
                    tap_code(KC_BRMU);

                } else {
                    tap_code(KC_BRMD);
                }
                break;
            default:
                break;
        }
    }
};

// LED indicator for layer switching
void rgb_matrix_indicators_kb(void) {
  switch (biton32(layer_state)) {
      case 0:
        rgb_matrix_set_color(0, 0xFF, 0x00, 0xFF);
        break;
      case 1:
        rgb_matrix_set_color(0, 0xBF, 0xFF, 0x00);
        break;
}
}