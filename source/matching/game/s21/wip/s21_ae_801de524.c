// desc: Appears to construct an object by installing two vtable pointers, initializing an embedded tag record, a float and three zeroed words.
struct S21Tag { int first; union { int word; volatile unsigned char bytes[4]; } u; };
struct S21Object { void *vtable; char pad[20]; float scale; int a; int b; int c; struct S21Tag tag; };
extern char lbl_80416a90[];
extern char lbl_80416a38[];
extern float lbl_803b02fc[];
static inline void s21_tag_init(struct S21Tag *t)
{
    t->u.bytes[3] = 2;
    t->u.word = t->u.bytes[3];
}
struct S21Object *w3d_s21_construct_801de524(struct S21Object *self)
{
    self->vtable = lbl_80416a90;
    s21_tag_init(&self->tag);
    self->vtable = lbl_80416a38;
    self->scale = lbl_803b02fc[0];
    self->c = 0;
    self->b = 0;
    self->a = 0;
    return self;
}
