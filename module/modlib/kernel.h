
#ifndef _MODLIB_KERNEL_H
#define _MODLIB_KERNEL_H

#include <kernsrv.h>

#define cprintf(format, ...) kernsrv->cprintf(format, ##__VA_ARGS__);

static inline void panic(const char* s) {
	return kernsrv->panic(s);
}

static inline void sleep(void* chan, struct spinlock* lock) {
	return kernsrv->sleep(chan, lock);
}

static inline void wakeup(void* chan) {
	return kernsrv->wakeup(chan);
}

static inline void initlock(struct spinlock* lock, const char* name) {
	return kernsrv->initlock(lock, name);
}

static inline void acquire(struct spinlock* lock) {
	return kernsrv->acquire(lock);
}

static inline void release(struct spinlock* lock) {
	return kernsrv->release(lock);
}

#endif
