
#ifndef _MODLIB_HAL_H
#define _MODLIB_HAL_H

#include <kernsrv.h>

struct BlockDeviceDriver {
	int (*block_read)(void* private, unsigned int begin, int count, void* buf);
	int (*block_write)(void* private, unsigned int begin, int count, const void* buf);
};

struct FramebufferDriver {
	phyaddr_t (*enable)(void* private, int xres, int yres);
	void (*disable)(void* private);
	void (*update)(void* private);
	unsigned int (*read_edid)(void* private, void* buffer, unsigned int bytes);
};

static inline void hal_block_register_device(const char* name, void* private,
											 const struct BlockDeviceDriver* driver) {
	return kernsrv->hal_block_register_device(name, private, driver);
}

static inline void hal_display_register_device(const char* name, void* private,
											   const struct FramebufferDriver* driver) {
	return kernsrv->hal_display_register_device(name, private, driver);
}

static inline void hal_mouse_update(unsigned int data) {
	return kernsrv->hal_mouse_update(data);
}

static inline void hal_keyboard_update(unsigned int data) {
	return kernsrv->hal_keyboard_update(data);
}

#endif
