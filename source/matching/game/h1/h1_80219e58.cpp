/* Named tagged-object constructors (session 47b5d14a, hand-matched; four
 * instances of one shape). See tools/gen_tag_ctor_units.py for the tag. */
extern "C" {
typedef struct W3dTagPair { int first; int second; } W3dTagPair;
typedef struct W3dTag { unsigned short a; unsigned short b; union { unsigned int word; volatile unsigned char byte[4]; } u; } W3dTag;
typedef struct W3dNamedTagged { void **vtbl; unsigned char name[16]; W3dTag tag; W3dTagPair pair; } W3dNamedTagged;
static inline void w3d_tag_pair_init(W3dTagPair *pair) { pair->second = 0; }
void *w3d_string_default(void *text);
extern unsigned char w3d_vtable_80419888[];
extern unsigned char w3d_vtable_804198c8[];
extern unsigned char w3d_vtable_80419908[];
extern unsigned char w3d_vtable_80419a08[];
extern unsigned char w3d_vtable_80419a48[];
extern unsigned char w3d_vtable_80419a88[];
extern unsigned char w3d_vtable_80419ac8[];
extern unsigned char w3d_vtable_80419b08[];
extern unsigned char w3d_vtable_80419b48[];
extern unsigned char w3d_vtable_80419b88[];
extern unsigned char w3d_vtable_80419bc8[];
extern unsigned char w3d_vtable_80419c08[];

W3dNamedTagged *w3d_named_tagged_construct_80219e58(W3dNamedTagged *self)
{
    W3dTag *tag;
    self->vtbl = (void **)w3d_vtable_80419c08;
    w3d_string_default(self->name);
    self->vtbl = (void **)w3d_vtable_80419bc8;
    tag = &self->tag;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80419b88;
    return self;
}

W3dNamedTagged *w3d_named_tagged_construct_80219f44(W3dNamedTagged *self)
{
    W3dTag *tag;
    self->vtbl = (void **)w3d_vtable_80419b48;
    w3d_string_default(self->name);
    self->vtbl = (void **)w3d_vtable_80419b08;
    tag = &self->tag;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80419ac8;
    return self;
}

W3dNamedTagged *w3d_named_tagged_construct_8021a030(W3dNamedTagged *self)
{
    W3dTag *tag;
    self->vtbl = (void **)w3d_vtable_80419a88;
    w3d_string_default(self->name);
    self->vtbl = (void **)w3d_vtable_80419a48;
    tag = &self->tag;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80419a08;
    return self;
}

W3dNamedTagged *w3d_named_tagged_construct_8021a184(W3dNamedTagged *self)
{
    W3dTag *tag;
    self->vtbl = (void **)w3d_vtable_80419908;
    w3d_string_default(self->name);
    self->vtbl = (void **)w3d_vtable_804198c8;
    tag = &self->tag;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80419888;
    return self;
}
}
