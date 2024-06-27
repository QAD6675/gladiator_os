
#include <gladiatoros.h>
#include <stdio.h>

int getc(FILE* stream) {
	char c;
	if (read(stream->fd, &c, 1) < 0) {
		return EOF;
	}
	return c;
}
