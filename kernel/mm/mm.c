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

    _kernel_log("Memory Map", __COL_SUCCESS, "Initalizing Finished with Success.\n");
}
