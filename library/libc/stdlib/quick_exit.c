
#include <gladiatoros.h>

void (*__libc_atquickexit_funcs[32])(void);
int __libc_atquickexit_count = -1;

_Noreturn void quick_exit(int status) {
	// call at_quick_exit() registered functions
	while (__libc_atquickexit_count >= 0) {
		__libc_atquickexit_funcs[__libc_atquickexit_count]();
		__libc_atquickexit_count--;
	}
	// terminate the program
	proc_exit(status);
}
