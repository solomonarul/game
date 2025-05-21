#pragma once
#ifndef FBGL_BUFFER_H
#define FBGL_BUFFER_H

#include <stdint.h>

struct fbgl_buffer {
    size_t width;
    size_t height;
    void* data;
};
typedef struct fbgl_buffer fbgl_buffer_t;

struct fbgl_color_rgb {
    uint8_t b;
    uint8_t g;
    uint8_t r;
};
typedef struct fbgl_color_rgb fbgl_color_rgb_t;

#endif
