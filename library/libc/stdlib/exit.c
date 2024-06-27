
#include <gladiatoros.h>

void (*__libc_atexit_funcs[32])(void);
int __libc_atexit_count = -1;

extern void (*__fini_array_start[])(void);
extern void (*__fini_array_end[])(void);

extern void _dl_fini(void);

_Noreturn void exit(int status) {
	// call atexit() registered functions
	while (__libc_atexit_count >= 0) {
		__libc_atexit_funcs[__libc_atexit_count]();
		__libc_atexit_count--;
	}
	// call global destructors
	void (**fini)(void) = __fini_array_end - 1;
	while (fini != __fini_array_start - 1) {
		(*fini)();
		fini--;
	}
	// call shared library destructors
	_dl_fini();
	// terminate the program
	proc_exit(status);
}
