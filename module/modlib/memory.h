
#ifndef _MODLIB_MEMORY_H
#define _MODLIB_MEMORY_H

#include <kernsrv.h>

static inline void* pgalloc(unsigned int num_pages) {
	return kernsrv->pgalloc(num_pages);
}

static inline void pgfree(void* ptr, unsigned int num_pages) {
	return kernsrv->pgfree(ptr, num_pages);
}

static inline void* map_mmio_region(phyaddr_t phyaddr, size_t size) {
	return kernsrv->map_mmio_region(phyaddr, size);
}

static inline void* map_ram_region(phyaddr_t phyaddr, size_t size) {
	return kernsrv->map_ram_region(phyaddr, size);
}

static inline void* map_rom_region(phyaddr_t phyaddr, size_t size) {
	return kernsrv->map_rom_region(phyaddr, size);
}

static inline void* kalloc(void) {
	return pgalloc(1);
}
static inline void kfree(void* ptr) {
	return pgfree(ptr, 1);
}

#endif
