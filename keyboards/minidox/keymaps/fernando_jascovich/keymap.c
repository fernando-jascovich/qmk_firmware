#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |  GUI |LOWER | Ctrl |    |L_Alt | RAISE| Tab  |
 *                  `-------------| ---- |    |----- |------+------.
 *                                |Space |    |Enter |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
KC_Q,    KC_W,  KC_E,          KC_R,             KC_T,  KC_Y, KC_U, KC_I,    KC_O,   KC_P,    \
KC_A,    KC_S,  KC_D,          KC_F,             KC_G,  KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, \
KC_Z,    KC_X,  KC_C,          KC_V,             KC_B,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
KC_LGUI, LOWER, CTL_T(KC_SPC), ALT_T(KC_RETURN), RAISE, KC_TAB                                \
),


/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   `  |   -  |   =  |   [  |   ]  |           | Left | Down |  Up  | Right|   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |   \  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE]=LAYOUT(\
KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, \
_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, \
_______, _______, _______, _______, _______, _______                                      \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  Esc |      |   E  |      |      |           |      |   U  |   I  |   O  | Del  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |      |Mou 1 |Mou 2 |Mou 3 |           |Mou L |Mou D |Mou T |Mou R |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |MouAc1|MouAc2|MouAc3|           |Mou WL|Mou WD|Mou WT|Mou WR|      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    | R_Alt|      |BckSpc|
 *                  `-------------|      |    | ---- |------+------.
 *                                |      |    | Enter|
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT( \
KC_ESC,  _______, _______,      _______,         _______,      _______,       _______,       _______,     _______,        KC_DEL,  \
_______, _______, KC_MS_BTN1,   KC_MS_BTN2,      KC_MS_BTN3,   KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,    _______, \
_______, _______, KC_MS_ACCEL0, KC_MS_ACCEL1,    KC_MS_ACCEL2, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, _______, \
_______, _______, _______,      ALGR(KC_RETURN), _______,      KC_BSPC       \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |           |AudioT|Audio+|Audio-|Brigh+|Brigh-|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |      |      |PrtScr|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT( \
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,         KC_F7,           KC_F8,             KC_F9,            KC_F10,             \
KC_F11,  KC_F12,  _______, _______, _______, KC_AUDIO_MUTE, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN, \
RESET,   _______, _______, _______, _______, _______,       _______,         _______,           _______,          KC_PSCR,            \
_______, _______, _______, _______, _______, _______\
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
