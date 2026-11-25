#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bz_8026462c.c"
// desc: Appears to report whether the slot selected by a global index holds zero, treating an out-of-range index as true.
struct S21Slots { char pad[220]; int slots[20]; };
extern unsigned lbl_804abb5c;
int w3d_s21_slot_is_free_8026462c(Ptr32<struct S21Slots> self)
{
    if (lbl_804abb5c > 19)
        return 1;
    return self->slots[lbl_804abb5c] == 0;
}

}
