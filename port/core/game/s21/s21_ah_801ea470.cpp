#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ah_801ea470.c"
// desc: Appears to fetch an object through two virtual slots, pass it to a helper together with this and return it.
struct S21Object;
struct S21Methods { Ptr32<void (void)> reserved[5]; Ptr32<Ptr32<struct S21Object> (Ptr32<struct S21Object>)> first; char pad[64]; Ptr32<Ptr32<struct S21Object> (Ptr32<struct S21Object>)> second; };
struct S21Object { Ptr32<struct S21Methods> methods; };
extern void fn_801ea4c8(Ptr32<struct S21Object>, Ptr32<struct S21Object>);
Ptr32<struct S21Object> w3d_s21_fetch_801ea470(Ptr32<struct S21Object> self)
{
    Ptr32<struct S21Object> inner = self->methods->first(self);
    Ptr32<struct S21Object> object = inner->methods->second(inner);
    fn_801ea4c8(object, self);
    return object;
}

}
