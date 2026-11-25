#include "w3d_ptr.h"
#line 1 "cc17d_scene_reset_802c603c.cpp"
// cc17d: two resets of a named child node (0x802c603c, 0x802c6f64); same
// owner layout as k8c 0x802c5f4c.  Observed: a temporary string built from
// the original "NULL" literal is passed to w3d_handle_set_name with the
// handle at +28 and 255; the child at +28 then receives vtable slot +76 with
// the owner's vector at +60 / +112 and 0, and slot +84 (scale) with a
// three-float vector of one original constant and 0.
extern "C" {
Ptr32<void> w3d_string_from_text(Ptr32<void>, Ptr32<const char>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
Ptr32<void> w3d_handle_set_name(Ptr32<const void>, Ptr32<void>, unsigned int);
}
extern "C" const char w3d_str_803d8d10[], w3d_str_803d8de4[];
extern "C" const float w3d_f32_803d8d18[], w3d_f32_803d8dec[];
struct Cc17dString {
    Ptr32<const char> text;
    int unknown;
    template <class W3dU> Cc17dString(Ptr32<W3dU> w3d_p) : Cc17dString((const char *)w3d_p.get()) {}
 Cc17dString(const char *s) { w3d_string_from_text(this, s); }
    ~Cc17dString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Cc17dVec3 { float x, y, z; inline void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Cc17dNode;
struct Cc17dNodeVtable {
    Ptr32<void> unused[19];
    Ptr32<void (Ptr32<Cc17dNode>, Ptr32<Cc17dVec3>, int)> position;   // +76
    Ptr32<void> gap[1];
    Ptr32<void (Ptr32<Cc17dNode>, Ptr32<Cc17dVec3>, int)> scale;      // +84
};
struct Cc17dNode { Ptr32<Cc17dNodeVtable> vtable; };
struct Cc17dNodeOwner {
    unsigned char opaque[28];
    Ptr32<Cc17dNode> child;                  // +28, named handle
    unsigned char pad20[28];
    Cc17dVec3 position;                // +60, used by 0x802c603c
    unsigned char pad48[40];
    Cc17dVec3 position2;               // +112, used by 0x802c6f64
};
// The name reset is an inline helper taking the owner: passing the owner
// (not the handle address) reproduces the original register choice for the
// temporary string's address.
static inline void cc17d_reset_name(Ptr32<Cc17dNodeOwner> owner, Ptr32<const char> text)
{
    Cc17dString name(text);
    w3d_handle_set_name(&name, &owner->child, 255);
}
extern "C" void w3d_cc17d_node_reset_802c603c(Ptr32<Cc17dNodeOwner> self)
{
    cc17d_reset_name(self, w3d_str_803d8d10);
    self->child->vtable->position(self->child, &self->position, 0);
    Cc17dVec3 v;
    Ptr32<Cc17dVec3> p = &v;                 // stores through p reproduce the original addi r11 form
    p->x = w3d_f32_803d8d18[0]; p->y = w3d_f32_803d8d18[0]; p->z = w3d_f32_803d8d18[0];
    self->child->vtable->scale(self->child, p, 0);
}
extern "C" void w3d_cc17d_node_reset_802c6f64(Ptr32<Cc17dNodeOwner> self)
{
    cc17d_reset_name(self, w3d_str_803d8de4);
    self->child->vtable->position(self->child, &self->position2, 0);
    Cc17dVec3 v;
    Ptr32<Cc17dVec3> p = &v;
    p->x = w3d_f32_803d8dec[0]; p->y = w3d_f32_803d8dec[0]; p->z = w3d_f32_803d8dec[0];
    self->child->vtable->scale(self->child, p, 0);
}


