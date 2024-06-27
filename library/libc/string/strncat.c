
#include <string.h>

char* strncat(char* restrict s1, const char* restrict s2, size_t n) {
	char* orig = s1;
	while (*s1) {
		s1++;
	}
	strncpy(s1, s2, n);
	return orig;
}
