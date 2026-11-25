#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ae_801ef5fc.c"
// desc: Appears to locate an embedded object using an offset from the type table, store one of its fields and return its member address.
struct S21TypeTable { char pad[4]; unsigned short offset; };
struct S21Holder { Ptr32<struct S21TypeTable> types; };
Ptr32<char> w3d_s21_locate_member_801ef5fc(Ptr32<struct S21Holder> self, Ptr32<char> base, Ptr32<int> out)
{
    Ptr32<char> object = *(Ptr32<Ptr32<char>>)(base + self->types->offset);
    *out = *(Ptr32<int>)(object + 24);
    return object + 32;
}

}
