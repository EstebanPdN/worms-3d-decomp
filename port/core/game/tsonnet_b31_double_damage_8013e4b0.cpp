#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b31_double_damage_8013e4b0.c"
/* Looks up the object's lbl_8039f2f0 entry through its context (into a
   36-byte result record), then copies the default-constructed position vector
   and passes the copy, the name lbl_8039fc3c, zero and a global float
   to the forwarding service. The record, the vector and its copy share one
   frame object whose parts the original reaches through two separate base
   registers; the vector is read through a named pointer except for its first
   word. The two names are external original strings (0x8039f2f0 "NameLocator",
   0x8039fc3c "UtilityDoubleDamage") because they sit in different original
   pools. Offsets are observed; field names and meanings are inferred. */
typedef struct { char p0[28]; Ptr32<void> ctx; } Obj;
typedef struct { float x, y, z; } V3;
typedef struct { int record[9]; V3 pos; V3 copy; } Frame;
extern void fn_80343740(Ptr32<V3>);
extern int fn_80181e3c(Ptr32<void>, Ptr32<const char>, Ptr32<void>);
extern Ptr32<void> fn_800e5ca4(Ptr32<V3>, Ptr32<const char>, int, float);
extern float lbl_8039fc50[];
extern const char lbl_8039f2f0[];
extern const char lbl_8039fc3c[];
void tsonnet_b31_double_damage_8013e4b0(Ptr32<Obj> o) {
    float x, y, z;
    Frame f; Ptr32<V3> p = &f.pos; Ptr32<int> rec = f.record;
    fn_80343740(p);
    fn_80181e3c(o->ctx, lbl_8039f2f0, rec);
    x = f.pos.x;
    y = p->y;
    z = p->z;
    f.copy.x = x;
    f.copy.y = y;
    f.copy.z = z;
    fn_800e5ca4(&f.copy, lbl_8039fc3c, 0, lbl_8039fc50[0]);
}

}
