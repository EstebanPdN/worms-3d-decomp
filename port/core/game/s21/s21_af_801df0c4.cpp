#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_af_801df0c4.c"
// desc: Appears to ask a stream object through a virtual slot to process this object's embedded block at offset 24 and return zero.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[37]; Ptr32<void (Ptr32<struct S21Stream>, Ptr32<void>, int)> process; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Block { char pad[24]; char block[4]; };
int w3d_s21_stream_process_801df0c4(Ptr32<struct S21Block> self, Ptr32<struct S21Stream> stream)
{
    stream->methods->process(stream, self->block, 0);
    return 0;
}

}
