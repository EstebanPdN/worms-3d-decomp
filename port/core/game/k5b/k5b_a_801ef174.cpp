#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_801ef174.c"
struct K5bIface { Ptr32<Ptr32<void>> vtable; };
struct K5bArray {
    Ptr32<Ptr32<void>> vtable;
    unsigned short references;
    char pad6[14];
    unsigned int capacity;
    unsigned int count;
    unsigned short locks;
    char pad30[2];
    unsigned char data[1];
};
extern Ptr32<void> w3d_k5b_array_ref_lock_801ef048(Ptr32<Ptr32<struct K5bArray>> ref, unsigned int count, unsigned int element_size,
    unsigned int flags);
static inline Ptr32<void> k5b_array_lock(Ptr32<Ptr32<struct K5bArray>> ref, unsigned int count, unsigned int element_size,
    unsigned int flags)
{
    Ptr32<struct K5bArray> array = *ref;
    if (array->references == 1 && count == array->count) {
        ++array->locks;
        return array->data;
    }
    return w3d_k5b_array_ref_lock_801ef048(ref, count, element_size, flags);
}
void w3d_k5b_iface_array_field_append_801ef174(Ptr32<char> object, int offset, int unused, Ptr32<struct K5bIface> item)
{
    Ptr32<Ptr32<struct K5bArray>> ref = (Ptr32<Ptr32<struct K5bArray>>)(object + offset);
    unsigned int index = (*ref)->count;
    Ptr32<Ptr32<struct K5bIface>> items = k5b_array_lock(ref, index + 1, 4, 2);
    items[index] = item;
    ((Ptr32<void (Ptr32<struct K5bIface>)>)item->vtable[3])(item);
}
// desc: w3d_k5b_iface_array_field_append_801ef174: Appears to append and retain an interface in the array referenced at the given field offset, growing it through 0x801ef048 unless solely owned and sized.

}
