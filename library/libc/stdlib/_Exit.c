
#include <gladiatoros.h>

_Noreturn void _Exit(int status) {
	proc_exit(status);
}
