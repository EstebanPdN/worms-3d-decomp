#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_8024df2c.c"
struct K5bIface { Ptr32<Ptr32<void>> vtable; };
struct K5bString { Ptr32<char> text; };
struct K5bVec3 { float x, y, z; };
struct K5bRgba { unsigned char r, g, b, a; };
struct K5bLightRig {
    Ptr32<Ptr32<void>> vtable;
    char base[44];
    struct K5bVec3 points[8];
    Ptr32<struct K5bIface> source;
    Ptr32<struct K5bIface> target;
    float colour[4];
    Ptr32<struct K5bIface> shared;
    Ptr32<struct K5bIface> shadow;
    struct K5bRgba tint;
    float intensity;
    Ptr32<struct K5bIface> mask;
    struct K5bString name;
    int params[4];
    unsigned char flags[3];
};
extern Ptr32<struct K5bIface> lbl_804b05a8;
extern Ptr32<struct K5bIface> lbl_804b05ac;
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_8041b7d0[];
extern Ptr32<void> w3d_ctor_held_801b4e94(Ptr32<void> object, Ptr32<void>);
extern void w3d_string_base_init(Ptr32<struct K5bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K5bString> string);
static inline void k5b_ref_init(Ptr32<Ptr32<struct K5bIface>> slot, Ptr32<struct K5bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K5bIface>)>)iface->vtable[3])(iface);
}
static inline void k5b_vec3_set(Ptr32<struct K5bVec3> v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}
static inline void k5b_rgba_set(Ptr32<struct K5bRgba> c, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    c->r = r;
    c->g = g;
    c->b = b;
    c->a = a;
}
Ptr32<struct K5bLightRig> w3d_k5b_light_rig_construct_8024df2c(Ptr32<struct K5bLightRig> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K5bString> name;
    Ptr32<Ptr32<char>> empty;
    w3d_ctor_held_801b4e94(self, arg_r4);
    self->vtable = lbl_8041b7d0;
    k5b_vec3_set(&self->points[0], 0.0f, 0.0f, 0.0f);
    k5b_vec3_set(&self->points[1], 0.0f, 0.0f, 0.0f);
    k5b_vec3_set(&self->points[2], 0.0f, 0.0f, 0.0f);
    k5b_vec3_set(&self->points[3], 0.0f, 0.0f, 0.0f);
    k5b_vec3_set(&self->points[4], 0.0f, 0.0f, 0.0f);
    k5b_vec3_set(&self->points[5], 0.0f, 0.0f, 0.0f);
    k5b_vec3_set(&self->points[6], 0.0f, 0.0f, 0.0f);
    k5b_vec3_set(&self->points[7], 0.0f, 0.0f, 0.0f);
    k5b_ref_init(&self->source, lbl_804b05a8);
    k5b_ref_init(&self->target, lbl_804b05a8);
    self->colour[0] = 0.0f;
    self->colour[1] = 0.0f;
    self->colour[2] = 0.0f;
    self->colour[3] = 0.0f;
    k5b_ref_init(&self->shared, lbl_804b05ac);
    k5b_ref_init(&self->shadow, lbl_804b05a8);
    k5b_rgba_set(&self->tint, 0, 0, 0, 0);
    self->intensity = 0.0f;
    k5b_ref_init(&self->mask, lbl_804b05a8);
    name = &self->name;
    empty = lbl_804b06a0;
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    self->params[0] = 0;
    self->params[1] = 0;
    self->params[2] = 0;
    self->params[3] = 0;
    self->flags[0] = 0;
    self->flags[1] = 0;
    self->flags[2] = 0;
    return self;
}
// desc: w3d_k5b_light_rig_construct_8024df2c: Appears to construct an object over 0x801b4e94: vtable 0x8041b7d0, eight zero vectors, zero colour and intensity, five retained shared interfaces, an empty name string and cleared parameters.

}
