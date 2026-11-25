// desc: Appears to construct an object on a base constructor, install a vtable, zero ten words, retain a shared global interface and set an integer property of 30000.
struct S21Ref;
struct S21RefMethods { void (*reserved[3])(void); void (*retain)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Object { void *vtable; char pad[16]; int w[9]; int tail; struct S21Ref *held; };
extern struct S21Ref *lbl_804b05ac;
extern char lbl_8041ae28[];
extern void * fn_801ea0ec(struct S21Object *, int);
extern void fn_802408a0(struct S21Object *, int);
struct S21Object *w3d_s21_construct_8023ac08(struct S21Object *self, void * arg_r4)
{
    struct S21Ref *shared;
    fn_801ea0ec(self, arg_r4);
    shared = lbl_804b05ac;
    self->vtable = lbl_8041ae28;
    self->w[0] = 0;
    self->w[1] = 0;
    self->w[2] = 0;
    self->w[3] = 0;
    self->w[4] = 0;
    self->w[5] = 0;
    self->w[6] = 0;
    self->w[7] = 0;
    self->w[8] = 0;
    self->tail = 0;
    self->held = shared;
    if (shared)
        shared->methods->retain(shared);
    fn_802408a0(self, 30000);
    return self;
}
