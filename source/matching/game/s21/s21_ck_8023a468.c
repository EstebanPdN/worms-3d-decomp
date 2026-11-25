// desc: Appears to construct an object on a base constructor, install a vtable, clear a field and retain a third shared global interface.
struct S21Ref;
struct S21RefMethods { void (*reserved[3])(void); void (*retain)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Object { void *vtable; char pad[16]; char pad2[20]; int cleared; struct S21Ref *held; };
extern struct S21Ref *lbl_804b05a8;
extern char lbl_8041aea0[];
extern int fn_80239d60(struct S21Object *, void *);
struct S21Object *w3d_s21_construct_8023a468(struct S21Object *self, void * arg_r4)
{
    struct S21Ref *shared;
    fn_80239d60(self, arg_r4);
    shared = lbl_804b05a8;
    self->vtable = lbl_8041aea0;
    self->cleared = 0;
    self->held = shared;
    if (shared)
        shared->methods->retain(shared);
    return self;
}
