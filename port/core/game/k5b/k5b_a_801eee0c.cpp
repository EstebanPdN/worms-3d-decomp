#include "w3d_ptr.h"
#line 1 "k5b_a_801eee0c.cpp"
struct K5bArrayAllocator { Ptr32<Ptr32<void>> vtable; };
struct K5bString;
extern "C" void w3d_string_base_init(Ptr32<K5bString> string);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<K5bString> string);
extern "C" Ptr32<void> w3d_string_default(Ptr32<K5bString> string);
struct K5bString {
    Ptr32<char> text;
    K5bString() { w3d_string_default(this); }
    K5bString(const K5bString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
};
inline void *operator new(__SIZE_TYPE__, void *place) throw() { return place; }
struct K5bStringArray {
    Ptr32<Ptr32<void>> vtable;
    unsigned short references;
    char pad6[14];
    unsigned int capacity;
    unsigned int count;
    char pad28[4];
    K5bString items[1];
};
template <class T> inline const T &k5b_min(const T &a, const T &b)
{
    return b < a ? b : a;
}
extern "C" Ptr32<K5bStringArray> w3d_h1_result_then_finish_801ee410(Ptr32<K5bStringArray> self, unsigned int count,
    unsigned int element_size, int keep);
extern "C" Ptr32<K5bStringArray> w3d_k5b_string_array_resize_owned_801eee0c(Ptr32<K5bStringArray> self, unsigned int count,
    unsigned int element_size, int keep)
{
    unsigned int bytes;
    Ptr32<K5bArrayAllocator> allocator;
    Ptr32<K5bStringArray> copy;
    Ptr32<K5bString> source;
    Ptr32<K5bString> target;
    unsigned int n;
    unsigned int i;
    if (keep == 0 || self->references != 1)
        return w3d_h1_result_then_finish_801ee410(self, count, element_size, keep);
    bytes = count * element_size;
    if (self->capacity >= bytes)
        return ((Ptr32<Ptr32<K5bStringArray> (Ptr32<K5bStringArray>, unsigned int, int)>)self->vtable[8])(self, count, 0);
    allocator = ((Ptr32<Ptr32<K5bArrayAllocator> (Ptr32<K5bStringArray>)>)self->vtable[9])(self);
    copy = ((Ptr32<Ptr32<K5bStringArray> (Ptr32<K5bArrayAllocator>, unsigned int, int)>)allocator->vtable[3])(allocator, bytes, 0);
    source = self->items;
    target = copy->items;
    n = k5b_min((unsigned int)self->count, count);
    for (i = 0; i < n; i++)
        new (&target[i]) K5bString(source[i]);
    for (; i < count; i++)
        new (&target[i]) K5bString;
    copy->count = count;
    ((Ptr32<void (Ptr32<K5bStringArray>)>)self->vtable[4])(self);
    return copy;
}
// desc: w3d_k5b_string_array_resize_owned_801eee0c: Appears to resize a solely owned shared-string array: in place when capacity allows, else copy-construct strings into a new allocation, default the rest and release the old one.


