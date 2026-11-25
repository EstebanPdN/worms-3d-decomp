#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_80158dd4.c"
struct K2bLookup { unsigned char pad0[800]; int busy_a; int busy_b; int busy_c; };
struct K2bOwner { unsigned char pad0[296]; Ptr32<void> context; unsigned char pad1[12]; int slots[16]; };
extern Ptr32<void> w3d_empty_803426b4(Ptr32<void> context);
extern int w3d_auto_80178c48(Ptr32<void>);
extern Ptr32<struct K2bLookup> w3d_s20_lookup_handle_object_80164fc8(int handle);
static inline int k2b_busy(Ptr32<struct K2bLookup> o){ int a=0; if (o->busy_a || o->busy_b || o->busy_c) a=1; return a; }
int w3d_k2b_current_slot_busy_80158dd4(Ptr32<struct K2bOwner> self)
{
    int index;
    int handle;
    Ptr32<struct K2bLookup> obj;index = w3d_auto_80178c48((Ptr32<void>)w3d_empty_803426b4(self->context));
    if (index == -1) return 0;
    handle = self->slots[index];
    if (handle == -1) return 0;
    obj = w3d_s20_lookup_handle_object_80164fc8(handle);
    return k2b_busy(obj) ? 1 : 0;
}
// desc: Appears to report whether the object in the current slot has any of three busy counters set.

}
