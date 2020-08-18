/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "microdrumpad.h"
#include "midi.h"

extern MidiDevice midi_device;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number { _BASE = 0, _MIDI, _LED };
int encoder_val = 64;

// LED
enum rgb_matrix_effects {
      RGB_MATRIX_CYCLE_LEFT_RIGHT,      // Full tighter gradient spinning around center of keyboard
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BASE: (Base Layer) Default Layer
   * ,-------------------------------.
   * |   EC11|      |TD(MIDI)| Backsp|
   * |-------------------------------|
   * |      7|     8|       9|      +|
   * |-------------------------------|
   * |      6|     5|       4|      -|  
   * |-------------------------------|
   * |      3|     2|       1|      *|
   * |-------------------------------|
   * |      0|     .|  Return|      /|
   * `-------------------------------'
   */
    [_BASE] = LAYOUT_full(
        KC_MUTE,    _______,    MO(1),      MO(2),
        KC_P7,      KC_P8,      KC_P9,      KC_PPLS,
        KC_P4,      KC_P5,      KC_P6,      KC_PMNS,
        KC_P1,      KC_P2,      KC_P3,      KC_PAST,
        KC_P0,      KC_PDOT,    KC_PENT,    KC_PSLS),

  /* Keymap _MIDI: MIDI Layer (Advanced)
   * ,-------------------------------.
   * |   EC11|      |TD(LED )|   Exit|
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
        KC_TRNS,    _______,        _______,        _______, 
        MI_Cs,      MI_Cs_1,        MI_Ds,          MI_Ds_1, 
        MI_Gs,      MI_A,           MI_As,          MI_B,    
        MI_E,       MI_F,           MI_Fs,          MI_G,    
        MI_C,       MI_Cs,          MI_D,           MI_Ds),

  /* Keymap _: LED Layer (Advanced)
   * ,-------------------------------.
   * |   EC11|      |TD(BASE)|    TOG|
   * |-------------------------------|
   * |      P|     B|       R|      S|
   * |-------------------------------|
   * |       |      |        |       |  
   * |-------------------------------|
   * |       |   VAI|     SAI|    HUI|
   * |-------------------------------|
   * |       |   VAD|     SAD|    HUD|
   * `-------------------------------'
   */ 
    [_LED] = LAYOUT_full(
        KC_MPLY,        _______,            _______,            _______, 
        RGB_MODE_RAINBOW,        RGB_MODE_GRADIENT,  _______,            _______, 
        _______,        _______,            _______,            _______, 
        RGB_MOD,        RGB_VAI,            RGB_SAI,            RGB_HUI, 
        RGB_RMOD,       RGB_VAD,            RGB_SAD,            RGB_HUD),

};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case _BASE:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _MIDI:
                if (clockwise) {
                    encoder_val++;
                    midi_send_cc(&midi_device, 0, 10, encoder_val);
                } else {
                    encoder_val--;
                    midi_send_cc(&midi_device, 0, 10, encoder_val);
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
                    tap_code(KC_BRIU);

                } else {
                    tap_code(KC_BRID);
                }
                break;
            default:
                break;
        }
    }
}
