
#include <gladiatoros.h>
#include <stdio.h>

int fseek(FILE* stream, long int offset, int whence) {
	int lsk;
	if (whence == SEEK_CUR) {
		lsk = FILE_SEEK_CUR;
	} else if (whence == SEEK_END) {
		lsk = FILE_SEEK_END;
	} else if (whence == SEEK_SET) {
		lsk = FILE_SEEK_SET;
	} else {
		return -1;
	}
	if (lseek(stream->fd, offset, lsk) < 0) {
		return -1;
	}
	return 0;
}
