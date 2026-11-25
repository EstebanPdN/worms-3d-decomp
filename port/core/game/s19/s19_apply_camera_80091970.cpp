#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_apply_camera_80091970.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>, Ptr32<void>, Ptr32<void>)> S19Apply;

void s19_apply_camera_80091970(Ptr32<void> self, Ptr32<void> other)
{
    if (FIELD(self, void *, 532) != other) {
        ((S19Apply)FIELD(self, void **, 2792)[8])(self, (Ptr32<char>)other + 240, (Ptr32<char>)other + 192);
        FIELD(self, void *, 532) = other;
        FIELD(self, int, 536) = 1;
    }
}

}
