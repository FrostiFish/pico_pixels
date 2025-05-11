#ifndef PICO_PIXELS_H
#define PICO_PIXELS_H

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "pixel.h"
#include "color_order.h"

typedef struct {
    PIO pio;
    uint sm;
    uint offset;
    uint pin;
    float frequency;
    pixel_t * pixels;
    size_t length;
    colorOrder color_order;
    pixel_t (*get_pixel_data) (rgb_t);
    bool ring;
} strip_t;

// functions

void strip_init(strip_t * strip, PIO pio, uint sm, uint offset, uint pin, float frequency, pixel_t * pixels, size_t length, colorOrder color_order, bool ring);
void strip_test_color_order(strip_t * strip);
void strip_set_pixel(strip_t * strip, uint index, rgb_t rgb);
void strip_set_all(strip_t * strip, rgb_t rgb);
void strip_update(strip_t * strip);

#endif