
#include <defs.h>

#include "hal.h"

struct MBREntry {
	uint8_t boot; // boot signature
	uint8_t first[3]; // first sector CHS address
	uint8_t type; // partition type
	uint8_t last[3]; // last sector CHS address
	uint32_t lba; // start sector LBA
	uint32_t size; // number of sectors
} PACKED;

void mbr_probe_partition(int block_id) {
	void* bootsect = kalloc();
	if (hal_disk_read(block_id, 0, 1, bootsect) < 0) {
		panic("disk read error");
	}
	for (int j = 0; j < 4; j++) {
		struct MBREntry* entry = bootsect + 0x1be + j * 0x10;
		enum HalPartitionFilesystemType fs;
		if (entry->type == 0) {
			continue;
		} else if ((entry->type == 0xb) || (entry->type == 0xc)) {
			cprintf("[mbr] FAT32 partition on block device %d MBR %d\n", block_id, j);
			fs = HAL_PARTITION_TYPE_FAT32;
		} else if (entry->type == 0x83) {
			cprintf("[mbr] Linux partition on block device %d MBR %d\n", block_id, j);
			fs = HAL_PARTITION_TYPE_LINUX;
		} else {
			cprintf("[mbr] Partition on block device %d MBR %d type %x\n", block_id, j,
					entry->type);
			fs = HAL_PARTITION_TYPE_OTHER;
		}
		if (!hal_partition_map_insert(fs, block_id, entry->lba, entry->size)) {
			panic("hal too many partition");
		}
	}
	kfree(bootsect);
}
