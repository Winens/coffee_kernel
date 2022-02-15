//
// Created by winens on 2/15/22.
//

#ifndef COFFEE_GRAPHICS_H
#define COFFEE_GRAPHICS_H
// Supports VBE, VGA And GOP

#include <stdint.h>

#define DEF_BG_COL 0x000000
#define DEF_TXT_COL 0xFFFFFF

void Driver_Graphics_Exec(uint32_t *fb, uint32_t w, uint32_t h, uint32_t pitch);
void _DRAW_PIXEL(uint32_t x, uint32_t y, uint32_t color);

#endif //COFFEE_GRAPHICS_H
