#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4a_toggler_update_8012bd08.c"
struct K4aIface;
typedef struct K4aIfaceVtable { Ptr32<void (void)> unknown_00[22]; Ptr32<int (Ptr32<struct K4aIface>, int)> set_enabled; } K4aIfaceVtable;
typedef struct K4aIface { Ptr32<const K4aIfaceVtable> vtable; } K4aIface;
typedef struct K4aToggler { char pad0[28]; Ptr32<K4aIface> iface; Ptr32<void> source; } K4aToggler;
extern Ptr32<void> w3d_constructor_native_cast(Ptr32<void>);
extern int w3d_auto_80178d1c(Ptr32<void>);
extern int w3d_constant_8015fb2c(Ptr32<void> self, int arg);

int k4a_toggler_update_8012bd08(Ptr32<K4aToggler> self, int arg)
{
    int mode = w3d_auto_80178d1c(w3d_constructor_native_cast(self->source));
    self->iface->vtable->set_enabled(self->iface, mode != 2);
    w3d_constant_8015fb2c(self, arg);
    return 0;
}

}
