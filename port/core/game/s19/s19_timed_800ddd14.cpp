#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_timed_800ddd14.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>, float, int, int, int)> S19Fn;

void s19_start_timed_virtual_800ddd14(Ptr32<void> self, unsigned t, int a, int b, int c)
{
    ((S19Fn)FIELD(self, void **, 112)[8])(self, (float)(t - FIELD(self, unsigned, 100)), a, b, c);
}

}
