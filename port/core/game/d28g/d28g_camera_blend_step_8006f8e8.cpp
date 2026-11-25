#include "w3d_ptr.h"
#line 1 "d28g_camera_blend_step_8006f8e8.cpp"
/* Worms 3D GameCube PAL 0x8006f8e8. Camera step: when the target handle at +76 resolves, fetches three target vectors and blends up (+28) and focus (+16) toward them by the rates at +80 and +84; while locked it unlocks past the +96 distance from the position target, and when unlocked it blends the position (+4) by the rate at +88, then extends bounds with +100 and +104. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float k) const { Vec r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    float dist(const Vec &o) const { float dx = x - o.x, dy = y - o.y, dz = z - o.z; return sqrt_802e82c0(dx * dx + dy * dy + dz * dz); }
};
struct Camera;
extern "C" {
Ptr32<void> w3d_s20_lookup_handle_object_80164fc8(Ptr32<void>);
void w3d_camera_targets_8006fca0(Ptr32<Camera>, Ptr32<Vec>, Ptr32<Vec>, Ptr32<Vec>);
void w3d_k2b_extend_bounds_8015ab54(Ptr32<Camera>, float, float);
}
struct Camera {
    Ptr32<void> vt; Vec pos; Vec focus; Vec up; char u40[76 - 40];
    Ptr32<void> target; float kUp; float kFocus; float kPos; char u92[96 - 92];
    float range; float a100; float a104; int locked;
};
extern "C" void w3d_d28g_camera_blend_step_8006f8e8(Ptr32<Camera> self)
{
    if (w3d_s20_lookup_handle_object_80164fc8(self->target) == 0) return;
    Vec c, b, a;
    w3d_camera_targets_8006fca0(self, &a, &b, &c);
    self->up = c * self->kUp + self->up * (1.0f - self->kUp);
    self->focus = b * self->kFocus + self->focus * (1.0f - self->kFocus);
    if (self->locked) {
        if (self->pos.dist(a) > self->range) self->locked = 0;
    }
    if (!self->locked) self->pos = a * self->kPos + self->pos * (1.0f - self->kPos);
    w3d_k2b_extend_bounds_8015ab54(self, self->a100, self->a104);
}


