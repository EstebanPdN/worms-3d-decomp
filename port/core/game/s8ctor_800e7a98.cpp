#include "w3d_ptr.h"
#line 1 "s8ctor_800e7a98.cpp"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern "C" {
int fn_801628b0(Ptr32<void>);
extern char w3d_vtable_80410170[];
}
struct s8_Constructed_800e7a98 { char observed[40]; s8_Constructed_800e7a98(); };
s8_Constructed_800e7a98::s8_Constructed_800e7a98()
{
    fn_801628b0(this);
    FIELD(this, void *, 0) = w3d_vtable_80410170;
    FIELD(this, int, 28) = 0;
    FIELD(this, int, 32) = 0;
    FIELD(this, int, 36) = 0;
}


