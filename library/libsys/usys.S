
#include "../../kernel/core/traps.h"
#include "include/syscall.h"

#define SYSCALL(name)                                                                  \
	.globl name;                                                                       \
	.type name STT_FUNC;                                                               \
	name:                                                                              \
	movl $SYS_##name, % eax;                                                           \
	int $T_SYSCALL;                                                                    \
	ret

SYSCALL(fork)
SYSCALL(proc_exit)
SYSCALL(wait)
SYSCALL(pipe)
SYSCALL(read)
SYSCALL(write)
SYSCALL(close)
SYSCALL(kill)
SYSCALL(exec)
SYSCALL(open)
SYSCALL(mknod)
SYSCALL(unlink)
SYSCALL(getcwd)
SYSCALL(link)
SYSCALL(mkdir)
SYSCALL(chdir)
SYSCALL(dup)
SYSCALL(getpid)
SYSCALL(sbrk)
SYSCALL(sleep)
SYSCALL(uptime)
SYSCALL(dir_open)
SYSCALL(dir_read)
SYSCALL(dir_close)
SYSCALL(file_get_size)
SYSCALL(lseek)
SYSCALL(file_get_mode)
SYSCALL(dynamic_load)
SYSCALL(kcall)
SYSCALL(message_send)
SYSCALL(message_receive)
SYSCALL(message_wait)
SYSCALL(getppid)
SYSCALL(proc_search)
SYSCALL(pty_create)
SYSCALL(pty_read_output)
SYSCALL(pty_write_input)
SYSCALL(pty_close)
SYSCALL(pty_switch)
SYSCALL(proc_status)
SYSCALL(module_load)
