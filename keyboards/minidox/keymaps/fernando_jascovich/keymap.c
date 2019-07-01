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
#define _I3     6
#define _MOUSE  10
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  EM_BUF_SELECT,
  EM_BUF_OTHER,
  EM_BUF_HIDE,
  EM_BUF_KILL,
  EM_W_INC_V,
  EM_W_INC_H,
  EM_W_BALANCE,
  EM_C_C_F,
  EM_C_X_C_F,
  EM_C_C_B,
  EM_C_C_S,
  EM_MAGIT,
  EM_C_C_C,
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
  EM_DIRED,
  I3_W1,
  I3_W2,
  I3_W3,
  I3_W4,
  I3_W5,
  I3_TO_W1,
  I3_TO_W2,
  I3_TO_W3,
  I3_TO_W4,
  I3_TO_W5,
  I3_SPLIT_H,
  I3_SPLIT_V,
  I3_SPLIT_TOGGLE,
  I3_FS,
  I3_TABBED,
  I3_LAYOUT_TOGGLE,
  I3_RESIZE_L,
  I3_RESIZE_D,
  I3_RESIZE_U,
  I3_RESIZE_R,
  I3_DMENU,
  I3_FOCUS_L,
  I3_FOCUS_D,
  I3_FOCUS_U,
  I3_FOCUS_R,
  I3_FOCUS_TOGGLE,
  I3_TERM,
  I3_MOVE_L,
  I3_MOVE_D,
  I3_MOVE_U,
  I3_MOVE_R,
  I3_QUIT,
  I3_RESET,
  I3_KILL,
};

enum {
  TD_CTRL_LALT = 0
};

void dance_ctrl_finished(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
  case 1:
    register_code(KC_LCTRL);
    break;
  case 2:
    register_code(KC_LALT);
    break;
  case 3:
    register_code(KC_LCTRL);
    register_code(KC_LALT);
    break;
  }
}

void dance_ctrl_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
  case 1:
    unregister_code(KC_LCTRL);
    break;
  case 2:
    unregister_code(KC_LALT);
    break;
  case 3:
    unregister_code(KC_LCTRL);
    unregister_code(KC_LALT);
    break;
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  /* [TD_CTRL_LALT]  = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, KC_LALT), */
  [TD_CTRL_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_ctrl_finished, dance_ctrl_reset),
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  | Shift|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Z/I3 |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  | /|AGR|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER |EMACS | Ctrl |    |      | Enter| RAISE|
 *                  `-------------| ---- |    | Space|------+------.
 *                                | LAlt |    |      |
 *                                `------'    `------'
 */
  [_QWERTY] = LAYOUT( \
    KC_Q,          KC_W,       KC_E,             KC_R,     KC_T,     KC_Y, KC_U, KC_I,    KC_O,   KC_P, \
    KC_A,          KC_S,       KC_D,             KC_F,     KC_G,     KC_H, KC_J, KC_K,    KC_L,   KC_LSHIFT, \
    LT(_I3, KC_Z), KC_X,       KC_C,             KC_V,     KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, ALGR_T(KC_SLASH), \
    LOWER,         MO(_EMACS), TD(TD_CTRL_LALT), KC_SPACE, KC_ENTER, RAISE \
    ),

/* Lower
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   :  |   `  |           |   (  |   [  |   {  |   -  |   |  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   4  |   5  |   6  |   ;  |   '  |           |   )  |   ]  |   }  |   _  |   \  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   7  |   8  |   9  |   0  |   "  |           |      |      |      |   <  |   >  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER |EMACS | Ctrl |    |      | Enter| RAISE|
 *                  `-------------| ---- |    |BckSpc|------+------.
 *                                | LAlt |    |      |
 *                                `------'    `------'
 */
  [_LOWER] = LAYOUT(\
    KC_1,    KC_2,    KC_3,    KC_COLN, KC_GRV,   KC_LPRN, KC_LBRC, KC_LCBR, KC_MINS,   KC_PIPE, \
    KC_4,    KC_5,    KC_6,    KC_SCLN, KC_QUOT,  KC_RPRN, KC_RBRC, KC_RCBR, KC_UNDS,   KC_BSLS, \
    KC_7,    KC_8,    KC_9,    KC_0,    KC_DQUO,  _______, _______, _______, KC_LT,   KC_GT, \
    _______, _______, _______, KC_BSPC, _______, _______                \
    ),

