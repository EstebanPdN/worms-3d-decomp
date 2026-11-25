#include "w3d_ptr.h"
#line 1 "h1_tagged_8015eccc.cpp"
/* Constructors of the tagged object family (session 47b5d14a), hand-matched
 * with analysis/worker-reports/h1_tagtry.py from the tools/gen_tag_ctor_units.py
 * template and proven identical to the original after linking. The inlined
 * base constructor sets the tag type byte to 2 (volatile, because the
 * original reloads it), clears the pair through an inline initializer and
 * the tag halves, then the derived constructor installs its vtable and sets
 * its own fields. Names are structural (original address). */
extern "C" {

typedef struct W3dTagPair {
    int first;
    int second;
} W3dTagPair;

typedef struct W3dTag {
    unsigned short a;
    unsigned short b;
    union {
        unsigned int word;
        w3d::be_array<volatile unsigned char, 4> byte;
    } u;
} W3dTag;

typedef struct W3dTagged {
    Ptr32<Ptr32<void>> vtbl;
    W3dTag tag;
    W3dTagPair pair;
} W3dTagged;

static inline void w3d_tag_pair_init(Ptr32<W3dTagPair> pair)
{
    pair->second = 0;
}

static inline void w3d_tag_triple_init(Ptr32<void> p)
{
    ((Ptr32<int>)p)[2] = 0;
    ((Ptr32<int>)p)[1] = 0;
}

extern unsigned char w3d_vtable_80411378[];
extern unsigned char w3d_vtable_80411420[];
extern unsigned char w3d_vtable_804114b8[];

typedef struct W3dRef_8015eccc W3dRef_8015eccc;

typedef struct W3dRefVtbl_8015eccc {
    Ptr32<void> slots[3];
    Ptr32<void (Ptr32<W3dRef_8015eccc>)> retain;     /* +12 */
    Ptr32<void (Ptr32<W3dRef_8015eccc>)> release;    /* +16 */
} W3dRefVtbl_8015eccc;

struct W3dRef_8015eccc {
    Ptr32<W3dRefVtbl_8015eccc> vtbl;
};

typedef struct W3dFlags_8015eccc {
    unsigned int rest:30; unsigned int visible:1; unsigned int active:1;
} W3dFlags_8015eccc;

extern unsigned char w3d_type_80412790[];

extern float w3d_float_803a4568[];

Ptr32<void> w3d_construct_802109dc(Ptr32<void> member);

Ptr32<W3dRef_8015eccc> w3d_s10_service_forward_8020b680(Ptr32<void> type);

#define W3D_PAIR(off) ((W3dTagPair *)w3d::AG((char *)self + (off)))

#define W3D_INT(off) (*(int *)w3d::AG((char *)self + (off)))

Ptr32<W3dTagged> w3d_tagged_construct_8015eccc(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80411378;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804114b8;
    Ptr32<W3dRef_8015eccc> ref;
    Ptr32<W3dRef_8015eccc> old;
    Ptr32<W3dFlags_8015eccc> flags;
    volatile char pad[8];
    W3D_INT(24) = 0;
    w3d_tag_pair_init(W3D_PAIR(24));
    w3d_tag_pair_init(W3D_PAIR(32));
    W3D_INT(56) = 0;
    W3D_INT(60) = 0;
    W3D_INT(64) = 0;
    W3D_INT(68) = 0;
    w3d_construct_802109dc((Ptr32<char>)self + 72);
    W3D_INT(88) = 0;
    W3D_INT(92) = 0;
    W3D_INT(96) = 0;
    W3D_INT(100) = 0;
    W3D_INT(104) = 0;
    W3D_INT(108) = 0;
    W3D_INT(112) = 0;
    W3D_INT(148) = 0;
    *(Ptr32<float>)((Ptr32<char>)self + 52) = w3d_float_803a4568[0];
    ref = w3d_s10_service_forward_8020b680(w3d_type_80412790);
    if (ref)
        ref->vtbl->retain(ref);
    old = *(Ptr32<Ptr32<W3dRef_8015eccc>>)((Ptr32<char>)self + 56);
    if (old)
        old->vtbl->release(old);
    *(Ptr32<Ptr32<W3dRef_8015eccc>>)((Ptr32<char>)self + 56) = ref;
    flags = (Ptr32<W3dFlags_8015eccc>)((Ptr32<char>)self + 48);
    flags->active = 0;
    flags->visible = 1;
    W3D_INT(40) = 0;
    W3D_INT(44) = 0;
    W3D_INT(20) = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80411420;
    return self;
}

}


