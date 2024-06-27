
#ifndef _COMMON_DELAY_H
#define _COMMON_DELAY_H

#include <common/types.h>

#define _X86GPRINTRIN_H_INCLUDED
#include <ia32intrin.h>

static inline void mdelay(uint64_t ms) {
	uint64_t end = __rdtsc() + ms * 2000 * 1000;
	while (__rdtsc() < end) {
	}
}

static inline void udelay(uint64_t us) {
	uint64_t end = __rdtsc() + us * 2000;
	while (__rdtsc() < end) {
	}
}

#endif
