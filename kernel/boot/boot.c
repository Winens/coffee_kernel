//
// Created by winens on 2/12/22.
//

#include <stdint.h>
#include <stddef.h>
#include <boot/stivale2.h>
#include <boot/stivale2_funcs.h>
#include <drivers/graphics/graphics.h>

void _start(struct stivale2_struct *stivale2_struct) {

    struct stivale2_struct_tag_framebuffer *_framebuffer = stivale2_get_tag(stivale2_struct, STIVALE2_STRUCT_TAG_FRAMEBUFFER_ID);

    Driver_Graphics_Exec((uint32_t *) _framebuffer->framebuffer_addr, _framebuffer->framebuffer_width, _framebuffer->framebuffer_height, _framebuffer->framebuffer_pitch);

    for (;;) {
        asm ("hlt");
    }
}