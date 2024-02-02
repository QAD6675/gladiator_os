    symbol-file /home/devil-7098/projs/gladiator_os/build/i686_debug/kernel/kernel.elf
    set disassembly-flavor intel
    target remote | qemu-system-i386 -S -gdb stdio -m 32 -hda /home/devil-7098/projs/gladiator_os/build/i686_debug/image.img
