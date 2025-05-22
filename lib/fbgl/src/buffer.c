#include "buffer.h"

#include <string.h>

void fbgl_buffer_clear(fbgl_buffer_t* self, fbgl_color_rgb_t color)
{
    for(size_t index = 0; index < self->width * self->height; index++)
        memcpy(self->data + index * sizeof(fbgl_color_rgb_t), &color, sizeof(fbgl_color_rgb_t));
}
