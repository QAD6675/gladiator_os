#include "keyboard.h"
#include <stdint.h>
#include "irq.h"
#include "io.h"
#include "isr.h"
#include <stdio.h>
#include "ascii.h"

#define MAX_KEYB_BUFFER_SIZE    255
#define NORMAL_STATE 0
#define PREFIX_STATE 1

int keyboard_buffer[MAX_KEYB_BUFFER_SIZE];
uint8_t buf_position = 0;
uint8_t current_state=NORMAL_STATE;
int prefix='\0'

void init_keyboard() {
    i686_IRQ_RegisterHandler(1, getKey);
    current_state = NORMAL_STATE;
}

void getKey(Registers* regs)
{
    int scancode = i686_inb(0x60); // Read byte from the Keyboard data port

    keyboard_buffer[buf_position]= scancode;
    buf_position = (buf_position + 1) % MAX_KEYB_BUFFER_SIZE;
    printf("%c",chars[scancode]);
    return ;
}