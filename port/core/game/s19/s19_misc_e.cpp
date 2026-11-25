#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_misc_e.c"
struct S19Svc;
struct S19SvcVT { char pad0[100]; Ptr32<void (Ptr32<struct S19Svc>, Ptr32<void>, int)> queue; };
struct S19Svc { Ptr32<struct S19SvcVT> vt; };
struct S19Ctx { char pad0[108]; Ptr32<struct S19Svc> svc; };
struct S19Slot { int handle; };
struct S19Pair { char pad0[28]; struct S19Slot a; struct S19Slot b; };
extern Ptr32<struct S19Ctx> lbl_804b1788;
static inline void s19_q(Ptr32<struct S19Slot> s) {
    if (s->handle)
        lbl_804b1788->svc->vt->queue(lbl_804b1788->svc, s, 1000);
}
void s19_notify_two_8002a040(Ptr32<struct S19Pair> p) {
    s19_q(&p->a);
    s19_q(&p->b);
}

}
