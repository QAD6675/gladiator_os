
#include <stddef.h>

void* memchr(const void* s, int c, size_t n) {
	const char* ss = s;
	for (size_t i = 0; i < n; i++) {
		if (ss[i] == c) {
			return (void*)s + i;
		}
	}
	return NULL;
}
