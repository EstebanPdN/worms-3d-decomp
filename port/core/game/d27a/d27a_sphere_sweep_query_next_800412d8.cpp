#include "w3d_ptr.h"
#line 1 "d27a_sphere_sweep_query_next_800412d8.cpp"
// GWMP8P rev0 0x800412d8. Next item of a ballistic sphere sweep query: finds
// items whose sphere the moving path enters and refines the hit time. Names
// are inferred from the original instructions.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    float lenSq() const { return x * x + y * y + z * z; }
    Vec &operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
    void normalize() { float k = 1.0f / sqrt_802e82c0(lenSq()); x *= k; y *= k; z *= k; }
};
struct Item {
    Vec position;
    float radius;
    int unknown10;
    unsigned mask;
    int owner;
    int unknown1c;
};
struct Items {
    Ptr32<Item> first; Ptr32<Item> last;
    unsigned size() const { return last - first; }
    Item &operator[](unsigned i) { return first[i]; }
};
extern Items g_items_804273ec[];
extern Vec g_origin_80427408[], g_dir_80427414[], g_axis_8042742c[], g_accel_80427438[], g_delta_80427444[];
extern unsigned short g_ignore_804aa950;
extern unsigned g_mask_804aa954;
extern unsigned short g_cursor_804aa95c, g_current_804aa95e;
extern int g_owner_804aa960;
extern float g_radius_804b17b8, g_range_804b17c8, g_sum_804b17dc, g_sumsq_804b17d8, g_t_804b17a4, g_time_804b17d4;
extern int g_limit_804b17bc, g_ti_804b1790;
extern "C" float w3d_cx12a_quadratic_roots_8009ee18(float c, float b, float a, Ptr32<float> second);
extern "C" int w3d_fn_800406b8(Ptr32<float> roots);
extern const float g_zero_8037479c[];
extern "C" unsigned short w3d_d27a_sphere_sweep_query_next_800412d8()
{
    for (; g_cursor_804aa95c < g_items_804273ec[0].size(); g_cursor_804aa95c++) {
        if (g_cursor_804aa95c == g_ignore_804aa950) continue;
        Item &it = g_items_804273ec[0][g_cursor_804aa95c];
        if (!(it.mask & g_mask_804aa954)) continue;
        if (it.owner == g_owner_804aa960) continue;
        g_sum_804b17dc = g_radius_804b17b8 + it.radius;
        g_delta_80427444[0].x = g_origin_80427408[0].x - it.position.x;
        g_delta_80427444[0].y = g_origin_80427408[0].y - it.position.y;
        g_delta_80427444[0].z = g_origin_80427408[0].z - it.position.z;
        g_sumsq_804b17d8 = g_sum_804b17dc * g_sum_804b17dc;
        if (g_delta_80427444[0].lenSq() < g_sumsq_804b17d8) {
            g_t_804b17a4 = g_zero_8037479c[0];
            g_current_804aa95e = g_cursor_804aa95c++;
            return g_current_804aa95e;
        }
        float range = g_range_804b17c8; float zero = g_zero_8037479c[0];
        if (!(range > zero)) continue;
        float h = g_delta_80427444[0].dot(g_axis_8042742c[0]);
        if (!(h > -g_sum_804b17dc)) continue;
        if (!(h <= g_sum_804b17dc)) continue;
        float s = sqrt_802e82c0(g_sumsq_804b17d8 - h * h);
        Vec c = g_axis_8042742c[0];
        c *= h;
        c += it.position;
        Vec n = g_delta_80427444[0];
        n.normalize();
        float t = -1.0f;
        Vec m;
        m.x = n.y * g_axis_8042742c[0].z - n.z * g_axis_8042742c[0].y;
        m.y = n.z * g_axis_8042742c[0].x - n.x * g_axis_8042742c[0].z;
        m.z = n.x * g_axis_8042742c[0].y - n.y * g_axis_8042742c[0].x;
        float limit = (float)g_limit_804b17bc;
        float roots[8];
        float a = n.dot(g_accel_80427438[0]) * 0.5f;
        float b = n.dot(g_dir_80427414[0]);
        float d = n.dot(g_delta_80427444[0]);
        roots[0] = w3d_cx12a_quadratic_roots_8009ee18(d - s, b, a, &roots[1]);
        roots[2] = w3d_cx12a_quadratic_roots_8009ee18(d + s, b, a, &roots[3]);
        a = m.dot(g_accel_80427438[0]) * 0.5f;
        b = m.dot(g_dir_80427414[0]);
        d = m.dot(g_delta_80427444[0]);
        roots[4] = w3d_cx12a_quadratic_roots_8009ee18(d - s, b, a, &roots[5]);
        roots[6] = w3d_cx12a_quadratic_roots_8009ee18(d + s, b, a, &roots[7]);
        if (roots[0] > limit) roots[0] = -1.0f;
        if (roots[1] > limit) roots[1] = -1.0f;
        if (roots[2] > limit) roots[2] = -1.0f;
        if (roots[3] > limit) roots[3] = -1.0f;
        if (roots[4] > limit) roots[4] = -1.0f;
        if (roots[5] > limit) roots[5] = -1.0f;
        if (roots[6] > limit) roots[6] = -1.0f;
        if (roots[7] > limit) roots[7] = -1.0f;
        if (roots[0] < zero) { roots[0] = roots[1]; roots[1] = -1.0f; }
        if (roots[2] < zero) { roots[2] = roots[3]; roots[3] = -1.0f; }
        if (roots[4] < zero) { roots[4] = roots[5]; roots[5] = -1.0f; }
        if (roots[6] < zero) { roots[6] = roots[7]; roots[7] = -1.0f; }
        if (w3d_fn_800406b8(roots)) {
            g_t_804b17a4 = g_time_804b17d4;
            g_ti_804b1790 = (int)g_time_804b17d4;
            g_current_804aa95e = g_cursor_804aa95c++;
            return g_current_804aa95e;
        }
    }
    return 0xffff;
}


