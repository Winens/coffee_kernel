cmake_minimum_required(VERSION 3.0.0)
project(coffee)
set(KERNEL_BUILD coffee-kernel-x86_64)

include_directories(kernel)
include_directories(kernel/dev)

# Generate compile_commands.json for coc-clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ASM_NASM_OBJECT_FORMAT elf)
enable_language(ASM_NASM)   # Enabling NASM Assembly
set(CMAKE_ASM_NASM_COMPILER nasm)

set(CMAKE_C_FLAGS "-std=gnu11 -ffreestanding -fno-stack-protector -fno-pic -fpie -mno-80387 -mno-mmx -mno-3dnow -mno-sse -mno-sse2 -mno-red-zone")
set(CMAKE_EXE_LINKER_FLAGS "-fno-pic -fpie -Wl,-static,-pie,--no-dynamic-linker,-ztext -static-pie -nostdlib -Tlinker.ld -z max-page-size=0x1000")

add_executable(${KERNEL_BUILD} kernel/boot/boot.c kernel/drivers/graphics/graphics.c kernel/drivers/graphics/graphics.h kernel/drivers/graphics/_font.h kernel/boot/stivale2_funcs.c kernel/boot/stivale2_funcs.h kernel/mm/mm.c kernel/mm/mm.h kernel/port/port.c kernel/port/port.h kernel/dev/stdio.c kernel/dev/stdio.h kernel/cpu/gdt.c kernel/cpu/gdt.h kernel/mm/heap.c kernel/mm/heap.h)
set_target_properties(${KERNEL_BUILD} PROPERTIES LINK_DEPENDS linker.ld)
