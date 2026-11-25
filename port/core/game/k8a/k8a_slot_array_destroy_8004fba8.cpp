#include "w3d_ptr.h"
#line 1 "k8a_slot_array_destroy_8004fba8.cpp"
// Appears to be the destructor of a service that owns an array of held interfaces:
// it releases and clears every slot, clears a global pointer, destroys the array
// storage and calls the base destructor.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
struct K8aSlotArray
{
    unsigned int count;      // +44
    int pad;
    Ptr32<Ptr32<void>> data;             // +52
};
struct K8aService
{
    Ptr32<const void> vtable;
    char pad4[40];
    K8aSlotArray slots;      // +44
};
extern Ptr32<const void> w3d_vtable_8040eae0[];
extern Ptr32<void> w3d_global_804aaa04;
extern "C" void w3d_auto_80210abc(Ptr32<void> array, int flags);
extern "C" void w3d_service_destroy_801628ec(Ptr32<void> self, int flags);
static inline Ptr32<Ptr32<void>> k8a_begin(Ptr32<K8aSlotArray> a)
{
    return a->data;
}
static inline Ptr32<Ptr32<void>> k8a_end(Ptr32<K8aSlotArray> a)
{
    return a->data + a->count;
}
extern "C" void w3d_k8a_slot_array_destroy_8004fba8(Ptr32<K8aService> self, int flags)
{
    self->vtable = w3d_vtable_8040eae0;
    for (Ptr32<Ptr32<void>> p = k8a_begin(&self->slots); p != k8a_end(&self->slots); p++)
    {
        if (*p)
            VCALL(*p, void (*)(void *), 16)(*p);
        *p = 0;
    }
    w3d_global_804aaa04 = 0;
    w3d_auto_80210abc(&self->slots, 2);
    w3d_service_destroy_801628ec(self, flags);
}


