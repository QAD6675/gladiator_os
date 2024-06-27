
#include <gladiatoros.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		fputs("Usage: mkdir [dir]\n", stderr);
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		if (mkdir(argv[i]) < 0) {
			perror("Create directory failed");
			return 1;
		}
	}
	return 0;
}
