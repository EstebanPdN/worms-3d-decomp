#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_timers_80029780.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<int (Ptr32<S19Iface>)> S19Query;
typedef Ptr32<void (Ptr32<S19Iface>)> S19Act;
extern int lbl_804aa858;
extern int lbl_804aa85c;

int s19_tick_timers_80029780(Ptr32<void> self, int now)
{
    int dt = now - lbl_804aa85c;
    lbl_804aa85c = now;
    if (lbl_804aa858) {
        if (FIELD(self, S19Iface *, 28) && FIELD(self, int, 40) == 0
            && !((S19Query)FIELD(self, S19Iface *, 28)->vtable[9])(FIELD(self, S19Iface *, 28))) {
            ((S19Act)FIELD(self, S19Iface *, 28)->vtable[5])(FIELD(self, S19Iface *, 28));
        } else {
            if (FIELD(self, int, 40) > dt)
                FIELD(self, int, 40) = FIELD(self, int, 40) - dt;
            else
                FIELD(self, int, 40) = 0;
        }
        if (FIELD(self, S19Iface *, 32) && FIELD(self, int, 36) == 0
            && !((S19Query)FIELD(self, S19Iface *, 32)->vtable[9])(FIELD(self, S19Iface *, 32))) {
            ((S19Act)FIELD(self, S19Iface *, 32)->vtable[5])(FIELD(self, S19Iface *, 32));
        } else {
            if (FIELD(self, int, 36) > dt)
                FIELD(self, int, 36) = FIELD(self, int, 36) - dt;
            else
                FIELD(self, int, 36) = 0;
        }
    }
    return 0;
}

}
