#include "keymap.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty */
    [_QWERTY] = LAYOUT(
        KC_Q,  KC_W,  KC_E,    KC_R,   KC_T, KC_TAB,
        KC_A,  KC_S,  KC_D,    KC_F,   KC_G,
        KC_Z,  KC_X,  KC_C,    KC_V,   KC_B,
        KC_A1, KC_A2, KC_A3,
        KC_Y,  KC_U,  KC_I,    KC_O,   KC_P, KC_BSPC,
        KC_H,  KC_J,  KC_K,    KC_L,   RSFT_T(KC_SCLN),
        KC_N,  KC_M,  KC_COMM, KC_DOT, ALGR_T(KC_SLASH),
        KC_A4, KC_A5, KC_A6
        ),

    /* Dvorak */
    [_DVORAK] = LAYOUT (
        KC_SLASH, KC_COMM, KC_DOT, KC_P, KC_Y, KC_TAB,
        KC_A,     KC_O,    KC_E,   KC_U, KC_I,
        KC_SCLN,  KC_Q,    KC_J,   KC_K, KC_X,
        KC_A1,    KC_A2,   KC_A3,
        KC_F,     KC_G,    KC_C,   KC_R, KC_L, KC_BSPC,
        KC_D,     KC_H,    KC_T,   KC_N, KC_S,
        KC_B,     KC_M,    KC_W,   KC_V, KC_Z,
        KC_A4,    KC_A5,   KC_A6
        ),

    /* Lower */
    [_LOWER] = LAYOUT(
        KC_1,    KC_2,    KC_3,          KC_0,    XXXXXXX,   _______,
        KC_4,    KC_5,    KC_6,          KC_QUOT, KC_DQUO,
        KC_7,    KC_8,    KC_9,          KC_COLN, KC_SCLN,
        _______, _______, _______,
        KC_LPRN, KC_RPRN, KC_AT,         KC_HASH, KC_DOLLAR, _______,
        KC_LBRC, KC_RBRC, ALGR(KC_SLSH), KC_QUES, KC_PIPE,
        KC_LCBR, KC_RCBR, KC_LT,         KC_GT,   KC_BSLS,
        _______, _______, _______
    ),

    /* Raise */
    [_RAISE] = LAYOUT(
    	KC_ESC,           KC_CIRC, KC_ASTR, KC_MINUS, KC_UNDS,    _______,
        KC_CAPS,          KC_TILD, KC_PERC, KC_PLUS,  KC_EQL,
        XXXXXXX,          KC_GRV,  XXXXXXX, XXXXXXX,  XXXXXXX,
        _______,          _______, _______,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,     _______,
        KC_LEFT,          KC_DOWN, KC_UP,   KC_RIGHT, KC_AMPR,
        ALGR(LSFT(KC_1)), KC_EXLM, XXXXXXX, XXXXXXX,  TG(_MOUSE),
        _______,          _______, _______
        ),

    /*Adjust(Lower+Raise) */
    [_ADJUST] = LAYOUT(                         \
        KC_F1,    KC_F2,       KC_F3,               KC_F4,         KC_F5,   _______,
        KC_F6,    KC_F7,       KC_F8,               KC_F9,         KC_F10,
        KC_F11,   KC_F12,      DF(_QWERTY),         DF(_DVORAK),   RESET,
        _______,  _______,     _______,
        KC__MUTE, KC__VOLDOWN, KC__VOLUP,           KC_F14,        KC_F15,  _______,
        KC_HOME,  KC_PGDN,     KC_PGUP,             KC_END,        XXXXXXX,
        XXXXXXX,  XXXXXXX,     LCTL(LSFT(KC_PSCR)), LSFT(KC_PSCR), KC_PSCR,
        _______,  _______,     _______
        ),

    /*Emacs*/
    [_EMACS] = LAYOUT(                                                  \
        EM_SPLIT_NONE, EM_SPLIT_H,   EM_SPLIT_V,  EM_W_INC_V,  EM_W_INC_H,  _______,
        EM_BUF_SELECT, EM_BUF_OTHER, EM_BUF_HIDE, EM_BUF_KILL, XXXXXXX,
        EM_REG_SET,    EM_REG_JUMP,  XXXXXXX,     EM_ORG_CL_I, EM_ORG_CL_O,
        _______,       _______,      _______,
        XXXXXXX,       XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,
        EM_COMMENT,    EM_QUERY_R,   EM_REGEX_R,  XXXXXXX,     XXXXXXX,
        EM_MAC_ST,     EM_MAC_END,   EM_TOP,      EM_BOTTOM,   EM_ZAP,
        _______, _______, _______
        ),

    /*Symbol*/
    [_SYMBOL] = LAYOUT(
        _______,    _______, _______, _______, _______, _______,
        ALGR(KC_A), _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______
        ),

    /*Mouse*/
    [_MOUSE] = LAYOUT(                                              \
        XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        KC_WH_L, KC_WH_D, KC_WH_U,    KC_WH_R,    XXXXXXX,
        KC_MS_L, KC_MS_D, KC_MS_U,    KC_MS_R,    _______,
        XXXXXXX, XXXXXXX, _______
        )
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool emacs_key(char *str, keyrecord_t *record) {
    if (record->event.pressed) {
        send_string(str);
    }
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EM_TOP:
        return emacs_key(SS_LALT("<"), record);
        break;
    case EM_BOTTOM:
        return emacs_key(SS_LALT(">"), record);
        break;
    case EM_REG_SET:
        return emacs_key(SS_LCTRL("x")"r 1", record);
        break;
    case EM_REG_JUMP:
        return emacs_key(SS_LCTRL("x")"rj1", record);
        break;
    case EM_MAC_ST:
        return emacs_key(SS_LCTRL("x")"(", record);
        break;
    case EM_MAC_END:
        return emacs_key(SS_LCTRL("x")")", record);
        break;
    }
    return true;
}