/* Raise
 * ,----------------------------------.           ,----------------------------------.
 * |  Esc |   ^  |   *  |   +  |  %   |           |  ¡   |  ¿   |   @  |   $  |  Del |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |CapsLk|   ~  |   /  |   -  |  =   |           |  !   |  ?   |   #  |   &  |  GUI |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | Left | Down |  Up  | Right|           |      |      |      |      |MouTgl|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER |EMACS | Ctrl |    |      | Enter| RAISE|
 *                  `-------------| ---- |    | Space|------+------.
 *                                | LAlt |    |      |
 *                                `------'    `------'
 */
  [_RAISE] = LAYOUT( \
    KC_ESC,  KC_CIRC, KC_ASTR,  KC_PLUS,  KC_PERC, ALGR(LSFT(KC_1)), ALGR(KC_SLSH), KC_AT,   KC_DOLLAR, KC_DEL,     \
    KC_CAPS, KC_TILD, KC_SLASH, KC_MINUS, KC_EQL,  KC_EXLM,          KC_QUES,       KC_HASH, KC_AMPR,   KC_LGUI,    \
    KC_TAB,  KC_LEFT, KC_DOWN,  KC_UP,    KC_RGHT, _______,          _______,       _______, _______,   TG(_MOUSE), \
    _______,  _______, _______,  _______, _______, _______\
    ),

/*Adjust(Lower+Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |AudioT|Audio-|Audio+|  F14 |  F15 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F6  |  F7  |  F8  |  F9  |  F10 |           | Home |PgDown| PgUp |  End |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |Reset |           |      |      |C+S+PS| S+PS |  PS  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER |EMACS | Ctrl |    |      | Enter| RAISE|
 *                  `-------------| ---- |    | Space|------+------.
 *                                | LAlt |    |      |
 *                                `------'    `------'
 */
  [_ADJUST] =  LAYOUT( \
    KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC__MUTE, KC__VOLDOWN, KC__VOLUP,           KC_F14,        KC_F15,  \
    KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_HOME,  KC_PGDN,     KC_PGUP,             KC_END,        _______, \
    KC_F11,  KC_F12,  _______, _______, RESET,   _______,  _______,     LCTL(LSFT(KC_PSCR)), LSFT(KC_PSCR), KC_PSCR, \
    _______, _______, _______,  _______, _______, _______\
    ),

/*Emacs
 *
 * ,----------------------------------.           ,----------------------------------.
 * |SpitNo|SplitH|SplitV| W+V  | W+H  |           |Magit | CC_C | CC_B |CC_S_F| CC_F |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |BufSel|BufOth|BufHid|BufKil|  W=  |           |Commt |QueryR|RegexR|      | CC_S |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |RegSet|RegJmp|Dired |OrgClI|OrgClO|           |MacroS|MacroE|  Top |Bottom|      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER |EMACS | Ctrl |    |      | Enter| RAISE|
 *                  `-------------| ---- |    | Space|------+------.
 *                                | LAlt |    |      |
 *                                `------'    `------'
 */
  [_EMACS] =  LAYOUT( \
    EM_SPLIT_NONE, EM_SPLIT_H,   EM_SPLIT_V,  EM_W_INC_V,  EM_W_INC_H,   EM_MAGIT,   EM_C_C_C,   EM_C_C_B,   EM_C_X_C_F, EM_C_C_F, \
    EM_BUF_SELECT, EM_BUF_OTHER, EM_BUF_HIDE, EM_BUF_KILL, EM_W_BALANCE, EM_COMMENT, EM_QUERY_R, EM_REGEX_R, _______,    EM_C_C_S,    \
    EM_REG_SET,    EM_REG_JUMP,  EM_DIRED,    EM_ORG_CL_I, EM_ORG_CL_O,  EM_MAC_ST,  EM_MAC_END, EM_TOP,     EM_BOTTOM,  _______,  \
    _______,       _______,      _______,     _______,     _______,      _______\
    ),

