#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _DVORAK 1
#define _LOWER  3
#define _RAISE  4
#define _EMACS  5
#define _MOUSE  10
#define _ADJUST 16

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum {
  TD_CTRL_LALT = 0,
  TD_SHIFT = 1,
  TD_ALT_EMACS = 2
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  EM_BUF_SELECT,
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
