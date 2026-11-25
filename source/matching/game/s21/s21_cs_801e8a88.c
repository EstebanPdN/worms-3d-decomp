// desc: Appears to construct an object on a base constructor with two vtable pointers and two cleared triples, and push it onto a global intrusive list.
struct S21Triple { int a; int b; int c; };
struct S21Object { void *vtable; char pad[8]; void *vtable2; char pad1[32]; struct S21Triple first; struct S21Triple second; int clear; struct S21Object *next; };
extern void * fn_8020fbd0(void *, void *, void *, void *, void *, void *);
extern char lbl_80417190[];
extern char lbl_804171b8[];
extern struct S21Object *lbl_804b18e0;
static inline void s21_clear(struct S21Triple *t)
{
    t->c = 0;
    t->b = 0;
    t->a = 0;
}
struct S21Object *w3d_s21_construct_801e8a88(struct S21Object *self, void * arg_r4, void * arg_r5, void * arg_r6, void * arg_r7, void * arg_r8)
{
    fn_8020fbd0(self, arg_r4, arg_r5, arg_r6, arg_r7, arg_r8);
    self->vtable2 = lbl_80417190;
    self->vtable = lbl_804171b8;
    s21_clear(&self->first);
    s21_clear(&self->second);
    self->clear = 0;
    self->next = lbl_804b18e0;
    lbl_804b18e0 = self;
    return self;
}
