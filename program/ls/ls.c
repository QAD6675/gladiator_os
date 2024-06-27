
#include <dirent.h>
#include <gladiatoros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	char* dir_target;
	char cwd[64];
	getcwd(cwd);
	if (argc == 1) {
		dir_target = cwd;
	} else {
		dir_target = argv[1];
	}
	DIR* dir = opendir(dir_target);
	if (!dir) {
		printf("opendir failed\n");
		return 1;
	}
	struct dirent* dirent;
	while ((dirent = readdir(dir)) != NULL) {
		printf("%s ", dirent->d_name);
	}
	closedir(dir);
	putchar('\n');
}
