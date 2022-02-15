//
// Created by winens on 2/15/22.
//

#include <drivers/graphics/graphics.h>
#include <boot/stivale2.h>
#include <boot/stivale2_funcs.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

uint32_t *_framebuffer;
uint16_t _w, _h, _pitch;

int _cursor_x, _cursor_y = 0;

void _CLEAN_TERMINAL(void){
    //b_width * fb_pitch / sizeof(uint32_t)
    for(size_t w = 0; w < _w; w++){
        for(size_t h = 0; h < _h; h++){
            _DRAW_PIXEL(w, h, DEF_BG_COL);
        }
    }
    _cursor_x = 0;
    _cursor_y = 0;
}

void Driver_Graphics_Exec(uint32_t *fb, uint32_t w, uint32_t h, uint32_t pitch){
    _framebuffer = fb;  //stivale2_get_tag(fb, STIVALE2_STRUCT_TAG_FRAMEBUFFER_ID);
    _w = w;
    _h = h;
    _pitch = pitch;
    _CLEAN_TERMINAL();
}

void _DRAW_PIXEL(uint32_t x, uint32_t y, uint32_t color){
    _framebuffer[y * (_pitch / sizeof(uint32_t)) + x] = color;
}