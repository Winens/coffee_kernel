//
// Created by winens on 2/14/22.
//

#ifndef COFFEE_VBE_H
#define COFFEE_VBE_H

#include <stdint.h>
#include <stdbool.h>
#include <graphics/fb.h>

bool init_vbe(struct fb_info *fb, uint16_t w, uint16_t h, uint16_t bpp);

#endif //COFFEE_VBE_H
