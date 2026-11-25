#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_step_800931ac.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>, float)> S19Step;
extern int w3d_auto_80178c48(Ptr32<void>);
extern void w3d_motion_step_800d3160(Ptr32<void>, float, int);
extern void FUN_800d4584(Ptr32<void>, float, Ptr32<void>);
extern void FUN_800d40f4(Ptr32<void>, float, Ptr32<void>);

void s19_step_all_800931ac(Ptr32<void> self, float t, int arg)
{
    if (w3d_auto_80178c48(w3d::G(FIELD(self, int, 216))) != 0) {
        w3d_motion_step_800d3160(self, t, arg);
    } else {
        ((S19Step)FIELD(self, void **, 72)[8])(self, t);
        FUN_800d4584(self, t, w3d::G(arg));
        FUN_800d40f4(self, t, w3d::G(arg));
    }
}

}
