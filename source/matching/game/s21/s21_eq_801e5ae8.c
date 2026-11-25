// desc: Appears to be a deleting destructor: it installs a vtable pointer, runs cleanup, frees the aligned block at offset 60, clears two pointer slots, releases the held interface and deletes the object when the low flag bit is set.
struct S21Ref;
struct S21RefMethods { void (*reserved[4])(void); void (*release)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Object { char pad[44]; struct S21Ref *held; char pad1[12]; int slots[2]; char pad2[100]; void *vtable; };
extern char lbl_80416f78[];
extern void fn_801e5dfc(struct S21Object *);
extern void fn_801fe2e0(void *);
extern void fn_801fe1f8(struct S21Object *);
void w3d_s21_destroy_801e5ae8(struct S21Object *self, int flags)
{
    int *slot;
    int *cursor;
    self->vtable = lbl_80416f78;
    fn_801e5dfc(self);
    slot = self->slots;
    if (slot)
        fn_801fe2e0(slot);
    cursor = slot;
    do {
        *cursor = 0;
        cursor++;
    } while (cursor <= self->slots + 1);
    if (self->held)
        self->held->methods->release(self->held);
    if (flags & 1)
        fn_801fe1f8(self);
}
