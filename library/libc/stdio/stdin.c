
#include <stdio.h>

FILE __libc_stdin = {.fd = 0};

FILE* stdin = &__libc_stdin;
