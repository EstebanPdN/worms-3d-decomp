/* Retains a looked-up resource while installing it on the receiving object. */
struct S5SelectIface;
struct S5SelectVtable { void (*reserved[3])(); void (*retain)(S5SelectIface *); void (*release)(S5SelectIface *); };
struct S5SelectIface { S5SelectVtable *vtable; };
struct S5SelectHandle { S5SelectIface *pointer; unsigned unknown; S5SelectHandle(S5SelectIface *); ~S5SelectHandle(); };
inline S5SelectHandle::S5SelectHandle(S5SelectIface *value) { pointer=value; if(pointer) pointer->vtable->retain(pointer); }
inline S5SelectHandle::~S5SelectHandle() { if(pointer) pointer->vtable->release(pointer); }
extern "C" {
extern unsigned char w3d_resource_name_804144f8[];
S5SelectIface *w3d_resource_lookup_8020b680(void *);
void w3d_resource_set_80174820(void *,S5SelectIface *);
int w3d_resource_select_800c9d98(void *receiver)
{
    S5SelectHandle handle(w3d_resource_lookup_8020b680(w3d_resource_name_804144f8));
    w3d_resource_set_80174820(receiver,handle.pointer);
    return 0;
}
}
