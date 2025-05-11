#include "pico/stdlib.h"
#include "color_order.h"

uint8_t min(uint8_t a, uint8_t b) {
    return (b < a) ? b : a;
}

uint8_t min3(uint8_t a, uint8_t b, uint8_t c) {
    return min(a, min(b, c));
}

pixel_t get_grb(rgb_t rgb) {
    return (pixel_t){ .bytes = { 0, rgb.blue, rgb.red, rgb.green } };
}

pixel_t get_rgb(rgb_t rgb) {
    return (pixel_t){ .bytes = { 0, rgb.blue, rgb.green, rgb.red } };
}

pixel_t get_rbg(rgb_t rgb) {
    return (pixel_t){ .bytes = { 0, rgb.green, rgb.blue, rgb.red } };
}

pixel_t get_gbr(rgb_t rgb) {
    return (pixel_t){ .bytes = { 0, rgb.red, rgb.blue, rgb.green } };
}

pixel_t get_brg(rgb_t rgb) {
    return (pixel_t){ .bytes = { 0, rgb.green, rgb.red, rgb.blue } };
}

pixel_t get_bgr(rgb_t rgb) {
    return (pixel_t){ .bytes = { 0, rgb.red, rgb.green, rgb.blue } };
}

pixel_t get_rgbw(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { white, rgb.blue-white, rgb.green-white, rgb.red-white } };
}

pixel_t get_rgwb(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.blue-white, white, rgb.green-white, rgb.red-white } };
}

pixel_t get_rbgw(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { white, rgb.green-white, rgb.blue-white, rgb.red-white } };
}

pixel_t get_rbwg(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.green-white, white, rgb.blue-white, rgb.red-white } };
}

pixel_t get_rwgb(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.blue-white, rgb.green-white, white, rgb.red-white } };
}

pixel_t get_rwbg(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.green-white, rgb.blue-white, white, rgb.red-white } };
}

pixel_t get_grbw(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { white, rgb.blue-white, rgb.red-white, rgb.green-white } };
}

pixel_t get_grwb(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.blue-white, white, rgb.red-white, rgb.green-white } };
}

pixel_t get_gbrw(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { white, rgb.red-white, rgb.blue-white, rgb.green-white } };
}

pixel_t get_gbwr(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.red-white, white, rgb.blue-white, rgb.green-white } };
}

pixel_t get_gwrb(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.blue-white, rgb.red-white, white, rgb.green-white } };
}

pixel_t get_gwbr(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.red-white, rgb.blue-white, white, rgb.green-white } };
}

pixel_t get_brgw(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { white, rgb.green-white, rgb.red-white, rgb.blue-white } };
}

pixel_t get_brwg(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.green-white, white, rgb.red-white, rgb.blue-white } };
}

pixel_t get_bgrw(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { white, rgb.red-white, rgb.green-white, rgb.blue-white } };
}

pixel_t get_bgwr(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.red-white, white, rgb.green-white, rgb.blue-white } };
}

pixel_t get_bwrg(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.green-white, rgb.red-white, white, rgb.blue-white } };
}

pixel_t get_bwgr(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.red-white, rgb.green-white, white, rgb.blue-white } };
}

pixel_t get_wrgb(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.blue-white, rgb.green-white, rgb.red-white, white } };
}

pixel_t get_wrbg(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.green-white, rgb.blue-white, rgb.red-white, white } };
}

pixel_t get_wgrb(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.blue-white, rgb.red-white, rgb.green-white, white } };
}

pixel_t get_wgbr(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.red-white, rgb.blue-white, rgb.green-white, white } };
}

pixel_t get_wbrg(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.green-white, rgb.red-white, rgb.blue-white, white } };
}

pixel_t get_wbgr(rgb_t rgb) {
    uint8_t white = min3(rgb.red, rgb.green, rgb.blue);
    return (pixel_t){ .bytes = { rgb.red-white, rgb.green-white, rgb.blue-white, white } };
}
