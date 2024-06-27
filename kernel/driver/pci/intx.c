
#include "pci-config.h"
#include "pci.h"

void pci_interrupt(int irq) {
	for (int i = 0; i < PCI_DEVICE_TABLE_SIZE; i++) {
		if (pci_device_table[i].irq == irq &&
			(pci_read_config_reg16(&pci_device_table[i].addr, PCI_CONF_STATUS) &
			 PCI_STATUS_INTERRUPT)) {
			pci_device_table[i].intx_intr_handler(&pci_device_table[i]);
		}
	}
}

void pci_register_intr_handler(struct PCIDevice* dev, void (*handler)(struct PCIDevice*)) {
	dev->intx_intr_handler = handler;
}

void pci_enable_intx_intr(const struct PciAddress* addr) {
	uint16_t pcicmd = pci_read_config_reg16(addr, PCI_CONF_COMMAND);
	pcicmd &= ~PCI_CONTROL_INTERRUPT_DISABLE;
	pci_write_config_reg16(addr, PCI_CONF_COMMAND, pcicmd);
}

void pci_disable_intx_intr(const struct PciAddress* addr) {
	uint16_t pcicmd = pci_read_config_reg16(addr, PCI_CONF_COMMAND);
	pcicmd |= PCI_CONTROL_INTERRUPT_DISABLE;
	pci_write_config_reg16(addr, PCI_CONF_COMMAND, pcicmd);
}
