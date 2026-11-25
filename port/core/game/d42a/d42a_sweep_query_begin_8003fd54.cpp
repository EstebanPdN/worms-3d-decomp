#include "w3d_ptr.h"
#line 1 "d42a_sweep_query_begin_8003fd54.cpp"
// GWMP8P rev0 0x8003fd54. Starts a query against the 32-byte item vector for
// item index moving by a with radius from the item: stores origin,
// direction, side vector, limit and owner in the query globals and picks the
// next-item function: sphere if a is zero, ray if b is zero, else the sweep,
// with the plane normal of a and b, or the unit axis when they are parallel.
// Names are inferred from the original instructions and the three query
// functions.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    float lenSq() const { return x * x + y * y + z * z; }
};
struct Mid {
    float x, y, z;
    Mid() {}
    Mid(const Mid &o) { x = o.x; y = o.y; z = o.z; }
};
inline Mid scaled(const Vec &a, float f) { Mid r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
struct Item {
    Vec centre;
    float radius;
    int unknown10;
    unsigned mask;
    int owner;
    int unknown1c;
};
struct Items { Ptr32<Item> first; Ptr32<Item> last; Item &operator[](unsigned i) { return first[i]; } };
extern Items g_items_804273ec[];
extern Vec g_origin_80427408[], g_dir_80427414[], g_normal_8042742c[], g_side_80427438[];
extern Mid g_axis_80427420[];
extern unsigned short g_ignore_804aa950, g_cursor_804aa95c;
extern int g_mask_804aa954, g_active_804aa958, g_owner_804aa960, g_ti_804b1790, g_limit_804b17bc;
typedef Ptr32<int (void)> Next;
extern Next g_next_804b17b4;
extern float g_radsq_804b17b0, g_radius_804b17b8, g_a_804b17c0, g_b_804b17c4, g_c_804b17c8, g_len_804b17cc;
extern "C" int w3d_d26a_sphere_query_next_8003ffb8();
extern "C" int w3d_d26a_ray_query_next_800400f0();
extern "C" int w3d_fn_800412d8();
extern "C" void w3d_d42a_sweep_query_begin_8003fd54(int index, int mask, Ptr32<const Vec> a, Ptr32<const Vec> b, int limit, int owner)
{
    Item &it = g_items_804273ec[0][index];
    g_origin_80427408[0] = it.centre;
    float r = it.radius;
    g_dir_80427414[0] = *a;
    g_radsq_804b17b0 = r * r;
    g_side_80427438[0] = *b;
    g_active_804aa958 = 1;
    float aa = a->lenSq();
    g_cursor_804aa95c = 0;
    g_mask_804aa954 = mask;
    g_owner_804aa960 = owner;
    g_ignore_804aa950 = index;
    g_radius_804b17b8 = r;
    g_a_804b17c0 = aa;
    float bb = b->lenSq();
    g_b_804b17c4 = bb;
    g_ti_804b1790 = 0;
    g_limit_804b17bc = limit;


    if (aa == 0.0f) {
        g_next_804b17b4 = w3d_d26a_sphere_query_next_8003ffb8;
    } else if (bb == 0.0f) {
        g_next_804b17b4 = w3d_d26a_ray_query_next_800400f0;
    } else {
        Vec &n = g_normal_8042742c[0];
        n.x = a->y * b->z - a->z * b->y;
        g_next_804b17b4 = w3d_fn_800412d8;
        n.y = a->z * b->x - a->x * b->z;
        n.z = a->x * b->y - a->y * b->x;
        float l = n.lenSq();
        g_c_804b17c8 = l;
        if (l == 0.0f) {
            float len = sqrt_802e82c0(aa);
            g_len_804b17cc = len;
            g_axis_80427420[0] = scaled(*a, 1.0f / len);
        } else {
            float f = 1.0f / sqrt_802e82c0(l);
            n.x *= f; n.y *= f; n.z *= f;
        }
    }
}


