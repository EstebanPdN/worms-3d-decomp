#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_k.c"
/* Bitmap row/column access and indexed handler dispatch. */
typedef struct S20Bitmap { int width; int height; Ptr32<unsigned char> data; int row_stride; int column_stride; } S20Bitmap;
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20Dispatch;

void w3d_s20_read_row_801d6888(Ptr32<unsigned char> out, Ptr32<S20Bitmap> bitmap, int row) {
    Ptr32<unsigned char> base;
    int i;
    if (row < 0)
        return;
    if (row >= bitmap->height)
        return;
    base = bitmap->data + row * bitmap->row_stride;
    for (i = 0; i < bitmap->width; i++)
        out[i] = base[i * bitmap->column_stride];
}

void w3d_s20_read_column_801d68e0(Ptr32<unsigned char> out, Ptr32<S20Bitmap> bitmap, int column) {
    Ptr32<unsigned char> base;
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

int w3d_s20_write_pixel_801d6940(Ptr32<S20Bitmap> bitmap, int x, int y, int value) {
    if (x < 0 || x >= bitmap->width || y < 0 || y >= bitmap->height)
        return 0;
    {
        Ptr32<unsigned char> row = bitmap->data + y * bitmap->row_stride;
        row[x * bitmap->column_stride] = value;
    }
    return value;
}

int w3d_s20_dispatch_indexed_801a4a90(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 20);
    unsigned int index = *(Ptr32<unsigned int>)(item + 24);
    Ptr32<char> items = record + 32;
    Ptr32<char> target;
    if (index < *(Ptr32<unsigned int>)(record + 24)) {
        target = *(Ptr32<Ptr32<char>>)(items + index * 4);
        return ((S20Dispatch)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    }
    return 0;
}

int w3d_s20_dispatch_indexed_801a4aec(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> owner = *(Ptr32<Ptr32<char>>)(self + 20);
    unsigned int index = *(Ptr32<unsigned int>)(item + 20);
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(owner + 44);
    Ptr32<char> items = record + 32;
    Ptr32<char> target;
    if (index < *(Ptr32<unsigned int>)(record + 24)) {
        target = *(Ptr32<Ptr32<char>>)(items + index * 4);
        return ((S20Dispatch)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    }
    return 0;
}

}
