#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b28_scene_800e9e04.c"
/* When the scene's name string differs from a fixed text, registers the name
   with the owner's target, notifies the owner's sink and sets the target's
   uniform vector to the scene's scale. Offsets are observed; field names and
   meanings are inferred. The callee at 0x8015adf4 is declared int because
   the original schedules the call as one with a result. */
typedef struct { Ptr32<Ptr32<void>> vtable; } Iface;
typedef struct { char p0[308]; float scale; char p1[32]; Ptr32<char> name; char p2[88]; int mode; } Scene;
typedef struct { char p0[28]; Ptr32<void> ctx; Ptr32<Iface> sink; char p1[172]; Ptr32<Iface> target; } Owner;
typedef struct { float x, y, z; } Vec3;
static inline void fill(Ptr32<Vec3> v, float f) { v->x = f; v->y = f; v->z = f; }
extern int strcmp(Ptr32<const char>, Ptr32<const char>);
extern Ptr32<void> fn_80341584(Ptr32<void>);
extern Ptr32<Scene> fn_801797b4(Ptr32<void>);
extern int fn_8015adf4(Ptr32<Ptr32<char>>, Ptr32<Ptr32<Iface>>, int);
extern char lbl_8038b1f8[];
void tsonnet_b28_scene_800e9e04(Ptr32<Owner> o) {
    Ptr32<Scene> s = fn_801797b4(fn_80341584(o->ctx));
    Ptr32<Ptr32<char>> np = &s->name;
    int differs = strcmp(*np, lbl_8038b1f8) != 0;
    if (differs) {
        Vec3 v;
        fn_8015adf4(np, &o->target, 255);
        ((Ptr32<void (Ptr32<Iface>, Ptr32<Iface>, int)>)o->sink->vtable[23])((Ptr32<Iface>)o->sink, o->target, s->mode);
        fill(&v, s->scale);
        ((Ptr32<void (Ptr32<Iface>, Ptr32<Vec3>, int)>)o->target->vtable[21])(o->target, &v, 0);
    }
}

}
