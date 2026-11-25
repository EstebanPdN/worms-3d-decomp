#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_eu_801e6fcc.c"
// desc: Appears to call virtual slot 8 of a stream for each word of an array with a shared context, stopping at the first negative status and returning zero otherwise.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[8]; Ptr32<int (Ptr32<struct S21Stream>, int, int)> write; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
int w3d_s21_write_words_801e6fcc(int unused, Ptr32<struct S21Stream> stream, Ptr32<int> items, int context, unsigned count)
{
    unsigned i = 0;
    if (i < count) {
        Ptr32<int> item = items;
        do {
            int status = stream->methods->write(stream, *item, context);
            item++;
            if (status < 0)
                return status;
            i++;
        } while (i < count);
    }
    return 0;
}

}
