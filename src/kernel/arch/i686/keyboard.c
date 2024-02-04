#include "keyboard.h"
#include <stdint.h>
#include "io.h"
#include "isr.h"
#include <stdio.h>
#include "ascii.h"

#define MAX_KEYB_BUFFER_SIZE    255
#define NORMAL_STATE 0
#define PREFIX_STATE 1

typedef struct {
    uint8_t code;
} key_event;

key_event keyboard_buffer[MAX_KEYB_BUFFER_SIZE];
uint8_t buf_position = 0;
uint8_t current_state;

void init_keyboard() {
    i686_IRQ_RegisterHandler(1, getKey);
    current_state = NORMAL_STATE;
}

int getKey(Registers* regs)
{
    int scancode = i686_inb(0x60); // Read byte from the Keyboard data port

    keyboard_buffer[buf_position].code = scancode;
    buf_position = (buf_position + 1) % MAX_KEYB_BUFFER_SIZE;

    printf("%i\n",scancode);
    return scancode;
}


void keyboard_driver_irq_handler() {
    int scancode = i686_inb(0x60); // Read byte from the Keyboard data port
    if (scancode == 0xE0) {
        current_state = PREFIX_STATE;
        // We have read a prefix, so update the state and exit.
        return ;
    }
    if (current_state == PREFIX_STATE) {
        // Store the next part of the scancode, then return to normal state.
        current_state = NORMAL_STATE;
    }
}