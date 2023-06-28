#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
[0] = LAYOUT(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, 
  KC_LALT, KC_LGUI, KC_HOME, KC_END,  MO(1),                                                MO(1),   KC_LBRC, KC_RBRC, MO(2),   KC_RSFT,
                                                        KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX,          
                                                        KC_SPC,  MO(2),   KC_DEL            
),

[1] = LAYOUT(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PSCR,
  KC_PENT, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,                            KC_MUTE, KC_VOLD, KC_VOLU, KC_F11,  KC_F12,  KC_DEL,
  _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PMNS,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_INS,
  _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT,                            _______, _______, _______, _______, _______, _______,
  _______, _______, KC_PGUP, KC_PGDN, _______,                                              _______, KC_MINS, KC_EQL,  _______, _______,
                                                        _______, _______, _______, _______,
                                                        _______, _______, _______
),

[2] = LAYOUT(
  KC_ESC,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  KC_NUM,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  KC_LCAP, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                              _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______,
                                                        _______, _______, _______
),

[3] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                              _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______,
                                                        _______, _______, _______
)
    // clang-format on
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [1] = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [2] = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [3] = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
};
#else
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* 1st encoder */
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    } else if (index == 1) { /* 2nd encoder */
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }

    return false;
}
#endif

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

#define DRAG_SCROLL MO(1) // Use the mouse movement to scroll instead of moving the cursor .
#define TRACKBALL_SCROLL_INVERT_V
// #define TRACKBALL_SCROLL_INVERT_H
// #define TRACKBALL_SCROLL_SWAP
#define TRACKABALL_SCROLL_SCALE (1.0)
#define TRACKABALL_SCROLL_MAX_V (5)
#define TRACKABALL_SCROLL_MAX_H (5)

bool set_scrolling = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
#if defined(TRACKBALL_SCROLL_SWAP)
        mouse_report.h = mouse_report.y / TRACKABALL_SCROLL_SCALE;
        mouse_report.v = mouse_report.x / TRACKABALL_SCROLL_SCALE;
#else
        mouse_report.h = mouse_report.x / TRACKABALL_SCROLL_SCALE;
        mouse_report.v = mouse_report.y / TRACKABALL_SCROLL_SCALE;
#endif

#if defined(TRACKBALL_SCROLL_INVERT_V)
        mouse_report.v = -mouse_report.v;
#endif

#if defined(TRACKBALL_SCROLL_INVERT_H)
        mouse_report.h = -mouse_report.h;
#endif

        // if(mouse_report.v > 0 && mouse_report.v > TRACKABALL_SCROLL_MAX_V) {
        //     mouse_report.v = TRACKABALL_SCROLL_MAX_V;
        // } else if (mouse_report.v < 0 && mouse_report.v < -TRACKABALL_SCROLL_MAX_V) {
        //     mouse_report.v = -TRACKABALL_SCROLL_MAX_V;
        // }

        // if(mouse_report.h > 0 && mouse_report.h > TRACKABALL_SCROLL_MAX_H) {
        //     mouse_report.h = TRACKABALL_SCROLL_MAX_H;
        // } else if (mouse_report.h < 0 && mouse_report.h < -TRACKABALL_SCROLL_MAX_H) {
        //     mouse_report.h = -TRACKABALL_SCROLL_MAX_H;
        // }

        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL && record->event.pressed) {
        set_scrolling = true;
    } else {
        set_scrolling = false;
    }

    return true;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    } else {
    }

    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    } else {
    }

    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
    } else {
    }

    if (usb_led & (1 << USB_LED_COMPOSE)) {
    } else {
    }

    if (usb_led & (1 << USB_LED_KANA)) {
    } else {
    }
}