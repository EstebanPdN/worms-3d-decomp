struct K5bIface { void **vtable; };
struct K5bArray {
    void **vtable;
    unsigned short references;
    char pad6[14];
    unsigned int capacity;
    unsigned int count;
    unsigned short locks;
    char pad30[2];
    struct K5bIface *items[1];
};
extern void *w3d_k5b_array_ref_lock_801ef048(struct K5bArray **ref, unsigned int count, unsigned int element_size,
    unsigned int flags);
static inline struct K5bArray **k5b_field_array(char *object, int offset)
{
    return (struct K5bArray **)(object + offset);
}
void w3d_k5b_iface_array_field_set_801ef2ec(char *object, int offset, int unused, struct K5bIface *item,
    int index)
{
    struct K5bArray *array = *(struct K5bArray **)(offset + object);
    struct K5bIface **items;
    struct K5bIface *old;
    if (array->references != 1) {
        w3d_k5b_array_ref_lock_801ef048(k5b_field_array(object, offset), array->count, 4, 2);
        array = *k5b_field_array(object, offset);
    }
    items = array->items;
    old = items[index];
    items[index] = item;
    ((void (*)(struct K5bIface *))item->vtable[3])(item);
    ((void (*)(struct K5bIface *))old->vtable[4])(old);
}
// desc: w3d_k5b_iface_array_field_set_801ef2ec: Appears to make the array referenced at the field offset unique, then replace the interface at the index, retaining the new one and releasing the old one.
