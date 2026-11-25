// desc: Appears to construct an object on a base constructor, install a vtable, retain a shared global interface and run a setup helper.
struct S21Ref;
struct S21RefMethods { void (*reserved[3])(void); void (*retain)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Object { void *vtable; char pad[16]; struct S21Ref *held; };
extern struct S21Ref *lbl_804b05ac;
extern char lbl_8041a798[];
extern void * fn_801ea0ec(struct S21Object *, int);
extern void fn_8025d618(struct S21Object *);
struct S21Object *w3d_s21_construct_802371dc(struct S21Object *self, void * arg_r4)
{
    struct S21Ref *shared;
    fn_801ea0ec(self, arg_r4);
    shared = lbl_804b05ac;
    self->vtable = lbl_8041a798;
    self->held = shared;
    if (shared)
        shared->methods->retain(shared);
    fn_8025d618(self);
    return self;
}
