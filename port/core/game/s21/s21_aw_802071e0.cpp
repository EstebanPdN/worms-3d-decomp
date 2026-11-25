#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_aw_802071e0.c"
// desc: Appears to return the word at an index of the array pointed to at offset 28.
struct S21Table { char pad[28]; Ptr32<int> items; };
int w3d_s21_table_item_802071e0(Ptr32<struct S21Table> self, int index)
{
    return self->items[index];
}

}
