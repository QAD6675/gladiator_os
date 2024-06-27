
#include <gladiatoros.h>
#include <stdio.h>
#include <string.h>

int fputs(const char* restrict s, FILE* restrict stream) {
	if (write(stream->fd, s, strlen(s)) < 0) {
		return EOF;
	}
	return 0;
}
