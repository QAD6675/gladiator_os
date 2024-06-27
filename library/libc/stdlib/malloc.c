
#include <gladiatoros.h>
#include <stdlib.h>

void* malloc(size_t size) {
	return sbrk(size);
}
