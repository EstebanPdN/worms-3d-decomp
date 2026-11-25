#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_float_800179ac.c"
struct S19Entry { char pad0[12]; float weight; };
struct S19Registry { Ptr32<Ptr32<struct S19Entry>> items; };
struct S19Mover { char pad0[4]; float pos; char pad8[36]; int entry; };
extern Ptr32<struct S19Registry> lbl_804aa750;
extern void FUN_80017380(Ptr32<struct S19Mover>);

void s19_advance_by_weight_800179ac(Ptr32<struct S19Mover> p) {
    p->pos = (*(Ptr32<Ptr32<struct S19Entry>>)((Ptr32<char>)lbl_804aa750->items + (p->entry << 2)))->weight * 10.0f + p->pos;
    FUN_80017380(p);
}

}
