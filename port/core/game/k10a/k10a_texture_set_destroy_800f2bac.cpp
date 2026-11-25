#include "w3d_ptr.h"
#line 1 "k10a_texture_set_destroy_800f2bac.cpp"
// Appears to be the destructor of a service-derived object that owns a trailing
// member object, a string, a 200-slot array of held interfaces plus one more, three storage
// blocks and three further held interfaces. The member destructors are real inline
// destructors; the explicit destructor call reproduces the compiler's
// reverse-order member cleanup, then the service base is destroyed.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
extern Ptr32<const void> w3d_vtable_804103e8[];
extern "C" void w3d_auto_8026c860(Ptr32<void> member, int flags);
extern "C" void w3d_string_base_finish(Ptr32<void> string);
extern "C" void w3d_string_release(Ptr32<void> string);
extern "C" void w3d_handle_storage_release(Ptr32<void> storage);
extern "C" void w3d_service_destroy_801628ec(Ptr32<void> self, int flags);

struct K10aHeld
{
    Ptr32<void> held;
    ~K10aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};

struct K10aStorage
{
    Ptr32<void> block;
    char pad4[8];
    ~K10aStorage() { if (block) w3d_handle_storage_release(block); }
};

struct K10aString
{
    Ptr32<char> text;
    unsigned int storage;
    ~K10aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};

struct K10aTail
{
    char pad0[4];
    ~K10aTail() { w3d_auto_8026c860(this, 2); }
};

struct K10aObject
{
    Ptr32<const void> vtable;          // +0
    char pad4[24];
    K10aHeld first;              // +28
    K10aHeld second;             // +32
    K10aHeld third;              // +36
    char pad40[4];
    K10aStorage storageA;        // +44
    K10aStorage storageB;        // +56
    K10aStorage storageC;        // +68
    char pad80[8];
    K10aHeld slots[200];         // +88
    K10aHeld top;                // +888
    K10aString name;             // +892
    char pad900[2172];
    K10aTail tail;               // +3072
    ~K10aObject() {}
};

extern "C" void w3d_k10a_texture_set_destroy_800f2bac(Ptr32<void> self, int flags)
{
    Ptr32<K10aObject> o = (Ptr32<K10aObject>)self;
    o->vtable = w3d_vtable_804103e8;
    o->~K10aObject();
    w3d_service_destroy_801628ec(self, flags);
}


