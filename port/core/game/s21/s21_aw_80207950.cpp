#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_aw_80207950.c"
// desc: Appears to look up a table entry by a halfword of the key and return its data pointer when its limit is at least the requested size, else zero.
struct S21Entry { Ptr32<void> data; unsigned limit; };
struct S21Key { char pad[5]; unsigned char slot0; unsigned char slot1; };
struct S21Registry { char pad[36]; Ptr32<Ptr32<struct S21Entry>> entries; };
Ptr32<void> w3d_s21_find_data_80207950(Ptr32<struct S21Registry> self, Ptr32<struct S21Key> key, unsigned size)
{
    Ptr32<struct S21Entry> entry = *(Ptr32<Ptr32<struct S21Entry>>)((Ptr32<char>)self->entries + (*(Ptr32<unsigned short>)((Ptr32<char>)key + 5) << 2));
    if (entry->limit < size)
        return 0;
    return entry->data;
}

}
