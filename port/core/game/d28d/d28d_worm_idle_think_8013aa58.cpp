#include "w3d_ptr.h"
#line 1 "d28d_worm_idle_think_8013aa58.cpp"
// GWMP8P rev0 0x8013aa58. Worm idle reaction to the active worm. Names are
// inferred from use. The play callee's argument order is chosen for the
// argument moves.
struct Vec {
    float x, y, z;
    float distSq(const Vec &o) const { float dx = x - o.x, dy = y - o.y, dz = z - o.z; return dx * dx + dy * dy + dz * dz; }
};
struct Obj { Ptr32<Ptr32<void>> vtable; };
struct Info { char u0[68]; Vec dir; Vec pos; };
struct Mesh;
struct Worm { char u0[52]; Vec eye; Vec look; char u4c[8]; Ptr32<void> colour; char u58[24]; int index; char u74[356]; int cue472; char u1dc[16]; int cue492; char u1f0[44]; Ptr32<Obj> f540; char u220[8]; Ptr32<void> f552; char u22c[104]; int aiming; float f664; float f668; };
extern "C" void stop_800e5bb8(Ptr32<void>);
extern "C" Ptr32<void> get_803426b4(Ptr32<void>);
extern "C" int target_80178c48(Ptr32<void>);
extern "C" Ptr32<Info> query_800fc6dc(int);
extern "C" int in_range_8013b5bc(Ptr32<Worm>, Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<float>);
extern "C" float angle_8013b898(Ptr32<Worm>, Ptr32<const Vec>, Ptr32<const Vec>);
extern "C" void apply_8013c21c(Ptr32<Worm>, Ptr32<Mesh>, float, float);
extern "C" int facing_8013b3b8(Ptr32<Worm>, Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<const Vec>);
extern "C" int visible_8013b91c(Ptr32<Worm>, Ptr32<Info>);
extern "C" unsigned rand_80162c20();
extern "C" int play_801359ec(Ptr32<Worm>, Ptr32<Mesh>, Ptr32<const char>, float, float, Ptr32<int>, float);
extern "C" void idle_8013a158(Ptr32<Worm>, Ptr32<Mesh>, int);
extern "C" void turn_8013b948(Ptr32<Worm>, Ptr32<const Vec>, Ptr32<Mesh>);
extern Ptr32<const char> a_804ab16c; extern Ptr32<const char> b_804ab100; extern Ptr32<const char> c_804ab2d0; extern Ptr32<const char> d_804ab2d8; extern Ptr32<const char> e_804ab2a4; extern Ptr32<const char> f_804ab2a8;
extern "C" void d28d_worm_idle_think_8013aa58(Ptr32<Worm> self, Ptr32<Mesh> mesh) {
    if (self->f552) {
        stop_800e5bb8(self->f552);
        Ptr32<Obj> o = self->f540;
        self->f552 = 0;
        if (o) ((Ptr32<void (Ptr32<Obj>)>)o->vtable[6])(o);
    }
    int other = target_80178c48(get_803426b4(self->colour));
    if (other == self->index) return;
    Ptr32<Info> me = query_800fc6dc(self->index);
    Ptr32<Info> him = query_800fc6dc(other);
    if (self->aiming) {
        float a = 0.0f;
        float z = a;
        Ptr32<const Vec> hp = &him->pos;
        Ptr32<const Vec> eye = &self->eye;
        int ok = in_range_8013b5bc(self, hp, eye, &self->look, &a);
        if (ok) {
            float b = angle_8013b898(self, hp, eye);
            apply_8013c21c(self, mesh, a, b);
        } else {
            apply_8013c21c(self, mesh, z, z);
            if (__builtin_fabsf(self->f664) < 0.01f && __builtin_fabsf(self->f668) < 0.01f) self->aiming = ok;
        }
    }
    const Vec &m = me->pos;
    Ptr32<const Vec> hp = &him->pos;
    float d = m.distSq(*hp);
    if (d > 202500.0f) {
        play_801359ec(self, mesh, a_804ab16c, 1.0f, 0.0f, &self->cue472, 0.0f);
        return;
    }
    if (d > 40000.0f) goto far;
    if (d > 6400.0f) {
        {
        Ptr32<const Vec> eye = &self->eye;
        if (facing_8013b3b8(self, hp, &him->dir, eye)) goto busy;
        float c;
        if (in_range_8013b5bc(self, hp, eye, &self->look, &c)) {
            float b = angle_8013b898(self, hp, eye);
            apply_8013c21c(self, mesh, c, b);
            return;
        }
        }
    far:
        idle_8013a158(self, mesh, 0);
        return;
    }
    Ptr32<const Vec> eye;
    eye = &self->eye;
    if (facing_8013b3b8(self, hp, &him->dir, eye)) {
        if (!visible_8013b91c(self, him)) { turn_8013b948(self, hp, mesh); return; }
        if (rand_80162c20() % 3 != 0) goto busy;
        play_801359ec(self, mesh, b_804ab100, 1.0f, 0.0f, &self->cue492, 0.0f);
        switch ((int)(rand_80162c20() & 3)) {
        case 0: play_801359ec(self, mesh, c_804ab2d0, 1.0f, -1.0f, &self->cue472, 0.0f); break;
        case 1: play_801359ec(self, mesh, d_804ab2d8, 1.0f, -1.0f, &self->cue472, 0.0f); break;
        case 2: play_801359ec(self, mesh, e_804ab2a4, 1.0f, -1.0f, &self->cue472, 0.0f); break;
        case 3: play_801359ec(self, mesh, f_804ab2a8, 1.0f, -1.0f, &self->cue472, 0.0f); break;
        }
        return;
    busy:
        idle_8013a158(self, mesh, 1);
        return;
    }
    float e;
    if (in_range_8013b5bc(self, hp, eye, &self->look, &e)) {
        float b = angle_8013b898(self, hp, eye);
        apply_8013c21c(self, mesh, e, b);
    } else if (self->aiming) {
        turn_8013b948(self, hp, mesh);
    } else idle_8013a158(self, mesh, 0);
}


