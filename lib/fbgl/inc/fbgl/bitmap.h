#pragma once
#ifndef FBGL_BITMAP_H
#define FBGL_BITMAP_H

#include <stdio.h>
#include <stdint.h>

void fbgl_bitmap_save_from_buffer(FILE* file, uint8_t *data, int width, int height);

#endif
