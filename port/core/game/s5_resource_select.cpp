#include "w3d_ptr.h"
#line 1 "s5_resource_select.cpp"
/* Retains a looked-up resource while installing it on the receiving object. */
struct S5SelectIface;
struct S5SelectVtable { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<S5SelectIface>)> retain; Ptr32<void (Ptr32<S5SelectIface>)> release; };
struct S5SelectIface { Ptr32<S5SelectVtable> vtable; };
struct S5SelectHandle { Ptr32<S5SelectIface> pointer; unsigned unknown; template <class W3dU> S5SelectHandle(Ptr32<W3dU> w3d_p) : S5SelectHandle((S5SelectIface *)w3d_p.get()) {}
 S5SelectHandle(S5SelectIface *); ~S5SelectHandle(); };
inline S5SelectHandle::S5SelectHandle(S5SelectIface *value) { pointer=value; if(pointer) pointer->vtable->retain(pointer); }
inline S5SelectHandle::~S5SelectHandle() { if(pointer) pointer->vtable->release(pointer); }
extern "C" {
extern unsigned char w3d_resource_name_804144f8[];
Ptr32<S5SelectIface> w3d_resource_lookup_8020b680(Ptr32<void>);
void w3d_resource_set_80174820(Ptr32<void>,Ptr32<S5SelectIface>);
int w3d_resource_select_800c9d98(Ptr32<void> receiver)
{
    S5SelectHandle handle(w3d_resource_lookup_8020b680(w3d_resource_name_804144f8));
    w3d_resource_set_80174820(receiver,handle.pointer);
    return 0;
}
}


