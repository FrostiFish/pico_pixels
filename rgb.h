#ifndef RGB_H
#define RGB_H

#include "pico/stdlib.h"

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} rgb_t;

#define RGB(red, green, blue) ((rgb_t){(uint8_t)red, (uint8_t)green, (uint8_t)blue})

#define RED RGB(255,0,0)
#define GREEN RGB(0,255,0)
#define BLUE RGB(0,0,255)
#define CYAN RGB(0,255,255)
#define YELLOW RGB(255,255,0)
#define MAGENTA RGB(255,0,255)
#define BLACK RGB(0,0,0)
#define WHITE RGB(255,255,255)
#define WHITE_6000 RGB(255,255,255)
#define WHITE_3200 RGB(255,241,224)
#define WHITE_2600 RGB(255,197,143)
#define WHITE_1900 RGB(255,147,41)
#define WHITE_7000 RGB(201,226,255)
#define WHITE_20000 RGB(64,156,255)

#endif