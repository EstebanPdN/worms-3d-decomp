#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cd_802ba070.c"
// desc: Appears to release the three objects held in an array at offset 224 through a helper and clear their slots.
struct S21Object { char pad[224]; Ptr32<void> slots[3]; };
extern void fn_8025e0c4(Ptr32<void>, int);
void w3d_s21_release_slots_802ba070(Ptr32<struct S21Object> self)
{
    Ptr32<Ptr32<void>> slot = self->slots;
    unsigned i = 0;
    do {
        Ptr32<void> object = *slot;
        i++;
        if (object) {
            fn_8025e0c4(object, 3);
            *slot = 0;
        }
        slot++;
    } while (i <= 2);
}

}
