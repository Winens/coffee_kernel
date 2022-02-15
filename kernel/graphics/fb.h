//
// Created by winens on 2/14/22.
//

#ifndef COFFEE_FB_H
#define COFFEE_FB_H

#include <stdint.h>
#include <stdbool.h>

struct res {
    uint16_t w;
    uint16_t h;
    uint16_t bpp;
};

struct fb_info {
    bool def_res;
    uint8_t  mem_model;
    uint64_t fb_addr;
    uint16_t fb_pitch;
    uint16_t fb_w;
    uint16_t fb_h;
    uint16_t fb_bpp;
    uint8_t RED_mask_size;
    uint8_t RED_mask_shift;
    uint8_t GREEN_mask_size;
    uint8_t GREEN_mask_shift;
    uint8_t BLUE_mask_size;
    uint8_t BLUE_mask_shift;
};

//bool fb_init(struct fb_info *fb, uint16_t w, uint16_t h, uint16_t bpp); // REMOVE
void fb_clean(struct fb_info *fb);

#endif //COFFEE_FB_H
