#include "w3d_ptr.h"
#line 1 "h1_tagged_8019da7c.cpp"
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

extern unsigned char w3d_vtable_80411590[];
extern unsigned char w3d_vtable_80413760[];
extern unsigned char w3d_vtable_804137b0[];
extern unsigned char w3d_vtable_80414170[];
extern unsigned char w3d_vtable_804141b8[];
extern unsigned char w3d_vtable_80416a10[];
extern unsigned char w3d_vtable_80417d10[];
extern unsigned char w3d_vtable_80417d40[];
extern unsigned char w3d_vtable_80418080[];
extern unsigned char w3d_vtable_804180a8[];
extern unsigned char w3d_vtable_80418110[];
extern unsigned char w3d_vtable_804181c0[];
extern unsigned char w3d_vtable_80418490[];
extern unsigned char w3d_vtable_804190f0[];
extern unsigned char w3d_vtable_80419138[];
extern unsigned char w3d_vtable_804192f8[];
extern unsigned char w3d_vtable_80419388[];
extern unsigned char w3d_vtable_804193d8[];
extern unsigned char w3d_vtable_80419430[];
extern unsigned char w3d_vtable_804197a8[];
extern unsigned char w3d_vtable_80419810[];
extern unsigned char w3d_vtable_80419858[];

Ptr32<void> w3d_construct_802109dc(Ptr32<void> member);

Ptr32<void> w3d_string_default(Ptr32<void> text);

Ptr32<void> w3d_string_assign_range(Ptr32<void> text, Ptr32<const char> chars, int count);

extern char w3d_string_unused_803b029c[];

typedef struct W3dIface_8020881c W3dIface_8020881c;

typedef struct W3dIfaceVtbl_8020881c {
    Ptr32<void> slots[3];
    Ptr32<void (Ptr32<W3dIface_8020881c>)> retain;    /* +12 */
} W3dIfaceVtbl_8020881c;

struct W3dIface_8020881c {
    Ptr32<W3dIfaceVtbl_8020881c> vtbl;
};

extern char w3d_string_column_format_803b2e04[];

Ptr32<void> w3d_string_from_text(Ptr32<void> text, Ptr32<const char> chars);

Ptr32<void> w3d_aligned_allocate(int size, int align);

Ptr32<W3dTagged> w3d_tagged_construct_8019da7c(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804137b0;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80413760;
    w3d_construct_802109dc((Ptr32<char>)self + 24);
    *(Ptr32<int>)((Ptr32<char>)self + 36) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_801aeac0(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804141b8;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80414170;
    volatile char pad[8];
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    w3d_tag_pair_init((Ptr32<W3dTagPair>)((Ptr32<char>)self + 20));
    w3d_tag_pair_init((Ptr32<W3dTagPair>)((Ptr32<char>)self + 28));
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_801dddf8(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80411590;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80416a10;
    Ptr32<char> text = (Ptr32<char>)self + 32;
    w3d_construct_802109dc((Ptr32<char>)self + 20);
    w3d_string_default(text);
    w3d_string_assign_range(text, w3d_string_unused_803b029c, 7);
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_801f2d24(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80417d40;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80417d10;
    w3d_tag_triple_init((Ptr32<char>)self + 20);
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 36) = 0;
    w3d_tag_triple_init((Ptr32<char>)self + 40);
    *(Ptr32<int>)((Ptr32<char>)self + 40) = 0;
    w3d_tag_triple_init((Ptr32<char>)self + 52);
    *(Ptr32<int>)((Ptr32<char>)self + 52) = 0;
    *(Ptr32<unsigned int>)((Ptr32<char>)self + 32) = (*(Ptr32<unsigned int>)((Ptr32<char>)self + 32) & 0x3fffffff) | 0x20000000;
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_801f7cec(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804180a8;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80418080;
    volatile char pad[8];
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    w3d_tag_pair_init((Ptr32<W3dTagPair>)((Ptr32<char>)self + 20));
    w3d_tag_pair_init((Ptr32<W3dTagPair>)((Ptr32<char>)self + 28));
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_80205a40(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80419138;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804190f0;
    volatile char pad[16];
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    w3d_tag_pair_init((Ptr32<W3dTagPair>)((Ptr32<char>)self + 20));
    w3d_tag_pair_init((Ptr32<W3dTagPair>)((Ptr32<char>)self + 28));
    w3d_construct_802109dc((Ptr32<char>)self + 36);
    *(Ptr32<int>)((Ptr32<char>)self + 48) = 0;
    w3d_tag_pair_init((Ptr32<W3dTagPair>)((Ptr32<char>)self + 48));
    w3d_tag_pair_init((Ptr32<W3dTagPair>)((Ptr32<char>)self + 56));
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_8020881c(Ptr32<W3dTagged> self, Ptr32<W3dIface_8020881c> source)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80418490;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804192f8;
    *(Ptr32<Ptr32<W3dIface_8020881c>>)((Ptr32<char>)self + 20) = source;
    if (source)
        source->vtbl->retain(source);
    w3d_string_from_text((Ptr32<char>)self + 24, w3d_string_column_format_803b2e04);
    *(Ptr32<int>)((Ptr32<char>)self + 28) = 1;
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_8020a03c(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804193d8;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80419388;
    w3d_tag_triple_init((Ptr32<char>)self + 20);
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 32) = 0;
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_8020aad0(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804181c0;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80419430;
    w3d_tag_triple_init((Ptr32<char>)self + 20);
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_80218300(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80418110;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80419810;
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    w3d_string_default((Ptr32<char>)self + 24);
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_802187dc(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804181c0;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804197a8;
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
//vt
    *(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 88) = w3d_aligned_allocate(1024, 32);
    *(Ptr32<int>)((Ptr32<char>)self + 92) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 96) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 100) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 108) = -1;
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_8021950c(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804181c0;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80419858;
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 24) = 0x10000;
    *(Ptr32<int>)((Ptr32<char>)self + 28) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 32) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 36) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 40) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 44) = 0;
    return self;
}

}


