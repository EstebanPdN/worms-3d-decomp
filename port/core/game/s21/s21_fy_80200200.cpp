#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fy_80200200.c"
// desc: Appears to look up an entry by name in the table at offset 4: entries are eight bytes, the lookup skips ones without a second field and returns the entry whose second field equals the name.
struct S21Entry { Ptr32<const char> id; Ptr32<const char> name; };
struct S21Table { char pad[4]; Ptr32<struct S21Entry> entries; };
extern int fn_802ef234(Ptr32<const char>, Ptr32<const char>);
Ptr32<struct S21Entry> w3d_s21_find_by_name_80200200(Ptr32<struct S21Table> table, Ptr32<const char> name)
{
    Ptr32<struct S21Entry> entry = table->entries;
    if (entry == 0)
        return 0;
    for (; entry->id != 0; entry++) {
        if (entry->name != 0 && fn_802ef234(name, entry->name) == 0)
            return entry;
    }
    return 0;
}

}
