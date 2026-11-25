// Appears to be the destructor of a name grid: 768 name strings, 768 held interfaces,
// a storage block and five more held interfaces, followed by the base destructor.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct K8aHeld
{
    void *held;
    ~K8aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};
extern "C" void w3d_string_base_finish(void *string);
extern "C" void w3d_string_release(void *string);
extern "C" void w3d_handle_storage_release(void *storage);
extern "C" void w3d_base_destroy_8015ff2c(void *self, int flags);
struct K8aString
{
    unsigned int word;
    ~K8aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K8aStorage
{
    void *storage;
    ~K8aStorage() { if (storage) w3d_handle_storage_release(storage); }
};
extern const void *w3d_vtable_8040f7d8[];
struct K8aGrid
{
    const void *vtable;      // +0
    char pad4[24];
    K8aHeld first;           // +28
    K8aHeld second;          // +32
    K8aHeld third;           // +36
    int pad40;
    K8aHeld fourth;          // +44
    int pad48;
    K8aStorage storage;      // +52
    char pad56[8];
    K8aString names[768];    // +64
    K8aHeld slots[768];      // +3136
    K8aHeld top;             // +6208
    ~K8aGrid() {}
};
extern "C" void w3d_k8a_name_grid_destroy_800b9598(void *self, int flags)
{
    K8aGrid *g = (K8aGrid *)self;
    g->vtable = w3d_vtable_8040f7d8;
    g->~K8aGrid();
    w3d_base_destroy_8015ff2c(self, flags);
}
