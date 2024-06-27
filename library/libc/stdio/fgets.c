
#include <stddef.h>
#include <stdio.h>

char* fgets(char* restrict s, int n, FILE* restrict stream) {
	char* str = s;
	while (--n) {
		int c = fgetc(stream);
		if (c == '\n') {
			*s = c;
			*(++s) = '\0';
			return str;
		} else if (c == EOF) {
			*s = '\0';
			return NULL;
		}
		*s = c;
		s++;
	}
	return str;
}
