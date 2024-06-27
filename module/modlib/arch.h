
#ifndef _MODLIB_ARCH_H
#define _MODLIB_ARCH_H

#include <kernsrv.h>

struct MSIMessage {
	uint64_t addr;
	uint32_t data;
};

static inline int msi_alloc_vector(struct MSIMessage* msg, void (*handler)(void*), void* private) {
	return kernsrv->msi_alloc_vector(msg, handler, private);
}

static inline void msi_free_vector(const struct MSIMessage* msg) {
	return kernsrv->msi_free_vector(msg);
}

#endif
