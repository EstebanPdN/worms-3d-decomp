#include "w3d_ptr.h"
#line 1 "k8a_pair_string_destroy_800b916c.cpp"
// Appears to be the deleting destructor of a record that holds two interfaces and a
// string: the body releases and clears both interfaces, then the members are destroyed.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
struct K8aHeld
{
    Ptr32<void> held;
    ~K8aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};
extern "C" void w3d_string_base_finish(Ptr32<void> string);
extern "C" void w3d_string_release(Ptr32<void> string);
struct K8aString
{
    unsigned int word[2];
    ~K8aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern unsigned int w3d_heap_804adde4;
extern "C" void w3d_heap_release(Ptr32<void> heap, Ptr32<void> object);
struct K8aRecord
{
    int pad0;
    K8aHeld first;           // +4
    K8aHeld second;          // +8
    int pad12;
    K8aString name;          // +16
    ~K8aRecord() {}
};
extern "C" void w3d_k8a_pair_string_destroy_800b916c(Ptr32<K8aRecord> self, int flags)
{
    Ptr32<void> none = 0;
    if (self->first.held)
        VCALL(self->first.held, void (*)(void *), 16)(self->first.held);
    self->first.held = none;
    if (self->second.held)
        VCALL(self->second.held, void (*)(void *), 16)(self->second.held);
    self->second.held = none;
    self->~K8aRecord();
    if (flags & 1)
        w3d_heap_release(&w3d_heap_804adde4, self);
}


