
#ifndef _LIBC_ASSERT_H
#define _LIBC_ASSERT_H

#ifndef NDEBUG
extern _Noreturn void __libc_assert_fail(const char* file, int line, const char* func,
										 const char* expr);
#define assert(expr)                                                                   \
	if ((expr) == 0) {                                                                 \
		__libc_assert_fail(__FILE__, __LINE__, __func__, #expr);                       \
	}
#else
#define assert(expr) ((void)0)
#endif

#endif
