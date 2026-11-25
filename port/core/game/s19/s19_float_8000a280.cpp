#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_float_8000a280.c"
struct S19Entry { char pad0[12]; float weight; };
struct S19Registry { Ptr32<Ptr32<struct S19Entry>> items; };
struct S19Globals { char pad0[96]; float scale; };
struct S19Scorer { int pad0; float score; char pad8[8]; int entry; };
extern Ptr32<struct S19Registry> lbl_804aa750;
extern Ptr32<struct S19Globals> lbl_804aa6d8;

void s19_score_add_weight_8000a280(Ptr32<struct S19Scorer> p) {
    if (p->entry != -1)
        p->score = (*(Ptr32<Ptr32<struct S19Entry>>)((Ptr32<char>)lbl_804aa750->items + (p->entry << 2)))->weight * lbl_804aa6d8->scale + p->score;
    else
        p->score = p->score + 1.0f;
}

}
