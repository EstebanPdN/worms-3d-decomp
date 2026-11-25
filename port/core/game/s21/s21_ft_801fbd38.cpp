#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ft_801fbd38.c"
// desc: Appears to look up an entry index in the vector at offset 36 and forward three arguments to the entry's virtual slot 14, or return 0x80004005 when not found.
struct S21Entry;
struct S21EntryMethods { Ptr32<void (void)> reserved[14]; Ptr32<int (Ptr32<struct S21Entry>, int, int, int)> apply; };
struct S21Entry { Ptr32<struct S21EntryMethods> methods; };
struct S21Object { char pad[36]; Ptr32<Ptr32<struct S21Entry>> items; };
extern int fn_801f9fbc(Ptr32<void>, int, int);
int w3d_s21_apply_entry_801fbd38(Ptr32<struct S21Object> self, int a, int b, int c, int d, int e)
{
    int index = fn_801f9fbc((Ptr32<char>)self + 36, a, b);
    Ptr32<struct S21Entry> entry;
    if (index < 0)
        return 0x80004005;
    entry = *(Ptr32<Ptr32<struct S21Entry>>)w3d::G(((unsigned)w3d::H(self->items) + (index << 2)));
    return entry->methods->apply(entry, c, d, e);
}

}
