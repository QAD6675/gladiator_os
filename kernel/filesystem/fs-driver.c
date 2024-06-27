
#include <defs.h>
#include <filesystem/fat32/fat32.h>
#include <filesystem/filesystem.h>
#include <filesystem/vfs/vfs.h>

const struct FilesystemDriver* filesystem_fat32_driver;

void filesystem_register_driver(const struct FilesystemDriver* fs_driver) {
	if (strncmp(fs_driver->name, "fat32", 10) == 0) {
		filesystem_fat32_driver = fs_driver;
	}
}

void filesystem_init(void) {
	fat32_init();
	vfs_init();
}
