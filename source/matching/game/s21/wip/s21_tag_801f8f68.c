struct S21Tag { short first; short second; union { int word; volatile unsigned char bytes[4]; } u; };
struct S21Pair { int a; int b; };
struct S21Object { void *vtable; struct S21Tag tag; struct S21Pair pair; int f20; int f24; int f28; };
extern char lbl_80418168[];
extern char lbl_80418140[];
static inline void s21_tag_init(struct S21Tag *t, short second)
{
    t->u.bytes[3] = 2;
    t->u.word = t->u.bytes[3];
    t->first = 0;
    t->second = second;
}
static inline void s21_pair_init(struct S21Pair *p)
{
    p->a = 0;
    p->b = 0;
}
struct S21Object *w3d_s21_construct_801f8f68(struct S21Object *self)
{
    self->vtable = lbl_80418168;
    s21_tag_init(&self->tag, 0);
    s21_pair_init(&self->pair);
    self->vtable = lbl_80418140;
    self->f20 = 0;
    self->f28 = 0;
    return self;
}
