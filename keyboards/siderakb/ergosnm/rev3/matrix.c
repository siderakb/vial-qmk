/*
Copyright 2012 Jun Wako
Copyright 2014 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdbool.h>
#if defined(__AVR__)
#    include <avr/io.h>
#endif

#include "wait.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "timer.h"
#include "uart.h"
#include "quantum.h" // mouse report

#if (MATRIX_COLS <= 8)
#    define print_matrix_header() print("\nr/c 01234567\n")
#    define print_matrix_row(row) print_bin_reverse8(matrix_get_row(row))
#    define matrix_bitpop(i) bitpop(matrix[i])
#    define ROW_SHIFTER ((uint8_t)1)
#elif (MATRIX_COLS <= 16)
#    define print_matrix_header() print("\nr/c 0123456789ABCDEF\n")
#    define print_matrix_row(row) print_bin_reverse16(matrix_get_row(row))
#    define matrix_bitpop(i) bitpop16(matrix[i])
#    define ROW_SHIFTER ((uint16_t)1)
#elif (MATRIX_COLS <= 32)
#    define print_matrix_header() print("\nr/c 0123456789ABCDEF0123456789ABCDEF\n")
#    define print_matrix_row(row) print_bin_reverse32(matrix_get_row(row))
#    define matrix_bitpop(i) bitpop32(matrix[i])
#    define ROW_SHIFTER ((uint32_t)1)
#endif

// #define EOT (0xFE)
// #define RX_BUF_SIZE (17) // Key: 5*2; Mouse: 6
// uint8_t rx_buf[RX_BUF_SIZE];
// uint8_t rx_cnt = 0;

extern uint8_t uart_rx_buf[17];

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];

__attribute__((weak)) void matrix_init_kb(void) {
    matrix_init_user();
}
__attribute__((weak)) void matrix_scan_kb(void) {
    matrix_scan_user();
}
__attribute__((weak)) void matrix_init_user(void) {}
__attribute__((weak)) void matrix_scan_user(void) {}

inline uint8_t matrix_rows(void) {
    return MATRIX_ROWS;
}
inline uint8_t matrix_cols(void) {
    return MATRIX_COLS;
}

void matrix_init(void) {
    matrix_init_quantum(); // This *must* be called for correct keyboard behavior.
}

uint8_t matrix_scan(void) {
    // Key matrix
    memcpy(matrix, uart_rx_buf, 5);
    memcpy(matrix + 6, uart_rx_buf + 5, 5);

    matrix_scan_quantum(); // This *must* be called for correct keyboard behavior.
    return 1;
}

inline bool matrix_is_on(uint8_t row, uint8_t col) {
    return (matrix[row] & ((matrix_row_t)1 << col));
}

inline matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}

void matrix_print(void) {
    print_matrix_header();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        print_hex8(row);

        print(": ");

        print_matrix_row(row);

        print("\n");
    }
}

uint8_t matrix_key_count(void) {
    uint8_t count = 0;

    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += matrix_bitpop(i);
    }

    return count;
}