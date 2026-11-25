// desc: Appears to be a deleting destructor that installs the vtable pointer, runs member cleanup and deletes the object when the low flag bit is set.
struct S21Object { char pad[28]; void *vtable; };
extern char lbl_80416f38[];
extern int fn_801e4de8(struct S21Object *);
extern void fn_801fe1f8(struct S21Object *);
void w3d_s21_destroy_801e4c48(struct S21Object *self, int flags)
{
    self->vtable = lbl_80416f38;
    fn_801e4de8(self);
    if (flags & 1)
        fn_801fe1f8(self);
}
