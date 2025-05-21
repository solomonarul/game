#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <fbgl/shader.h>
#include <fbgl/buffer.h>
#include <fbgl/bitmap.h>

void fragment_shader(void* userdata, double x, double y, fbgl_color_rgb_t* pixel)
{
    pixel->r = 0;
    pixel->g = 0;
    pixel->b = 255 * x;
}

int main(int argc, char* argv[])
{
    const size_t width = 128;
    const size_t height = 128;
    uint8_t data[width * height * sizeof(fbgl_color_rgb_t)];    // Avoid za heap.
    memset(data, 0, sizeof(data));
    fbgl_buffer_t buffer = (fbgl_buffer_t) {
        .width = width,
        .height = height,
        .data = data
    };

    for(size_t x = 0; x < width; x++)
    {
        for(size_t y = 0; y < height; y++)
        {
            fbgl_color_rgb_t* pixel = (buffer.data + (y * width + x) * sizeof(fbgl_color_rgb_t));
            fragment_shader(NULL, x * 1.0 / width, y * 1.0 / height, pixel);
            // This is called per rasterized pixel. For now the entire screen is rasterized.
        }
    }

    FILE* output = fopen("out/output.bmp", "wb");
    fbgl_bitmap_save_from_buffer(output, buffer.data, width, height);
    fclose(output);

    return EXIT_SUCCESS;
}