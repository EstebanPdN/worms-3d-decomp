#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_8020fc60.c"
extern Ptr32<void> lbl_80419598[];
extern Ptr32<void> lbl_804195c0[];
struct K6bNode {
    Ptr32<Ptr32<void>> vtable;
    char body[8];
    Ptr32<Ptr32<void>> second_vtable;
};
extern void fn_8020fe64(Ptr32<struct K6bNode> self);
extern void w3d_auto_801ffe58(Ptr32<struct K6bNode> self, Ptr32<void> arg);
void w3d_k6b_node_init_8020fc60(Ptr32<struct K6bNode> self, Ptr32<void> arg)
{
    self->second_vtable = lbl_80419598;
    self->vtable = lbl_804195c0;
    fn_8020fe64(self);
    w3d_auto_801ffe58(self, arg);
}
// desc: w3d_k6b_node_init_8020fc60: Appears to install the vtables at +0 and +12, then call 0x8020fe64 and 0x801ffe58 with the object and argument.

}
