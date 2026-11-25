#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ah_801eb0b0.c"
// desc: Appears to return one when the first object's flag byte has bit 4 or 32 set, else the result of a virtual slot called with this.
struct S21Object;
struct S21Methods { Ptr32<void (void)> reserved[6]; Ptr32<int (Ptr32<struct S21Object>)> query; };
struct S21First { char pad[6]; char w3d_kind; unsigned char flags; };
struct S21Object { Ptr32<struct S21First> first; Ptr32<struct S21Methods> methods; };
int w3d_s21_query_flags_801eb0b0(Ptr32<struct S21Object> self)
{
    unsigned flags = self->first->flags;
    if (flags & 4)
        goto done;
    if (flags & 32)
        goto done;
    return self->methods->query(self);
done:
    return 1;
}

}
