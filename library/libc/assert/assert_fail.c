
#include <stdio.h>
#include <stdlib.h>

_Noreturn void __libc_assert_fail(const char* file, int line, const char* func, const char* expr) {
	printf("%s:%d: %s: Assertion '%s' failed\n", file, line, func, expr);
	abort();
}
