#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_eb_801dba3c.c"
// desc: Appears to scan the counted array of interface objects for the first whose virtual slot 7 returns one and return the result of its virtual slot 15, or 0x80004005 when none matches.
struct S21Item;
struct S21ItemMethods { Ptr32<void (void)> reserved[7]; Ptr32<int (Ptr32<struct S21Item>)> kind; Ptr32<void (void)> reserved2[7]; Ptr32<int (Ptr32<struct S21Item>)> activate; };
struct S21Item { Ptr32<struct S21ItemMethods> methods; };
struct S21Array { unsigned count; int reserved; Ptr32<Ptr32<struct S21Item>> items; };
struct S21Object { char pad[48]; struct S21Array array; };
int w3d_s21_activate_first_801dba3c(Ptr32<struct S21Object> self)
{
    unsigned i = 0;
    if (i < self->array.count) {
        Ptr32<struct S21Array> array = &self->array;
        unsigned offset = 0;
        do {
            Ptr32<struct S21Item> item = *(Ptr32<Ptr32<struct S21Item>>)w3d::G((offset + (unsigned)w3d::H(array->items)));
            if (item->methods->kind(item) == 1) {
                item = *(Ptr32<Ptr32<struct S21Item>>)w3d::G((offset + (unsigned)w3d::H(array->items)));
                return item->methods->activate(item);
            }
            i++;
            offset += 4;
        } while (i < self->array.count);
    }
    return 0x80004005;
}

}
