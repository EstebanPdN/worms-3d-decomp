#include "w3d_ptr.h"
#line 1 "k5b_a_801ee8c4.cpp"
struct K5bIface { Ptr32<Ptr32<void>> vtable; };
struct K5bArrayAllocator { Ptr32<Ptr32<void>> vtable; };
struct K5bIfaceArray {
    Ptr32<Ptr32<void>> vtable;
    char pad4[20];
    unsigned int count;
    char pad28[4];
    Ptr32<K5bIface> items[1];
};
template <class T> inline const T &k5b_min(const T &a, const T &b)
{
    return b < a ? b : a;
}
extern "C" Ptr32<K5bIfaceArray> w3d_k5b_handle_array_resized_801ee8c4(Ptr32<K5bIfaceArray> self, unsigned int count,
    unsigned int element_size, int keep)
{
    unsigned int bytes = count * element_size;
    Ptr32<K5bArrayAllocator> allocator = ((Ptr32<Ptr32<K5bArrayAllocator> (Ptr32<K5bIfaceArray>)>)self->vtable[9])(self);
    Ptr32<K5bIfaceArray> copy = ((Ptr32<Ptr32<K5bIfaceArray> (Ptr32<K5bArrayAllocator>, unsigned int, int)>)allocator->vtable[3])(allocator, bytes, 0);
    Ptr32<Ptr32<K5bIface>> source = self->items;
    Ptr32<Ptr32<K5bIface>> target = copy->items;
    unsigned int i;
    if (keep != 0) {
        unsigned int n = k5b_min((unsigned int)self->count, count);
        for (i = 0; i < n; i++) {
            Ptr32<K5bIface> item = source[i];
            target[i] = item;
            ((Ptr32<void (Ptr32<K5bIface>)>)item->vtable[3])(item);
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
// desc: w3d_k5b_handle_array_resized_801ee8c4: Appears to allocate a resized handle array (twin of 0x801ee4f8) through the owner's allocator, copy and retain up to the old count of entries when asked, and null the rest.


