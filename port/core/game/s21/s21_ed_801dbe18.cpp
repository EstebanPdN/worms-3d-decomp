#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ed_801dbe18.c"
// desc: Appears to find the entry of the counted array whose id field matches the third argument, run two helpers on it with the second argument and return the second helper's result, or 0x80004005.
struct S21Entry { char pad[36]; int id; };
struct S21Array { unsigned count; int reserved; Ptr32<Ptr32<struct S21Entry>> items; };
struct S21Object { char pad[36]; struct S21Array array; };
extern void fn_801de13c(Ptr32<struct S21Entry>, int);
extern int fn_801de328(Ptr32<struct S21Entry>, int, Ptr32<void>);
int w3d_s21_dispatch_by_id_801dbe18(Ptr32<struct S21Object> self, int value, int id)
{
    unsigned i = 0;
    if (i < self->array.count) {
        Ptr32<struct S21Array> array = &self->array;
        unsigned offset = 0;
        do {
            Ptr32<struct S21Entry> entry = *(Ptr32<Ptr32<struct S21Entry>>)w3d::G((offset + (unsigned)w3d::H(array->items)));
            if (id == entry->id) {
                fn_801de13c(entry, value);
                return fn_801de328(entry, value, 0);
            }
            i++;
            offset += 4;
        } while (i < self->array.count);
    }
    return 0x80004005;
}

}
