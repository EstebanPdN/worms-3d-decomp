#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801b17bc.c"
struct K4bTriple { int first; int second; int third; };
struct K4bMember { char data[12]; };
struct K4bTracker {
    Ptr32<Ptr32<void>> vtable;
    char base[36];
    struct K4bTriple triple;
    struct K4bMember member;
    int field_40;
    int field_44;
    int field_48;
    int field_4c;
    int field_50;
};
extern Ptr32<void> lbl_804142c0[];
extern Ptr32<void> lbl_80414270[];
extern Ptr32<void> fn_801e81c8(Ptr32<void> member);
extern Ptr32<void> w3d_construct_801f2678(Ptr32<struct K4bMember> member);
static inline void k4b_triple_init(Ptr32<struct K4bTriple> t)
{
    t->third = 0;
    t->second = 0;
    t->first = 0;
}
Ptr32<struct K4bTracker> w3d_k4b_tracker_construct_801b17bc(Ptr32<struct K4bTracker> self)
{
    self->vtable = lbl_804142c0;
    fn_801e81c8(self->base);
    self->vtable = lbl_80414270;
    k4b_triple_init(&self->triple);
    w3d_construct_801f2678(&self->member);
    self->field_40 = 0;
    self->field_44 = 0;
    self->field_48 = 0;
    self->field_4c = 0;
    self->field_50 = 0;
    return self;
}
// desc: w3d_k4b_tracker_construct_801b17bc: Appears to construct an object: base vtable, member at +4 via 0x801e81c8, derived vtable 0x80414270, zero a three-word block, construct a member at +52 and zero five words.

}
