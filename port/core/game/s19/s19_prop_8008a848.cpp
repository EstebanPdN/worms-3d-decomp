#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_prop_8008a848.c"
extern Ptr32<void> w3d_auto_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);
extern void FUN_8008a30c(Ptr32<void>, int, int, int);
struct S19Crate { char pad0[288]; int state; };

void s19_crate_showered_8008a848(Ptr32<struct S19Crate> p) {
    Ptr32<const char> name = "Crate.Showered";
    int value;
    w3d_auto_800fc1f0(&name, &value);
    if (p->state != 0 && value == 1)
        FUN_8008a30c(p, 0, 1, 0);
}

}
