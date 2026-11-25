// GWMP8P rev0 0x8013f73c. Worm trail segment update. Field names are
// inferred from use.
struct Obj { void **vtable; };
struct V { float x, y, z; };
struct Vec : V { Vec(); };
struct Mat { float r[9]; Vec t; };
struct Self { char pad[32]; Obj *a; Obj *b; char pad2[116]; int target; char pad3[4]; void *mesh; char pad4[320]; int clip; };
extern "C" int w3d_mesh_instance_is_playing(void *, int);
extern "C" void tsonnet_b29_release_8013f6b4(Self *);
extern "C" void *w3d_s20_lookup_handle_object_80164fc8(int);
extern "C" void w3d_trail_graphic_entity_set_segment_80122800(void *, const V *, const V *, int);
extern "C" void d28d_worm_trail_segment_8013f73c(Self *self) {
    if (self->target == -1) return;
    if (!self->mesh || w3d_mesh_instance_is_playing(self->mesh, self->clip)) {
        tsonnet_b29_release_8013f6b4(self);
        return;
    }
    void *e = 0;
    void *h = w3d_s20_lookup_handle_object_80164fc8(self->target);
    if (!h) { self->target = -1; return; }
    e = h;
    V p, q;
    Mat m;
    ((void (*)(Obj *, Mat *))self->a->vtable[31])(self->a, &m);
    p = m.t;
    ((void (*)(Obj *, Mat *))self->b->vtable[31])(self->b, &m);
    q = m.t;
    w3d_trail_graphic_entity_set_segment_80122800(e, &p, &q, 0);
}
