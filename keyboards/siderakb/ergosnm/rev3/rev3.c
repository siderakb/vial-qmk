#include "rev3.h"
#include "quantum.h"
#include "uart.h"

// #ifdef POINTING_DEVICE_ENABLE

#define UART_EOT (0xFE)
#define UART_RX_BUF_SIZE (17) // Key: 5*2; Mouse: 6; EOT: 1

uint8_t uart_rx_buf[UART_RX_BUF_SIZE] = {0};
uint8_t uart_rx_index                 = 0;

void pointing_device_init_kb(void) {
    uart_init(57600);
    pointing_device_init_user();
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    // memset(uart_rx_buf, 0, UART_RX_BUF_SIZE);

    while (1) {
        if (uart_available()) {
            uint8_t indata = uart_read();

            if (indata == UART_EOT) {
                if (uart_rx_index < (UART_RX_BUF_SIZE - 1)) {
                    uart_rx_index = 0;
                    continue;
                } else {
                    uart_rx_index = 0;
                    break;
                }
            }

            uart_rx_buf[uart_rx_index] = indata;
            ++uart_rx_index;
        }
    }

    mouse_report.x = (int16_t)((uart_rx_buf[10] << 8) + uart_rx_buf[11]);
    mouse_report.y = (int16_t)((uart_rx_buf[12] << 8) + uart_rx_buf[13]);
    mouse_report.v = (int16_t)((uart_rx_buf[14] << 8) + uart_rx_buf[15]);
    mouse_report.h = 0;

    return pointing_device_task_user(mouse_report);
}

// #endif