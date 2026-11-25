#include "w3d_ptr.h"
#line 1 "k2b_a_8014d59c.cpp"
struct K2bVec3 {
    float x, y, z;
    K2bVec3() {}
    K2bVec3(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
struct K2bWorm { char pad0[560]; float pos_x; float pos_y; char pad1[120]; float probe; };
extern unsigned int w3d_global_804b1764;
extern "C" void w3d_ground_probe_800b0824(Ptr32<void> a, Ptr32<K2bVec3> dir, Ptr32<void> b, int steps, int flags);
extern "C" void w3d_motion_get_contact_point(Ptr32<K2bVec3> out, Ptr32<K2bWorm> self);
extern "C" int w3d_k2b_is_near_ground_8014d59c(Ptr32<K2bWorm> self)
{
    K2bVec3 dir(0.0f, -100.0f, 0.0f);
    w3d_ground_probe_800b0824(&self->pos_x, &dir, &self->probe, 20, 1);
    int result;
    if (w3d_global_804b1764 <= 20) {
        K2bVec3 hit_copy;
        K2bVec3 hit;
        w3d_motion_get_contact_point(&hit, self);
        hit_copy = hit;
        result = self->pos_y - hit_copy.y < 10.0f;
    } else {
        result = 0;
    }
    return result;
}
// desc: Appears to probe downward from the worm and report whether the contact point lies within ten units below it.


