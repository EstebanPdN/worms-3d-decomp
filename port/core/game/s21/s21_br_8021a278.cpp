#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_br_8021a278.c"
// desc: Appears to report whether a lookup in the object's registry for the key and the object's halfword size plus four finds nothing.
struct S21Object { char pad[10]; unsigned short size; char pad1[4]; Ptr32<void> registry; };
extern Ptr32<void> fn_80207950(Ptr32<void>, Ptr32<void>, unsigned);
int w3d_s21_missing_8021a278(Ptr32<struct S21Object> self, Ptr32<void> key)
{
    return fn_80207950(self->registry, key, self->size + 4) == 0;
}

}
