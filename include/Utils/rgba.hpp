#pragma once
#include <stdint.h>

typedef struct RGBA{
    union color
    {
        struct color4i{
            uint8_t r, g, b, a;
        } components;
        int full;
    }rgba;
} RGBA;