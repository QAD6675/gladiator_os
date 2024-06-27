
#include <gladiatoros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void load_module(const char* name) {
	char module_path[512];
	strcpy(module_path, "/boot/module/");
	strcat(module_path, name);
	strcat(module_path, ".mod");
	int ret = module_load(module_path);
	if (ret < 0) {
		printf("load %s failed with %d\n", name, ret);
		exit(0);
	}
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		puts("kmod mod_name(s)");
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		load_module(argv[i]);
	}
	return 0;
}
