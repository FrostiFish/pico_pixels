#ifndef PIXEL_H
#define PIXEL_H

#include "pico/stdlib.h"

// Pixel data as array and castable as 32uint_t. index 0 is last byte, index 3 is first byte
typedef union {
    uint8_t bytes[4];
    uint32_t data;
} pixel_t;

#endif