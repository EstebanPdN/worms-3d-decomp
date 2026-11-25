#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_es_801e5fd4.c"
// desc: Appears to report whether a voice should count as busy: flag bit 0x200000 set, a linked query succeeding together with bit 0x800000, or an open stream handle.
struct S21Object { char pad[8]; unsigned flags; char pad1[44]; int handle; };
extern int lbl_804ab85c;
extern int fn_801e65fc(Ptr32<struct S21Object>);
extern int fn_801e4444(int, int);
int w3d_s21_is_busy_801e5fd4(Ptr32<struct S21Object> self)
{
    if (self->flags & 0x200000)
        return 1;
    if (fn_801e65fc(self) && (self->flags & 0x800000))
        return 1;
    if (self->handle != -1 && fn_801e4444(lbl_804ab85c, self->handle) != 0)
        return 1;
    return 0;
}

}
