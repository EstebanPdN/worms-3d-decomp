#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_801b5c24.c"
struct K6bBounds6 { float v[6]; };
struct K6bBinding {
    char head[8];
    struct K6bBounds6 bounds;
};
extern struct K6bBounds6 lbl_8045e690[];
extern char lbl_803ab078[];
extern char lbl_803ab0a8[];
extern Ptr32<struct K6bBinding> w3d_binding_create_801f1094(Ptr32<void> owner, Ptr32<const char> name);
extern Ptr32<void> w3d_s12_create_member_binding_801ece2c(Ptr32<void> owner, Ptr32<const char> name);
extern void fn_801e8d9c(Ptr32<void> owner);
int w3d_k6b_register_bounds_bindings_801b5c24(Ptr32<void> owner)
{
    w3d_binding_create_801f1094(owner, lbl_803ab078)->bounds = lbl_8045e690[0];
    w3d_s12_create_member_binding_801ece2c(owner, lbl_803ab0a8);
    fn_801e8d9c(owner);
    return 0;
}
// desc: w3d_k6b_register_bounds_bindings_801b5c24: Appears to create the binding named at 0x803ab078 with the default six-word bounds from 0x8045e690, add the member binding 0x803ab0a8 and finish with 0x801e8d9c.

}
