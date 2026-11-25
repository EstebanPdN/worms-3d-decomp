#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b36_ratio_800f12f0.c"
/* Returns how far an elapsed count has progressed through a span as a ratio.
   Below the object's start count the result is the first global constant;
   past the span length reported by the helper chain on the context pointer it
   is the second; otherwise it is the elapsed count divided by the span
   length, both converted from signed integers. The result is kept in a local
   because the original returns through one shared epilogue path. Offsets are
   observed; field names and meanings are inferred. */
typedef struct { char p0[32]; Ptr32<void> ctx; char p1[8]; unsigned start; } Obj;
extern Ptr32<void> fn_80342a78(Ptr32<void>);
extern int fn_80178d1c(Ptr32<void>);
extern float lbl_8038c30c[];
extern float lbl_8038c310[];
float tsonnet_b36_ratio_800f12f0(Ptr32<Obj> o, unsigned t) {
    float r;
    if (t < o->start) r = lbl_8038c30c[0];
    else {
        int d = t - o->start;
        int n = fn_80178d1c(fn_80342a78(o->ctx));
        if (d > n) r = lbl_8038c310[0];
        else r = (float)d / (float)n;
    }
    return r;
}

}
