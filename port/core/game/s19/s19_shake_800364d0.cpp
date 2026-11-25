#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_shake_800364d0.c"
extern Ptr32<void> FUN_8003671c(Ptr32<void>);
extern void w3d_auto_80036abc(Ptr32<void>, int, int, float);
extern int s8_property_write_800fc43c(Ptr32<void> name, int value);
struct S19Cam { char pad0[16]; int handle; };

void s19_update_shake_800364d0(Ptr32<struct S19Cam> self, int arg, float t)
{
    struct { Ptr32<const char> name; int extra[2]; } k;
    self->handle = self->handle + 1;
    w3d_auto_80036abc(FUN_8003671c(self), self->handle, arg, t);
    k.name = "Camera.Shake.Handle";
    s8_property_write_800fc43c(&k.name, self->handle);
}

}
