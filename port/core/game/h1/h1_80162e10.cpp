#include "w3d_ptr.h"
#line 1 "h1_80162e10.cpp"
/* Registry-owner constructor of the tagged object family (session 47b5d14a,
 * hand-matched from the tools/gen_tag_ctor_units.py template). The inlined
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

extern unsigned char w3d_vtable_80411940[];
extern unsigned char w3d_vtable_80411908[];
extern Ptr32<void> w3d_sda_registry_owner_804b178c;
extern int w3d_sda_registry_state_804b1890;
Ptr32<void> w3d_s20_init_registry_8016130c(Ptr32<void> registry);
Ptr32<W3dTagged> w3d_h1_registry_owner_construct_80162e10(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80411940;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80411908;
    w3d_s20_init_registry_8016130c((Ptr32<char>)self + 32);
    w3d_sda_registry_owner_804b178c = self;
    w3d_sda_registry_state_804b1890 = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 60) = 0;
    return self;
}
}


