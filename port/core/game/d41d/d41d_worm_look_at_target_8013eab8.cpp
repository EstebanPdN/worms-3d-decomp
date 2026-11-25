#include "w3d_ptr.h"
#line 1 "d41d_worm_look_at_target_8013eab8.cpp"
// d41d: 0x8013eab8. Worm's turn toward a tracked object: resets when the
// handle is gone, keeps aiming while the aiming flag is set, otherwise
// starts an aim with a mood-chosen animation and line when the target is
// within range. Class fields are partial views.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    float distSqX(float ox, const Vec &o) const { float dx = x - ox, dy = y - o.y, dz = z - o.z; return dx * dx + dy * dy + dz * dz; }
    float distSq(const Vec &o) const { float dx = x - o.x, dy = y - o.y, dz = z - o.z; return dx * dx + dy * dy + dz * dz; }
};
struct Mesh;
struct Tracked { Ptr32<Ptr32<void>> vtable; };
struct Engine { char u0[52]; int now; };
struct Worm { char u0[52]; Vec eye; Vec look; char u4c[396]; int cue472; char u1dc[184]; int aiming; char u298[16]; int handle; };
extern "C" void reset_8013c54c(Ptr32<Worm>, Ptr32<Mesh>);
extern "C" Ptr32<Tracked> lookup_80164fc8(int);
extern "C" Ptr32<Engine> engine_80165254();
extern "C" int facing_8013b3b8(Ptr32<Worm>, Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<const Vec>);
extern "C" int in_range_8013b5bc(Ptr32<Worm>, Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<float>);
extern "C" float angle_8013b898(Ptr32<Worm>, Ptr32<const Vec>, Ptr32<const Vec>);
extern "C" void apply_8013c21c(Ptr32<Worm>, Ptr32<Mesh>, float, float);
extern "C" void turn_8013b948(Ptr32<Worm>, Ptr32<const Vec>, Ptr32<Mesh>);
extern "C" int playing_80181ccc(Ptr32<Mesh>, int);
extern "C" int control_801817e0(Ptr32<Mesh>, int);
extern "C" int play_801359ec(Ptr32<Worm>, Ptr32<Mesh>, Ptr32<const char>, float, float, Ptr32<int>, float);
extern "C" unsigned mood_8013ef50(Ptr32<Worm>);
extern "C" unsigned rand_80162c20();
extern "C" void speak_8013bd0c(Ptr32<Worm>, Ptr32<const char>);
extern const char line_8039edfc[];
extern Ptr32<const char> i_804ab100; extern Ptr32<const char> a_804ab2ac; extern Ptr32<const char> b_804ab2cc; extern Ptr32<const char> c_804ab2d0; extern Ptr32<const char> d_804ab2d4; extern Ptr32<const char> e_804ab2e4; extern Ptr32<const char> f_804ab2b0;
extern "C" void w3d_d41d_worm_look_at_target_8013eab8(Ptr32<Worm> self, Ptr32<Mesh> mesh) {
    if (!self->handle) { reset_8013c54c(self, mesh); return; }
    Ptr32<Tracked> t = lookup_80164fc8(self->handle);
    if (!t) { self->handle = (int)w3d::H(t); reset_8013c54c(self, mesh); return; }
    Ptr32<const Vec> eye = &self->eye;
    Vec pos;
    ((Ptr32<void (Ptr32<Tracked>, int, Ptr32<Vec>)>)t->vtable[11])(t, engine_80165254()->now, &pos);
    float x0 = self->eye.x;
    Vec at;
    at.x = x0;
    at.z = eye->z;
    at.y = eye->y + 15.0f;
    float zero = 0.0f;
    float out = zero;
    int aiming = self->aiming;
    if (aiming) {
        if (facing_8013b3b8(self, &at, &self->look, &pos)) { reset_8013c54c(self, mesh); self->aiming = 0; }
if (in_range_8013b5bc(self, &pos, &at, &self->look, &out)) {
float b = angle_8013b898(self, &pos, eye);
apply_8013c21c(self, mesh, out, b);
return; }
do { turn_8013b948(self, &pos, mesh); return; } while (0);
    }
    if (!(pos.distSqX(x0, *eye) < 2500.0f)) return;
    if (!in_range_8013b5bc(self, &pos, &at, &self->look, &out)) { turn_8013b948(self, &pos, mesh); return; }
    if (!playing_80181ccc(mesh, self->cue472)) return;
    control_801817e0(mesh, -1);
    play_801359ec(self, mesh, i_804ab100, 1.0f, zero, &self->cue472, zero);
    self->aiming = aiming;
    switch (mood_8013ef50(self)) {
    case 5: {
        play_801359ec(self, mesh, "Pray", 1.0f, zero, &self->cue472, zero);
        speak_8013bd0c(self, "Pray");
        break;
    }
    case 0: case 14: case 16: case 25:
        play_801359ec(self, mesh, "Scream2", 1.0f, 0.0f, &self->cue472, 0.0f);
        break;
    case 1: case 4: case 7: case 18: case 23: case 24:
        {
        unsigned n = rand_80162c20() % 6;
        switch ((int)n) {
        case 0:
            play_801359ec(self, mesh, a_804ab2ac, 1.0f, -1.0f, &self->cue472, 0.0f);
            speak_8013bd0c(self, line_8039edfc);
            break;
        case 1: play_801359ec(self, mesh, b_804ab2cc, 1.0f, -1.0f, &self->cue472, 0.0f); break;
        case 2: play_801359ec(self, mesh, c_804ab2d0, 1.0f, -1.0f, &self->cue472, 0.0f); break;
        case 3: play_801359ec(self, mesh, d_804ab2d4, 1.0f, -1.0f, &self->cue472, 0.0f); break;
        case 4: play_801359ec(self, mesh, e_804ab2e4, 1.0f, -1.0f, &self->cue472, 0.0f); break;
        case 5: play_801359ec(self, mesh, f_804ab2b0, 1.0f, -1.0f, &self->cue472, 0.0f); break;
        }
        }
        break;
    default:
        play_801359ec(self, mesh, c_804ab2d0, 1.0f, -1.0f, &self->cue472, 0.0f);
        break;
    }
}


