#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS { GP29, GP28, GP27, GP26, GP25 }
#define MATRIX_COL_PINS { GP22, GP23, GP24, GP18, GP17, GP16, GP9, GP10, GP11, GP3, GP2, GP12, GP4, GP5, GP6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* RP2040 Bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP19

/* LED indicators. */
#define LED_CAPS_LOCK_PIN GP20

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
// #define IS_COMMAND() (keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))
