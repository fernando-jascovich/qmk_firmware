#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _DVORAK 1
#define _LOWER  3
#define _RAISE  4
#define _VIM    7
#define _MOUSE  10
#define _ADJUST 16

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_A1   MO(_LOWER)
#define KC_A2   LALT_T(KC_TAB)
#define KC_A3   KC_LCTRL
#define KC_A4   KC_SPACE
#define KC_A5   LGUI_T(KC_ENTER)
#define KC_A6   MO(_RAISE)

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
          KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y, KC_U, KC_I,    KC_O,   KC_P,             \
          KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H, KC_J, KC_K,    KC_L,   RSFT_T(KC_BSPC),  \
          KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N, KC_M, KC_COMM, KC_DOT, ALGR_T(KC_SLASH), \
          KC_A1, KC_A2, KC_A3, KC_A4, KC_A5, KC_A6 \
    ),
  [_DVORAK] = LAYOUT ( \
          ALGR_T(KC_SLASH), KC_COMM, KC_DOT, KC_P,  KC_Y,  KC_F, KC_G, KC_C, KC_R, KC_L, \
          KC_A,             KC_O,    KC_E,   KC_U,  KC_I,  KC_D, KC_H, KC_T, KC_N, KC_S, \
          RSFT_T(KC_BSPC),  KC_Q,    KC_J,   KC_K,  KC_X,  KC_B, KC_M, KC_W, KC_V, KC_Z, \
          KC_A1,            KC_A2,   KC_A3,  KC_A4, KC_A5, KC_A6 \
          ),
  [_LOWER] = LAYOUT(
          KC_1,    KC_2,    KC_3,    KC_0,         XXXXXXX, KC_LPRN, KC_RPRN, KC_AT,         KC_HASH, KC_DOLLAR,
          KC_4,    KC_5,    KC_6,    KC_QUOT,      KC_DQUO, KC_LBRC, KC_RBRC, ALGR(KC_SLSH), KC_QUES, KC_PIPE,
          KC_7,    KC_8,    KC_9,    KC_COLN,      KC_SCLN, KC_LCBR, KC_RCBR, KC_LT,         KC_GT,   KC_BSLS,
          _______, _______, _______, LCTL(KC_TAB), _______, _______ \
          ),
  [_RAISE] = LAYOUT(
          KC_ESC,  KC_CIRC, KC_ASTR, KC_MINS, KC_UNDS, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
          KC_CAPS, KC_TILD, KC_PERC, KC_PLUS, KC_EQL,  KC_LEFT,          KC_DOWN, KC_UP,   KC_RGHT, KC_AMPR,
          XXXXXXX, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, ALGR(LSFT(KC_1)), KC_EXLM, XXXXXXX, XXXXXXX, TG(_MOUSE),
          _______, _______, KC_TAB,  _______, _______, _______ \
          ),
  [_ADJUST] = LAYOUT(
          KC_F1,   KC_F2,   KC_F3,       KC_F4,       KC_F5,   KC__MUTE, KC__VOLDOWN,   KC__VOLUP,   LCTL(LSFT(KC_SPC)), LCTL(LSFT(KC_V)),
          KC_F6,   KC_F7,   KC_F8,       KC_F9,       KC_F10,  KC_HOME,  KC_PGDN,       KC_PGUP,     KC_END,             _______,
          KC_F11,  KC_F12,  DF(_QWERTY), DF(_DVORAK), RESET,   _______,  LGUI(KC_DOWN), LGUI(KC_UP), LSFT(KC_PSCR),      KC_PSCR,
          _______, _______, _______,     _______,     _______, _______ \
          ),
  [_MOUSE] =  LAYOUT( \
          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, \
          XXXXXXX, XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, \
          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    _______ \
          )
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool custom_key(keyrecord_t *record, const char *seq) {
  if (record->event.pressed) {
    send_string(seq);
  }
  return false;
}
