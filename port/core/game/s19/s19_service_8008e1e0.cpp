#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_service_8008e1e0.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern int FUN_80164514(Ptr32<void>, Ptr32<void>, int);
extern unsigned char lbl_80410358[];
extern Ptr32<void> lbl_804b178c;
void s19_register_service_8008e1e0(Ptr32<void> self)
{
    Ptr32<void> s = w3d_s10_service_forward_8020b680(lbl_80410358);
    FUN_80164514(lbl_804b178c, s, FIELD(self, int, 20));
}

}
