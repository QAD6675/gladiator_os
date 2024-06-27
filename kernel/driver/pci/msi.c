
#include <arch/x86/msi.h>
#include <defs.h>

#include "pci.h"

static int pci_msi_probe(const struct PciAddress* addr, int* sixfour_bits) {
	int capoff = pci_find_capability(addr, 5);
	if (!capoff) {
		return 0;
	}

	uint16_t msictl = pci_read_config_reg16(addr, capoff + 2);
	cprintf("[pci] MSI %d:%d.%d off %x 64bits%s Mask%s MulMsg %x\n", addr->bus, addr->device,
			addr->function, capoff, BOOL2SIGN(msictl & (1 << 7)), BOOL2SIGN(msictl & (1 << 8)),
			(msictl >> 1) & 7);

	*sixfour_bits = msictl & (1 << 7);
	return capoff;
}

int pci_msi_enable(const struct PciAddress* addr, const struct MSIMessage* msg) {
	int sixfour_bits;
	int capoff = pci_msi_probe(addr, &sixfour_bits);
	if (!capoff) {
		return 0;
	}

	pci_write_config_reg32(addr, capoff + 4, msg->addr);
	if (sixfour_bits) {
		pci_write_config_reg32(addr, capoff + 8, 0);
		pci_write_config_reg16(addr, capoff + 12, msg->data);
	} else {
		pci_write_config_reg16(addr, capoff + 8, msg->data);
	}
	uint16_t msictl = pci_read_config_reg16(addr, capoff + 2);
	msictl &= 0xff8e;
	msictl |= 1;
	pci_write_config_reg16(addr, capoff + 2, msictl);
	pci_enable_bus_mastering(addr);
	return capoff;
}

void pci_msi_disable(const struct PciAddress* addr) {
	int capoff = pci_find_capability(addr, 5);
	if (!capoff) {
		return;
	}
	uint16_t msictl = pci_read_config_reg16(addr, capoff + 2);
	msictl &= ~1;
	pci_write_config_reg16(addr, capoff + 2, msictl);
}
