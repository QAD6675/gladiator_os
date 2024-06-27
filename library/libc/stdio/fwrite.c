
#include <gladiatoros.h>
#include <stdio.h>

size_t fwrite(const void* restrict ptr, size_t size, size_t nmemb, FILE* restrict stream) {
	if (!size) {
		return 0;
	}
	if (!nmemb) {
		return 0;
	}
	for (size_t i = 0; i < nmemb; i++) {
		if (write(stream->fd, ptr + i * size, size) < 0) {
			return i;
		}
	}
	return nmemb;
}
