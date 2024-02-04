#include "keyboard.h"
#include <stdbool.h>
#include <stdint.h>
#include "irq.h"
#include "io.h"
#include "isr.h"
#include <stdio.h>
#include "ascii.h"

#define MAX_KEYB_BUFFER_SIZE    255

int keyboard_buffer[MAX_KEYB_BUFFER_SIZE];
uint8_t buf_position = 0;

typedef struct {
        bool shift;
        bool ctrl;
        bool alt;
        bool super;
        bool caps;
        bool none;
}Kstate;

Kstate state={
    .shift=false,
    .ctrl=false,
    .alt=false,
    .super=false,
    .caps=false,
    .none=true,
};
void init_keyboard() {
    i686_IRQ_RegisterHandler(1, getKey);
    state.shift=false;
    state.ctrl=false;
    state.alt=false;
    state.super=false;
    state.caps=false;
    state.none=true;
    
}

void getKey(Registers* regs)
{
    int scancode = i686_inb(0x60); // Read byte from the Keyboard data port
    int c=chars[scancode];
    
    if(!state.shift){
        switch(c){
            case '%'://caps
                state.caps=true;
                state.none=false;
                return;
            case '*'://alt
                state.alt=true;
                state.none=false;
                return; 
            case '@'://super    
                state.super=true;
                state.none=false;
                return;
            case '^'://ctrl 
                state.ctrl=true;
                state.none=false;
                return;
            case '+'://shift
                state.shift=true;
                state.none=false;
                return;
            default:
                keyboard_buffer[buf_position]= c;
                buf_position = (buf_position + 1) % MAX_KEYB_BUFFER_SIZE;
                putc(c,);
                printf("%i",c);
                return;
        }
    }else{

        c-=32;
        keyboard_buffer[buf_position]= c;
        buf_position = (buf_position + 1) % MAX_KEYB_BUFFER_SIZE;
        putc(c);        
    }

}