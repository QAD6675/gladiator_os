
#include <gladiatoros.h>
#include <stdio.h>

long int ftell(FILE* stream) {
	return lseek(stream->fd, 0, FILE_SEEK_CUR);
}
