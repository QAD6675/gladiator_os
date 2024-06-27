
#include <core/proc.h>
#include <defs.h>
#include <filesystem/vfs/vfs.h>

#include "elf.h"

int proc_elf_load(pde_t* pgdir, unsigned int base, const char* name, unsigned int* entry,
				  unsigned int* dynamic, unsigned int* interp) {
	struct FileDesc fd;
	if (vfs_fd_open(&fd, name, O_READ) < 0) {
		return -1;
	}

	struct elfhdr elf;
	if (vfs_fd_read(&fd, (char*)&elf, sizeof(elf)) != sizeof(elf)) {
		vfs_fd_close(&fd);
		return -1;
	}
	if (elf.magic != ELF_MAGIC) {
		vfs_fd_close(&fd);
		return -1;
	}
	*entry = elf.entry;

	struct proghdr ph;
	unsigned int sz = 0;
	for (unsigned int off = elf.phoff; off < elf.phoff + elf.phnum * sizeof(ph);
		 off += sizeof(ph)) {
		if (vfs_fd_seek(&fd, off, SEEK_SET) < 0) {
			vfs_fd_close(&fd);
			return -1;
		}
		if (vfs_fd_read(&fd, (char*)&ph, sizeof(ph)) != sizeof(ph)) {
			vfs_fd_close(&fd);
			return -1;
		}
		if (ph.type == ELF_PROG_DYNAMIC) {
			*dynamic = base + ph.vaddr;
			continue;
		} else if (ph.type == ELF_PROG_INTERP) {
			*interp = base + ph.vaddr;
			continue;
		} else if (ph.type != ELF_PROG_LOAD) {
			continue;
		}
		if (allocuvm(pgdir, base + ph.vaddr - ph.vaddr % PGSIZE, base + ph.vaddr + ph.memsz,
					 (ph.flags & ELF_PROG_FLAG_WRITE) ? (PTE_W | PTE_U) : PTE_U) == 0) {
			vfs_fd_close(&fd);
			return -1;
		}
		if (ph.vaddr + ph.memsz > sz) {
			sz = ph.vaddr + ph.memsz;
		}
		if (loaduvm(pgdir, (char*)base + ph.vaddr - ph.vaddr % PGSIZE, &fd,
					ph.off - ph.vaddr % PGSIZE, ph.vaddr % PGSIZE + ph.filesz) < 0) {
			vfs_fd_close(&fd);
			return -1;
		}
	}

	vfs_fd_close(&fd);

	return sz;
}
