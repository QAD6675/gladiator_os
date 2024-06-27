
#ifndef _POSIX_DIRENT_H
#define _POSIX_DIRENT_H

typedef struct {
	int fd;
} DIR;

struct dirent {
	char d_name[256];
};

DIR* opendir(const char* dirname);
struct dirent* readdir(DIR* dirp);
int closedir(DIR* dirp);

#endif
