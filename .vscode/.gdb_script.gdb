    set disassembly-flavor intel
    target remote | qemu-system-i386 -S -gdb stdio -m 32 -hda /home/qad7098/sources/gladiator_os/build/i686_debug/image.img
    symbol-file /home/qad7098/sources/gladiator_os/build/i686_debug/kernel/kernel.elf
