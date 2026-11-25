#include "w3d_ptr.h"
#line 1 "s8deepctor_800e35fc.cpp"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern "C" {
int fn_80161014(Ptr32<void>);
Ptr32<void> fn_800de988(Ptr32<void>);
extern char w3d_vtable_80410058[];
extern char w3d_vtable_80410078[];
}
struct s8_Constructed_800e35fc { char observed[352]; s8_Constructed_800e35fc(); };
s8_Constructed_800e35fc::s8_Constructed_800e35fc()
{
    fn_80161014(this);
    fn_800de988((Ptr32<char>)this + 28);
    FIELD(this, void *, 256) = w3d_vtable_80410058;
    FIELD(this, void *, 0) = w3d_vtable_80410078;
    FIELD(this, int, 260) = 0;
    FIELD(this, int, 264) = 0;
    FIELD(this, int, 268) = 0;
    FIELD(this, int, 272) = 0;
    FIELD(this, int, 276) = 0;
    FIELD(this, int, 280) = 0;
    FIELD(this, int, 348) = 0;
}


