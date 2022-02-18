//
// Created by winens on 2/18/22.
//

#include <mm/heap.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

struct _HEAP *_heap;

void HEAP_Exec(){
    _heap->_block = 0;
}

void HEAP_Add_Block(struct _HEAP heap, uintptr_t address, uint32_t size, uint32_t bsize){
    struct _HEAP_BLOCK *__block;
    uint32_t bcnt, x;
    uint8_t *bm;

    __block = (struct _HEAP_BLOCK*)address;
    __block->_size = size - sizeof(struct _HEAP_BLOCK);
    __block->_bsize = bsize;
    __block->_next = heap._block;

    heap._block = __block;

    bcnt = (__block->_bsize / __block->_size);
    bm = (uint8_t*)&__block[1];

    for(int q = 0; q < bcnt; ++q){
        bm[q] = 0;
    }

    bcnt = (bcnt / bsize) * bsize < bcnt ? bcnt / bsize + 1 : bcnt / bsize;
    for(int q = 0; q < bcnt; ++q){
        bm[q] = 5;
    }

    __block->_lfb = bcnt - 1;
    __block->_used = bcnt;
}

static uint8_t HEAP_Get_NID(uint8_t q, uint8_t w){
    uint8_t r;
    for(r = q + 1; r == w || r == 0; ++r);
    return r;
}