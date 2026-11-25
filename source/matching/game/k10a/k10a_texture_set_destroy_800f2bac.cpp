// Appears to be the destructor of a service-derived object that owns a trailing
// member object, a string, a 200-slot array of held interfaces plus one more, three storage
// blocks and three further held interfaces. The member destructors are real inline
// destructors; the explicit destructor call reproduces the compiler's
// reverse-order member cleanup, then the service base is destroyed.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
extern const void *w3d_vtable_804103e8[];
extern "C" void w3d_auto_8026c860(void *member, int flags);
extern "C" void w3d_string_base_finish(void *string);
extern "C" void w3d_string_release(void *string);
extern "C" void w3d_handle_storage_release(void *storage);
extern "C" void w3d_service_destroy_801628ec(void *self, int flags);

struct K10aHeld
{
    void *held;
    ~K10aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};

struct K10aStorage
{
    void *block;
    char pad4[8];
    ~K10aStorage() { if (block) w3d_handle_storage_release(block); }
};

struct K10aString
{
    char *text;
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
    const void *vtable;          // +0
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

extern "C" void w3d_k10a_texture_set_destroy_800f2bac(void *self, int flags)
{
    K10aObject *o = (K10aObject *)self;
    o->vtable = w3d_vtable_804103e8;
    o->~K10aObject();
    w3d_service_destroy_801628ec(self, flags);
}
