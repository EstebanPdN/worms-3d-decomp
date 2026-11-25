#include "w3d_ptr.h"
#line 1 "k5b_a_801eec98.cpp"
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
    char pad4[20];
    unsigned int count;
    char pad28[4];
    K5bString items[1];
};
template <class T> inline const T &k5b_min(const T &a, const T &b)
{
    return b < a ? b : a;
}
extern "C" Ptr32<K5bStringArray> w3d_k5b_string_array_resized_801eec98(Ptr32<K5bStringArray> self, unsigned int count,
    unsigned int element_size, int keep)
{
    unsigned int bytes = count * element_size;
    Ptr32<K5bArrayAllocator> allocator = ((Ptr32<Ptr32<K5bArrayAllocator> (Ptr32<K5bStringArray>)>)self->vtable[9])(self);
    Ptr32<K5bStringArray> copy = ((Ptr32<Ptr32<K5bStringArray> (Ptr32<K5bArrayAllocator>, unsigned int, int)>)allocator->vtable[3])(allocator, bytes, 0);
    Ptr32<K5bString> source = self->items;
    Ptr32<K5bString> target = copy->items;
    unsigned int i;
    if (keep != 0) {
        unsigned int n = k5b_min((unsigned int)self->count, count);
        for (i = 0; i < n; i++)
            new (&target[i]) K5bString(source[i]);
        for (; i < count; i++)
            new (&target[i]) K5bString;
    } else {
        unsigned int j;
        for (j = 0; j < count; j++)
            new (&target[j]) K5bString;
    }
    copy->count = count;
    return copy;
}
// desc: w3d_k5b_string_array_resized_801eec98: Appears to allocate a resized shared-string array through the owner's allocator, copy-construct up to the old count of strings when asked and default-construct the rest.


