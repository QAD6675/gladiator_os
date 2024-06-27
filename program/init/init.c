
#include <gladiatoros.h>
#include <stdio.h>

const char* argv[] = {"sh", 0};

int main(void) {
	int pid, wpid;
	for (;;) {
		puts("init: starting sh");
		pid = fork();
		if (pid < 0) {
			fputs("init: fork failed\n", stderr);
			return 1;
		}
		if (pid == 0) {
			exec("/bin/sh", argv);
			fputs("init: exec sh failed\n", stderr);
			return 1;
		}
		while ((wpid = wait()) >= 0 && wpid != pid)
			fputs("init: zombie!\n", stderr);
	}
}
