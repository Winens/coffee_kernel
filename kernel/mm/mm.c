//
// Created by winens on 2/15/22.
//

#include <mm/mm.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <boot/stivale2.h>

struct stivale2_struct_tag_memmap *_mmap;

void Memory_Map_Exec(uint32_t *mmap){
    _mmap = mmap;

    //_kernel_log("Memory Map", 0x00FF00, "Initalizing Finished with Success.\n");
}
