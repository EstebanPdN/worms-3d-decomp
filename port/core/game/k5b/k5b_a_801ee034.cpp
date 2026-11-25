#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_801ee034.c"
struct K5bClass { char pad[20]; Ptr32<struct K5bClass> parent; };
struct K5bComponent { Ptr32<Ptr32<void>> vtable; };
struct K5bComponentSet {
    char pad[24];
    unsigned int count;
    char pad28[4];
    Ptr32<struct K5bComponent> items[1];
};
static inline int k5b_class_derives(Ptr32<struct K5bClass> cls, Ptr32<struct K5bClass> base)
{
    while (cls != base) {
        if (cls == cls->parent)
            return 0;
        cls = cls->parent;
    }
    return 1;
}
Ptr32<struct K5bComponent> w3d_k5b_component_set_find_class_801ee034(Ptr32<struct K5bComponentSet> self, Ptr32<struct K5bClass> base)
{
    unsigned int i;
    Ptr32<Ptr32<struct K5bComponent>> items = self->items;
    for (i = 0; i < self->count; i++) {
        Ptr32<struct K5bClass> cls = ((Ptr32<Ptr32<struct K5bClass> (Ptr32<struct K5bComponent>)>)items[i]->vtable[5])(items[i]);
        if (k5b_class_derives(cls, base))
            return items[i];
    }
    return 0;
}
// desc: w3d_k5b_component_set_find_class_801ee034: Appears to return the first component in the inline array at +32 reports a class (virtual slot 5) derived from the given class, or null.

}
