//
// Created by winens on 2/16/22.
//

#ifndef COFFEE_STDIO_H
#define COFFEE_STDIO_H

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>
#include <drivers/graphics/graphics.h>
#include <port/port.h>
#include <mm/mm.h>

enum __SYSTEM_DEF_COLORS{
    __COL_DARK=0x141414,
    __COL_LIGHT=0xcccccc,
    __COL_SUCCESS=0x3db950,
    __COL_WARNING=0xd29922,
    __COL_ERROR=0xff7b72,
    __COL_CYAN=0x39c5cf,
    __COL_MAGENTA=0xd2a8ff,
    __COL_BLUE=0x58a6ff
};

int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
size_t strlen(const char*);

void printf(const char *s, ...);
void _kernel_log(const char* _title, int _title_col, const char* _index, ...);

#endif //COFFEE_STDIO_H
