
#include <gladiatoros.h>
#include <stdio.h>
#include <stdlib.h>

_Noreturn void abort(void) {
	fputs("Aborted\n", stderr);
	proc_exit(EXIT_FAILURE);
}
