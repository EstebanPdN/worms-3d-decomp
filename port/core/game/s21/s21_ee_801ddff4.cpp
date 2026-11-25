#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ee_801ddff4.c"
// desc: Appears to report whether any object in the counted array returns a name from virtual slot 10 that equals the given text.
struct S21Named;
struct S21NamedMethods { Ptr32<void (void)> reserved[10]; Ptr32<Ptr32<const char> (Ptr32<struct S21Named>)> name; };
struct S21Named { Ptr32<struct S21NamedMethods> methods; };
struct S21Array { unsigned count; int reserved; Ptr32<Ptr32<struct S21Named>> items; };
struct S21Object { char pad[20]; struct S21Array array; };
extern int fn_802ef234(Ptr32<const char>, Ptr32<const char>);
int w3d_s21_has_name_801ddff4(Ptr32<struct S21Object> self, Ptr32<const char> name)
{
    unsigned i = 0;
    if (i < self->array.count) {
        Ptr32<struct S21Array> array = &self->array;
        unsigned offset = 0;
        do {
            Ptr32<struct S21Named> item = *(Ptr32<Ptr32<struct S21Named>>)w3d::G((offset + (unsigned)w3d::H(array->items)));
            if (fn_802ef234(item->methods->name(item), name) == 0)
                return 1;
            i++;
            offset += 4;
        } while (i < self->array.count);
    }
    return 0;
}

}
