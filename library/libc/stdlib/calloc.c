
#include <stdlib.h>
#include <string.h>

void* calloc(size_t nmemb, size_t size) {
	void* ptr = malloc(nmemb * size);
	if (!ptr) {
		return NULL;
	}
	memset(ptr, 0, nmemb * size);
	return ptr;
}
