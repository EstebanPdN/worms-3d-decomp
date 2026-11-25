struct K5bIface { void **vtable; };
struct K5bArray {
    void **vtable;
    unsigned short references;
    char pad6[14];
    unsigned int capacity;
    unsigned int count;
    unsigned short locks;
    char pad30[2];
    unsigned char data[1];
};
extern void *w3d_k5b_array_ref_lock_801ef048(struct K5bArray **ref, unsigned int count, unsigned int element_size,
    unsigned int flags);
static inline void *k5b_array_lock(struct K5bArray **ref, unsigned int count, unsigned int element_size,
    unsigned int flags)
{
    struct K5bArray *array = *ref;
    if (array->references == 1 && count == array->count) {
        ++array->locks;
        return array->data;
    }
    return w3d_k5b_array_ref_lock_801ef048(ref, count, element_size, flags);
}
void w3d_k5b_iface_array_field_append_801ef174(char *object, int offset, int unused, struct K5bIface *item)
{
    struct K5bArray **ref = (struct K5bArray **)(object + offset);
    unsigned int index = (*ref)->count;
    struct K5bIface **items = k5b_array_lock(ref, index + 1, 4, 2);
    items[index] = item;
    ((void (*)(struct K5bIface *))item->vtable[3])(item);
}
// desc: w3d_k5b_iface_array_field_append_801ef174: Appears to append and retain an interface in the array referenced at the given field offset, growing it through 0x801ef048 unless solely owned and sized.
