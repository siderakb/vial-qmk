#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS (6 * 2)
#define MATRIX_COLS (8)

/* Key matrix pins. */
#define MATRIX_ROW_PINS { GP28, GP27, GP26, GP25, GP24, GP20 }
#define MATRIX_COL_PINS { GP11, GP10, GP9, GP6, GP5, GP4, GP22, GP21 }
#define MATRIX_ROW_PINS_RIGHT { GP29, GP9, GP6, GP4, GP2, NO_PIN }
#define MATRIX_COL_PINS_RIGHT { GP12, GP18, GP11, GP19, GP25, GP27, NO_PIN, NO_PIN }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

/* Encoders. */
// #define ENCODERS_PAD_A { GP23 }
// #define ENCODERS_PAD_B { GP18 }
// #define ENCODER_RESOLUTIONS { 4 }
// #define ENCODERS_PAD_A_RIGHT { }
// #define ENCODERS_PAD_B_RIGHT { }
// #define ENCODER_RESOLUTIONS_RIGHT { }
// #define ENCODER_DIRECTION_FLIP

/* SPI */
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20

/* Pointing device */
#define PMW33XX_CS_PIN GP21 // SPI CS pin.
#define PMW33XX_CPI 800    // The CPI range is 100-12000, in increments of 100. Defaults to 1600 CPI.
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_TASK_THROTTLE_MS 10
#define MOUSE_EXTENDED_REPORT

/* Split keyboard */
// #define EE_HANDS // Handedness by EEPROM.
#define SPLIT_HAND_PIN GP15 // Handedness by Pin. By default high is left, low is right.
#define SOFT_SERIAL_PIN GP0
#define SPLIT_POINTING_ENABLE
#define SERIAL_PIO_USE_PIO0 // By default the 'Serial' implementation uses the PIO0 peripheral.
// #define SERIAL_USART_TIMEOUT 20    // USART driver timeout, default 20.

/* RP2040 Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Limit the number of layers */
// #define LAYER_STATE_8BIT

/* key combination for command */
#define IS_COMMAND() (keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))
