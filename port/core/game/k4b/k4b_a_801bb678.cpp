#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801bb678.c"
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bService {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    Ptr32<struct K4bIface> shared;
    unsigned short count;
};
extern Ptr32<struct K4bIface> lbl_804b05a8;
extern Ptr32<void> lbl_80415410[];
extern Ptr32<struct K4bService> w3d_ctor_801b87c0(Ptr32<struct K4bService> object, Ptr32<void>);
Ptr32<struct K4bService> w3d_k4b_service_construct_801bb678(Ptr32<struct K4bService> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K4bIface> shared;
    w3d_ctor_801b87c0(self, arg_r4);
    shared = lbl_804b05a8;
    self->vtable = lbl_80415410;
    self->shared = shared;
    if (shared != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)shared->vtable[3])(shared);
    self->count = 0;
    return self;
}
// desc: w3d_k4b_service_construct_801bb678: Appears to construct an object over base 0x801b87c0, install vtable 0x80415410, retain a shared global interface into +20 and clear the 16-bit count at +24.

}
