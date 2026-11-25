#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_dtor_80017304.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>, int)> S19Fn2;
extern unsigned char lbl_8040d990[];
extern void w3d_path_cost_destroy(Ptr32<void>, int);
extern void w3d_auto_80015264(Ptr32<void>);

void s19_path_owner_destroy_80017304(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 12) = lbl_8040d990;
    if (FIELD(self, void *, 32)) {
        ((S19Fn2)FIELD(FIELD(self, void *, 32), void **, 16)[2])(FIELD(self, void *, 32), 3);
    }
    FIELD(self, void *, 32) = 0;
    w3d_path_cost_destroy(self, 0);
    if (flags & 1)
        w3d_auto_80015264(self);
}

}
