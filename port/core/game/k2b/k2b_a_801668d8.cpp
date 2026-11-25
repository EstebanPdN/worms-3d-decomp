#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_801668d8.c"
struct K2bInterface { Ptr32<Ptr32<void>> vtable; };
struct K2bHolder { unsigned char pad0[40]; Ptr32<struct K2bInterface> held; };
extern unsigned char w3d_obj_80411a20[];
extern Ptr32<struct K2bInterface> w3d_auto_8020b648(void);
int w3d_k2b_replace_held_interface_801668d8(Ptr32<struct K2bHolder> self)
{
    Ptr32<struct K2bInterface> replacement;
    Ptr32<struct K2bInterface> registry;
    Ptr32<void> type = w3d_obj_80411a20;
    registry = w3d_auto_8020b648();
    replacement = ((Ptr32<Ptr32<struct K2bInterface> (Ptr32<struct K2bInterface>, Ptr32<void>)>)registry->vtable[23])(registry, type);
    if (replacement)
        ((Ptr32<void (Ptr32<struct K2bInterface>)>)replacement->vtable[3])(replacement);
    if (self->held)
        ((Ptr32<void (Ptr32<struct K2bInterface>)>)self->held->vtable[4])(self->held);
    self->held = replacement;
    return 0;
}
// desc: Appears to look up an interface by type, retain it and replace the held interface after releasing the old one.

}
