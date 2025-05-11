#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "pico_pixels.h"

#define PIN 2
#define NUM_PIXELS 12

int main()
{
    stdio_init_all();

    // todo get free sm
    PIO pio;
    uint sm;
    uint offset;

    pixel_t pixels[NUM_PIXELS];
    strip_t strip;
    strip_init(&strip, pio, sm, offset, PIN, 800000, pixels, NUM_PIXELS, GRBW, true);

    while (true) {
        rgb_t red = RGB(255, 0, 0);
        rgb_t green = RGB(0, 255, 0);
        rgb_t blue = RGB(0, 0, 255);
        rgb_t white = RGB(255, 255, 255);

        strip_set_all(&strip, red);
        strip_update(&strip);
        sleep_ms(1000);
        strip_set_all(&strip, green);
        strip_update(&strip);
        sleep_ms(1000);
        strip_set_all(&strip, blue);
        strip_update(&strip);
        sleep_ms(1000);
        strip_set_all(&strip, white);
        strip_update(&strip);
        sleep_ms(1000);
        strip_set_all(&strip, (rgb_t){0});
        strip_update(&strip);
        sleep_ms(1000);

        for (uint8_t w=0; w<255; w++) {
            rgb_t color = RGB(255, w, w);
            strip_set_all(&strip, color);
            strip_update(&strip);
            sleep_ms(10);
        }

        strip_set_all(&strip, WHITE_1900);
        strip_update(&strip);
        sleep_ms(1000);
        strip_set_all(&strip, WHITE_2600);
        strip_update(&strip);
        sleep_ms(1000);
        strip_set_all(&strip, WHITE_3200);
        strip_update(&strip);
        sleep_ms(1000);
        strip_set_all(&strip, WHITE_6000);
        strip_update(&strip);
        sleep_ms(1000);
        strip_set_all(&strip, WHITE_7000);
        strip_update(&strip);
        sleep_ms(1000);
        strip_set_all(&strip, WHITE_20000);
        strip_update(&strip);
        sleep_ms(1000);
        strip_set_all(&strip, (rgb_t){0});
        strip_update(&strip);
        sleep_ms(1000);

        sleep_us(1000);
    }
}
