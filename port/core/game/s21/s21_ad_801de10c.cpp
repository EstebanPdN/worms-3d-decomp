#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ad_801de10c.c"
// desc: Appears to return the word at an index of an embedded counted array, or zero when the index is out of range.
struct S21Vector { unsigned count; int reserved; Ptr32<int> items; };
struct S21Object { char pad[20]; struct S21Vector vector; };
static inline int s21_vector_get(Ptr32<struct S21Vector> v, unsigned index)
{
    if (index >= v->count)
        return 0;
    return v->items[index];
}
int w3d_s21_get_item_801de10c(Ptr32<struct S21Object> self, unsigned index)
{
    return s21_vector_get(&self->vector, index);
}

}
