/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "print.h"

#define _QWERTY 0
#define _DVORAK 2
#define _LOWER 5
#define _RAISE 6
#define _ADJUST 8
#define _MOUSE 10

enum my_keycodes {
    EM_W_F = SAFE_RANGE,
    EM_W_H,
    EM_W_V,
    EM_OTHER,
    EM_ERR_P,
    EM_ERR_N,
    EM_ERR_L
};

#include "./gui_helper.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,

LSFT_T(KC_TAB),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(_LOWER),KC_LGUI, KC_LCTL,  KC_SPACE,KC_ENTER,MO(_RAISE)
                                      //`--------------------------'  `--------------------------'

  ),

  [_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(_LOWER),KC_LGUI,KC_LCTL,   KC_SPACE,KC_ENTER,MO(_RAISE)
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       EM_W_F,  EM_W_V,  EM_W_H,EM_OTHER, XXXXXXX, XXXXXXX,                      KC_LPRN, KC_RPRN,  KC_GRV, KC_QUOT, KC_DQUO, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX,EM_ERR_L,EM_ERR_P,EM_ERR_N,                      KC_LBRC, KC_RBRC, KC_COLN, KC_SCLN, KC_PIPE, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LCBR, KC_RCBR,   KC_LT,   KC_GT, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_1,    KC_2,    KC_3,    KC_0, KC_MINS, KC_UNDS,                      KC_TILD, KC_CIRC, KC_ASTR, KC_PLUS,  KC_EQL,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_4,    KC_5,    KC_6,   KC_AT, KC_HASH,  KC_DLR,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_PERC, KC_AMPR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_7,    KC_8,    KC_9, XXXXXXX,ALGR(KC_SLSH),KC_QUES,         ALGR(LSFT(KC_1)),KC_EXLM, XXXXXXX, XXXXXXX, XXXXXXX,TG(_MOUSE),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,                         KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,DF(_QWERTY),DF(_DVORAK),QK_RBT,                KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, LSFT(KC_PSCR),KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2,                      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool should_continue = gui_onkeypress(keycode, record);
    if (!should_continue) {
        return false;
    }
    return true;
}

/*void keyboard_post_init_user(void) {*/
   /*Customise these values to desired behaviour*/
  /*debug_enable=true;*/
  /*debug_matrix=true;*/
  /*debug_keyboard=true;*/
  /*debug_mouse=true;*/
/*}*/
