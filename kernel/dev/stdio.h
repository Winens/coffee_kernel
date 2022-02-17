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

int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
size_t strlen(const char*);

void printf(const char *s, ...);
void _kernel_log(const char* _title, int _title_col, const char* _index, ...);

#endif //COFFEE_STDIO_H
