#include "w3d_ptr.h"
#line 1 "k10a_pool_owner_destroy_800c8630.cpp"
// Appears to be the destructor of a service-derived pool owner: it clears the
// global current-owner pointer if it names this object, releases the four
// shared held interfaces, and its members (held interfaces and two small
// arrays of them) are destroyed in reverse order before the service base.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
extern Ptr32<const void> w3d_vtable_8040fb38[];
extern Ptr32<void> w3d_owner_804b1794;
struct K10aHeld;
extern K10aHeld w3d_shared_8043eda4[4];
extern "C" void w3d_base_destroy_8015ff2c(Ptr32<void> self, int flags);

struct K10aHeld
{
    Ptr32<void> held;
    ~K10aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
    void replace(Ptr32<void> next)
    {
        if (held)
            VCALL(held, void (*)(void *), 16)(held);
        held = next;
    }
};

struct K10aObject
{
    Ptr32<const void> vtable;          // +0
    char pad4[24];
    K10aHeld a;                  // +28
    K10aHeld b;                  // +32
    K10aHeld c;                  // +36
    K10aHeld d;                  // +40
    K10aHeld pair[2];            // +44
    K10aHeld e;                  // +52
    char pad56[4];
    K10aHeld quad[4];            // +60
    char pad76[276];
    K10aHeld f;                  // +352
    K10aHeld g;                  // +356
    char pad360[12];
    K10aHeld h;                  // +372
    char pad376[4];
    K10aHeld i;                  // +380
    ~K10aObject()
    {
        if (w3d_owner_804b1794 == this)
            w3d_owner_804b1794 = 0;
        for (unsigned int n = 0; n <= 3; n++)
            w3d_shared_8043eda4[n].replace(0);
    }
};

extern "C" void w3d_k10a_pool_owner_destroy_800c8630(Ptr32<void> self, int flags)
{
    Ptr32<K10aObject> o = (Ptr32<K10aObject>)self;
    o->vtable = w3d_vtable_8040fb38;
    o->~K10aObject();
    w3d_base_destroy_8015ff2c(self, flags);
}


