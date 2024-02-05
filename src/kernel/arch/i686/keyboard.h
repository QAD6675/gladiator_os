#pragma once
#include "isr.h"
#include <stdbool.h>

typedef struct {
        bool shift;
        bool ctrl;
        bool alt;
        bool super;
        bool caps;
        bool enabled;
        int last;
}Kbstate;

Kbstate KbgetState();
void clearBuffer();
char** readBuffer();
bool toggleTyping();
void init_keyboard();