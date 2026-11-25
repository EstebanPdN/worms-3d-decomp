#include "w3d_ptr.h"
#line 1 "s19_hide_flag_800a4038.cpp"
struct S19Iface { Ptr32<Ptr32<void>> vtable; };
struct S19Handle {
    Ptr32<S19Iface> p;
    int unused;
    S19Handle() {}
    ~S19Handle() { if (p) ((Ptr32<void (Ptr32<S19Iface>)>)p->vtable[4])(p); }
};
extern "C" Ptr32<S19Iface> w3d_constructor_native_cast(Ptr32<void>);
extern "C" int w3d_auto_80178d1c(Ptr32<void>);
extern "C" void s19_visibility_hide_800a3bb4(Ptr32<void>);

extern "C" int s19_hide_when_flagged_800a4038(Ptr32<void> owner, Ptr32<void> target)
{
    S19Handle h;
    h.p = w3d_constructor_native_cast(owner);
    if (h.p)
        ((Ptr32<void (Ptr32<S19Iface>)>)h.p->vtable[3])(h.p);
    if (w3d_auto_80178d1c(h.p))
        s19_visibility_hide_800a3bb4(target);
    return 0;
}