/*Mouse
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |Mou L |Mou D |Mou T |Mou R |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |Mou 1 |Mou 2 |Mou 3 |           |Mou WL|Mou WD|Mou WT|Mou WR|MouTgl|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      | RAISE|
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
  [_MOUSE] =  LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
    XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,  \
    XXXXXXX, XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,  \
    XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    _______ \
    ),




/*I3
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  W_1 |  W_2 |  W_3 |  W_4 |  W_5 |           |ResizL|ResizD|ResizU|ResizR| Dmenu|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |To_W_1|To_W_2|To_W_3|To_W_4|To_W_5|           |FocusL|FocusD|FocusU|FocusR| Term |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  I3  |FocusT|FullSc|Tabbed|LayTgl|           | MoveL| MoveD| MoveU| MoveR| Kill |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |SplitH|SplitV|      |    |      | Quit | Reset|
 *                  `-------------|SplitT|    |  GUI |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
  [_I3] =  LAYOUT( \
    I3_W1,      I3_W2,           I3_W3,           I3_W4,     I3_W5,            I3_RESIZE_L, I3_RESIZE_D, I3_RESIZE_U, I3_RESIZE_R, I3_DMENU, \
    I3_TO_W1,   I3_TO_W2,        I3_TO_W3,        I3_TO_W4,  I3_TO_W5,         I3_FOCUS_L,  I3_FOCUS_D,  I3_FOCUS_U,  I3_FOCUS_R,  I3_TERM,  \
    _______,    I3_FOCUS_TOGGLE, I3_FS,           I3_TABBED, I3_LAYOUT_TOGGLE, I3_MOVE_L,   I3_MOVE_D,   I3_MOVE_U,   I3_MOVE_R,   I3_KILL,  \
    I3_SPLIT_H, I3_SPLIT_V,      I3_SPLIT_TOGGLE, KC_LGUI,   I3_QUIT,          I3_RESET\
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
  case EM_BUF_HIDE:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"0");
    }
    return false;
    break;
  case EM_BUF_KILL:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"k"SS_TAP(X_ENTER));
    }
    return false;
    break;
  case EM_C_C_F:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c")"f");
    }
    return false;
    break;
  case EM_C_X_C_F:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")SS_LCTRL("f"));
    }
    return false;
    break;
  case EM_C_C_B:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c")"b");
    }
    return false;
    break;
  case EM_C_C_S:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c")"s");
    }
    return false;
    break;
  case EM_MAGIT:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"g");
    }
    return false;
    break;
  case EM_C_C_C:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c")"c");
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
  case EM_W_INC_H:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"}");
    }
    return false;
    break;
  case EM_W_INC_V:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"^");
    }
    return false;
    break;
  case EM_W_BALANCE:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"+");
    }
    return false;
    break;
  case EM_REG_SET:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"r 1");
    }
    return false;
    break;
  case EM_REG_JUMP:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"rj1");
    }
    return false;
    break;
  case EM_MAC_ST:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"(");
    }
    return false;
    break;
  case EM_MAC_END:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")")");
    }
    return false;
    break;
  case EM_QUERY_R:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT("%"));
    }
    return false;
    break;
  case EM_REGEX_R:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL(SS_LALT("%")));
    }
    return false;
    break;
  case EM_DIRED:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x")"d");
    }
    return false;
    break;
  case I3_W1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("1"));
    }
    return false;
    break;
  case I3_W2:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("2"));
    }
    return false;
    break;
  case I3_W3:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("3"));
    }
    return false;
    break;
  case I3_W4:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("4"));
    }
    return false;
    break;
  case I3_W5:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("5"));
    }
    return false;
    break;
  case I3_TO_W1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT("1")));
    }
    return false;
    break;
  case I3_TO_W2:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT("2")));
    }
    return false;
    break;
  case I3_TO_W3:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT("3")));
    }
    return false;
    break;
  case I3_TO_W4:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT("4")));
    }
    return false;
    break;
  case I3_TO_W5:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT("5")));
    }
    return false;
    break;
  case I3_SPLIT_H:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("h"));
    }
    return false;
    break;
  case I3_SPLIT_V:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("v"));
    }
    return false;
    break;
  case I3_SPLIT_TOGGLE:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("e"));
    }
    return false;
    break;
  case I3_FS:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("f"));
    }
    return false;
    break;
  case I3_TABBED:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("w"));
    }
    return false;
    break;
  case I3_LAYOUT_TOGGLE:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(" ")));
    }
    return false;
    break;
  case I3_RESIZE_L:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("r")"j"SS_TAP(X_ENTER));
    }
    return false;
    break;
  case I3_RESIZE_D:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("r")"k"SS_TAP(X_ENTER));
    }
    return false;
    break;
  case I3_RESIZE_U:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("r")"l"SS_TAP(X_ENTER));
    }
    return false;
    break;
  case I3_RESIZE_R:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("r")";"SS_TAP(X_ENTER));
    }
    return false;
    break;
  case I3_DMENU:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("d"));
    }
    return false;
    break;
  case I3_FOCUS_L:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("j"));
    }
    return false;
    break;
  case I3_FOCUS_D:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("k"));
    }
    return false;
    break;
  case I3_FOCUS_U:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI("l"));
    }
    return false;
    break;
  case I3_FOCUS_R:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(";"));
    }
    return false;
    break;
  case I3_FOCUS_TOGGLE:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(" "));
    }
    return false;
    break;
  case I3_TERM:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_ENTER)));
    }
    return false;
    break;
  case I3_MOVE_L:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT("j")));
    }
    return false;
    break;
  case I3_MOVE_D:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT("k")));
    }
    return false;
    break;
  case I3_MOVE_U:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT("l")));
    }
    return false;
    break;
  case I3_MOVE_R:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(";")));
    }
    return false;
    break;
  case I3_QUIT:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT("e")));
    }
    return false;
    break;
  case I3_RESET:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT("r")));
    }
    return false;
    break;
  case I3_KILL:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT("q")));
    }
  }
  return true;
}
