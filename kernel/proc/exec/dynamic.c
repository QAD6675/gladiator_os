
#include "elf.h"
#include <core/proc.h>
#include <defs.h>

int proc_load_dynamic(struct proc* proc, const char* name, unsigned int* dynamic,
					  unsigned int* entry) {
	int sz;
	unsigned int interp;
	unsigned int load_base = myproc()->dyn_base;
	if ((sz = proc_elf_load(proc->pgdir, load_base, name, entry, dynamic, &interp)) < 0) {
		return 0;
	}
	myproc()->dyn_base += PGROUNDUP(sz);
	return load_base;
}
