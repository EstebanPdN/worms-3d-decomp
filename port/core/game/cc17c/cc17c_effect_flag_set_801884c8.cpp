#include "w3d_ptr.h"
#line 1 "cc17c_effect_flag_set_801884c8.cpp"
/* Same source shape as the admitted particle-set flag setter 0x80184b70 (b_particle_set.cpp):
 * a reference-counted effect is held in an 8-byte local while its state is switched.
 * Observed object virtual slots: +12 add reference, +16 release. Inferred names. */
struct Cc17cObject;
struct Cc17cObjectTable { char pad0[12]; Ptr32<void (Ptr32<Cc17cObject>)> add_ref; Ptr32<void (Ptr32<Cc17cObject>)> release; };
struct Cc17cObject { Ptr32<Cc17cObjectTable> vt; };
struct Cc17cLocalRef {
    Ptr32<Cc17cObject> p;
    int unknown_04;
    template <class W3dU> Cc17cLocalRef(Ptr32<W3dU> w3d_p) : Cc17cLocalRef((Cc17cObject *)w3d_p.get()) {}
 Cc17cLocalRef(Cc17cObject *object) : p(object) { if (p) p->vt->add_ref(p); }
    ~Cc17cLocalRef() { if (p) p->vt->release(p); }
};
struct Cc17cEffectGroup { char pad0[52]; Ptr32<Cc17cObject> effect; };
/* Observed: group pointer at +48, 16-bit flags at +56. */
struct Cc17cEffectOwner { char pad0[48]; Ptr32<Cc17cEffectGroup> group; char pad52[4]; unsigned short flags; };
extern "C" int fn_801d4544(Ptr32<Cc17cObject>, Ptr32<Cc17cObject>);
extern Ptr32<Cc17cObject> lbl_804b0220;
extern Ptr32<Cc17cObject> lbl_804b0224;
extern "C" int w3d_cc17c_effect_flag_set_801884c8(Ptr32<Cc17cEffectOwner> self, int on)
{
    Cc17cLocalRef effect(self->group->effect);
    if (on == 0) {
        fn_801d4544(effect.p, lbl_804b0220);
        self->flags &= ~1;
    } else {
        fn_801d4544(effect.p, lbl_804b0224);
        self->flags |= 1;
    }
    return 0;
}


