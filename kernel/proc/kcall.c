
#include <defs.h>

#include "kcall.h"

struct KCallTable kcall_table[256];

static int kcall_true(unsigned int arg) {
	return 123;
}

void kcall_init(void) {
	memset(kcall_table, 0, sizeof(kcall_table));
	kcall_set("true", kcall_true);
}

void kcall_set(const char* name, int (*handler)(unsigned int)) {
	for (int i = 0; i < 256; i++) {
		if (strncmp(kcall_table[i].name, name, 32) == 0) {
			if (handler) {
				kcall_table[i].handler = handler;
			} else {
				kcall_table[i].name[0] = '\0';
				kcall_table[i].handler = 0;
			}
			return;
		} else if (kcall_table[i].handler == 0) {
			strncpy(kcall_table[i].name, name, 32);
			kcall_table[i].handler = handler;
			return;
		}
	}
	panic("out ouf kcall table");
}

int kcall(const char* name, unsigned int arg) {
	for (int i = 0; i < 256; i++) {
		if (strncmp(kcall_table[i].name, name, 32) == 0) {
			return kcall_table[i].handler(arg);
		}
	}
	return -1;
}
