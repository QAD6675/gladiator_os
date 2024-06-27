
#include <stddef.h>

char* strncpy(char* restrict s1, const char* restrict s2, size_t n) {
	while (n--) {
		*s1++ = *s2++;
		if (*s2 == '\0') {
			while (n--) {
				*s1++ = '\0';
			}
			break;
		}
	}
	return s1;
}
