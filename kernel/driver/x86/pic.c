
#include <common/x86.h>
#include <core/traps.h>

// I/O Addresses of the two programmable interrupt controllers
#define IO_PIC1 0x20 // First (IRQs 0-7)
#define IO_PIC2 0xA0 // Second (IRQs 8-15)

void picinit(void) {
	// mask all interrupts
	outb(IO_PIC1 + 1, 0xFF);
	outb(IO_PIC2 + 1, 0xFF);

	outb(IO_PIC1, 0x11);
	outb(IO_PIC2, 0x11);

	outb(IO_PIC1 + 1, 32);
	outb(IO_PIC2 + 1, 40);

	outb(IO_PIC1 + 1, 0x04);
	outb(IO_PIC2 + 1, 0x02);

	outb(IO_PIC1 + 1, 0x01);
	outb(IO_PIC1 + 1, 0x01);
}
