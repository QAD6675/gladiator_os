
#include <cpuid.h>

#include "cpuinfo.h"

unsigned int cpu_get_physical_address_size(void) {
	if (cpu_get_max_ext_cpuid() < 0x80000008) {
		return 0;
	}
	unsigned int eax = 0, ebx, ecx, edx;
	__get_cpuid(0x80000008, &eax, &ebx, &ecx, &edx);
	return eax & 0xff;
}

unsigned int cpu_get_virtual_address_size(void) {
	if (cpu_get_max_ext_cpuid() < 0x80000008) {
		return 0;
	}
	unsigned int eax = 0, ebx, ecx, edx;
	__get_cpuid(0x80000008, &eax, &ebx, &ecx, &edx);
	return (eax >> 8) & 0xff;
}
