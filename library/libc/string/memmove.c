
#include <stddef.h>
#include <string.h>

void* memmove(void* s1, const void* s2, size_t n) {
	char tmp[n];
	memcpy(tmp, s2, n);
	memcpy(s1, tmp, n);
	return s1;
}
