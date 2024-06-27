
#include <stdio.h>

FILE __libc_stdout = {.fd = 1};

FILE* stdout = &__libc_stdout;
