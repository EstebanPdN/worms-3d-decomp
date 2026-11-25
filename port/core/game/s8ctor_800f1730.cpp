#include "w3d_ptr.h"
#line 1 "s8ctor_800f1730.cpp"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern "C" {
int fn_8015fef0(Ptr32<void>);
extern char w3d_vtable_80410368[];
}
struct s8_Constructed_800f1730 { char observed[48]; s8_Constructed_800f1730(); };
s8_Constructed_800f1730::s8_Constructed_800f1730()
{
    fn_8015fef0(this);
    FIELD(this, void *, 0) = w3d_vtable_80410368;
    FIELD(this, int, 44) = 0;
    FIELD(this, int, 28) = 0;
    FIELD(this, int, 32) = 0;
}


