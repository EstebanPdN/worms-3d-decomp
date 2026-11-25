#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_ctor_80015c6c.c"
struct S19V3 { float x, y, z; };
struct S19Marker { char pad0[4]; float scale; int a; int b; int c; struct S19V3 pos; int e; struct S19V3 target; };
extern Ptr32<struct S19V3> w3d_auto_80015588(int);

Ptr32<struct S19Marker> s19_marker_ctor_80015c6c(Ptr32<struct S19Marker> p, int a, int b, int c, Ptr32<struct S19V3> pos, int e)
{
    p->scale = 1.0f;
    p->a = a;
    p->b = b;
    p->target = *w3d_auto_80015588(b);
    p->c = c;
    p->pos = *pos;
    p->e = e;
    return p;
}

}
