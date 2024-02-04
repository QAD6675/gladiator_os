#include "keyboard.h"
#include <stdint.h>
#include "isr.h"
#include <stdio.h>

int getKey(Registers* regs)
{
    printf("a key was pressed!\n");
    return 0;
}