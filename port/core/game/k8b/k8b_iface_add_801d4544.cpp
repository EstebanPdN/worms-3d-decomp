#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_iface_add_801d4544.c"
struct K8bDesc { char pad0[20]; Ptr32<struct K8bDesc> parent; };
struct K8bIface { Ptr32<Ptr32<Ptr32<struct K8bDesc> (Ptr32<struct K8bIface>)>> vtable; };
struct K8bArray {
    Ptr32<Ptr32<void>> vtable;
    unsigned short references;
    char pad6[14];
    unsigned int capacity;
    unsigned int count;
    unsigned short locks;
    char pad30[2];
    Ptr32<struct K8bIface> data[1];
};
extern void w3d_k5b_iface_array_field_set_801ef2ec(Ptr32<char> object, int offset, int unused, Ptr32<struct K8bIface> item, int index);
extern void w3d_k5b_iface_array_field_append_801ef174(Ptr32<char> object, int offset, int unused, Ptr32<struct K8bIface> item);

static inline int k8b_derives(Ptr32<struct K8bDesc> desc, Ptr32<struct K8bDesc> key)
{
    while (desc != key) {
        Ptr32<struct K8bDesc> parent = desc->parent;
        if (desc == parent)
            return 0;
        desc = parent;
    }
    return 1;
}

int w3d_k8b_iface_add_801d4544(Ptr32<char> self, Ptr32<struct K8bIface> item)
{
    Ptr32<struct K8bArray> array = *(Ptr32<Ptr32<struct K8bArray>>)(self + 28);
    unsigned int count = array->count;
    Ptr32<Ptr32<struct K8bIface>> cursor = array->data;
    unsigned int i = 0;
    Ptr32<struct K8bDesc> key = item->vtable[5](item);
    (*(Ptr32<Ptr32<struct K8bArray>>)(self + 28))->locks++;
    for (; i < count; i++) {
        Ptr32<struct K8bIface> entry = *cursor++;
        if (k8b_derives(entry->vtable[5](entry), key)) {
            w3d_k5b_iface_array_field_set_801ef2ec(self, 28, 3, item, i);
            return 1;
        }
    }
    w3d_k5b_iface_array_field_append_801ef174(self, 28, 3, item);
    return 0;
}

}
