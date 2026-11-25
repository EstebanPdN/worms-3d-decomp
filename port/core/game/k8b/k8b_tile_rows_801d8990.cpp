#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_tile_rows_801d8990.c"
extern void w3d_cx14b_byte_tile_copy_801d7f9c(Ptr32<const unsigned char> source, unsigned int pitch, unsigned int width, unsigned int height, unsigned int x, unsigned int y, Ptr32<unsigned char> out);

int w3d_k8b_tile_rows_801d8990(Ptr32<const unsigned char> source, unsigned int unused0, unsigned int pitch, unsigned int width, unsigned int height, Ptr32<unsigned char> out, int unused1, int unused2, Ptr32<unsigned int> total)
{
    unsigned int w;
    unsigned int h;
    unsigned int rows;
    unsigned int cols;
    unsigned int row;
    unsigned int col;
    w = width >> 1;
    h = height >> 1;
    rows = (h + 7) >> 3;
    *total = 0;
    cols = (w + 7) >> 3;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            w3d_cx14b_byte_tile_copy_801d7f9c(source, pitch, w, h, col << 3, row << 3, out);
            out += 32;
            *total += 32;
        }
    }
    return 0;
}

}
