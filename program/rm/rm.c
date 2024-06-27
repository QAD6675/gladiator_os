
#include <gladiatoros.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		fputs("usage: rm [file]\n", stderr);
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		if (remove(argv[i]) < 0) {
			perror("remove failed");
			return 1;
		}
	}
	return 0;
}
