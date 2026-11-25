struct K3bTag { unsigned short a; unsigned short b; union { unsigned int word; unsigned char byte[4]; } u; };
struct K3bPair { int first; int second; };
struct K3bObj { void **vtable; struct K3bTag tag; struct K3bPair pair; };
extern void *w3d_vtable_804181c0[];
extern void *w3d_vtable_80419180[];
static inline void k3b_pair_init(struct K3bPair *p)
{
    p->first = 0;
    p->second = 0;
}
struct K3bObj *w3d_k3b_tagged_construct_80206af4(struct K3bObj *self)
{
    struct K3bTag *new_var2;
    struct K3bTag *t = &self->tag;
    unsigned int new_var;
    short zero;
    zero = 0;
    self->vtable = w3d_vtable_804181c0;
    t->u.byte[3] = 2;
    new_var = t->u.word;
    t->u.word = 0xff & new_var;
    new_var2 = t;
    k3b_pair_init(&self->pair);
    new_var2->a = zero;
    t->b = zero;
    self->vtable = w3d_vtable_80419180;
    return self;
}
// desc: Appears to construct a tagged object that installs a base vtable, initializes a tag word to two and clears a pair of fields before installing its own vtable.
