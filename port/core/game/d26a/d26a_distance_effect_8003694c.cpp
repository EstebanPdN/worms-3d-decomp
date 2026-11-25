#include "w3d_ptr.h"
#line 1 "d26a_distance_effect_8003694c.cpp"
// GWMP8P rev0 0x8003694c. Distance-scaled effect: strength falls off
// linearly with distance from the current body, scaled by three properties.
// Names are inferred from the original instructions.
extern "C" float sqrt_802e82c0(float);
extern "C" float w3d_value_80178df0(Ptr32<void>);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Body { int unknown00; Vec position; };
struct World {
    char unknown00[312];
    int current;       /* +312 */
    Ptr32<Ptr32<Body>> bodies;     /* +316 */
    Ptr32<Body> Current() { return *(Ptr32<Ptr32<Body>>)((Ptr32<char>)bodies + (current << 2)); }
};
extern Ptr32<World> g_world_804aa8c8;
struct Thing {
    char unknown00[20];
    int range;         /* +20 */
    int radius;        /* +24 */
    int count;         /* +28 */
};
extern "C" Ptr32<void> w3d_fn_8003671c(Ptr32<Thing>);
extern "C" void w3d_fn_80036abc(Ptr32<void>, int, float, unsigned);

inline float Distance(const Vec &a, const Vec &b)
{
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
}

extern "C" void w3d_d26a_distance_effect_8003694c(Ptr32<Thing> self, Ptr32<const Vec> v, float s, float d)
{
    float a = s * w3d_value_80178df0((Ptr32<void>)w3d::G(self->range));
    float b = d * w3d_value_80178df0((Ptr32<void>)w3d::G(self->radius));
    Vec p = g_world_804aa8c8->Current()->position;
    float dist = Distance(p, *v);
    unsigned n = (unsigned)(s * w3d_value_80178df0((Ptr32<void>)w3d::G(self->count)));
    if (dist < b && n) {
        float e = (b - dist) * a / b;
        w3d_fn_80036abc(w3d_fn_8003671c(self), 0, e, n);
    }
}


