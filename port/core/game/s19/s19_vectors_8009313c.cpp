#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_vectors_8009313c.c"
struct S19V3 { float x, y, z; };
struct S19Obj { char pad0[140]; struct S19V3 a; char pad152[12]; struct S19V3 b; char pad176[32]; int h208; int h212; };
extern Ptr32<struct S19V3> w3d_auto_80178ec4(Ptr32<void>);

void s19_load_vectors_8009313c(Ptr32<struct S19Obj> self)
{
    self->a = *w3d_auto_80178ec4(w3d::G(self->h208));
    self->b = *w3d_auto_80178ec4(w3d::G(self->h212));
}

}
