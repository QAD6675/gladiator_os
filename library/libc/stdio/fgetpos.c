
#include <gladiatoros.h>
#include <stdio.h>

int fgetpos(FILE* restrict stream, fpos_t* restrict pos) {
	fpos_t position = lseek(stream->fd, 0, FILE_SEEK_CUR);
	if (position < 0) {
		return position;
	}
	*pos = position;
	return 0;
}
