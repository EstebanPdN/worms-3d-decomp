#include "w3d_ptr.h"
#line 1 "d42i_effect_construct_8011da38.cpp"
// d42i: 0x8011da38. Constructs an effect object: base constructor, clears
// the held references, then releases and clears them through the reference
// helpers.
struct Obj;
struct ObjVt { char u0[12]; Ptr32<int (Ptr32<Obj>)> add; Ptr32<int (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
    Ptr32<Obj> p;
    void init(Ptr32<Obj> const &q) { if (q) { q->vt->add(q); p = q; } else p = 0; }
    void clr(Ptr32<Obj> q) { if (p) p->vt->release(p); p = q; }
    void reset() { if (p) p->vt->release(p); p = 0; }
};
struct Thing {
    Ptr32<const void> vt;
    char u4[24];
    Ref o28, o32, o36, o40;
    char u44[12];
    Ref o56, o60, o64, o68;
    int w72;
    Ref o76, o80, o84, o88, o92;
    char u96[12];
    Ref o108;
    char u112[4];
    unsigned char b116;
    char u117[3];
    int w120;
};
extern "C" Ptr32<Thing> base_8015fef0(Ptr32<Thing>);
extern Ptr32<const void> const vt_80410ab0[];
extern "C" Ptr32<Thing> d42i_effect_construct_8011da38(Ptr32<Thing> self) {
    base_8015fef0(self);
    self->vt = vt_80410ab0;
    Ptr32<Obj> z = 0;
    self->o28.p = z; self->o32.p = z; self->o36.p = z; self->o40.p = z; self->o68.p = z;
    self->o76.p = z; self->o80.p = z; self->o84.p = z; self->o88.p = z; self->o92.p = z; self->o108.p = z;
    self->o64.p = z;
    self->o56.init(z);
    self->o60.p = 0;
    self->o64.reset(); self->o68.reset(); self->o28.reset(); self->o32.reset(); self->o36.reset();
    self->w72 = 0; self->b116 = 0; self->w120 = 0;
    self->o108.reset(); self->o88.reset(); self->o92.clr(z);
    return self;
}


