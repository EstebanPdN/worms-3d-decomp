#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_camera_ctor_800520f4.c"
struct S19Camera { char pad0[72]; Ptr32<void> vt; char pad76[132]; int f208; };
extern Ptr32<void> FUN_800d2dec(Ptr32<struct S19Camera>, Ptr32<void>, Ptr32<const char>, Ptr32<void>);
extern void w3d_auto_800d31d8(Ptr32<struct S19Camera>, Ptr32<const char>);
extern unsigned char lbl_8040eb90[];

Ptr32<struct S19Camera> s19_camera_ctor_800520f4(Ptr32<struct S19Camera> p, Ptr32<void> a, Ptr32<void> b) {
    FUN_800d2dec(p, a, "Shoulder", b);
    p->vt = (Ptr32<void>)lbl_8040eb90;
    p->f208 = 0;
    w3d_auto_800d31d8(p, "ShoulderCamera");
    return p;
}

}
