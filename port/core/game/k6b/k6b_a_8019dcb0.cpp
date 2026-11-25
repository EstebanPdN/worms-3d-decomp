#include "w3d_ptr.h"
#line 1 "k6b_a_8019dcb0.cpp"
struct K6bIface { Ptr32<Ptr32<void>> vtable; };
struct K6bIfaceRef {
    Ptr32<K6bIface> p;
    K6bIfaceRef() : p(0) {}
    ~K6bIfaceRef() { if (p != 0) ((Ptr32<void (Ptr32<K6bIface>)>)p->vtable[4])(p); }
};
struct K6bObjectFactory { Ptr32<Ptr32<void>> vtable; };
struct K6bScriptHost { Ptr32<Ptr32<void>> vtable; };
extern "C" Ptr32<K6bObjectFactory> w3d_auto_8020b648(void);
extern "C" char lbl_8040ebd8[];
extern "C" Ptr32<K6bIface> w3d_k6b_script_host_create_object_8019dcb0(Ptr32<K6bScriptHost> self, Ptr32<const char> name)
{
    K6bIfaceRef object;
    Ptr32<K6bObjectFactory> factory = w3d_auto_8020b648();
    if (((Ptr32<int (Ptr32<K6bObjectFactory>, Ptr32<const char>, Ptr32<void>, Ptr32<Ptr32<K6bIface>>)>)factory->vtable[22])(factory, name, lbl_8040ebd8, &object.p) < 0
        || ((Ptr32<int (Ptr32<K6bScriptHost>, Ptr32<K6bIface>)>)self->vtable[7])(self, object.p) < 0)
        return 0;
    return object.p;
}
// desc: w3d_k6b_script_host_create_object_8019dcb0: Appears to create the named object through slot 22 of the 0x8020b648 factory with interface 0x8040ebd8, register it through slot 7 and return it.


