#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_update_800a8ad8.c"
extern int w3d_service_optional_context_query(Ptr32<void>);
extern void FUN_800a8b38(Ptr32<void>);
extern void FUN_800a8d00(Ptr32<void>, float, Ptr32<void>);

void s19_update_or_idle_800a8ad8(Ptr32<void> self, float t, int arg)
{
    if (w3d_service_optional_context_query(self))
        FUN_800a8b38(self);
    else
        FUN_800a8d00(self, t, w3d::G(arg));
}

}
