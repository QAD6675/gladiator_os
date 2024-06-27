
#include <common/x86.h>
#include <core/mmu.h>
#include <core/proc.h>
#include <defs.h>

int exec(char* path, char** argv) {
	char *s, *last;
	unsigned int argc, sp, ustack[3 + MAXARG + 1];
	int sz;
	pde_t *pgdir = 0, *oldpgdir;
	struct proc* curproc = myproc();
	unsigned int entry, dynamic, interp = 0;

	// get a new page directory
	if ((pgdir = setupkvm()) == 0)
		goto bad;

	// Load program into memory.
	if ((sz = proc_elf_load(pgdir, 0, path, &entry, &dynamic, &interp)) < 0) {
		goto bad;
	}

	// create the process stack
	if (allocuvm(pgdir, PROC_STACK_BOTTOM - PGSIZE, PROC_STACK_BOTTOM, PTE_W | PTE_U) == 0) {
		goto bad;
	}
	sp = PROC_STACK_BOTTOM;

	// Push argument strings, prepare rest of stack in ustack.
	for (argc = 0; argv[argc]; argc++) {
		if (argc >= MAXARG)
			goto bad;
		sp = (sp - (strlen(argv[argc]) + 1)) & ~3;
		if (copyout(pgdir, sp, argv[argc], strlen(argv[argc]) + 1) < 0)
			goto bad;
		ustack[5 + argc] = sp;
	}
	ustack[5 + argc] = 0;

	ustack[0] = 0xffffffff; // fake return PC
	ustack[1] = argc; // int argc
	ustack[2] = sp - (argc + 1) * 4; // char* argv[]
	ustack[3] = 0; // char* envp[]
	ustack[4] = interp; // const char* interp

	sp -= (5 + argc + 1) * 4;
	if (copyout(pgdir, sp, ustack, (5 + argc + 1) * 4) < 0)
		goto bad;

	// Save program name for debugging.
	for (last = s = path; *s; s++)
		if (*s == '/')
			last = s + 1;
	safestrcpy(curproc->name, last, sizeof(curproc->name));

	// Commit to the user image.
	oldpgdir = curproc->pgdir;
	curproc->pgdir = pgdir;
	curproc->sz = sz;
	curproc->stack_size = PGSIZE;
	curproc->heap_size = 0;
	curproc->dyn_base = PROC_DYNAMIC_BOTTOM;
	curproc->tf->eip = entry; // _start
	curproc->tf->esp = sp;
	switchuvm(curproc);
	freevm(oldpgdir);
	return 0;

bad:
	if (pgdir)
		freevm(pgdir);
	return -1;
}
