#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8c_panel_reset_8026ec30.c"
struct K8cHeld;
struct K8cHeldVtable { Ptr32<void> slots[4]; Ptr32<void (Ptr32<struct K8cHeld>)> release; };
struct K8cHeld { Ptr32<struct K8cHeldVtable> vtable; };
struct K8cPanel {
    char pad00[28];
    char body[184];
    Ptr32<struct K8cHeld> held;
    char pad_d8[72];
    Ptr32<void> handle;
};
extern void fn_8015fd1c(Ptr32<void> handle);
extern void fn_8027035c(Ptr32<struct K8cPanel> self, int a, int b);
extern void fn_802b0fec(Ptr32<void> body);
void w3d_k8c_panel_reset_8026ec30(Ptr32<struct K8cPanel> self)
{
    int zero = 0;
    if (self->held)
        self->held->vtable->release(self->held);
    self->held = (Ptr32<struct K8cHeld>)w3d::G(zero);
    if (self->handle) {
        fn_8015fd1c(self->handle);
        self->handle = (Ptr32<void>)w3d::G(zero);
    }
    fn_8027035c(self, 1, 1);
    fn_802b0fec(self->body);
}
extern char w3d_vtable_8041bdf0[];
extern char w3d_vtable_8041be40[];
extern void fn_802afc40(Ptr32<void> body, int flags);
extern void fn_8015ff2c(Ptr32<struct K8cPanel> self, int flags);
void w3d_k8c_panel_destroy_80270698(Ptr32<struct K8cPanel> self, int flags)
{
    *(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 208) = w3d_vtable_8041bdf0;
    *(Ptr32<Ptr32<void>>)self = w3d_vtable_8041be40;
    if (self->held)
        self->held->vtable->release(self->held);
    fn_802afc40(self->body, 0);
    fn_8015ff2c(self, flags);
}

}
