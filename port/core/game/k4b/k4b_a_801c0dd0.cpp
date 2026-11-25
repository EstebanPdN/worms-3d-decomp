#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801c0dd0.c"
struct K4bVec3 { float x, y, z; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bBox {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    struct K4bVec3 min;
    struct K4bVec3 max;
    int valid;
    int slots[4];
};
struct K4bLayeredSurfaceBox {
    struct K4bBox box;
    Ptr32<struct K4bIface> diffuse;
    Ptr32<struct K4bIface> specular;
    int params[3];
    Ptr32<struct K4bIface> normal;
    Ptr32<struct K4bIface> gloss;
    int layer;
    unsigned char two_sided;
    char pad61[3];
    Ptr32<struct K4bIface> emissive;
    Ptr32<struct K4bIface> alpha;
    int enabled;
};
extern Ptr32<struct K4bIface> lbl_804b05a8;
extern Ptr32<void> lbl_80414e20[];
extern Ptr32<struct K4bBox> w3d_k4b_box_construct_801b5b30(Ptr32<struct K4bBox> self, Ptr32<void>);
static inline void k4b_ref_init(Ptr32<Ptr32<struct K4bIface>> slot, Ptr32<struct K4bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K4bLayeredSurfaceBox> w3d_k4b_layered_surface_box_construct_801c0dd0(Ptr32<struct K4bLayeredSurfaceBox> self, Ptr32<void> arg_r4)
{
    w3d_k4b_box_construct_801b5b30(&self->box, arg_r4);
    self->box.vtable = lbl_80414e20;
    k4b_ref_init(&self->diffuse, lbl_804b05a8);
    k4b_ref_init(&self->specular, lbl_804b05a8);
    self->params[0] = 0;
    self->params[1] = 0;
    self->params[2] = 0;
    k4b_ref_init(&self->normal, lbl_804b05a8);
    k4b_ref_init(&self->gloss, lbl_804b05a8);
    self->layer = 0;
    self->two_sided = 0;
    k4b_ref_init(&self->emissive, lbl_804b05a8);
    k4b_ref_init(&self->alpha, lbl_804b05a8);
    self->enabled = 1;
    return self;
}
// desc: w3d_k4b_layered_surface_box_construct_801c0dd0: Appears to construct a derived bounds object over 0x801b5b30: vtable 0x80414e20, six retained shared default interfaces, cleared parameters, layer and flag, enabled set.

}
