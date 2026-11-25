/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

void fn_801d7914(void *source, int format, unsigned width, unsigned height, unsigned x, unsigned y, char *tile);
void fn_801d79f0(void *source, int format, unsigned width, unsigned height, unsigned x, unsigned y, char *tile);
void fn_801d814c(void *source, int format, unsigned width, unsigned height, unsigned x, unsigned y, char *tile);
void fn_801d8034(void *source, int format, unsigned width, unsigned height, unsigned x, unsigned y, char *tile);
void fn_801d7c94(void *source, int format, unsigned width, unsigned height, unsigned x, unsigned y, char *tile);
void fn_801d7bb4(void *source, int format, unsigned width, unsigned height, unsigned x, unsigned y, char *tile);
void fn_801d7ad0(void *source, int format, unsigned width, unsigned height, unsigned x, unsigned y, char *tile);
void fn_801d7e20(void *source, int format, unsigned width, unsigned height, unsigned x, unsigned y, char *tile);

int w3d_tiles_801d8288(void *source, int unused1, void *format, unsigned width, unsigned height, char *tile,
                       int unused6, int unused7, int *size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d7914(source, format, width, height, column * 4, row * 4, tile);
            tile += 64;
            *size += 64;
        }
    return 0;
}

int w3d_tiles_801d834c(void *source, int unused1, void *format, unsigned width, unsigned height, char *tile,
                       int unused6, int unused7, int *size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d79f0(source, format, width, height, column * 4, row * 4, tile);
            tile += 64;
            *size += 64;
        }
    return 0;
}

int w3d_tiles_801d8410(void *source, int unused1, void *format, unsigned width, unsigned height, char *tile,
                       int unused6, int unused7, int *size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d814c(source, format, width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}

int w3d_tiles_801d84d4(void *source, int unused1, void *format, unsigned width, unsigned height, char *tile,
                       int unused6, int unused7, int *size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d8034(source, format, width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}

int w3d_tiles_801d8598(void *source, int unused1, void *format, unsigned width, unsigned height, char *tile,
                       int unused6, int unused7, int *size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d7c94(source, format, width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}

int w3d_tiles_801d865c(void *source, int unused1, void *format, unsigned width, unsigned height, char *tile,
                       int unused6, int unused7, int *size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d7bb4(source, format, width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}

int w3d_tiles_801d8720(void *source, int unused1, void *format, unsigned width, unsigned height, char *tile,
                       int unused6, int unused7, int *size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d7ad0(source, format, width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}

int w3d_tiles_801d87e4(void *source, int unused1, void *format, unsigned width, unsigned height, char *tile,
                       int unused6, int unused7, int *size)
{
    unsigned rows, columns, row, column;
    rows = (height + 3) >> 2;
    *size = 0;
    columns = (width + 3) >> 2;
    for (row = 0; row < rows; row++)
        for (column = 0; column < columns; column++) {
            fn_801d7e20(source, format, width, height, column * 4, row * 4, tile);
            tile += 32;
            *size += 32;
        }
    return 0;
}
