#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b30_ease_800d47f0.c"
/* Advances a countdown-like value by subtracting a step. When it falls below
   the limit record's lower bound it is either set to that bound (when the flag
   is set) or the companion value is raised by rate times the shortfall, capped
   by the record's upper bound, and the value is set to the bound. Offsets are
   observed; field names and meanings are inferred. The two-float temporary is
   reached through separate pointers and sits in a 16-byte local because the
   original reserves that frame. */
typedef struct { char p0[52]; float lo; float hi; char p1[24]; float rate; } Limits;
typedef struct { char p0[136]; Ptr32<void> ctx; char p1[40]; float cur; float aux; } Obj;
typedef struct { float v[4]; } Tmp;
extern Ptr32<void> fn_80341584(Ptr32<void>);
extern Ptr32<Limits> fn_801797b4(Ptr32<void>);
static inline Ptr32<const float> pick(Ptr32<const float> a, Ptr32<const float> b) { return *b < *a ? w3d::R(b) : w3d::R(a); }
void tsonnet_b30_ease_800d47f0(Ptr32<Obj> o, float dt, int snap) {
    Ptr32<Limits> l = fn_801797b4(fn_80341584(o->ctx));
    o->cur = o->cur - dt;
    if (o->cur < l->lo) {
        if (snap) {
            o->cur = l->lo;
        } else {
            Tmp t; Ptr32<float> a = &t.v[0]; Ptr32<float> b = &t.v[1];
            *a = l->rate * (l->lo - o->cur) + o->aux; *b = l->hi;
            o->aux = *pick(a, b);
            o->cur = l->lo;
        }
    }
}

}
