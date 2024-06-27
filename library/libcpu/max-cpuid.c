
#include <cpuid.h>

unsigned int cpu_get_max_cpuid(void) {
	unsigned int eax = 0, ebx, ecx, edx;
	__get_cpuid(0, &eax, &ebx, &ecx, &edx);
	return eax;
}

unsigned int cpu_get_max_ext_cpuid(void) {
	unsigned int eax = 0, ebx, ecx, edx;
	__get_cpuid(0x80000000, &eax, &ebx, &ecx, &edx);
	return eax;
}
