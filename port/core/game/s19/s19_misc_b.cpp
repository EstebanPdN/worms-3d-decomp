#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_misc_b.c"
struct S19Obj;
struct S19VT { char pad0[20]; Ptr32<void (Ptr32<struct S19Obj>)> slot5; Ptr32<void (Ptr32<struct S19Obj>)> slot6; };
struct S19Obj { Ptr32<struct S19VT> vt; };
struct S19Holder { char pad0[96]; Ptr32<struct S19Obj> held; };

void s19_held_call5_8003864c(Ptr32<struct S19Holder> p) {
    if (p->held)
        p->held->vt->slot5(p->held);
}

void s19_held_call6_80038684(Ptr32<struct S19Holder> p) {
    if (p->held)
        p->held->vt->slot6(p->held);
}

struct S19Q { char pad0[100]; Ptr32<void> handle; };
extern int w3d_auto_80178d1c(Ptr32<void>);

int s19_handle_is_one_8003cf8c(Ptr32<struct S19Q> p) {
    return w3d_auto_80178d1c(p->handle) == 1;
}

struct S19W { char pad0[80]; Ptr32<void> handle; };
extern int w3d_auto_80178c48(Ptr32<void>);

int s19_handle_not_minus1_80049298(Ptr32<struct S19W> p) {
    if (w3d_auto_80178c48(p->handle) == -1)
        return 0;
    return 1;
}

struct S19X { char pad0[736]; Ptr32<void> handle; };
extern Ptr32<void> w3d_constructor_native_cast(Ptr32<void>);

int s19_handle_cast_query_80096564(Ptr32<struct S19X> p) {
    Ptr32<void> h = p->handle;
    int r;
    if (h)
        r = w3d_auto_80178d1c(w3d_constructor_native_cast(h));
    else
        r = 0;
    return r;
}

}
