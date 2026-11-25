#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_z_80204348.c"
// desc: Appears to call a virtual write slot on a stream for each entry of an integer array, passing a shared argument, and return zero.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[8]; Ptr32<int (Ptr32<struct S21Stream>, int, int)> write; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
int w3d_s21_write_each_80204348(Ptr32<struct S21Stream> stream, Ptr32<int> items, unsigned count, int context)
{
    unsigned i = 0;
    if (i < count) {
        Ptr32<int> item = items;
        do {
            stream->methods->write(stream, *item, context);
            i++;
            item++;
        } while (i < count);
    }
    return 0;
}

}
