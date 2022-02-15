//
// Created by winens on 2/15/22.
//

#include <drivers/graphics/graphics.h>
#include <boot/stivale2.h>
#include <boot/stivale2_funcs.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <drivers/graphics/font.h>

uint32_t *_framebuffer;
uint16_t _w, _h, _pitch;

int _cursor_x = 1, _cursor_y = 1; // = 0
uint8_t *_font_bm;
uint16_t _font_w = 8, _font_h = 16;

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
    _framebuffer = fb;
    _w = w;
    _h = h;
    _pitch = pitch;
    _CLEAN_TERMINAL();
    _font_bm = (uint8_t *) &font; // font;
}

void _DRAW_PIXEL(int x, int y, uint32_t color){
    _framebuffer[y * (_pitch / sizeof(uint32_t)) + x] = color;
}

void _DRAW_CHAR(unsigned char c){
    int mask[8] = {1,2,4,8,16,32,64,128};
    unsigned char *glyph = font+(int)c*16;

    int _draw_x = _cursor_x * _font_w;
    int _draw_y = _cursor_y * _font_h;

    //unsigned  char *glyph = &_font_bm[c * _font_h];
    for(int _y = 0; _y < _font_h; _y++){
        for(int _x = _font_w - 1; _x >= 0; _x--){
            _draw_x++;
            if (glyph[_y]&mask[_x]) _DRAW_PIXEL(_draw_x, _draw_y, DEF_TXT_COL);
        }
        _draw_x -= 8;
        _draw_y++;
    }
    _cursor_x++;
}
