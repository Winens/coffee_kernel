//
// Created by winens on 2/15/22.
//

#include <drivers/graphics/graphics.h>
#include <boot/stivale2.h>
#include <boot/stivale2_funcs.h>
#include <drivers/graphics/_font.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

uint32_t *_framebuffer;
uint16_t _w, _h, _pitch;

uint8_t *_font_bm;
uint16_t _font_w = 8, _font_h = 16;

int _cmd_max_width, _cursor_x, _cursor_y = 0;

void _CLEAN_TERMINAL(){
    for(size_t w = 0; w < _w; w++){
        for(size_t h = 0; h < _h; h++){
            _DRAW_PIXEL(w, h, __COL_DARK);
        }
    }
    _cursor_x = 0;
    _cursor_y = 0;
}

void _NEW_LINE(){
    _cursor_y++;
    _cursor_x = 0;
}

void Driver_Graphics_Exec(uint32_t *fb, uint32_t w, uint32_t h, uint32_t pitch){
    _cmd_max_width = w;
    _framebuffer = fb;
    _w = w;
    _h = h;
    _pitch = pitch;
    _CLEAN_TERMINAL();
    _font_bm = (uint8_t *) &_font;
}

void _DRAW_PIXEL(int x, int y, uint32_t color){
    _framebuffer[y * (_pitch / sizeof(uint32_t)) + x] = color;
}

void _DRAW_CHAR(unsigned char c){
    int mask[8] = {1,2,4,8,16,32,64,128};
    unsigned char *glyph = _font_bm+(int)c*_font_h;

    int _draw_x = _cursor_x * _font_w;
    if(_draw_x >= _cmd_max_width){
        _NEW_LINE();
        _draw_x = _cursor_x * _font_w;
    }
    int _draw_y = _cursor_y * _font_h;

    for(int _y = 0; _y < _font_h; _y++){
        for(int _x = _font_w - 1; _x >= 0; _x--){
            _draw_x++;
            if (glyph[_y]&mask[_x]) _DRAW_PIXEL(_draw_x, _draw_y, __COL_LIGHT);
        }
        _draw_x -= _font_w;
        _draw_y++;
    }
    _cursor_x++;
}

void _DRAW_CHAR_C(unsigned char c, uint32_t color){
    int mask[8] = {1,2,4,8,16,32,64,128};
    unsigned char *glyph = _font_bm+(int)c*_font_h;

    int _draw_x = _cursor_x * _font_w;
    if(_draw_x >= _cmd_max_width){
        _NEW_LINE();
        _draw_x = _cursor_x * _font_w;
    }
    int _draw_y = _cursor_y * _font_h;

    for(int _y = 0; _y < _font_h; _y++){
        for(int _x = _font_w - 1; _x >= 0; _x--){
            _draw_x++;
            if (glyph[_y]&mask[_x]) _DRAW_PIXEL(_draw_x, _draw_y, color);
        }
        _draw_x -= _font_w;
        _draw_y++;
    }
    _cursor_x++;
}

int _CALC_CC_LENGTH(const char *s){
    int _s = 0;
    while(s[_s] != '\0') _s++;
    return _s;
}

void _DRAW_STRING(const char *s){
    for(int _r = 0; _r <= _CALC_CC_LENGTH(s)-1; _r++){
        _DRAW_CHAR(s[_r]);
    }
}