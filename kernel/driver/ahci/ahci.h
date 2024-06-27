
#ifndef _DRIVER_AHCI_AHCI_H
#define _DRIVER_AHCI_AHCI_H

#include <common/types.h>

struct AHCIController {
	volatile uint32_t* abar;
	volatile struct AHCICommandList* command_list[32];
	volatile void* received_fis_buffer[32];
};

void ahci_init(void);
int ahci_port_get_link_status(struct AHCIController* ahci_controller, unsigned int port);
uint32_t ahci_port_get_signature(struct AHCIController* ahci_controller, unsigned int port);
void ahci_port_reset(struct AHCIController* ahci_controller, unsigned int port);
int ahci_exec_pio_in(struct AHCIController* ahci_controller, unsigned int port, uint8_t cmd,
					 unsigned long long lba, unsigned int cont, void* buf, unsigned int blocks);
int ahci_exec_pio_out(struct AHCIController* ahci, unsigned int port, uint8_t cmd,
					  unsigned long long lba, unsigned int cont, const void* buf,
					  unsigned int blocks);
#endif
