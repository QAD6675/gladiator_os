
#include <stddef.h>

int memcmp(const void* s1, const void* s2, size_t n) {
	const char* p = s1;
	const char* q = s2;
	while (n--) {
		if (*p == *q) {
			p++;
			q++;
		} else {
			return *p - *q;
		}
	}
	return 0;
}
