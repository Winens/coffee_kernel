//
// Created by winens on 2/15/22.
//

#ifndef COFFEE_OS_PORT_H
#define COFFEE_OS_PORT_H

#include <stdint.h>

uint8_t _inb(uint16_t port);

void _outb(uint16_t port, uint8_t data);

#endif //COFFEE_OS_PORT_H
