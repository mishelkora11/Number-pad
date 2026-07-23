#include QMK_KEYBOARD_H

// Custom keycodes for Tap (Number) vs Hold (Arrow)
enum custom_keycodes {
    NUM_8 = SAFE_RANGE,
    NUM_4,
    NUM_6,
    NUM_2,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM_8:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P8); // Tap = Numpad 8
            } else if (record->event.pressed) {
                tap_code(KC_UP); // Hold = Up Arrow
            }
            return false;
        case NUM_4:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P4); // Tap = Numpad 4
            } else if (record->event.pressed) {
                tap_code(KC_LEFT); // Hold = Left Arrow
            }
            return false;
        case NUM_6:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P6); // Tap = Numpad 6
            } else if (record->event.pressed) {
                tap_code(KC_RGHT); // Hold = Right Arrow
            }
            return false;
        case NUM_2:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P2); // Tap = Numpad 2
            } else if (record->event.pressed) {
                tap_code(KC_DOWN); // Hold = Down Arrow
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_P0,
        KC_P7, NUM_8, KC_P9,
        NUM_4, KC_P5, NUM_6,
        KC_P1, NUM_2, KC_P3
    )
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("MISHEL PAD\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("MODE: NUMPAD"), false);
            break;
        default:
            oled_write_P(PSTR("MODE: FN"), false);
            break;
    }
    return false;
}
#endif