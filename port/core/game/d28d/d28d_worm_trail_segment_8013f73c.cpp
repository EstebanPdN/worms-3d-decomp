#include "w3d_ptr.h"
#line 1 "d28d_worm_trail_segment_8013f73c.cpp"
// GWMP8P rev0 0x8013f73c. Worm trail segment update. Field names are
// inferred from use.
struct Obj { Ptr32<Ptr32<void>> vtable; };
struct V { float x, y, z; };
struct Vec : V { Vec(); };
struct Mat { float r[9]; Vec t; };
struct Self { char pad[32]; Ptr32<Obj> a; Ptr32<Obj> b; char pad2[116]; int target; char pad3[4]; Ptr32<void> mesh; char pad4[320]; int clip; };
extern "C" int w3d_mesh_instance_is_playing(Ptr32<void>, int);
extern "C" void tsonnet_b29_release_8013f6b4(Ptr32<Self>);
extern "C" Ptr32<void> w3d_s20_lookup_handle_object_80164fc8(int);
extern "C" void w3d_trail_graphic_entity_set_segment_80122800(Ptr32<void>, Ptr32<const V>, Ptr32<const V>, int);
extern "C" void d28d_worm_trail_segment_8013f73c(Ptr32<Self> self) {
    if (self->target == -1) return;
    if (!self->mesh || w3d_mesh_instance_is_playing(self->mesh, self->clip)) {
        tsonnet_b29_release_8013f6b4(self);
        return;
    }
    Ptr32<void> e = 0;
    Ptr32<void> h = w3d_s20_lookup_handle_object_80164fc8(self->target);
    if (!h) { self->target = -1; return; }
    e = h;
    V p, q;
    Mat m;
    ((Ptr32<void (Ptr32<Obj>, Ptr32<Mat>)>)self->a->vtable[31])(self->a, &m);
    p = m.t;
    ((Ptr32<void (Ptr32<Obj>, Ptr32<Mat>)>)self->b->vtable[31])(self->b, &m);
    q = m.t;
    w3d_trail_graphic_entity_set_segment_80122800(e, &p, &q, 0);
}


