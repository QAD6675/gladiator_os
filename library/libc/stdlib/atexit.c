
extern void (*__libc_atexit_funcs[])(void);
extern int __libc_atexit_count;

#define ATEXIT_MAX 32

int atexit(void (*func)(void)) {
	if (__libc_atexit_count >= ATEXIT_MAX - 1) {
		return -1;
	}
	__libc_atexit_count++;
	__libc_atexit_funcs[__libc_atexit_count] = func;
	return 0;
}
