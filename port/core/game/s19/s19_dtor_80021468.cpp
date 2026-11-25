#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_dtor_80021468.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern unsigned char lbl_8040dd88[];
extern void w3d_auto_80015264(Ptr32<void>);
void s19_dtor_80021468(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 16) = lbl_8040dd88;
    FIELD(self, void *, 12) = 0;
    if (flags & 1)
        w3d_auto_80015264(self);
}

}
