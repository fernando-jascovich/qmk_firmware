#include "keymap.h"
#include "tapdance.c"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |TD_SFT|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  | /|AGR|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER |EMACS | Ctrl |    |      |RET/GU| RAISE|
 *                  `-------------| ---- |    | Space|------+------.
 *                                | LAlt |    |      |
 *                                `------'    `------'
 */
  [_QWERTY] = LAYOUT( \
    KC_Q,  KC_W,       KC_E,             KC_R,     KC_T,              KC_Y, KC_U, KC_I,    KC_O,   KC_P, \
    KC_A,  KC_S,       KC_D,             KC_F,     KC_G,              KC_H, KC_J, KC_K,    KC_L,   TD(TD_SHIFT), \
    KC_Z,  KC_X,       KC_C,             KC_V,     KC_B,              KC_N, KC_M, KC_COMM, KC_DOT, ALGR_T(KC_SLASH), \
    LOWER, MO(_EMACS), TD(TD_CTRL_LALT), KC_SPACE, LGUI_T(KC_ENTER),  RAISE \
    ),

/* Lower
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   (  |   )  |   [  |   ]  |   `  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   6  |   7  |   8  |   9  |   0  |           | Left | Down |  Up  | Right|   |  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |   {  |   }  |   <  |   >  |   \  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER |EMACS | Ctrl |    |      | Enter| RAISE|
 *                  `-------------| ---- |    |BckSpc|------+------.
 *                                | LAlt |    |      |
 *                                `------'    `------'
 */
  [_LOWER] = LAYOUT(\
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_GRV, \
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PIPE, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_LT, KC_GT,  KC_BSLS, \
    _______, _______, _______, KC_BSPC, _______, _______ \
    ),

/* Raise
 * ,----------------------------------.           ,----------------------------------.
 * |  Esc |   ^  |   *  |   +  |  %   |           |  ¡   |  ¿   |   @  |   $  |  Del |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |CapsLk|   ~  |   /  |   -  |  =   |           |  !   |  ?   |   #  |   &  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   :  |   ;  |   '  |   "  |  _   |           |      |      |      |      |Moutgl|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER |EMACS |      |    |      | Enter| RAISE|
 *                  `-------------| Tab  |    | Space|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
  [_RAISE] = LAYOUT( \
    KC_ESC,  KC_CIRC, KC_ASTR,  KC_PLUS,  KC_PERC, ALGR(LSFT(KC_1)), ALGR(KC_SLSH), KC_AT,   KC_DOLLAR, KC_DEL,     \
    KC_CAPS, KC_TILD, KC_SLASH, KC_MINUS, KC_EQL,  KC_EXLM,          KC_QUES,       KC_HASH, KC_AMPR,   XXXXXXX,    \
    KC_COLN, KC_SCLN, KC_QUOT,  KC_DQUO,  KC_UNDS, XXXXXXX,          XXXXXXX,       XXXXXXX, XXXXXXX,   TG(_MOUSE), \
    _______, _______, KC_TAB,   _______,  _______, _______\
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
    KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_HOME,  KC_PGDN,     KC_PGUP,             KC_END,        XXXXXXX, \
    KC_F11,  KC_F12,  XXXXXXX,  XXXXXXX, RESET,   XXXXXXX,  XXXXXXX,     LCTL(LSFT(KC_PSCR)), LSFT(KC_PSCR), KC_PSCR, \
    _______, _______, _______,  _______, _______, _______\
    ),

/*Emacs
 *
 * ,----------------------------------.           ,----------------------------------.
 * |SpitNo|SplitH|SplitV| W+V  | W+H  |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |BufSel|BufOth|BufHid|BufKil|      |           |Commt |QueryR|RegexR|      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |RegSet|RegJmp|      |OrgClI|OrgClO|           |MacroS|MacroE|  Top |Bottom|EM_ZAP|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER |EMACS | Ctrl |    |      | Enter| RAISE|
 *                  `-------------| ---- |    | Space|------+------.
 *                                | LAlt |    |      |
 *                                `------'    `------'
 */
  [_EMACS] =  LAYOUT( \
    EM_SPLIT_NONE, EM_SPLIT_H,   EM_SPLIT_V,  EM_W_INC_V,  EM_W_INC_H,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX, \
    EM_BUF_SELECT, EM_BUF_OTHER, EM_BUF_HIDE, EM_BUF_KILL, XXXXXXX,      EM_COMMENT, EM_QUERY_R, EM_REGEX_R, XXXXXXX,   XXXXXXX,    \
    EM_REG_SET,    EM_REG_JUMP,  XXXXXXX,     EM_ORG_CL_I, EM_ORG_CL_O,  EM_MAC_ST,  EM_MAC_END, EM_TOP,     EM_BOTTOM, EM_ZAP,  \
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
        return emacs_key(SS_LCTRL("x")"b", record);
        break;
    case EM_BUF_OTHER:
        return emacs_key(SS_LCTRL("x")"o", record);
        break;
    case EM_BUF_HIDE:
        return emacs_key(SS_LCTRL("x")"0", record);
        break;
    case EM_BUF_KILL:
        return emacs_key(SS_LCTRL("x")"k"SS_TAP(X_ENTER), record);
        break;
    case EM_SPLIT_NONE:
        return emacs_key(SS_LCTRL("x")"1", record);
        break;
    case EM_SPLIT_V:
        return emacs_key(SS_LCTRL("x")"3", record);
        break;
    case EM_SPLIT_H:
        return emacs_key(SS_LCTRL("x")"2", record);
        break;
    case EM_ORG_CL_I:
        return emacs_key(SS_DOWN(X_LCTRL)"cxi"SS_UP(X_LCTRL), record);
        break;
    case EM_ORG_CL_O:
        return emacs_key(SS_DOWN(X_LCTRL)"cxo"SS_UP(X_LCTRL), record);
        break;
    case EM_COMMENT:
        return emacs_key(SS_DOWN(X_LCTRL)"x;"SS_UP(X_LCTRL), record);
        break;
    case EM_TOP:
        return emacs_key(SS_LALT("<"), record);
        break;
    case EM_BOTTOM:
        return emacs_key(SS_LALT(">"), record);
        break;
    case EM_W_INC_H:
        return emacs_key(SS_LCTRL("x")"}", record);
        break;
    case EM_W_INC_V:
        return emacs_key(SS_LCTRL("x")"^", record);
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
    case EM_QUERY_R:
        return emacs_key(SS_LALT("%"), record);
        break;
    case EM_REGEX_R:
        return emacs_key(SS_LCTRL(SS_LALT("%")), record);
        break;
    case EM_ZAP:
        return emacs_key(SS_LALT("z"), record);
        break;
    }
    return true;
}
