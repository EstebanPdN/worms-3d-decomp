#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ea_801db420.c"
// desc: Appears to start an object once: when not yet started it calls virtual slot 36, marks it started and returns the slot's result, otherwise it returns 0x80004005.
struct S21Object;
struct S21Methods { Ptr32<void (void)> reserved[36]; Ptr32<int (Ptr32<struct S21Object>)> start; };
struct S21Object { Ptr32<struct S21Methods> methods; char pad[172]; int started; };
int w3d_s21_start_once_801db420(Ptr32<struct S21Object> self)
{
    int status;
    if (self->started == 0) {
        status = self->methods->start(self);
        self->started = 1;
    } else
        status = 0x80004005;
    return status;
}

}
