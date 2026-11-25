#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ay_802017d0.c"
// desc: Appears to replace a shared string pointer with an entry of a string table chosen by a helper, adjusting reference counts and releasing the old header at zero.
#define S21_ENTRY (*(Ptr32<char> *)w3d::AG((char *)table + (index << 2)))
struct S21Owner { char pad[140]; Ptr32<Ptr32<char>> table; };
extern int fn_802024f4(Ptr32<struct S21Owner>);
extern void fn_8020bb2c(Ptr32<void>);
int w3d_s21_select_string_802017d0(Ptr32<struct S21Owner> self, Ptr32<Ptr32<char>> slot)
{
    int index = fn_802024f4(self);
    Ptr32<Ptr32<char>> table = self->table;
    Ptr32<unsigned short> count = (Ptr32<unsigned short>)(S21_ENTRY - 6);
    ++*count;
    {
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(*slot - 6);
        unsigned short remaining = --*header;
        if (remaining == 0)
            fn_8020bb2c(header);
    }
    *slot = S21_ENTRY;
    return 0;
}

}
