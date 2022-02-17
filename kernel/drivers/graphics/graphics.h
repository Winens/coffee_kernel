//
// Created by winens on 2/15/22.
//

#ifndef COFFEE_GRAPHICS_H
#define COFFEE_GRAPHICS_H
// Supports VBE, VGA And GOP

#include <stdint.h>
#include <stddef.h>

void _NEW_LINE();
void Driver_Graphics_Exec(uint32_t *fb, uint32_t w, uint32_t h, uint32_t pitch);
void _DRAW_PIXEL(int x, int y, uint32_t color);
void _DRAW_CHAR(unsigned char c);
void _DRAW_CHAR_C(unsigned char c, uint32_t color);
int _CALC_CC_LENGTH(const char *s);
void _DRAW_STRING(const char *s);

#endif //COFFEE_GRAPHICS_H
