#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_802e0e84.c"
struct K6bDevice {
    Ptr32<Ptr32<void>> vtable;
    char body[76];
    int field_80;
    int state;
};
extern Ptr32<void> w3d_disc_monitor_instance_800c8120(void);
extern void w3d_disc_set_flag1_800c7fe4(Ptr32<void> monitor, int value);
extern void w3d_auto_802e1720(Ptr32<struct K6bDevice> self);
extern int fn_802e1730(Ptr32<struct K6bDevice> self);
extern void fn_80304b84(int value);
void w3d_k6b_device_reset_802e0e84(Ptr32<struct K6bDevice> self)
{
    ((Ptr32<void (Ptr32<struct K6bDevice>)>)self->vtable[9])(self);
    self->state = 5;
    self->field_80 = 0;
    w3d_disc_set_flag1_800c7fe4(w3d_disc_monitor_instance_800c8120(), 0);
    w3d_auto_802e1720(self);
    fn_802e1730(self);
    fn_80304b84(0);
}
// desc: w3d_k6b_device_reset_802e0e84: Appears to call virtual slot 9, set +84 to 5 and clear +80, clear the disc monitor flag, then call 0x802e1720, 0x802e1730 and 0x80304b84(0).

}
