
#include <dirent.h>
#include <gladiatoros.h>

struct dirent* readdir(DIR* dirp) {
	static struct dirent dire;
	if (!dir_read(dirp->fd, dire.d_name)) {
		return 0;
	}
	return &dire;
}
