#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_801d8288.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

void fn_801d7914(Ptr32<void> source, int format, unsigned width, unsigned height, unsigned x, unsigned y, Ptr32<char> tile);
void fn_801d79f0(Ptr32<void> source, int format, unsigned width, unsigned height, unsigned x, unsigned y, Ptr32<char> tile);
void fn_801d814c(Ptr32<void> source, int format, unsigned width, unsigned height, unsigned x, unsigned y, Ptr32<char> tile);
void fn_801d8034(Ptr32<void> source, int format, unsigned width, unsigned height, unsigned x, unsigned y, Ptr32<char> tile);
void fn_801d7c94(Ptr32<void> source, int format, unsigned width, unsigned height, unsigned x, unsigned y, Ptr32<char> tile);
void fn_801d7bb4(Ptr32<void> source, int format, unsigned width, unsigned height, unsigned x, unsigned y, Ptr32<char> tile);
void fn_801d7ad0(Ptr32<void> source, int format, unsigned width, unsigned height, unsigned x, unsigned y, Ptr32<char> tile);
void fn_801d7e20(Ptr32<void> source, int format, unsigned width, unsigned height, unsigned x, unsigned y, Ptr32<char> tile);

int w3d_tiles_801d8288(Ptr32<void> source, int unused1, Ptr32<void> format, unsigned width, unsigned height, Ptr32<char> tile,
                       int unused6, int unused7, Ptr32<int> size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d7914(source, w3d::H(format), width, height, column * 4, row * 4, tile);
            tile += 64;
            *size += 64;
        }
    return 0;
}

int w3d_tiles_801d834c(Ptr32<void> source, int unused1, Ptr32<void> format, unsigned width, unsigned height, Ptr32<char> tile,
                       int unused6, int unused7, Ptr32<int> size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d79f0(source, w3d::H(format), width, height, column * 4, row * 4, tile);
            tile += 64;
            *size += 64;
        }
    return 0;
}

int w3d_tiles_801d8410(Ptr32<void> source, int unused1, Ptr32<void> format, unsigned width, unsigned height, Ptr32<char> tile,
                       int unused6, int unused7, Ptr32<int> size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d814c(source, w3d::H(format), width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}

int w3d_tiles_801d84d4(Ptr32<void> source, int unused1, Ptr32<void> format, unsigned width, unsigned height, Ptr32<char> tile,
                       int unused6, int unused7, Ptr32<int> size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d8034(source, w3d::H(format), width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}

int w3d_tiles_801d8598(Ptr32<void> source, int unused1, Ptr32<void> format, unsigned width, unsigned height, Ptr32<char> tile,
                       int unused6, int unused7, Ptr32<int> size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d7c94(source, w3d::H(format), width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}

int w3d_tiles_801d865c(Ptr32<void> source, int unused1, Ptr32<void> format, unsigned width, unsigned height, Ptr32<char> tile,
                       int unused6, int unused7, Ptr32<int> size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d7bb4(source, w3d::H(format), width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}

int w3d_tiles_801d8720(Ptr32<void> source, int unused1, Ptr32<void> format, unsigned width, unsigned height, Ptr32<char> tile,
                       int unused6, int unused7, Ptr32<int> size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d7ad0(source, w3d::H(format), width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}

int w3d_tiles_801d87e4(Ptr32<void> source, int unused1, Ptr32<void> format, unsigned width, unsigned height, Ptr32<char> tile,
                       int unused6, int unused7, Ptr32<int> size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d7e20(source, w3d::H(format), width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}

}
