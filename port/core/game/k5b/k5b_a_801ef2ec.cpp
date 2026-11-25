#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_801ef2ec.c"
struct K5bIface { Ptr32<Ptr32<void>> vtable; };
struct K5bArray {
    Ptr32<Ptr32<void>> vtable;
    unsigned short references;
    char pad6[14];
    unsigned int capacity;
    unsigned int count;
    unsigned short locks;
    char pad30[2];
    Ptr32<struct K5bIface> items[1];
};
extern Ptr32<void> w3d_k5b_array_ref_lock_801ef048(Ptr32<Ptr32<struct K5bArray>> ref, unsigned int count, unsigned int element_size,
    unsigned int flags);
static inline Ptr32<Ptr32<struct K5bArray>> k5b_field_array(Ptr32<char> object, int offset)
{
    return (Ptr32<Ptr32<struct K5bArray>>)(object + offset);
}
void w3d_k5b_iface_array_field_set_801ef2ec(Ptr32<char> object, int offset, int unused, Ptr32<struct K5bIface> item,
    int index)
{
    Ptr32<struct K5bArray> array = *(Ptr32<Ptr32<struct K5bArray>>)(offset + object);
    Ptr32<Ptr32<struct K5bIface>> items;
    Ptr32<struct K5bIface> old;
    if (array->references != 1) {
        w3d_k5b_array_ref_lock_801ef048(k5b_field_array(object, offset), array->count, 4, 2);
        array = *k5b_field_array(object, offset);
    }
    items = array->items;
    old = items[index];
    items[index] = item;
    ((Ptr32<void (Ptr32<struct K5bIface>)>)item->vtable[3])(item);
    ((Ptr32<void (Ptr32<struct K5bIface>)>)old->vtable[4])(old);
}
// desc: w3d_k5b_iface_array_field_set_801ef2ec: Appears to make the array referenced at the field offset unique, then replace the interface at the index, retaining the new one and releasing the old one.

}
