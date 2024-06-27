
#include <gladiatoros.h>
#include <stdio.h>

struct KernelTime {
	unsigned int year, month, day_of_week, day_of_month;
	unsigned int hour, minute, second;
};

int main(int argc, char* argv[]) {
	struct KernelTime time;
	kcall("date", (unsigned int)&time);
	printf("%d-%d-%d %d:%d:%d\n", time.year, time.month, time.day_of_month, time.hour,
		   time.minute, time.second);
}
