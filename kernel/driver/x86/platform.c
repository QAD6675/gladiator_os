
#include <defs.h>
#include <driver/pci/pci.h>
#include <driver/ps2/ps2.h>
#include <driver/x86/ioapic.h>
#include <driver/x86/rtc.h>
#include <driver/x86/uart.h>

extern int intel_pcie_mmcfg_init(const struct PciAddress* host_bridge_addr);
extern void picinit(void);

void platform_init(void) {
	// onboard devices
	picinit();
	ioapic_init();
	uart_init();
	rtc_init();
	ps2_keyboard_init();
	ps2_mouse_init();
	const struct PciAddress pci_host_addr = {0, 0, 0};
	intel_pcie_mmcfg_init(&pci_host_addr);
	pci_init();
}
