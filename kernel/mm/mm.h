//
// Created by winens on 2/15/22.
//

#ifndef COFFEE_OS_MM_H
#define COFFEE_OS_MM_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#define MM_PAGE_SIZE (4096)
#define MM_KERNEL_BASE (0xffffffff80000000)
#define MM_HIGHER_BASE (0xffff800000000000)

struct _memory {
    size_t _total;
    size_t _usable;
};

void Memory_Map_Exec(uint32_t *mmap);

#endif //COFFEE_OS_MM_H
