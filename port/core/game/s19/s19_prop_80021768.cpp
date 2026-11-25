#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_prop_80021768.c"
struct S19Sel { int pad0; int f4, f8, f12; Ptr32<void> vt; int f20; };
extern unsigned char lbl_8040dd08[];
extern Ptr32<void> w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>, Ptr32<int>);
Ptr32<struct S19Sel> s19_active_worm_ctor_80021768(Ptr32<struct S19Sel> p) {
    Ptr32<const char> name;
    p->vt = (Ptr32<void>)lbl_8040dd08;
    p->f4 = 0;
    p->f8 = 0;
    p->f20 = 0;
    p->f12 = 4;
    name = "ActiveWormIndex";
    w3d_constructor_lookup_name(&name, &p->f20);
    return p;
}

}
