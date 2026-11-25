#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_no_target_800358b4.c"
struct S19Obj;
struct S19ObjVT { char pad0[20]; Ptr32<void (Ptr32<struct S19Obj>)> slot5; };
struct S19Obj { Ptr32<struct S19ObjVT> vt; };
struct S19Lookup;
struct S19LookupVT { char pad0[92]; Ptr32<void (Ptr32<struct S19Lookup>, Ptr32<const char>, Ptr32<Ptr32<struct S19Obj>>)> find; };
struct S19Lookup { Ptr32<struct S19LookupVT> vt; };
struct S19Ctx { char pad0[108]; Ptr32<struct S19Lookup> lookup; };
struct S19Holder { char pad0[860]; Ptr32<struct S19Obj> target; };
extern Ptr32<struct S19Ctx> lbl_804b1788;

void s19_no_target_800358b4(Ptr32<struct S19Holder> p) {
    Ptr32<struct S19Lookup> l = lbl_804b1788->lookup;
    if (l) {
        l->vt->find(l, "NoTargetAquired", &p->target);
        p->target->vt->slot5(p->target);
    }
}

}
