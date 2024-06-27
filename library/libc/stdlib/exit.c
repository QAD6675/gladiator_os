/*
 * exit function
 *
 * This file is part of GLADIATOROS.
 *
 * GLADIATOROS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GLADIATOROS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GLADIATOROS.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <gladiatoros.h>

void (*__libc_atexit_funcs[32])(void);
int __libc_atexit_count = -1;

extern void (*__fini_array_start[])(void);
extern void (*__fini_array_end[])(void);

extern void _dl_fini(void);

_Noreturn void exit(int status) {
	// call atexit() registered functions
	while (__libc_atexit_count >= 0) {
		__libc_atexit_funcs[__libc_atexit_count]();
		__libc_atexit_count--;
	}
	// call global destructors
	void (**fini)(void) = __fini_array_end - 1;
	while (fini != __fini_array_start - 1) {
		(*fini)();
		fini--;
	}
	// call shared library destructors
	_dl_fini();
	// terminate the program
	proc_exit(status);
}
