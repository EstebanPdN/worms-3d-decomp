#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801c1864.c"
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
struct K4bMappedBox {
    struct K4bBox box;
    Ptr32<struct K4bIface> maps[5];
    unsigned char two_sided;
    char pad55[3];
    Ptr32<struct K4bIface> alpha;
    int enabled;
};
extern Ptr32<struct K4bIface> lbl_804b05a8;
extern Ptr32<void> lbl_80414da8[];
extern Ptr32<struct K4bBox> w3d_k4b_box_construct_801b5b30(Ptr32<struct K4bBox> self, Ptr32<void>);
static inline void k4b_ref_init(Ptr32<Ptr32<struct K4bIface>> slot, Ptr32<struct K4bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K4bMappedBox> w3d_k4b_mapped_box_construct_801c1864(Ptr32<struct K4bMappedBox> self, Ptr32<void> arg_r4)
{
    w3d_k4b_box_construct_801b5b30(&self->box, arg_r4);
    self->box.vtable = lbl_80414da8;
    k4b_ref_init(&self->maps[0], lbl_804b05a8);
    k4b_ref_init(&self->maps[1], lbl_804b05a8);
    k4b_ref_init(&self->maps[2], lbl_804b05a8);
    k4b_ref_init(&self->maps[3], lbl_804b05a8);
    k4b_ref_init(&self->maps[4], lbl_804b05a8);
    self->two_sided = 0;
    k4b_ref_init(&self->alpha, lbl_804b05a8);
    self->enabled = 1;
    return self;
}
// desc: w3d_k4b_mapped_box_construct_801c1864: Appears to construct a derived bounds object over 0x801b5b30: vtable 0x80414da8, six retained shared default interfaces, a cleared flag byte, enabled set.

}
