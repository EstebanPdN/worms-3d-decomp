#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_shape_check_801d6644.c"
struct K8bShape {
    char pad0[36];
    Ptr32<const char> name;      /* +36 */
    char pad28[8];
    Ptr32<void> geometry;        /* +48 */
    Ptr32<void> shader;          /* +52 */
};

extern void w3d_k8b_log_801d6000(Ptr32<void> owner, Ptr32<const char> format, ...);
extern int w3d_s20_dispatch_two_targets_801a3adc(Ptr32<void> self, Ptr32<struct K8bShape> shape);

void w3d_k8b_shape_check_801d6644(Ptr32<char> self, Ptr32<struct K8bShape> shape)
{
    Ptr32<char> owner = self ? w3d::R(self - 4) : 0;
    if (shape->geometry == 0)
        w3d_k8b_log_801d6000(owner, "Warning: No geometry attached to shape '%s' @ %08x\n", w3d::VA(shape->name), w3d::VA(shape));
    if (shape->shader == 0)
        w3d_k8b_log_801d6000(owner, "Warning: No shader attached to shape '%s' @ %08x\n", w3d::VA(shape->name), w3d::VA(shape));
    w3d_s20_dispatch_two_targets_801a3adc(self, shape);
}

}
