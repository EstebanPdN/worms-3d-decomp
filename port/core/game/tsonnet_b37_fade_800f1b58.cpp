#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b37_fade_800f1b58.c"
/* Advances a clamped value by the elapsed count since the previous call.
   The elapsed count (unsigned) is scaled by a global factor and subtracted
   from the value when a flag is set, otherwise added. The value is then
   limited between two global bounds through pointer-returning min/max
   helpers (the bounds live in stack slots whose addresses are taken, as the
   original does), and the result is passed to slot 13 of the two held
   objects. Offsets are observed; field names and meanings are inferred. */
struct Obj;
typedef struct { char pad[52]; Ptr32<void (Ptr32<struct Obj>, int, float)> set; } VT;
typedef struct Obj { Ptr32<VT> vtable; } Obj;
typedef struct {
    char p0[28];
    Ptr32<Obj> first;
    Ptr32<Obj> second;
    float value;
    unsigned flag;
    char p1[4];
    unsigned stamp;
} Fade;
extern float lbl_8038c3f8[];
extern float lbl_8038c3fc[];
extern float lbl_8038c400[];
static inline Ptr32<float> b37_min(Ptr32<float> a, Ptr32<float> b) { return *a < *b ? w3d::R(a) : w3d::R(b); }
static inline Ptr32<float> b37_max(Ptr32<float> a, Ptr32<float> b) { return *a < *b ? w3d::R(b) : w3d::R(a); }
void tsonnet_b37_fade_800f1b58(Ptr32<Fade> f, unsigned now)
{
    unsigned elapsed = now - f->stamp;
    float conv;
    float step;
    float hi;
    float lo;
    Ptr32<float> pv;
    Ptr32<float> ph;
    Ptr32<float> pl;
    conv = (float)elapsed;
    f->stamp = now;
    step = conv * lbl_8038c3f8[0];
    if (f->flag) f->value -= step; else f->value += step;
    lo = lbl_8038c3fc[0];
    hi = lbl_8038c400[0];
    pv = &f->value;
    pl = &lo;
    ph = &hi;
    f->value = *b37_max(b37_min(pv, ph), pl);
    f->first->vtable->set(f->first, 1, f->value);
    f->second->vtable->set(f->second, 1, f->value);
}

}
