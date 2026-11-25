#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801ac19c.c"
struct K4bVec3 { float x, y, z; };
struct K4bMtx34 { float m[3][3]; struct K4bVec3 t; };
struct K4bMtx44 { float m[16]; };
struct K4bMember { char data[12]; };
struct K4bXformNode {
    Ptr32<Ptr32<void>> vtable;
    char base[36];
    float weight;
    struct K4bMtx44 matrix;
    int enabled;
    char pad70[4];
    int field_74;
    int field_78;
    char pad7c[12];
    struct K4bMember member;
};
extern Ptr32<void> lbl_80411de0[];
extern Ptr32<void> lbl_80411d70[];
extern Ptr32<void> lbl_80413fc0[];
extern struct K4bMtx34 lbl_8045e748[];
extern Ptr32<void> fn_801e81c8(Ptr32<void> member);
extern Ptr32<void> w3d_construct_801f2678(Ptr32<struct K4bMember> member);
static inline void k4b_mtx44_from34(Ptr32<struct K4bMtx44> d, Ptr32<const struct K4bMtx34> s)
{
    Ptr32<const struct K4bVec3> t = &s->t;
    d->m[0] = s->m[0][0];
    d->m[1] = s->m[0][1];
    d->m[2] = s->m[0][2];
    d->m[3] = 0.0f;
    d->m[4] = s->m[1][0];
    d->m[5] = s->m[1][1];
    d->m[6] = s->m[1][2];
    d->m[7] = 0.0f;
    d->m[8] = s->m[2][0];
    d->m[9] = s->m[2][1];
    d->m[10] = s->m[2][2];
    d->m[11] = 0.0f;
    d->m[12] = t->x;
    d->m[13] = t->y;
    d->m[14] = t->z;
    d->m[15] = 1.0f;
}
Ptr32<struct K4bXformNode> w3d_k4b_xform_node_construct_801ac19c(Ptr32<struct K4bXformNode> self)
{
    self->vtable = lbl_80411de0;
    fn_801e81c8(self->base);
    self->vtable = lbl_80411d70;
    self->field_74 = 0;
    self->field_78 = 0;
    w3d_construct_801f2678(&self->member);
    k4b_mtx44_from34(&self->matrix, &lbl_8045e748[0]);
    self->weight = 0.0f;
    self->enabled = 1;
    self->vtable = lbl_80413fc0;
    return self;
}
// desc: w3d_k4b_xform_node_construct_801ac19c: Appears to construct a transform node: vtables, member at +4, member at +136, a 4x4 matrix expanded from the global 3x4 matrix 0x8045e748, zero weight, enabled flag set.

}
