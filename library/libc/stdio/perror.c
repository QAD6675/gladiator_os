
#include <errno.h>
#include <stdio.h>
#include <string.h>

void perror(const char* s) {
	if (errno) {
		printf("%s: %s\n", s, strerror(errno));
	}
}
