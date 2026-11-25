#include "w3d_ptr.h"
#line 1 "d27a_motion_step_trace_8001b964.cpp"
// GWMP8P rev0 0x8001b964. Steps a motion along its velocity with up to ten
// traces until the remaining step is short enough. Names are inferred from
// the original instructions.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float LengthSq() const { return x * x + y * y + z * z; }
};
struct Motion {
    Vec position;      /* +0 */
    char unknown0c[12];
    Vec offset;        /* +24 */
};
extern Motion w3d_motion_8041e780;
extern Vec w3d_step_8041e850;
extern Vec w3d_goal_8041e85c;
extern Vec w3d_hit_8043ae20;
extern unsigned w3d_hit_time_804b1764;
extern "C" void w3d_trace_800b0824(Vec &, const Vec &, const Vec &, int, int);
extern "C" void w3d_cx11a_linear_sample_800d76dc(Ptr32<Motion>, Vec &, float);
extern "C" void w3d_cx14a_dispatch_normal_8001baf4(Vec &);
extern "C" int w3d_motion_at_height_80118a5c(Ptr32<Motion>, float, Ptr32<const Vec>, int);
extern "C" void w3d_d27a_motion_step_trace_8001b964(float limit, float height)
{
    Vec v = w3d_step_8041e850;
    Vec p = w3d_motion_8041e780.position;
    if (v.LengthSq() > limit) {
        int n = 9;
        do {
            Ptr32<Motion> m = &w3d_motion_8041e780;
            w3d_trace_800b0824(p, v, m->offset, 10000, 1);
            if (w3d_hit_time_804b1764 >= 10000) {
                w3d_motion_at_height_80118a5c(m, height, &w3d_goal_8041e85c, 0);
                return;
            }
            w3d_goal_8041e85c = w3d_hit_8043ae20;
            p = w3d_hit_8043ae20;
            w3d_cx11a_linear_sample_800d76dc(m, v, (float)w3d_hit_time_804b1764);
            w3d_cx14a_dispatch_normal_8001baf4(v);
            if (!(v.LengthSq() > limit)) return;
        } while (n-- > 0);
    }
}


