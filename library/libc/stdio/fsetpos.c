
#include <gladiatoros.h>
#include <stdio.h>

int fsetpos(FILE* stream, const fpos_t* pos) {
	int ret = lseek(stream->fd, *pos, FILE_SEEK_SET);
	if (ret < 0) {
		return ret;
	}
	return 0;
}
