#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ez_801eb2a8.c"
// desc: Appears to look up an entry by name in the null-terminated table returned by a helper, comparing the name with each eight-byte entry's leading string, returning the entry or zero.
// desc: Appears to look up an entry by name in the null-terminated table returned by a helper, comparing the name with each eight-byte entry's leading string, returning the entry or zero.
struct S21Entry { Ptr32<const char> name; int value; };
extern Ptr32<struct S21Entry> fn_801eb29c(Ptr32<void>);
extern int fn_802ef234(Ptr32<const char>, Ptr32<const char>);
Ptr32<struct S21Entry> w3d_s21_find_entry_801eb2a8(Ptr32<void> self, Ptr32<const char> name)
{
    Ptr32<struct S21Entry> entry = fn_801eb29c(self);
    if (entry == 0)
        return 0;
    for (; entry->name != 0; entry++) {
        if (fn_802ef234(name, entry->name) == 0)
            return entry;
    }
    return 0;
}

}
