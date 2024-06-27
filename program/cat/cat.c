
#include <stdio.h>
#include <string.h>

void print_file(FILE* file) {
	char buf[256];
	while (fgets(buf, 256, file) != NULL) {
		fputs(buf, stdout);
	}
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		// no command line arguments
		print_file(stdin);
	} else {
		for (int i = 1; i < argc; i++) {
			// display file one by one
			if (strcmp(argv[i], "-") == 0) {
				print_file(stdin);
			} else {
				FILE* file = fopen(argv[i], "r");
				if (file == NULL) {
					fputs("File not found\n", stderr);
					return 1;
				}
				print_file(file);
				fclose(file);
			}
		}
	}
}
