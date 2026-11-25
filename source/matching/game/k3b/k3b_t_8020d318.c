#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
struct K3bTag { unsigned short a; unsigned short b; union { unsigned int word; unsigned char byte[4]; } u; };
struct K3bPair { int first; int second; };
extern void *w3d_vtable_804181c0[];
extern void *w3d_vtable_804194d0[];
static inline void k3b_pair_init(struct K3bPair *p)
{
    p->first = 0;
    p->second = 0;
}
void *w3d_k3b_tagged_construct_8020d318(void *self, unsigned int a4)
{
    struct K3bTag *new_var2;
    struct K3bTag *t = (struct K3bTag *)((char *)self + 4);
    unsigned int new_var;
    short zero;
    zero = 0;
    FIELD(self, void **, 0) = w3d_vtable_804181c0;
    t->u.byte[3] = 2;
    new_var = t->u.word;
    t->u.word = 0xff & new_var;
    new_var2 = t;
    k3b_pair_init((struct K3bPair *)((char *)self + 12));
    new_var2->a = zero;
    t->b = zero;
    FIELD(self, void **, 0) = w3d_vtable_804194d0;
    FIELD(self, int, 24) = 0;
    FIELD(self, int, 20) = a4;
    return self;
}
// desc: Appears to construct a tagged object that installs a base vtable, initializes a tag word to two and clears a pair of fields before installing its own vtable.
