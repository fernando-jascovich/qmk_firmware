/* Copyright 2020 Fernando Jascovich
 *
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _DVORAK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_DVORAK] = LAYOUT(
  		KC_SLSH,  KC_COMM, KC_DOT, KC_P, KC_Y, KC_ESC,
		KC_A,     KC_O,    KC_E,   KC_U, KC_I,
		KC_COLN,  KC_Q,    KC_J,   KC_K, KC_X,
		KC_TAB,   KC_LALT, KC_LCTRL,
		KC_F,     KC_G,   KC_C, KC_R, KC_L, KC_BSPC,
		KC_D,     KC_H,   KC_T, KC_N, KC_S,
		KC_B,     KC_M,   KC_W, KC_V, KC_Z,
        KC_SPC, KC_ENT, KC_LGUI
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
