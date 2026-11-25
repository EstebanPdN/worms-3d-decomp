#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_br_8021eb48.c"
// desc: Appears to return the word at an index of the counted array inside the object at offset 20, or zero when the index is out of range.
struct S21Array { char pad[24]; unsigned count; char pad1[4]; int items[1]; };
struct S21Holder { char pad[20]; Ptr32<struct S21Array> array; };
int w3d_s21_get_item_8021eb48(Ptr32<struct S21Holder> self, unsigned index)
{
    Ptr32<struct S21Array> array = self->array;
    Ptr32<int> items = array->items;
    if (index < array->count)
        return items[index];
    return 0;
}

}
