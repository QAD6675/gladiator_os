
#include <iostream>

#include "Devices.hpp"

int main() {
	std::cout << "List of Devices:\n\n";

	devices_init();

	for (DevmgrDevice& dev : devmgr_devices) {
		std::cout << dev.name << " at " << dev.dev_addr << '\n';
		for (DevmgrResource& res : dev.resource) {
			switch (res.type) {
			case DevmgrResourceType::io:
				std::cout << "    Resource IO " << std::hex << res.addr << " - "
						  << res.addr + res.size - 1 << '\n';
				break;
			case DevmgrResourceType::memory:
				std::cout << "    Resource Memory " << std::hex << res.addr << " - "
						  << res.addr + res.size - 1 << '\n';
				break;
			case DevmgrResourceType::irq:
				std::cout << "    Resource IRQ " << std::dec << res.addr << '\n';
				break;
			case DevmgrResourceType::msi:
				if (res.size == 1) {
					std::cout << "    Resource MSI " << std::dec << res.addr << '\n';
				} else {
					std::cout << "    Resource MSI " << std::dec << res.addr << " num " << res.size
							  << '\n';
				}
				break;
			case DevmgrResourceType::msix:
				std::cout << "    Resource MSI-X num " << std::dec << res.size << '\n';
				break;
			}
		}
		if (dev.driver_name.length()) {
			std::cout << "Driver: " << dev.driver_name << '\n';
		}
		std::cout << std::endl;
	}

	return 0;
}
