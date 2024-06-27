
#include <common/sleeplock.h>
#include <common/spinlock.h>
#include <common/x86.h>
#include <core/mmu.h>
#include <core/proc.h>
#include <defs.h>
#include <memlayout.h>
#include <param.h>

void initsleeplock(struct sleeplock* lk, const char* name) {
	initlock(&lk->lk, "sleep lock");
	lk->name = name;
	lk->locked = 0;
	lk->pid = 0;
}

void acquiresleep(struct sleeplock* lk) {
	acquire(&lk->lk);
	while (lk->locked) {
		sleep(lk, &lk->lk);
	}
	lk->locked = 1;
	lk->pid = myproc()->pid;
	release(&lk->lk);
}

void releasesleep(struct sleeplock* lk) {
	acquire(&lk->lk);
	lk->locked = 0;
	lk->pid = 0;
	wakeup(lk);
	release(&lk->lk);
}

int holdingsleep(struct sleeplock* lk) {
	int r;

	acquire(&lk->lk);
	r = lk->locked && (lk->pid == myproc()->pid);
	release(&lk->lk);
	return r;
}
