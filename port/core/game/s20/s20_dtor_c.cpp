#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_dtor_c.c"
/* Deleting destructor of a listed object that frees four buffers. */
extern void fn_80210990(Ptr32<char>, int);
extern void fn_801fe1f8(Ptr32<char>);
extern void fn_802134fc(Ptr32<void>);
extern Ptr32<char> lbl_804ab750;
extern char lbl_80413a00[];
extern char lbl_80411ac0[];

void w3d_s20_destroy_listed_801a2668(Ptr32<char> self, int flags) {
    Ptr32<char> current = lbl_804ab750;
    Ptr32<char> previous;
    Ptr32<void> buffer;
    *(Ptr32<Ptr32<char>>)self = lbl_80413a00;
    previous = 0;
    while (current != 0 && current != self) {
        previous = current;
        current = *(Ptr32<Ptr32<char>>)(previous + 32);
    }
    if (previous == 0)
        lbl_804ab750 = *(Ptr32<Ptr32<char>>)(self + 32);
    else
        *(Ptr32<Ptr32<char>>)(previous + 32) = *(Ptr32<Ptr32<char>>)(self + 32);
    buffer = *(Ptr32<Ptr32<void>>)(self + 72);
    *(Ptr32<int>)(self + 32) = 0;
    *(Ptr32<int>)(self + 20) = 0;
    if (buffer != 0)
        fn_802134fc(buffer);
    if (*(Ptr32<Ptr32<void>>)(self + 60) != 0)
        fn_802134fc(*(Ptr32<Ptr32<void>>)(self + 60));
    if (*(Ptr32<Ptr32<void>>)(self + 48) != 0)
        fn_802134fc(*(Ptr32<Ptr32<void>>)(self + 48));
    if (*(Ptr32<Ptr32<void>>)(self + 36) != 0)
        fn_802134fc(*(Ptr32<Ptr32<void>>)(self + 36));
    *(Ptr32<Ptr32<char>>)self = lbl_80411ac0;
    fn_80210990(self + 4, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}

}
