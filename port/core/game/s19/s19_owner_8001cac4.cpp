#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_owner_8001cac4.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>, int)> S19Fn2;
extern void FUN_80004394(Ptr32<void>);
extern void FUN_80342a7c(Ptr32<void>);
extern void w3d_vector_free_80342b60(Ptr32<void>);
extern void w3d_auto_800200f4(Ptr32<void>);

void s19_release_owner_8001cac4(Ptr32<void> self)
{
    if (FIELD(self, void *, 68)) {
        FUN_80004394(FIELD(self, void *, 68));
        if (FIELD(self, void *, 68)) {
            ((S19Fn2)FIELD(FIELD(self, void *, 68), void **, 32872)[2])(FIELD(self, void *, 68), 3);
        }
    }
    FIELD(self, void *, 68) = 0;
    FUN_80342a7c((Ptr32<char>)self + 88);
    w3d_vector_free_80342b60((Ptr32<char>)self + 32);
    w3d_auto_800200f4(self);
}

}
