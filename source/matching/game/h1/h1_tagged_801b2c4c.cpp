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

extern unsigned char w3d_vtable_804143f0[];
extern unsigned char w3d_vtable_80414430[];

typedef struct W3dRef W3dRef;

typedef struct W3dRefVtbl {
    void *slots[3];
    void (*retain)(W3dRef *self);              /* +12 */
    void (*release)(W3dRef *self);             /* +16 */
} W3dRefVtbl;

struct W3dRef {
    W3dRefVtbl *vtbl;
};

extern unsigned char w3d_type_80414478[];

extern unsigned char w3d_type_80413be8[];

void *w3d_construct_802109dc(void *member);

W3dRef *w3d_s10_service_forward_8020b680(void *type);

#define W3D_PAIR(off) ((W3dTagPair *)((char *)self + (off)))

#define W3D_INT(off) (*(int *)((char *)self + (off)))

W3dTagged *w3d_tagged_construct_801b2c4c(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_80414430;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_804143f0;
    W3dRef *ref;
    W3dRef *old;
    volatile char pad[32];
    W3D_INT(20) = 0;
    W3D_INT(24) = 0;
    W3D_INT(28) = 0;
    w3d_tag_pair_init(W3D_PAIR(28));
    w3d_tag_pair_init(W3D_PAIR(36));
    W3D_INT(44) = 0;
    w3d_tag_pair_init(W3D_PAIR(44));
    w3d_tag_pair_init(W3D_PAIR(52));
    w3d_construct_802109dc((char *)self + 60);
    W3D_INT(72) = 0;
    w3d_tag_pair_init(W3D_PAIR(72));
    w3d_tag_pair_init(W3D_PAIR(80));
    W3D_INT(88) = 0;
    w3d_tag_pair_init(W3D_PAIR(88));
    w3d_tag_pair_init(W3D_PAIR(96));
    ref = w3d_s10_service_forward_8020b680(w3d_type_80414478);
    if (ref)
        ref->vtbl->retain(ref);
    old = *(W3dRef **)((char *)self + 20);
    if (old)
        old->vtbl->release(old);
    *(W3dRef **)((char *)self + 20) = ref;
    ref = w3d_s10_service_forward_8020b680(w3d_type_80413be8);
    if (ref)
        ref->vtbl->retain(ref);
    old = *(W3dRef **)((char *)self + 24);
    if (old)
        old->vtbl->release(old);
    *(W3dRef **)((char *)self + 24) = ref;
    return self;
}

}
