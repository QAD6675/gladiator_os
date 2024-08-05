#include "keyboard.h"
#include <stdbool.h>
#include <stdint.h>
#include "irq.h"
#include "io.h"
#include "isr.h"
#include <stdio.h>
#include <memory.h>
#include "ascii.h"

#define MAX_KEYB_BUFFER_SIZE    255

char keyboard_buffer[MAX_KEYB_BUFFER_SIZE]={0};
uint8_t buf_position = 0;

Kbstate Kstate={
    .shift=false,
    .ctrl=false,
    .alt=false,
    .super=false,
    .caps=false,
    .enabled=false,
    .last='\0'
};

bool toggleTyping(){
    Kstate.enabled=!Kstate.enabled;
    return Kstate.enabled;
}

void keyboard_irq(Registers* regs)
{
    if (!Kstate.enabled)return;
    int scancode = i686_inb(0x60); // Read byte from the Keyboard data port
    char c=translate(scancode);

    if (Kstate.last == 9999){
        Kstate.last =0;
        return;
    }
    if(c == 127){
        keyboard_buffer[(buf_position - 1) % MAX_KEYB_BUFFER_SIZE]='\0';
    }

    switch(scancode){//disableing mods on key up
        case 219:
            Kstate.super=false;
            return;
        case 184:
            Kstate.alt=false;
            return;
        case 157:
            Kstate.ctrl=false;
            return;
        case 170:
            Kstate.shift=false;
            return;
    }
    if(scancode-128 == Kstate.last){
        return;
    }
        switch(c){
        case '%'://caps
            Kstate.caps=!Kstate.caps;
            Kstate.last=9999;
            return;
        case '*'://alt 
            Kstate.alt=true;
            return; 
        case '@'://super 
            Kstate.super=true;
            return;
        case '^'://ctrl 
            Kstate.ctrl=true;
            return;
        case '+'://shift
            Kstate.shift=true;
            return;
            }
    if ((Kstate.shift || Kstate.caps) && !(Kstate.caps==Kstate.shift)){
        c-=32;
        keyboard_buffer[buf_position]= c;
        buf_position = (buf_position + 1) % MAX_KEYB_BUFFER_SIZE;      
    }else{//handling mods
        keyboard_buffer[buf_position]= c;
        buf_position = (buf_position + 1) % MAX_KEYB_BUFFER_SIZE;

    }
    Kstate.last=scancode;
    return;
}

void clearBuffer(){
    for(size_t i = 0; i < sizeof keyboard_buffer; ++i){
        keyboard_buffer[i] = 0;
    }
}
void init_keyboard() {
    i686_IRQ_RegisterHandler(1, keyboard_irq);
    Kstate.shift=false;
    Kstate.ctrl=false;
    Kstate.alt=false;
    Kstate.super=false;
    Kstate.caps=false;
    Kstate.enabled=false;
    Kstate.last='\0';
    clearBuffer();
}
char** readBuffer(){
    return &keyboard_buffer;
}

Kbstate KbgetState(){
    return Kstate;
}