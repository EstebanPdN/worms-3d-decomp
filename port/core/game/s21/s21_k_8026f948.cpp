#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_k_8026f948.c"
struct S21Gauge { char pad[288]; int source; int notify; int active; char pad1[8]; float target; float current; };
extern void fn_8026fc98(Ptr32<struct S21Gauge>, int);
extern float fn_802bc93c(Ptr32<void>, int, int);
extern void fn_80296410(Ptr32<void>, float);
void w3d_s21_gauge_sync_8026f948(Ptr32<struct S21Gauge> self, int mode, int store_target)
{
    if (self->active && self->source) {
        float value;
        if (mode != -1)
            fn_8026fc98(self, 0);
        value = fn_802bc93c(w3d::G(self->source), mode, 1);
        self->current = value;
        if (store_target)
            self->target = value;
        if (self->notify)
            fn_80296410(w3d::G(self->notify), value);
    }
}

}
