
#include <stddef.h>

void* memcpy(void* restrict s1, const void* restrict s2, volatile size_t n) {
	char* dest = s1;
	const char* from = s2;
	while (n--) {
		*dest++ = *from++;
	}
	return s1;
}
