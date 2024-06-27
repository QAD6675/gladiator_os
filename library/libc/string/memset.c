
#include <stddef.h>

void* memset(void* s, int c, volatile size_t n) {
	char* ss = s;
	while (n--) {
		*ss = c;
		ss++;
	}
	return s;
}
