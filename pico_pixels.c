#include "pico_pixels.h"
#include "ws2812.pio.h"

void strip_init(strip_t * strip, PIO pio, uint sm, uint offset, uint pin, float frequency, pixel_t * pixels, size_t length, colorOrder color_order, bool ring) {
    bool success = pio_claim_free_sm_and_add_program_for_gpio_range(&ws2812_program, &pio, &sm, &offset, pin, 1, true);
    hard_assert(success);

    ws2812_program_init(pio, sm, offset, pin, frequency, color_order > BGR);

    strip->pio = pio;
    strip->sm = sm;
    strip->offset = offset;
    strip->pin = pin;
    strip->frequency = frequency;
    strip->pixels = pixels;
    strip->length = length;
    strip->color_order = color_order;
    strip->ring = ring;

    // set function poiners
    switch (color_order) {
        case GRB:   strip->get_pixel_data = get_grb; break;
        case RGB:   strip->get_pixel_data = get_rgb; break;
        case RBG:   strip->get_pixel_data = get_rbg; break;
        case GBR:   strip->get_pixel_data = get_gbr; break;
        case BRG:   strip->get_pixel_data = get_brg; break;
        case BGR:   strip->get_pixel_data = get_bgr; break;
        case RGBW:  strip->get_pixel_data = get_rgbw; break;
        case RGWB:  strip->get_pixel_data = get_rgwb; break;
        case RBGW:  strip->get_pixel_data = get_rbgw; break;
        case RBWG:  strip->get_pixel_data = get_rbwg; break;
        case RWGB:  strip->get_pixel_data = get_rwgb; break;
        case RWBG:  strip->get_pixel_data = get_rwbg; break;
        case GRBW:  strip->get_pixel_data = get_grbw; break;
        case GRWB:  strip->get_pixel_data = get_grwb; break;
        case GBRW:  strip->get_pixel_data = get_gbrw; break;
        case GBWR:  strip->get_pixel_data = get_gbwr; break;
        case GWRB:  strip->get_pixel_data = get_gwrb; break;
        case GWBR:  strip->get_pixel_data = get_gwbr; break;
        case BRGW:  strip->get_pixel_data = get_brgw; break;
        case BRWG:  strip->get_pixel_data = get_brwg; break;
        case BGRW:  strip->get_pixel_data = get_bgrw; break;
        case BGWR:  strip->get_pixel_data = get_bgwr; break;
        case BWRG:  strip->get_pixel_data = get_bwrg; break;
        case BWGR:  strip->get_pixel_data = get_bwgr; break;
        case WRGB:  strip->get_pixel_data = get_wrgb; break;
        case WRBG:  strip->get_pixel_data = get_wrbg; break;
        case WGRB:  strip->get_pixel_data = get_wgrb; break;
        case WGBR:  strip->get_pixel_data = get_wgbr; break;
        case WBRG:  strip->get_pixel_data = get_wbrg; break;
        case WBGR:  strip->get_pixel_data = get_wbgr; break;
        default:    strip->get_pixel_data = get_grb; break; // fallback default
    }
}

void strip_test_color_order(strip_t * strip) {
    for (uint i=0; i<strip->length; i++) pio_sm_put_blocking(strip->pio, strip->sm, (uint32_t)255<<24);
    sleep_ms(1000);
    for (uint i=0; i<strip->length; i++) pio_sm_put_blocking(strip->pio, strip->sm, (uint32_t)255<<16);
    sleep_ms(1000);
    for (uint i=0; i<strip->length; i++) pio_sm_put_blocking(strip->pio, strip->sm, (uint32_t)255<<8);
    sleep_ms(1000);
    for (uint i=0; i<strip->length; i++) pio_sm_put_blocking(strip->pio, strip->sm, (uint32_t)255);
    sleep_ms(1000);
    for (uint i=0; i<strip->length; i++) pio_sm_put_blocking(strip->pio, strip->sm, (uint32_t)0);
    sleep_ms(1000);
}

void strip_set_pixel(strip_t * strip, uint index, rgb_t rgb) {
    strip->pixels[index] = strip->get_pixel_data(rgb);
}

void strip_set_all(strip_t * strip, rgb_t rgb) {
    for (uint i=0; i<strip->length; i++) {
        strip_set_pixel(strip, i, rgb);
    }
}

void strip_update(strip_t * strip) {
    for (uint i=0; i<strip->length; i++) pio_sm_put_blocking(strip->pio, strip->sm, strip->pixels[i].data);
}
