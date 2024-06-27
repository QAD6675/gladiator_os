
#include <stdio.h>

FILE __libc_stderr = {.fd = 2};

FILE* stderr = &__libc_stderr;
