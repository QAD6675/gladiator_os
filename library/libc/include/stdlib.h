
#ifndef _LIBC_STDLIB_H
#define _LIBC_STDLIB_H

#include <stddef.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

// numeric conversion functions
int atoi(const char* nptr);
long int atol(const char* nptr);
long long int atoll(const char* nptr);

// memory management functions
void* calloc(size_t nmemb, size_t size);
void free(void* ptr);
void* malloc(size_t size);

// communication with the environment
_Noreturn void abort(void);
int atexit(void (*func)(void));
int at_quick_exit(void (*func)(void));
_Noreturn void exit(int status);
_Noreturn void _Exit(int status);
_Noreturn void quick_exit(int status);

// integer arithmetic functions
int abs(int j);
long int labs(long int j);
long long int llabs(long long int j);

#endif
