// desc: Appears to construct an object on a base constructor, install a vtable, store a count of twenty and retain a shared global interface.
struct S21Ref;
struct S21RefMethods { void (*reserved[3])(void); void (*retain)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Object { void *vtable; char pad[16]; int count; struct S21Ref *held; };
extern struct S21Ref *lbl_804b05b0;
extern char lbl_8041a2a8[];
extern void * fn_801ea0ec(struct S21Object *, int);
struct S21Object *w3d_s21_construct_80225ef0(struct S21Object *self, void * arg_r4)
{
    struct S21Ref *shared;
    fn_801ea0ec(self, arg_r4);
    shared = lbl_804b05b0;
    self->vtable = lbl_8041a2a8;
    self->count = 20;
    self->held = shared;
    if (shared)
        shared->methods->retain(shared);
    return self;
}
