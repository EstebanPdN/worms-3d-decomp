// desc: Appears to construct an object with a base constructor, a vtable pointer and a global 16-bit sequence number that is then incremented.
struct S21Object { void *vtable; char pad[4]; unsigned short serial; };
extern void fn_801ffe44(struct S21Object *);
extern char lbl_80418cf0[];
extern unsigned short lbl_804b0638;
struct S21Object *w3d_s21_construct_801ffecc(struct S21Object *self)
{
    fn_801ffe44(self);
    self->vtable = lbl_80418cf0;
    self->serial = ++lbl_804b0638;
    return self;
}
