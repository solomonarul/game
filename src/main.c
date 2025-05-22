#include <stdlib.h>

#include <fbgl/all.h>

void fragment_shader(void* userdata, double x, double y, fbgl_color_rgb_t* pixel)
{
    pixel->r = pixel->r / 2;
    pixel->g = pixel->g / 2;
    pixel->b = (255 * x + pixel->b) / 2;
}

int main(int argc, char* argv[])
{
    const size_t width = 128;
    const size_t height = 128;
    uint8_t data[width * height * sizeof(fbgl_color_rgb_t)];    // Avoid za heap.
    fbgl_buffer_t buffer = (fbgl_buffer_t) {
        .width = width,
        .height = height,
        .data = data
    };
    fbgl_buffer_clear(&buffer, (fbgl_color_rgb_t){
        .r = 255,
        .g = 125,
        .b = 25
    });

    fbgl_pipeline_t pipeline;
    fbgl_pipeline_init(&pipeline);
    pipeline.fragment_shader = fragment_shader;
    fbgl_pipeline_apply(&pipeline, &buffer);

    FILE* output = fopen("out/output.bmp", "wb");
    fbgl_bitmap_save_from_buffer(output, buffer.data, width, height);
    fclose(output);

    return EXIT_SUCCESS;
}