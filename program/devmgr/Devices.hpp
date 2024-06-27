
#ifndef _DEVMGR_DEVICE_CPP
#define _DEVMGR_DEVICE_CPP

#include <cstdint>
#include <string>
#include <vector>

enum class DevmgrResourceType {
	io,
	memory,
	irq,
	msi,
	msix,
};

struct DevmgrResource {
	DevmgrResourceType type;
	std::uint64_t addr;
	std::uint64_t size;
};

class DevmgrDevice {
public:
	std::string name;
	std::string dev_addr;
	std::string driver_name;
	std::vector<DevmgrResource> resource;
};

extern std::vector<DevmgrDevice> devmgr_devices;

void devices_init();

#endif
