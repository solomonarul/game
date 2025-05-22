#pragma once
#ifndef FBGL_PIPELINE_H
#define FBGL_PIPELINE_H

#include "shader.h"
#include "buffer.h"

struct fbgl_pipeline
{
    fbgl_color_rgba_t clear_color;
    fbgl_fragment_shader_t fragment_shader;
};
typedef struct fbgl_pipeline fbgl_pipeline_t;

void fbgl_pipeline_init(fbgl_pipeline_t* self);
void fbgl_pipeline_apply(fbgl_pipeline_t* self, fbgl_buffer_t* buffer);

#endif
