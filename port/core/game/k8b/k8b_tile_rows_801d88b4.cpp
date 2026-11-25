#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_tile_rows_801d88b4.c"
extern int fn_801d7f04(Ptr32<const unsigned char> source, unsigned int pitch, unsigned int width, unsigned int height, unsigned int x, unsigned int y, Ptr32<unsigned char> out);

int w3d_k8b_tile_rows_801d88b4(Ptr32<const unsigned char> source, unsigned int unused0, unsigned int pitch, unsigned int width, unsigned int height, Ptr32<unsigned char> out, int unused1, int unused2, Ptr32<unsigned int> total)
{
    unsigned int rows;
    unsigned int cols;
    unsigned int row;
    unsigned int col;
    rows = (height + 3) >> 2;
    *total = 0;
    cols = (width + 7) >> 3;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            fn_801d7f04(source, pitch, width, height, col << 3, row << 2, out);
            out += 32;
            *total += 32;
        }
    }
    return 0;
}

}
