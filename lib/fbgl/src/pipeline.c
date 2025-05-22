#include "pipeline.h"

void fbgl_pipeline_init(fbgl_pipeline_t* self)
{
    self->clear_color = (fbgl_color_rgba_t){0};
    self->fragment_shader = NULL;
}

void fbgl_pipeline_apply(fbgl_pipeline_t* self, fbgl_buffer_t* buffer)
{
    for(size_t x = 0; x < buffer->width; x++)
    {
        for(size_t y = 0; y < buffer->height; y++)
        {
            fbgl_color_rgb_t* pixel = (buffer->data + (y * buffer->width + x) * sizeof(fbgl_color_rgb_t));
            if(self->fragment_shader != NULL)
                self->fragment_shader(NULL, x * 1.0 / buffer->width, y * 1.0 / buffer->height, pixel);
            // This is called per rasterized pixel. For now the entire screen is rasterized.
        }
    }
}
