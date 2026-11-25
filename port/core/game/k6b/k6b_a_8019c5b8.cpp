#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_8019c5b8.c"
struct K6bIface { Ptr32<Ptr32<void>> vtable; };
struct K6bDispatcher {
    char head[44];
    Ptr32<struct K6bIface> result;
};
struct K6bDispatchTarget {
    char head[64];
    Ptr32<struct K6bIface> result;
};
extern int w3d_s20_dispatch_five_targets_801a4874(Ptr32<void> self, Ptr32<struct K6bDispatchTarget> target);
int w3d_k6b_dispatcher_run_8019c5b8(Ptr32<char> self, Ptr32<struct K6bDispatchTarget> target)
{
    Ptr32<struct K6bDispatcher> owner = self ? w3d::R((Ptr32<struct K6bDispatcher>)(self - 4)) : 0;
    if (owner->result != 0)
        ((Ptr32<void (Ptr32<struct K6bIface>)>)owner->result->vtable[4])(owner->result);
    owner->result = 0;
    w3d_s20_dispatch_five_targets_801a4874(self, target);
    if (owner->result != 0) {
        Ptr32<struct K6bIface> value = owner->result;
        Ptr32<struct K6bIface> old = target->result;
        target->result = value;
        ((Ptr32<void (Ptr32<struct K6bIface>)>)value->vtable[3])(value);
        if (old != 0)
            ((Ptr32<void (Ptr32<struct K6bIface>)>)old->vtable[4])(old);
    }
    return 0;
}
// desc: w3d_k6b_dispatcher_run_8019c5b8: Appears to release and clear the result at +44 of the primary object, dispatch to the target through 0x801a4874 and hand any new result to the target at +64.

}
