// d17d: 0x801410f8 (388 bytes). Collision shape initialiser: set state 10 and,
// on first use (cached radius 0), compute the bounding box of the ten shape
// points 0x80453030, store its centre in 0x804530a8 and half its diagonal
// length in the radius 0x804ab3cc. Built with -mps-float (SN paired-single
// mode), which reserves the original frame slot below the FPR save area.
struct D17dVec3 {
    float x, y, z;
    D17dVec3() {}
    D17dVec3(float a, float b, float c) { x = a; y = b; z = c; }
    void Min(const D17dVec3 &o) { if (o.x < x) x = o.x; if (o.y < y) y = o.y; if (o.z < z) z = o.z; }
    void Max(const D17dVec3 &o) { if (o.x > x) x = o.x; if (o.y > y) y = o.y; if (o.z > z) z = o.z; }
};
struct D17dShape { unsigned char unknown00[36]; int state; };
extern "C" {
extern D17dVec3 w3d_points_80453030[];
extern D17dVec3 w3d_center_804530a8[];
extern float w3d_radius_804ab3cc;
float w3d_sqrt_802e82c0(float);
D17dShape *d17d_collision_shape_initialize_801410f8(D17dShape *self);
}
static inline void d17d_bounds(const D17dVec3 &lo, D17dVec3 &hi)
{
    w3d_center_804530a8[0].x = (lo.x + hi.x) * 0.5f;
    w3d_center_804530a8[0].y = (lo.y + hi.y) * 0.5f;
    w3d_center_804530a8[0].z = (lo.z + hi.z) * 0.5f;
    hi.x -= lo.x; hi.y -= lo.y; hi.z -= lo.z;
    w3d_radius_804ab3cc = w3d_sqrt_802e82c0(hi.x * hi.x + hi.y * hi.y + hi.z * hi.z) * 0.5f;
}
D17dShape *d17d_collision_shape_initialize_801410f8(D17dShape *self)
{
    self->state = 10;
    if (w3d_radius_804ab3cc == 0.0f) {
        D17dVec3 low(0.0f, 0.0f, 0.0f);
        D17dVec3 high(0.0f, 0.0f, 0.0f);
        for (int i = 0; i < 10; i++) {
            low.Min(w3d_points_80453030[i]);
            high.Max(w3d_points_80453030[i]);
        }
        d17d_bounds(low, high);
    }
    return self;
}
