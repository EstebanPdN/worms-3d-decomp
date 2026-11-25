// desc: Appears to append an interface object to a growable array: it reserves one more slot, retains the new object, releases whatever the slot held, stores it, bumps the count and returns one.
struct S21Ref;
struct S21RefMethods { void (*reserved[3])(void); void (*retain)(struct S21Ref *); void (*release)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Array { unsigned count; int reserved; struct S21Ref **items; };
struct S21Object { char pad[20]; struct S21Array array; };
extern void fn_80210d54(struct S21Array *, unsigned);
int w3d_s21_append_ref_801ddf5c(struct S21Object *self, struct S21Ref *ref)
{
    struct S21Array *array = &self->array;
    unsigned offset;
    struct S21Ref **items;
    fn_80210d54(array, array->count + 1);
    offset = self->array.count << 2;
    items = array->items;
    if (ref)
        ref->methods->retain(ref);
    if (*(struct S21Ref **)(offset + (unsigned)items))
        (*(struct S21Ref **)(offset + (unsigned)items))->methods->release(*(struct S21Ref **)(offset + (unsigned)items));
    *(struct S21Ref **)(offset + (unsigned)items) = ref;
    self->array.count++;
    return 1;
}
