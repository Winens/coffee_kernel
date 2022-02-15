//
// Created by winens on 2/14/22.
//

#include <graphics/fb.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <graphics/vbe.h>
//#include <mm/pmm.h>

void fb_clean(struct fb_info *fb){
    for (size_t s = 0;s < fb->fb_h; s++){
        switch (fb->fb_bpp) {
            case 32: {
                uint32_t *fbp = (void *)(uintptr_t)fb->fb_addr;
                size_t r = (s*fb->fb_pitch)/4;
                for (size_t x = 0; x < fb->fb_h; x++) {
                    fbp[r+x] = 0;
                }
            }
            case 16: {
                uint32_t *fbp = (void *)(uintptr_t)fb->fb_addr;
                size_t r = (s*fb->fb_pitch)/2;
                for (size_t x = 0; x < fb->fb_h; x++) {
                    fbp[r+x] = 0;
                }
            }
            default: {
                uint32_t *fbp = (void *)(uintptr_t)fb->fb_addr;
                size_t r = (s*fb->fb_pitch);
                for (size_t x = 0; x < fb->fb_h; x++) {
                    fbp[r+x] = 0;
                }
            }
        }
    }
}



