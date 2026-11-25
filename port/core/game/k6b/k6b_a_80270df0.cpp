#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_80270df0.c"
extern Ptr32<void> lbl_8041be80[];
struct K6bPair { int first; int second; };
struct K6bWidget {
    Ptr32<Ptr32<void>> vtable;
    char base[24];
    int field_28;
    char gap_32[20];
    char member_52[12];
    struct K6bPair range_64;
    struct K6bPair range_72;
    char gap_80[8];
    int field_88;
    int field_92;
};
extern int w3d_ctor_801628b0(Ptr32<struct K6bWidget> self);
extern void w3d_construct_802109dc(Ptr32<void> member);
static inline void k6b_pair_clear_second(Ptr32<struct K6bPair> pair, int zero)
{
    pair->second = zero;
}
Ptr32<struct K6bWidget> w3d_k6b_widget_ctor_80270df0(Ptr32<struct K6bWidget> self)
{
    int zero = 0;
    volatile char pad[8];
    w3d_ctor_801628b0(self);
    self->field_28 = zero;
    self->vtable = lbl_8041be80;
    w3d_construct_802109dc(self->member_52);
    self->range_64.first = zero;
    k6b_pair_clear_second(&self->range_64, zero);
    k6b_pair_clear_second(&self->range_72, zero);
    self->field_88 = zero;
    self->field_92 = zero;
    return self;
}
// desc: w3d_k6b_widget_ctor_80270df0: Appears to construct an object over base 0x801628b0: clear +28, install vtable 0x8041be80, construct the member at +52 and clear +64, +68, +76, +88, +92.

}
