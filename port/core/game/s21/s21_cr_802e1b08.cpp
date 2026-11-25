#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cr_802e1b08.c"
// desc: Appears to apply stored position and size values to the linked surface through helpers when active and a descriptor is valid, returning the descriptor's handle or minus one.
struct S21Descriptor { char pad[356]; int handle; };
struct S21Object { char pad[4]; Ptr32<struct S21Descriptor> descriptor; int surface; char pad1[32]; short x; short y; short w; short h; char pad2[20]; int p; int q; int active; };
extern void fn_802e2508(int, int, int);
extern void fn_802e2a00(int, int, int, int, int);
extern void fn_802e23e8(int);
int w3d_s21_apply_802e1b08(Ptr32<struct S21Object> self)
{
    if (self->active && self->descriptor->handle >= 0) {
        fn_802e2508(self->surface, self->p, self->q);
        fn_802e2a00(self->surface, self->x, self->y, self->w, self->h);
        fn_802e23e8(self->surface);
        return self->descriptor->handle;
    }
    return -1;
}

}
