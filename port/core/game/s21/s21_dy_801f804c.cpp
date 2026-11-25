#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_dy_801f804c.c"
// desc: Appears to erase one pointer from the vector at offset 20: it locates the element through a helper, shifts the tail down with memmove and shrinks the vector by one entry.
// desc: Appears to erase one pointer from the vector at offset 20: it locates the element through a helper, shifts the tail down with memmove and shrinks the vector by one entry.
struct S21Vector { Ptr32<int> begin; Ptr32<int> end; };
struct S21Object { char pad[20]; struct S21Vector items; };
extern Ptr32<int> fn_80359cec(Ptr32<int>, Ptr32<int>, Ptr32<int>);
extern Ptr32<void> fn_802eeef4(Ptr32<void>, Ptr32<const void>, unsigned);
void w3d_s21_erase_item_801f804c(Ptr32<struct S21Object> self, int key)
{
    Ptr32<struct S21Vector> items = &self->items;
    Ptr32<int> position = fn_80359cec(self->items.begin, items->end, &key);
    Ptr32<int> next = position + 1;
    if (next != items->end) {
        Ptr32<int> end = items->end;
        if (end != next)
            fn_802eeef4(position, next, (Ptr32<char>)end - (Ptr32<char>)next);
    }
    items->end = items->end - 1;
}

}
