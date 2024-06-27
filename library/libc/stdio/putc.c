
#include <gladiatoros.h>
#include <stdio.h>

int putc(int c, FILE* stream) {
	if (write(stream->fd, &c, 1) < 0) {
		return EOF;
	}
	return c;
}
