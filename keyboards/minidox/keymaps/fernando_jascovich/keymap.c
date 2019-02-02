#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _EMACS  5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  EM_BUF_SELECT,
  EM_BUF_OTHER,
  EM_BUF_KILL,
  EM_PROJ_FIND,
  EM_PROJ_SWITCH,
  EM_PROJ_AG,
  EM_PROJ_VC,
  EM_PROJ_TEST,
  EM_PROJ_COMPILE,
  EM_PROJ_OCCUR,
  EM_SPLIT_NONE,
  EM_SPLIT_V,
  EM_SPLIT_H,
  EM_ORG_CL_I,
  EM_ORG_CL_O,
  EM_COMMENT,
  EM_TOP,
  EM_BOTTOM
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
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  | Shift|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |EMACS |LOWER | Ctrl |    |      | RAISE| L_Alt|
 *                  `-------------| ---- |    | Space|------+------.
 *                                |Enter |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
KC_Q,    KC_W,  KC_E,            KC_R,     KC_T,  KC_Y, KC_U, KC_I,    KC_O,   KC_P,     \
KC_A,    KC_S,  KC_D,            KC_F,     KC_G,  KC_H, KC_J, KC_K,    KC_L,   KC_LSHIFT,\
KC_Z,    KC_X,  KC_C,            KC_V,     KC_B,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, \
MO(_EMACS), LOWER, CTL_T(KC_ENTER), KC_SPACE, RAISE, KC_LALT\
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   =  |   `  |           |   (  |   [  |   {  |   -  |BckSpc|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   4  |   5  |   6  |   *  |   '  |           |   )  |   ]  |   }  |   _  |   |  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   7  |   8  |   9  |   0  |   "  |           |   !  |   @  |   #  |   $  |   \  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |EMACS |LOWER | Ctrl |    |      | RAISE| L_Alt|
 *                  `-------------| ---- |    | Space|------+------.
 *                                |Enter |    |      |
 *                                `------'    `------'
 */
[_LOWER]=LAYOUT(\
KC_1,    KC_2,    KC_3,    KC_EQL,  KC_GRV,  KC_LPRN, KC_LBRC, KC_LCBR, KC_MINS,   KC_BSPC, \
KC_4,    KC_5,    KC_6,    KC_PAST, KC_QUOT, KC_RPRN, KC_RBRC, KC_RCBR, KC_UNDS,   KC_PIPE, \
KC_7,    KC_8,    KC_9,    KC_0,    KC_DQUO, KC_EXLM, KC_AT,   KC_HASH, KC_DOLLAR, KC_BSLS, \
_______, _______, _______, _______, _______, _______\
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  Esc |   %  |   ^  |   &  |  ~   |           | Left | Down |  Up  | Right| Del  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab |   +  |      |   :  |   ;  |           |Mou L |Mou D |Mou T |Mou R |CapsLk|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  GUI |MouAc2|Mou 1 |Mou 2 |Mou 3 |           |Mou WL|Mou WD|Mou WT|Mou WR| AltGr|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |EMACS |LOWER | Ctrl |    |      | RAISE| L_Alt|
 *                  `-------------| ---- |    | Space|------+------.
 *                                |Enter |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT( \
KC_ESC,    KC_PERC,  KC_CIRC,   KC_AMPR,    KC_TILD,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,        \
KC_TAB,  KC_PLUS,   _______,    KC_COLN,    KC_SCLN,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_CAPS,       \
KC_LGUI, KC_ACL1,   KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, OSM(MOD_RALT), \
_______, _______,   _______,    _______,    _______,    _______\
),

/*Adjust(Lower+Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |AudioT|Audio-|Audio+|Brigh-|Brigh+|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F6  |  F7  |  F8  |  F9  |  F10 |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |Reset |           |      |      |      |      |PrtScr|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |EMACS |LOWER | Ctrl |    |      | RAISE| L_Alt|
 *                  `-------------| ---- |    | Space|------+------.
 *                                |Enter |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT( \
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC__MUTE, KC__VOLDOWN, KC__VOLUP, KC_BRID, KC_BRIU, \
KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,  _______,     _______,   _______, _______, \
KC_F11,  KC_F12,  _______, _______, RESET,   _______,  _______,     _______,   _______, KC_PSCR, \
_______, _______, _______, _______, _______, _______\
),

/*Emacs
*
 * ,----------------------------------.           ,----------------------------------.
 * |SpitNo|SplitH|SplitV|OrgClI|OrgClO|           |ProjVC|ProjCo|ProjTe|ProjSw|ProjFi|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |BufSel|BufOth|BufKil|      |      |           |Commt |      |      |      |ProjAG|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |  Top |Bottom|ProjOc|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |EMACS |LOWER | Ctrl |    |      | RAISE| L_Alt|
 *                  `-------------| ---- |    | Space|------+------.
 *                                |Enter |    |      |
 *                                `------'    `------'
 */
[_EMACS] =  LAYOUT( \
EM_SPLIT_NONE, EM_SPLIT_H,   EM_SPLIT_V,  EM_ORG_CL_I, EM_ORG_CL_O, EM_PROJ_VC, EM_PROJ_COMPILE, EM_PROJ_TEST, EM_PROJ_SWITCH, EM_PROJ_FIND, \
EM_BUF_SELECT, EM_BUF_OTHER, EM_BUF_KILL, _______,     _______,     EM_COMMENT, _______,         _______,      _______,        EM_PROJ_AG,   \
_______,       _______,      _______,     _______,     _______,     _______,    _______,         EM_TOP,      EM_BOTTOM,        EM_PROJ_OCCUR, \
_______,          _______,         _______,        _______, _______, _______ \
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
  case EM_BUF_SELECT:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"b");
    }
    return false;
    break;
  case EM_BUF_OTHER:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"o");
    }
    return false;
    break;
  case EM_BUF_KILL:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"0");
    }
    return false;
    break;
  case EM_PROJ_FIND:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c")"pf");
    }
    return false;
    break;
  case EM_PROJ_SWITCH:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c")"pp");
    }
    return false;
    break;
  case EM_PROJ_AG:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c")"pss");
    }
    return false;
    break;
  case EM_PROJ_VC:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c")"pv");
    }
    return false;
    break;
  case EM_PROJ_TEST:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c")"pP");
    }
    return false;
    break;
  case EM_PROJ_COMPILE:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c")"pc");
    }
    return false;
    break;
  case EM_PROJ_OCCUR:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c")"po");
    }
    return false;
    break;
  case EM_SPLIT_NONE:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"1");
    }
    return false;
    break;
  case EM_SPLIT_V:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"3");
    }
    return false;
    break;
  case EM_SPLIT_H:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"2");
    }
    return false;
    break;
  case EM_ORG_CL_I:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LCTRL)"cxi"SS_UP(X_LCTRL));
    }
    return false;
    break;
  case EM_ORG_CL_O:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LCTRL)"cxo"SS_UP(X_LCTRL));
    }
    return false;
    break;
  case EM_COMMENT:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LCTRL)"x;"SS_UP(X_LCTRL));
    }
    return false;
    break;
  case EM_TOP:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT("<"));
    }
    return false;
    break;
  case EM_BOTTOM:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(">"));
    }
    return false;
    break;
  }
  return true;
}
