#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_locator_refresh_800a4de4.c"
struct S19Frozen { char pad0[32]; Ptr32<void> owner; char pad36[4]; Ptr32<void> locator; };
extern void w3d_auto_800a4da4(Ptr32<void>);
extern Ptr32<void> w3d_empty_80343584(Ptr32<void>);
extern Ptr32<void> FUN_800e5cf0(Ptr32<void>, Ptr32<const char>, Ptr32<const char>, int, int);

void s19_locator_refresh_800a4de4(Ptr32<struct S19Frozen> p) {
    if (p->locator)
        w3d_auto_800a4da4((Ptr32<void>)p);
    p->locator = FUN_800e5cf0(w3d_empty_80343584(p->owner), "IceGasLocator", "UtilityFreeze", -1, 0);
}

}
