#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_prop_80021958.c"
extern void w3d_auto_800fc230(Ptr32<Ptr32<const char>>, Ptr32<unsigned int>);
struct S19Task { char pad0[4]; int done; char pad8[12]; unsigned limit; };

void s19_check_bullet_count_80021958(Ptr32<struct S19Task> p) {
    unsigned count = 0;
    Ptr32<const char> name = "AI.BulletCount";
    w3d_auto_800fc230(&name, &count);
    if (count > p->limit)
        p->done = 1;
}

}
