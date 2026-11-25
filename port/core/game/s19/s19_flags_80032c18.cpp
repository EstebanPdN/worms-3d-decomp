#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_flags_80032c18.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern Ptr32<void> w3d_empty_80342a74(Ptr32<void>);
extern float w3d_auto_80178df0(Ptr32<void>);
void s19_set_priority_flags_80032c18(Ptr32<void> self)
{
    float v = w3d_auto_80178df0(w3d_empty_80342a74(FIELD(self, void *, 752)));
    unsigned a, b;
    if (v > 0.0f) {
        a = FIELD(self, unsigned, 728);
        b = FIELD(self, unsigned, 596);
        a |= 0x800000;
    } else {
        a = FIELD(self, unsigned, 728);
        b = FIELD(self, unsigned, 596);
        a &= ~0x800000u;
    }
    b |= 0x800000;
    FIELD(self, unsigned, 728) = a;
    FIELD(self, unsigned, 596) = b;
}

}
