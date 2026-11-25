// Appears to be the destructor of an owner service: it releases its owner link and
// global pointer, then its seven held interfaces, a storage block, an entry table and
// another storage block, and calls the base destructor.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct K8aHeld
{
    void *held;
    ~K8aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};
extern "C" void w3d_handle_storage_release(void *storage);
struct K8aStorage
{
    void *storage;
    ~K8aStorage() { if (storage) w3d_handle_storage_release(storage); }
};
struct K8aEntry
{
    char data[32];
    ~K8aEntry() {}
};
struct K8aEntryVector
{
    K8aEntry *begin;
    K8aEntry *end;
    int pad8;
    K8aEntry *capacity;
    ~K8aEntryVector()
    {
        for (K8aEntry *p = begin; p != end; ++p)
            p->~K8aEntry();
        if (begin)
            w3d_handle_storage_release(begin);
    }
};
extern const void *w3d_vtable_8040dac8[];
extern void *w3d_global_804b1758;
extern "C" void s19_release_owner_8001cac4(void *self);
extern "C" void w3d_service_destroy_801628ec(void *self, int flags);
struct K8aOwner
{
    const void *vtable;      // +0
    char pad4[28];
    K8aStorage first;        // +32
    char pad36[36];
    K8aEntryVector entries;  // +72
    K8aStorage second;       // +88
    char pad92[60];
    K8aHeld held152;
    K8aHeld held156;
    K8aHeld held160;
    K8aHeld held164;
    K8aHeld held168;
    K8aHeld held172;
    K8aHeld held176;
    ~K8aOwner() {}
};
extern "C" void w3d_k8a_owner_service_destroy_8001c960(void *self, int flags)
{
    K8aOwner *o = (K8aOwner *)self;
    o->vtable = w3d_vtable_8040dac8;
    s19_release_owner_8001cac4(self);
    w3d_global_804b1758 = 0;
    o->~K8aOwner();
    w3d_service_destroy_801628ec(self, flags);
}
