#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_send_800a7d18.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
struct S19Ctx { char pad0[52]; int tick; };
extern Ptr32<void> FUN_801613f0(Ptr32<void>, int);
extern Ptr32<void> w3d_value_range_init_80069a30(Ptr32<void>, int, float, float);
extern int w3d_message_post_current(Ptr32<void>);
extern Ptr32<struct S19Ctx> w3d_engine_get_context(void);
extern void FUN_800fb1b8(int, int, float, float);
extern Ptr32<void> lbl_804b1754;

void s19_send_range_800a7d18(Ptr32<void> self, int id, float a, float b)
{
    if (FIELD(self, int, 180) != 0)
        w3d_message_post_current(w3d_value_range_init_80069a30(FUN_801613f0(lbl_804b1754, 16), id, a, b));
    else
        FUN_800fb1b8(id, w3d_engine_get_context()->tick + 10, a, b);
}

}
