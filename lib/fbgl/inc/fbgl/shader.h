#pragma once
#ifndef FBGL_SHADER_H
#define FBGL_SHADER_H

#include "buffer.h"

typedef void(*fbgl_fragment_shader_t)(void* userdata, double x, double y, fbgl_color_rgb_t* pixel);

#endif