#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bu_8021a32c.c"
// desc: Appears to look up an entry in the object's registry and return the word at the object's halfword offset within it, or zero when missing.
struct S21Object { char pad[10]; unsigned short size; char pad1[4]; Ptr32<void> registry; };
extern Ptr32<void> fn_80207950(Ptr32<void>, Ptr32<void>, unsigned);
int w3d_s21_read_entry_8021a32c(Ptr32<struct S21Object> self, Ptr32<void> key)
{
    Ptr32<void> entry = fn_80207950(self->registry, key, self->size + 4);
    if (entry)
        return *(Ptr32<int>)((Ptr32<char>)entry + self->size);
    return 0;
}

}
