#include "w3d_ptr.h"
#line 1 "d26d_worm_apply_aim_8013c21c.cpp"
// GWMP8P rev0 0x8013c21c. Blend the worm's aim yaw and pitch (+664, +668)
// toward clamped targets (within 60 degrees), feed both to the mesh blend
// controls, then unless the mode is 1 or 18 and while no aim animation is
// playing, pick and play an aim animation: alternate or idle when already
// aimed, or one of three by random for modes 22 and 21. Names are inferred.
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline float clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Mesh;
struct Worm {
    char u0[476]; int control; char u1e0[16]; int mode; char u1f4[160]; int aimed; float yaw; float pitch; char u2a0[64]; int f2e0;
};
extern "C" int blend_80181814(Ptr32<Mesh>, Ptr32<const char>, float, float);
extern "C" int playing_80181ccc(Ptr32<Mesh>, int);
extern "C" unsigned rand_80162c20();
extern "C" int play_801359ec(Ptr32<Worm>, Ptr32<Mesh>, Ptr32<const char>, Ptr32<int>, float, float, float);
extern Ptr32<const char> blendYaw_804ab31c; extern Ptr32<const char> blendPitch_804ab320;
extern Ptr32<const char> aimAlt_804ab244; extern Ptr32<const char> aimIdle_804ab16c;
extern Ptr32<const char> a0_804ab388; extern Ptr32<const char> a1_804ab38c; extern Ptr32<const char> a2_804ab390; extern Ptr32<const char> b0_804ab394; extern Ptr32<const char> b1_804ab398; extern Ptr32<const char> b2_804ab39c;
extern "C" void d26d_worm_apply_aim_8013c21c(Ptr32<Worm> self, Ptr32<Mesh> mesh, float yaw, float pitch) {
    self->yaw = self->yaw * 0.74f + clamp(-yaw, -1.0471976f, 1.0471976f) * 0.26f;
    float half = 0.5f;
    blend_80181814(mesh, blendYaw_804ab31c, self->yaw / 1.0471976f * half + half, 1.0f);
    self->pitch = self->pitch * 0.81f + -pitch * 0.19f;
    self->pitch = clamp(self->pitch, -1.0471976f, 1.0471976f);
    blend_80181814(mesh, blendPitch_804ab320, self->pitch / 1.0471976f * half + half, 1.0f);
    if (self->mode == 1 || self->mode == 18) return;
    if (self->control == -1 || playing_80181ccc(mesh, self->control)) {
        if (self->aimed) {
            if ((rand_80162c20() & 3) == 0 && self->f2e0)
                play_801359ec(self, mesh, aimAlt_804ab244, &self->control, 1.0f, 0.0f, 0.0f);
            else
                play_801359ec(self, mesh, aimIdle_804ab16c, &self->control, 1.0f, 0.0f, 0.0f);
        } else if (self->mode == 22) {
            int r = rand_80162c20() % 3;
            switch (r) {
            case 0: play_801359ec(self, mesh, a0_804ab388, &self->control, 1.0f, 0.0f, 0.0f); break;
            case 1: play_801359ec(self, mesh, a1_804ab38c, &self->control, 1.0f, 0.0f, 0.0f); break;
            case 2: play_801359ec(self, mesh, a2_804ab390, &self->control, 1.0f, 0.0f, 0.0f); break;
            }
        } else if (self->mode == 21) {
            int r = rand_80162c20() % 3;
            switch (r) {
            case 0: play_801359ec(self, mesh, b0_804ab394, &self->control, 1.0f, 0.0f, 0.0f); break;
            case 1: play_801359ec(self, mesh, b1_804ab398, &self->control, 1.0f, 0.0f, 0.0f); break;
            case 2: play_801359ec(self, mesh, b2_804ab39c, &self->control, 1.0f, 0.0f, 0.0f); break;
            }
        }
    }
    self->aimed = 1;
}


