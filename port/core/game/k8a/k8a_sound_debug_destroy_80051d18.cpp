#include "w3d_ptr.h"
#line 1 "k8a_sound_debug_destroy_80051d18.cpp"
// Appears to be the destructor of the sound-debug service: it releases the output
// channel, clears the global instance pointer, releases three held interfaces and a
// five-slot interface array, then calls the base destructor.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
struct K8aHeld
{
    Ptr32<void> held;
    ~K8aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};
extern Ptr32<const void> w3d_vtable_8040eb60[];
extern unsigned int w3d_output_804aaa14;
extern Ptr32<void> w3d_sound_debug_804aaa10;
extern "C" void w3d_auto_802cc58c(unsigned int output);
extern "C" void w3d_service_destroy_801628ec(Ptr32<void> self, int flags);
struct K8aObject
{
    Ptr32<const void> vtable;      // +0
    char pad4[28];
    K8aHeld slots[5];        // +32
    char pad52[20];
    K8aHeld fourth;          // +72
    K8aHeld fifth;           // +76
    K8aHeld sixth;           // +80
    ~K8aObject() {}
};
extern "C" void w3d_k8a_sound_debug_destroy_80051d18(Ptr32<void> self, int flags)
{
    Ptr32<K8aObject> o = (Ptr32<K8aObject>)self;
    o->vtable = w3d_vtable_8040eb60;
    w3d_auto_802cc58c(w3d_output_804aaa14);
    w3d_sound_debug_804aaa10 = 0;
    o->~K8aObject();
    w3d_service_destroy_801628ec(self, flags);
}


