
#include <dirent.h>
#include <gladiatoros.h>
#include <stdlib.h>

DIR* opendir(const char* dirname) {
	DIR* dir = malloc(sizeof(DIR));
	if (!dir) {
		return NULL;
	}
	dir->fd = dir_open(dirname);
	if (dir->fd < 0) {
		free(dir);
		return NULL;
	}
	return dir;
}
