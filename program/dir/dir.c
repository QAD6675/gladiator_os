
#include <gladiatoros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_IFMT 0170000
#define S_IFDIR 0040000

char* dir_type_str(const char* name) {
	int mode = file_get_mode(name);
	if ((mode & S_IFMT) == S_IFDIR) {
		return "<DIR>";
	} else {
		return "     ";
	}
}

int main(int argc, char* argv[]) {
	char* dir_target;
	char cwd[64];
	getcwd(cwd);
	if (argc == 1) {
		dir_target = cwd;
	} else {
		dir_target = argv[1];
	}
	int handle = dir_open(dir_target);
	if (handle < 0) {
		fputs("Directory not exist\n", stderr);
		exit(EXIT_FAILURE);
	}
	char buf[256];
	char fullname[256];
	int num = 0;
	while (dir_read(handle, buf)) {
		strcpy(fullname, dir_target);
		fullname[strlen(dir_target)] = '/';
		strcpy(fullname + strlen(dir_target) + 1, buf);
		printf("%s %s %d\n", dir_type_str(fullname), buf, file_get_size(fullname));
		num++;
	}
	printf("\nTotal: %d\n", num);
	return 0;
}
