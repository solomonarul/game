#include "bitmap.h"

void fwrite_u16_le(FILE *f, uint16_t val)
{
    const uint8_t b[2] = { val & 0xFF, val >> 8 };
    fwrite(b, 1, 2, f);
}

void fwrite_u32_le(FILE *f, uint32_t val)
{
    const uint8_t b[4] = { val & 0xFF, val >> 8, val >> 16, val >> 24 };
    fwrite(b, 1, 4, f);
}

void fbgl_bitmap_save_from_buffer(FILE* file, uint8_t *data, int width, int height)
{
    int row_padded = (width * 3 + 3) & (~3);
    int data_size = row_padded * height;

    // BITMAPFILEHEADER (14 bytes)
    fwrite_u16_le(file, 0x4D42);                         // bfType = 'BM'
    fwrite_u32_le(file, 14 + 12 + data_size);            // bfSize
    fwrite_u16_le(file, 0);                              // bfReserved1
    fwrite_u16_le(file, 0);                              // bfReserved2
    fwrite_u32_le(file, 14 + 12);                        // bfOffBits

    // BITMAPCOREHEADER (12 bytes)
    fwrite_u32_le(file, 12);                             // bcSize
    fwrite_u16_le(file, width);                          // bcWidth
    fwrite_u16_le(file, height);                         // bcHeight
    fwrite_u16_le(file, 1);                              // bcPlanes
    fwrite_u16_le(file, 24);                             // bcBitCount

    const uint8_t pad[3] = {0};
    for (int y = 0; y < height; y++)
    {
        fwrite(data + (height - 1 - y) * width * 3, 3, width, file);
        fwrite(pad, 1, row_padded - width * 3, file);
    }
}
