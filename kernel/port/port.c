//
// Created by winens on 2/15/22.
//

#include <port/port.h>

uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
    return ret;
}

void outb(uint16_t port, uint8_t data)
{
    asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}