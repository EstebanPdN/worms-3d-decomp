#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fy_801ff8b0.c"
// desc: Appears to call virtual slot 21 of the stream object a given number of times with a shared context, stopping at the first negative status and returning zero otherwise.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[21]; Ptr32<int (Ptr32<struct S21Stream>, int, int, int)> step; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
int w3d_s21_repeat_step_801ff8b0(int unused, Ptr32<struct S21Stream> stream, int unused2, int context, unsigned count)
{
    unsigned i = 0;
    if (i < count) {
        do {
            int status = stream->methods->step(stream, 0, context, 0);
            if (status < 0)
                return status;
            i++;
        } while (i < count);
    }
    return 0;
}

}
