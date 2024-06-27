
extern void (*__libc_atquickexit_funcs[])(void);
extern int __libc_atquickexit_count;

#define ATQUICKEXIT_MAX 32

int at_quick_exit(void (*func)(void)) {
	if (__libc_atquickexit_count >= ATQUICKEXIT_MAX - 1) {
		return -1;
	}
	__libc_atquickexit_count++;
	__libc_atquickexit_funcs[__libc_atquickexit_count] = func;
	return 0;
}
