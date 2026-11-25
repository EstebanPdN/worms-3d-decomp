#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_float_80016978.c"
struct S19Item { char pad0[4]; float weight; char pad8[4]; int owner; };
struct S19List { Ptr32<Ptr32<struct S19Item>> begin; Ptr32<Ptr32<struct S19Item>> end; };
extern Ptr32<struct S19List> lbl_804aa700;
extern int lbl_804aa6c0;
float s19_owner_weight_inverse_80016978(void) {
    float sum = 0.0f;
    Ptr32<struct S19List> l = lbl_804aa700;
    Ptr32<Ptr32<struct S19Item>> b = l->begin;
    int n = l->end - b;
    int i;
    for (i = 0; i < n; i++) {
        Ptr32<struct S19Item> e = b[i];
        if (lbl_804aa6c0 == e->owner)
            sum += e->weight;
    }
    return 1.0f / (sum * 5.0f + 1.0f);
}

}
