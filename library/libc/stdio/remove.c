
#include <errno.h>
#include <gladiatoros.h>

int remove(const char* filename) {
	return errno = unlink(filename);
}
