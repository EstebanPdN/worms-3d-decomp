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
        volatile unsigned char byte[4];
    } u;
} W3dTag;

typedef struct W3dTagged {
    void **vtbl;
    W3dTag tag;
    W3dTagPair pair;
} W3dTagged;

static inline void w3d_tag_pair_init(W3dTagPair *pair)
{
    pair->second = 0;
}

static inline void w3d_tag_triple_init(void *p)
{
    ((int *)p)[2] = 0;
    ((int *)p)[1] = 0;
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

void *w3d_construct_802109dc(void *member);

void *w3d_string_default(void *text);

void *w3d_string_assign_range(void *text, const char *chars, int count);

extern char w3d_string_unused_803b029c[];

typedef struct W3dIface_8020881c W3dIface_8020881c;

typedef struct W3dIfaceVtbl_8020881c {
    void *slots[3];
    void (*retain)(W3dIface_8020881c *self);    /* +12 */
} W3dIfaceVtbl_8020881c;

struct W3dIface_8020881c {
    W3dIfaceVtbl_8020881c *vtbl;
};

extern char w3d_string_column_format_803b2e04[];

void *w3d_string_from_text(void *text, const char *chars);

void *w3d_aligned_allocate(int size, int align);

W3dTagged *w3d_tagged_construct_8019da7c(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_804137b0;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80413760;
    w3d_construct_802109dc((char *)self + 24);
    *(int *)((char *)self + 36) = 0;
    *(int *)((char *)self + 20) = 0;
    return self;
}

W3dTagged *w3d_tagged_construct_801aeac0(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_804141b8;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80414170;
    volatile char pad[8];
    *(int *)((char *)self + 20) = 0;
    w3d_tag_pair_init((W3dTagPair *)((char *)self + 20));
    w3d_tag_pair_init((W3dTagPair *)((char *)self + 28));
    return self;
}

W3dTagged *w3d_tagged_construct_801dddf8(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_80411590;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80416a10;
    char *text = (char *)self + 32;
    w3d_construct_802109dc((char *)self + 20);
    w3d_string_default(text);
    w3d_string_assign_range(text, w3d_string_unused_803b029c, 7);
    return self;
}

W3dTagged *w3d_tagged_construct_801f2d24(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_80417d40;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80417d10;
    w3d_tag_triple_init((char *)self + 20);
    *(int *)((char *)self + 20) = 0;
    *(int *)((char *)self + 36) = 0;
    w3d_tag_triple_init((char *)self + 40);
    *(int *)((char *)self + 40) = 0;
    w3d_tag_triple_init((char *)self + 52);
    *(int *)((char *)self + 52) = 0;
    *(unsigned int *)((char *)self + 32) = (*(unsigned int *)((char *)self + 32) & 0x3fffffff) | 0x20000000;
    return self;
}

W3dTagged *w3d_tagged_construct_801f7cec(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_804180a8;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80418080;
    volatile char pad[8];
    *(int *)((char *)self + 20) = 0;
    w3d_tag_pair_init((W3dTagPair *)((char *)self + 20));
    w3d_tag_pair_init((W3dTagPair *)((char *)self + 28));
    return self;
}

W3dTagged *w3d_tagged_construct_80205a40(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_80419138;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_804190f0;
    volatile char pad[16];
    *(int *)((char *)self + 20) = 0;
    w3d_tag_pair_init((W3dTagPair *)((char *)self + 20));
    w3d_tag_pair_init((W3dTagPair *)((char *)self + 28));
    w3d_construct_802109dc((char *)self + 36);
    *(int *)((char *)self + 48) = 0;
    w3d_tag_pair_init((W3dTagPair *)((char *)self + 48));
    w3d_tag_pair_init((W3dTagPair *)((char *)self + 56));
    return self;
}

W3dTagged *w3d_tagged_construct_8020881c(W3dTagged *self, W3dIface_8020881c *source)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_80418490;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_804192f8;
    *(W3dIface_8020881c **)((char *)self + 20) = source;
    if (source)
        source->vtbl->retain(source);
    w3d_string_from_text((char *)self + 24, w3d_string_column_format_803b2e04);
    *(int *)((char *)self + 28) = 1;
    return self;
}

W3dTagged *w3d_tagged_construct_8020a03c(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_804193d8;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80419388;
    w3d_tag_triple_init((char *)self + 20);
    *(int *)((char *)self + 20) = 0;
    *(int *)((char *)self + 32) = 0;
    return self;
}

W3dTagged *w3d_tagged_construct_8020aad0(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_804181c0;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80419430;
    w3d_tag_triple_init((char *)self + 20);
    *(int *)((char *)self + 20) = 0;
    return self;
}

W3dTagged *w3d_tagged_construct_80218300(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_80418110;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80419810;
    *(int *)((char *)self + 20) = 0;
    w3d_string_default((char *)self + 24);
    return self;
}

W3dTagged *w3d_tagged_construct_802187dc(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_804181c0;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_804197a8;
    *(int *)((char *)self + 20) = 0;
//vt
    *(void **)((char *)self + 88) = w3d_aligned_allocate(1024, 32);
    *(int *)((char *)self + 92) = 0;
    *(int *)((char *)self + 96) = 0;
    *(int *)((char *)self + 100) = 0;
    *(int *)((char *)self + 108) = -1;
    return self;
}

W3dTagged *w3d_tagged_construct_8021950c(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_804181c0;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80419858;
    *(int *)((char *)self + 20) = 0;
    *(int *)((char *)self + 24) = 0x10000;
    *(int *)((char *)self + 28) = 0;
    *(int *)((char *)self + 32) = 0;
    *(int *)((char *)self + 36) = 0;
    *(int *)((char *)self + 40) = 0;
    *(int *)((char *)self + 44) = 0;
    return self;
}

}
