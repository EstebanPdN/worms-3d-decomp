#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801c1ef8.c"
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bService {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    Ptr32<struct K4bIface> shared;
    int count;
};
extern Ptr32<struct K4bIface> lbl_804b05ac;
extern Ptr32<void> lbl_80414d80[];
extern Ptr32<struct K4bService> w3d_tagged_construct_801ea0ec(Ptr32<struct K4bService> object, int);
Ptr32<struct K4bService> w3d_k4b_service_construct_801c1ef8(Ptr32<struct K4bService> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K4bIface> shared;
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
    shared = lbl_804b05ac;
    self->vtable = lbl_80414d80;
    self->shared = shared;
    if (shared != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)shared->vtable[3])(shared);
    self->count = 0;
    return self;
}
// desc: w3d_k4b_service_construct_801c1ef8: Appears to construct an object over base 0x801ea0ec, install vtable 0x80414d80, retain a shared global interface into +20 and clear the word at +24.

}
