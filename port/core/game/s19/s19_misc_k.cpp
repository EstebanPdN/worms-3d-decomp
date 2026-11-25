#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_misc_k.c"
struct S19Entry { char pad0[12]; float weight; };
struct S19Registry { Ptr32<Ptr32<struct S19Entry>> items; };
struct S19Globals { char pad0[96]; float scale; char pad100[328]; float damp; };
struct S19Unit { char pad0[4]; float pos; char pad8[8]; int entry; char pad20[80]; float rate; };
extern Ptr32<struct S19Registry> lbl_804aa750;
extern Ptr32<struct S19Globals> lbl_804aa6d8;
extern void w3d_auto_8000b2f8(Ptr32<struct S19Unit>, int);
extern int w3d_cached_name_lookup_80341710(Ptr32<struct S19Unit>, int);

void s19_unit_step_8000d568(Ptr32<struct S19Unit> p) {
    w3d_auto_8000b2f8(p, 0);
    w3d_cached_name_lookup_80341710(p, 1);
    p->pos = (*(Ptr32<Ptr32<struct S19Entry>>)((Ptr32<char>)lbl_804aa750->items + (p->entry << 2)))->weight * lbl_804aa6d8->scale + p->pos;
    p->pos = p->pos * lbl_804aa6d8->damp * p->rate;
}

}
