#ifndef COLOR_ORDER_H
#define COLOR_ORDER_H

#include "rgb.h"
#include "pixel.h"

typedef enum {
    GRB, //default
    RGB,
    RBG,
    GBR,
    BRG,
    BGR,
    RGBW,
    RGWB,
    RBGW,
    RBWG,
    RWGB,
    RWBG,
    GRBW,
    GRWB,
    GBRW,
    GBWR,
    GWRB,
    GWBR,
    BRGW,
    BRWG,
    BGRW,
    BGWR,
    BWRG,
    BWGR,
    WRGB,
    WRBG,
    WGRB,
    WGBR,
    WBRG,
    WBGR
} colorOrder;

#define DEFAULT_COLOR_ORDER GRB

// Function declarations
pixel_t get_grb(rgb_t rgb);
pixel_t get_rgb(rgb_t rgb);
pixel_t get_rbg(rgb_t rgb);
pixel_t get_gbr(rgb_t rgb);
pixel_t get_brg(rgb_t rgb);
pixel_t get_bgr(rgb_t rgb);
pixel_t get_rgbw(rgb_t rgb);
pixel_t get_rgwb(rgb_t rgb);
pixel_t get_rbgw(rgb_t rgb);
pixel_t get_rbwg(rgb_t rgb);
pixel_t get_rwgb(rgb_t rgb);
pixel_t get_rwbg(rgb_t rgb);
pixel_t get_grbw(rgb_t rgb);
pixel_t get_grwb(rgb_t rgb);
pixel_t get_gbrw(rgb_t rgb);
pixel_t get_gbwr(rgb_t rgb);
pixel_t get_gwrb(rgb_t rgb);
pixel_t get_gwbr(rgb_t rgb);
pixel_t get_brgw(rgb_t rgb);
pixel_t get_brwg(rgb_t rgb);
pixel_t get_bgrw(rgb_t rgb);
pixel_t get_bgwr(rgb_t rgb);
pixel_t get_bwrg(rgb_t rgb);
pixel_t get_bwgr(rgb_t rgb);
pixel_t get_wrgb(rgb_t rgb);
pixel_t get_wrbg(rgb_t rgb);
pixel_t get_wgrb(rgb_t rgb);
pixel_t get_wgbr(rgb_t rgb);
pixel_t get_wbrg(rgb_t rgb);
pixel_t get_wbgr(rgb_t rgb);


#endif