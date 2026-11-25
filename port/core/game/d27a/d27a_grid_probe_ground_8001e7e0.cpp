#include "w3d_ptr.h"
#line 1 "d27a_grid_probe_ground_8001e7e0.cpp"
// GWMP8P rev0 0x8001e7e0. Traces a square of rays downwards to find the
// ground heights under a footprint. Names are inferred from the original
// instructions.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Self { char unknown00[104]; float width; float floor; };
extern float g_margin_804aa790;
extern unsigned g_hit_time_804b1764;
extern int g_hit_kind_804b1784;
extern Vec g_hit_8043ae20[];
extern char g_hit_object_8043ae38[];
extern "C" void w3d_trace_800b0824(Vec &, const Vec &, const Vec &, int, int);
extern "C" void s19_dispatch_indexed_800bd920();
extern "C" int w3d_motion_slope_allowed(Ptr32<void>);
extern "C" int w3d_d27a_grid_probe_ground_8001e7e0(Ptr32<Self> self, const Vec &pos, const Vec &delta, Ptr32<float> low, Ptr32<float> high, Ptr32<char> flag)
{
    *high = self->floor;
    *low = pos.y;
    int result = 0;
    float half = 0.5f;
    const float one = 1.0f;
    float w = half + half;
    float r = self->width / (w + w);
    float limit = pos.y - g_margin_804aa790 * half;
    for (float u = -half; u <= half; ) {
        float step = half + half;
        for (float v = -half; v <= half; v += one) {
            Vec a = pos;
            a.x += u * r;
            a.z += v * r;
            Vec b(0.0f, 0.0f, 0.0f);
            w3d_trace_800b0824(a, delta, b, 1000, 1);
            if ((float)g_hit_time_804b1764 != 1001.0f) {
                float y = g_hit_8043ae20[0].y;
                if (y > limit) return 0;
                if (y > *high) *high = y;
                if (y <= *low) {
                    *low = y;
                    if (y < self->floor) {
                        *low = self->floor;
                        *flag = 1;
                        return 1;
                    }
                }
                if (g_hit_kind_804b1784 == 0) s19_dispatch_indexed_800bd920();
                if (!w3d_motion_slope_allowed(g_hit_object_8043ae38)) result = 2;
            } else {
                *low = self->floor;
                *flag = 1;
                return 1;
            }
        }
        u += step;
    }
    *flag = result;
    return 1;
}


