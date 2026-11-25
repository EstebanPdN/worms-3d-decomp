/* Bitmap row/column access and indexed handler dispatch. */
typedef struct S20Bitmap { int width; int height; unsigned char *data; int row_stride; int column_stride; } S20Bitmap;
typedef int (*S20Dispatch)(char *, char *);

void w3d_s20_read_row_801d6888(unsigned char *out, S20Bitmap *bitmap, int row) {
    unsigned char *base;
    int i;
    if (row < 0)
        return;
    if (row >= bitmap->height)
        return;
    base = bitmap->data + row * bitmap->row_stride;
    for (i = 0; i < bitmap->width; i++)
        out[i] = base[i * bitmap->column_stride];
}

void w3d_s20_read_column_801d68e0(unsigned char *out, S20Bitmap *bitmap, int column) {
    unsigned char *base;
    int count;
    int step;
    if (column < 0)
        return;
    if (column >= bitmap->width)
        return;
    base = bitmap->data + column * bitmap->column_stride;
    count = bitmap->height;
    step = bitmap->row_stride;
    while (count-- > 0) {
        *out++ = *base;
        base += step;
    }
}

int w3d_s20_write_pixel_801d6940(S20Bitmap *bitmap, int x, int y, int value) {
    if (x < 0 || x >= bitmap->width || y < 0 || y >= bitmap->height)
        return 0;
    {
        unsigned char *row = bitmap->data + y * bitmap->row_stride;
        row[x * bitmap->column_stride] = value;
    }
    return value;
}

int w3d_s20_dispatch_indexed_801a4a90(char *self, char *item) {
    char *record = *(char **)(item + 20);
    unsigned int index = *(unsigned int *)(item + 24);
    char *items = record + 32;
    char *target;
    if (index < *(unsigned int *)(record + 24)) {
        target = *(char **)(items + index * 4);
        return ((S20Dispatch)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    }
    return 0;
}

int w3d_s20_dispatch_indexed_801a4aec(char *self, char *item) {
    char *owner = *(char **)(self + 20);
    unsigned int index = *(unsigned int *)(item + 20);
    char *record = *(char **)(owner + 44);
    char *items = record + 32;
    char *target;
    if (index < *(unsigned int *)(record + 24)) {
        target = *(char **)(items + index * 4);
        return ((S20Dispatch)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    }
    return 0;
}
