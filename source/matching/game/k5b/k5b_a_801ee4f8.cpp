struct K5bIface { void **vtable; };
struct K5bArrayAllocator { void **vtable; };
struct K5bIfaceArray {
    void **vtable;
    char pad4[20];
    unsigned int count;
    char pad28[4];
    K5bIface *items[1];
};
template <class T> inline const T &k5b_min(const T &a, const T &b)
{
    return b < a ? b : a;
}
extern "C" K5bIfaceArray *w3d_k5b_iface_array_resized_801ee4f8(K5bIfaceArray *self, unsigned int count,
    unsigned int element_size, int keep)
{
    unsigned int bytes = count * element_size;
    K5bArrayAllocator *allocator = ((K5bArrayAllocator *(*)(K5bIfaceArray *))self->vtable[9])(self);
    K5bIfaceArray *copy = ((K5bIfaceArray *(*)(K5bArrayAllocator *, unsigned int, int))allocator->vtable[3])(allocator, bytes, 0);
    K5bIface **source = self->items;
    K5bIface **target = copy->items;
    unsigned int i;
    if (keep != 0) {
        unsigned int n = k5b_min((unsigned int)self->count, count);
        for (i = 0; i < n; i++) {
            K5bIface *item = source[i];
            target[i] = item;
            ((void (*)(K5bIface *))item->vtable[3])(item);
        }
        for (; i < count; i++)
            target[i] = 0;
    } else {
        unsigned int j;
        for (j = 0; j < count; j++)
            target[j] = 0;
    }
    copy->count = count;
    return copy;
}
// desc: w3d_k5b_iface_array_resized_801ee4f8: Appears to allocate a resized interface array through the owner's allocator, copy and retain up to the old count of entries when asked, and null the rest.
