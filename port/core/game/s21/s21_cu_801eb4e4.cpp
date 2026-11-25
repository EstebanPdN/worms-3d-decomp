#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cu_801eb4e4.c"
// desc: Appears to compare the bytes at a descriptor's halfword offset in two buffers over a length from a helper and report whether they are equal.
struct S21Info { char pad[4]; unsigned short offset; char pad1[2]; int size; };
struct S21Object { Ptr32<struct S21Info> info; };
extern unsigned fn_80200050(int);
extern int fn_802eedc0(Ptr32<const void>, Ptr32<const void>, unsigned);
int w3d_s21_equal_801eb4e4(Ptr32<struct S21Object> self, Ptr32<char> a, Ptr32<char> b)
{
    Ptr32<struct S21Info> info = self->info;
    unsigned short offset = info->offset;
    Ptr32<char> first = a + offset;
    Ptr32<char> second = b + offset;
    unsigned length = fn_80200050(info->size);
    return fn_802eedc0(first, second, length) == 0;
}

}
