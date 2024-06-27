
#include <gladiatoros.h>
#include <stdio.h>
#include <stdlib.h>

int fclose(FILE* stream) {
	if (close(stream->fd) < 0) {
		return EOF;
	}
	free(stream);
	return 0;
}
