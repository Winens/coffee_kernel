//
// Created by winens on 2/18/22.
//

#ifndef COFFEE_HEAP_H
#define COFFEE_HEAP_H

#include <stdint.h>

struct _HEAP_BLOCK{
    struct _HEAP_BLOCK *_next;
    uint32_t _size;
    uint32_t _used;
    uint32_t _bsize;
    uint32_t _lfb;
};

struct _HEAP{
    struct _HEAP_BLOCK *_block;
};

void HEAP_Exec();
void HEAP_Add_Block(struct _HEAP *heap, uintptr_t address, uint32_t size, uint32_t bsize);
static uint8_t HEAP_Get_NID(uint8_t q, uint8_t w);

#endif //COFFEE_HEAP_H
