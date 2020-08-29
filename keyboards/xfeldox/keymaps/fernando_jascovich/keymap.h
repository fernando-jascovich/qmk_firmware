#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _DVORAK 1
#define _LOWER  3
#define _RAISE  4
#define _EMACS  5
#define _SYMBOL 7
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

enum custom_keycodes {
  EM_BUF_SELECT = SAFE_RANGE,
  EM_BUF_OTHER,
  EM_BUF_HIDE,
  EM_BUF_KILL,
  EM_W_INC_V,
  EM_W_INC_H,
  EM_SPLIT_NONE,
  EM_SPLIT_V,
  EM_SPLIT_H,
  EM_ORG_CL_I,
  EM_ORG_CL_O,
  EM_COMMENT,
  EM_TOP,
  EM_BOTTOM,
  EM_REG_SET,
  EM_REG_JUMP,
  EM_MAC_ST,
  EM_MAC_END,
  EM_QUERY_R,
  EM_REGEX_R,
  EM_ZAP,
};
