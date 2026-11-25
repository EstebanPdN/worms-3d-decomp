#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_ctor_800269fc.c"
struct S19Obj { Ptr32<void> vt; char pad4[24]; int f28, f32, f36, f40, f44, f48, f52, f56, f60, f64, f68, f72, f76, f80; int pad84; float f88, f92; int pad96; int f100; };
extern unsigned char lbl_8040e008[];
extern int w3d_actor_base_initialize(Ptr32<struct S19Obj>);

Ptr32<struct S19Obj> s19_ctor_800269fc(Ptr32<struct S19Obj> p) {
    w3d_actor_base_initialize(p);
    p->f28 = 0;
    p->f32 = 0;
    p->f36 = 0;
    p->f40 = 0;
    p->f44 = 0;
    p->f48 = 0;
    p->f52 = 0;
    p->f56 = 0;
    p->f60 = 0;
    p->f64 = 0;
    p->f68 = 0;
    p->f72 = 0;
    p->f100 = 0;
    p->f76 = 0;
    p->f80 = 0;
    p->vt = (Ptr32<void>)lbl_8040e008;
    p->f88 = 1.5707964f;
    p->f92 = -1.5707964f;
    return p;
}

}
