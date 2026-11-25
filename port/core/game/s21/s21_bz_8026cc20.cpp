#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bz_8026cc20.c"
// desc: Appears to wrap a value modulo a global halfword limit, store it in two fields and call a follow-up helper.
struct S21Object { char pad[40]; unsigned wrapped; char pad1[48]; unsigned current; };
extern unsigned short lbl_803cbcc2[];
extern int fn_8026cc60(Ptr32<struct S21Object>);
int w3d_s21_wrap_value_8026cc20(Ptr32<struct S21Object> self, unsigned value)
{
    value = value % lbl_803cbcc2[0];
    self->wrapped = value;
    self->current = value;
    return fn_8026cc60(self);
}

}
