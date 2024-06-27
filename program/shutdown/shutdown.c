
#include <gladiatoros.h>

#define POWER_KCALL_OP_SHUTDOWN 0
#define POWER_KCALL_OP_REBOOT 1
#define POWER_KCALL_OP_SUSPEND 2
#define POWER_KCALL_OP_HIBERNATE 3

int main() {
	kcall("power", POWER_KCALL_OP_SHUTDOWN);
}
