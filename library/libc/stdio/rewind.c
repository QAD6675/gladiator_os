
#include <gladiatoros.h>
#include <stdio.h>

void rewind(FILE* stream) {
	lseek(stream->fd, 0, FILE_SEEK_SET);
}
