// desc: Appears to be a destructor body that releases every interface of the counted array at offset 32, installs the base vtable and destroys the embedded node.
struct S21Ref;
struct S21RefMethods { void (*reserved[4])(void); void (*release)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Object { void *vtable; char node[20]; int count; char pad[4]; struct S21Ref *items[1]; };
extern char lbl_804176d0[];
extern char lbl_80411ac0[];
extern void fn_80210990(void *, int);
void w3d_s21_destroy_refs_801ee46c(struct S21Object *self)
{
    int count = self->count;
    struct S21Ref **strings = self->items;
    struct S21Ref **item;
    int remaining;
    self->vtable = lbl_804176d0;
    if (count > 0) {
        item = strings;
        remaining = count;
        do {
            struct S21Ref *ref = *item;
            item++;
            if (ref)
                ref->methods->release(ref);
        } while (--remaining);
    }
    self->vtable = lbl_80411ac0;
    fn_80210990(self->node, 0);
}
