bool gui_onkeypress(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EM_W_F:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("x")"1");
        }
        return false; // Skip all further processing of this key
    case EM_W_V:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("x")"2");
        }
        return false;
    case EM_W_H:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("x")"3");
        }
        return false;
    case EM_OTHER:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("x")"o");
        }
        return false;
    case EM_ERR_P:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c")"!p");
        }
        return false;
    case EM_ERR_N:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c")"!n");
        }
        return false;
    case EM_ERR_L:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c")"!l");
        }
        return false;
    default:
        return true; // Process all other keycodes normally
    }
}
