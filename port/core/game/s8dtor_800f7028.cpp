#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8dtor_800f7028.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_80410428[];
void fn_8002a978(Ptr32<void>, Ptr32<void>);

void s8_destroy_800f7028(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80410428;
    fn_8002a978(self, (Ptr32<void>)w3d::G(flags));
}

}
