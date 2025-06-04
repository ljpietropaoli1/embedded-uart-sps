#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "sensirion_arch_config.h"
#include "sensirion_uart.h"

#define BAUDRATE 115200  // Baud rate for SPS30

/**
 * sensirion_uart_select_port() - Select the UART port index to use.
 *                                Optional for single-port setups.
 */
int16_t sensirion_uart_select_port(uint8_t port) {
    return 0;
}

/**
 * sensirion_uart_open() - Initialize UART.
 */
int16_t sensirion_uart_open() {
    Serial1.begin(BAUDRATE);
    return 0;
}

/**
 * sensirion_uart_close() - Release UART resources.
 */
int16_t sensirion_uart_close() {
    Serial1.end();
    return 0;
}

/**
 * sensirion_uart_tx() - Transmit data over UART.
 */
int16_t sensirion_uart_tx(uint16_t data_len, const uint8_t* data) {
    return Serial1.write(data, data_len);
}

/**
 * sensirion_uart_rx() - Receive data over UART.
 */
int16_t sensirion_uart_rx(uint16_t max_data_len, uint8_t* data) {
    int16_t i = 0;
    while (Serial1.available() > 0 && i < max_data_len) {
        data[i++] = (uint8_t)Serial1.read();
    }
    return i;
}

/**
 * Sleep for a given number of microseconds.
 */
void sensirion_sleep_usec(uint32_t useconds) {
    delay((useconds / 1000) + 1);
}

#ifdef __cplusplus
}  // extern "C"
#endif
