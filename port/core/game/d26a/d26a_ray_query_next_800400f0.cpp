#include "w3d_ptr.h"
#line 1 "d26a_ray_query_next_800400f0.cpp"
// GWMP8P rev0 0x800400f0. Next item of a moving-sphere query: tests the
// swept ray from the query origin against each item sphere with the
// quadratic discriminant. Names are inferred from the original instructions.
extern "C" float sqrt_802e82c0(float);
struct Vec { float x, y, z; float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; } float lenSq() const { return x * x + y * y + z * z; } };
struct Item {
    float x, y, z, radius;
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
extern Vec g_origin_80427408[], g_dir_80427414[], g_delta_80427444[];
extern unsigned short g_ignore_804aa950;
extern unsigned g_mask_804aa954;
extern unsigned short g_cursor_804aa95c, g_current_804aa95e;
extern int g_owner_804aa960, g_past_804aa964;
extern float g_radius_804b17b8, g_a_804b17c0, g_dist_804b17d0, g_t_804b17a4;
extern int g_limit_804b17bc, g_ti_804b1790;
extern const float g_four_8037473c[];
extern "C" int w3d_d26a_ray_query_next_800400f0()
{
    while (g_cursor_804aa95c < g_items_804273ec[0].size()) {
        if (g_cursor_804aa95c != g_ignore_804aa950) {
            Item &it = g_items_804273ec[0][g_cursor_804aa95c];
            if ((it.mask & g_mask_804aa954) && it.owner != g_owner_804aa960) {
                g_delta_80427444[0].x = g_origin_80427408[0].x - it.x;
                g_delta_80427444[0].y = g_origin_80427408[0].y - it.y;
                g_delta_80427444[0].z = g_origin_80427408[0].z - it.z;
                g_dist_804b17d0 = g_delta_80427444[0].lenSq();
                float h = g_delta_80427444[0].dot(g_dir_80427414[0]);
                float b = h + h;
                float rr = it.radius + g_radius_804b17b8;
                float disc = b * b - g_a_804b17c0 * g_four_8037473c[0] * (g_dist_804b17d0 - rr * rr);
                if (disc >= 0.0f) {
                    float s = sqrt_802e82c0(disc);
                    float x = -b;
                    float t1 = x - s;
                    float t = -1.0f;
                    float n = x;
                    if (t1 > 0.0f) t = t1 / (g_a_804b17c0 + g_a_804b17c0);
                    else {
                        x = s - b;
                        if (x > 0.0f) t = 0.0f;
                    }
                    if (t >= 0.0f) {
                        float limit = (float)g_limit_804b17bc;
                        if (t < limit) {
                            g_t_804b17a4 = t; g_current_804aa95e = g_cursor_804aa95c++;
 g_past_804aa964 = (n + s) / (g_a_804b17c0 + g_a_804b17c0) > limit; g_ti_804b1790 = (int)t;
 return g_current_804aa95e;
                        }
                    }
                }
            }
        }
        ++g_cursor_804aa95c;
    }
    return 0xffff;
}


