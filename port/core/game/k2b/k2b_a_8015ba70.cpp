#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_8015ba70.c"
struct K2bLoop { Ptr32<Ptr32<void>> vtable; unsigned char pad0[72]; int quit_state; };
extern unsigned char w3d_obj_80455170[];
extern int w3d_global_804b0054;
extern void w3d_auto_8015ce28(Ptr32<void> history);
extern int w3d_clock_ticks_801fe45c(void);
extern void w3d_history_tick(Ptr32<void> history);
void w3d_k2b_run_main_loop_8015ba70(Ptr32<struct K2bLoop> self)
{
    Ptr32<Ptr32<Ptr32<void>>> vtable_slot = &self->vtable;
    int delta;
    ((Ptr32<void (Ptr32<struct K2bLoop>)>)self->vtable[15])(self);
    w3d_auto_8015ce28(w3d_obj_80455170);
    w3d_global_804b0054 = w3d_clock_ticks_801fe45c();
    do {
        int now = w3d_clock_ticks_801fe45c();
        delta = now - w3d_global_804b0054;
        w3d_global_804b0054 = now;
        ((Ptr32<void (Ptr32<struct K2bLoop>, int)>)(*vtable_slot)[16])(self, delta);
        w3d_history_tick(w3d_obj_80455170);
    } while (self->quit_state < 0);
}
// desc: Appears to run the main loop: start-up callback, then per-frame tick deltas and history ticks until the quit state is set.

}
