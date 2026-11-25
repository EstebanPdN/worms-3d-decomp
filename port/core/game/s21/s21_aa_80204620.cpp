#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_aa_80204620.c"
// desc: Appears to call a virtual write slot on a stream for each sixteen-byte entry, stopping at the first negative status and returning zero otherwise.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[34]; Ptr32<int (Ptr32<struct S21Stream>, Ptr32<void>, int, int)> write_block; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
int w3d_s21_write_blocks_80204620(Ptr32<struct S21Stream> stream, Ptr32<char> blocks, unsigned count, int context)
{
    unsigned i = 0;
    if (i < count) {
        do {
            int status = stream->methods->write_block(stream, blocks, context, 0);
            blocks += 16;
            if (status < 0)
                return status;
            i++;
        } while (i < count);
    }
    return 0;
}

}
