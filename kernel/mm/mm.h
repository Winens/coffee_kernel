//
// Created by winens on 2/15/22.
//

#ifndef COFFEE_OS_MM_H
#define COFFEE_OS_MM_H

#include <stdint.h>
#include <stddef.h>

struct _memory {
    size_t total;
    size_t usable;
};

void Memory_Map_Exec(uint32_t *mmap);

#endif //COFFEE_OS_MM_H
