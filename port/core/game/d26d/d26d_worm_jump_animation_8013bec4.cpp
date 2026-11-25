#include "w3d_ptr.h"
#line 1 "d26d_worm_jump_animation_8013bec4.cpp"
// GWMP8P rev0 0x8013bec4. Start a worm's jump animation when no state is
// active (+144 is -1) and the jump direction is not too low: rotate the
// direction into the worm frame, choose motion and animation from the local
// slope, and play it at the right rate; when the jump takes longer than the
// animation also set the end time (+672) and sync the held item, looping
// Flap for weapon 16 and playing the same animation otherwise. Finally
// restart the run layer. Names are inferred.
extern "C" float asin_802e83ec(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Transform {
    Axis axis[3]; Pos position;
    const Axis &A(int i) const { return axis[i]; }
    const Pos &P() const { return position; }
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * A(0).x + v.y * A(1).x + v.z * A(2).x + P().x;
        o.y = v.x * A(0).y + v.y * A(1).y + v.z * A(2).y + P().y;
        o.z = v.x * A(0).z + v.y * A(1).z + v.z * A(2).z + P().z;
    }
};
struct Mesh;
struct Worm {
    char u0[68]; float yaw; char u48[72]; int f90; char u94[20]; Ptr32<Mesh> held; char uac[300];
    int ctrlBody; char u1dc[8]; int ctrlHeld; char u1e8[4]; int ctrlRun; char u1f0[176]; int f2a0; int f2a4; char u2a8[4]; int weapon;
};
extern "C" void construct_801f7538(Ptr32<Transform>, float, float, float, float);
extern "C" float jump_time_80137d6c(Ptr32<Worm>, Ptr32<Vec>);
extern "C" int ticks_8015fd14();
extern "C" float duration_80181d30(Ptr32<Mesh>, Ptr32<const char>);
extern "C" int play_801359ec(Ptr32<Worm>, Ptr32<Mesh>, Ptr32<const char>, Ptr32<int>, float, float, float);
extern Vec reference_8045e788;
extern const char spin_8039f898[];
extern int mA_804ab380, mB_804ab384, mC_804ab37c, mD_804ab378;
extern Ptr32<const char> nA_804ab114; extern Ptr32<const char> nB_804ab130; extern Ptr32<const char> nC_804ab124; extern Ptr32<const char> nD_804ab11c; extern Ptr32<const char> nRun_804ab100;
extern "C" void d26d_worm_jump_animation_8013bec4(Ptr32<Worm> self, Ptr32<Mesh> mesh) {
    Vec v = reference_8045e788;
    float time = jump_time_80137d6c(self, &v);
    if (self->f90 != -1 || v.y < -0.25f) return;
    Transform t;
    construct_801f7538(&t, 0.0f, 1.0f, 0.0f, -self->yaw);
    Vec o;
    t.apply(o, v);
    Ptr32<const char> name;
    float limit = 0.0f;
    if (o.z > limit) {
        name = nA_804ab114;
        limit = 0.125f;
        self->f2a4 = mA_804ab380;
    } else {
        float a = asin_802e83ec(o.z / o.y);
        if (a < 0.02f) {
            name = nB_804ab130;
            limit = 0.083333336f;
            self->f2a4 = mB_804ab384;
        } else if (a < 0.25f) {
            name = nC_804ab124;
            limit = 0.125f;
            self->f2a4 = mC_804ab37c;
        } else {
            name = nD_804ab11c;
            limit = 0.083333336f;
            self->f2a4 = mD_804ab378;
        }
    }
    if (time > limit) {
        play_801359ec(self, mesh, name, &self->ctrlBody, 1.0f, time - limit, 0.0f);
        self->f2a0 = ticks_8015fd14() + (int)((time - limit) * 1000.0f);
        if (self->held && (self->weapon == 13 || self->weapon == 16)) {
            if (self->weapon == 16) {
                float d = duration_80181d30(self->held, spin_8039f898);
                if (d > 0.0f) {
                    int n = (int)((time - limit) / d);
                    for (int i = 0; i < n; i++)
                        play_801359ec(self, self->held, spin_8039f898, &self->ctrlHeld, 1.0f, -1.0f, 0.0f);
                }
            }
            play_801359ec(self, self->held, name, &self->ctrlHeld, 1.0f, time - limit, 0.0f);
        }
    } else if (time != 0.0f) {
        play_801359ec(self, mesh, name, &self->ctrlBody, limit / time, 0.0f, 0.0f);
    }
    play_801359ec(self, mesh, nRun_804ab100, &self->ctrlRun, 1.0f, -1.0f, 0.0f);
}


