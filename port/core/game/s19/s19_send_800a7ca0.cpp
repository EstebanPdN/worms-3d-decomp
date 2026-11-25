#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_send_800a7ca0.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
struct S19Ctx { char pad0[52]; int tick; };
extern Ptr32<void> FUN_801613f0(Ptr32<void>, int);
extern Ptr32<void> w3d_message_float_init(Ptr32<void>, int, float);
extern int w3d_message_post_current(Ptr32<void>);
extern Ptr32<struct S19Ctx> w3d_engine_get_context(void);
extern void FUN_800faa44(int, int, float);
extern Ptr32<void> lbl_804b1754;

void s19_send_float_800a7ca0(Ptr32<void> self, int id, float value)
{
    if (FIELD(self, int, 180) != 0)
        w3d_message_post_current(w3d_message_float_init(FUN_801613f0(lbl_804b1754, 12), id, value));
    else
        FUN_800faa44(id, w3d_engine_get_context()->tick + 10, value);
}

}
