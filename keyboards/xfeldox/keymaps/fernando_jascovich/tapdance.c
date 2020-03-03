void dance_shift_finished(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
  case 1:
    if(state->pressed) {
      register_code(KC_LSHIFT);
    } else {
      register_code(KC_LSHIFT);
      register_code(KC_SCLN);
    }
    break;
  case 2:
    register_code(KC_SCLN);
    break;
  }
}

void dance_shift_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
  case 1:
    unregister_code(KC_LSHIFT);
    unregister_code(KC_SCLN);
    break;
  case 2:
    unregister_code(KC_SCLN);
    break;
  }
}

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

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTRL_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_ctrl_finished, dance_ctrl_reset),
  [TD_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_shift_finished, dance_shift_reset)
};
