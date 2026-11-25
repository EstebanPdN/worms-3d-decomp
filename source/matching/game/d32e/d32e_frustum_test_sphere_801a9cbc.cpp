// (Worms 3D GameCube PAL, 0x801a9cbc).
//
// Tests a sphere against a view frustum: transforms it into view space, then
// checks six planes (a general plane loop, or the axis-aligned symmetric
// form when the ortho flag at +60 is set). Returns 0 outside, 1 intersecting
// (and sets the flag at +44), 2 fully inside.

struct Sphere { float x, y, z, r; };
struct Plane { float a, b, c, d; };
extern "C" void w3d_d24e_transform_sphere_801f5214(Sphere *out, void *m, const Sphere *in);
// Partial view: a culling camera. Field names are inferred from their use.
struct Frustum {
    char u0[44]; int outside; char u48[8]; void *xf; int ortho;
    Plane plane[6];
};
static inline float Abs(float v) { *(int *)&v &= 0x7fffffff; return v; }
extern "C" int w3d_d32e_frustum_test_sphere_801a9cbc(Frustum *self, const Sphere *in)
{
    Sphere s;
    w3d_d24e_transform_sphere_801f5214(&s, self->xf, in);
    bool inside = true;
    if (self->ortho) {
        float d = self->plane[4].d - s.z;
        if (Abs(d) < s.r) inside = false; else if (d < 0.0f) return 0;
        d = s.z + self->plane[5].d;
        if (Abs(d) < s.r) inside = false; else if (d < 0.0f) return 0;
        float e;
        {
            float a = self->plane[0].c * s.z, b = self->plane[0].a * s.x;
            d = a - b; e = a + b;
        }
        if (Abs(d) < s.r) inside = false; else if (d < 0.0f) return 0;
        if (Abs(e) < s.r) inside = false; else if (e < 0.0f) return 0;
        {
            float a = self->plane[2].c * s.z, b = self->plane[2].b * s.y;
            d = a - b; e = a + b;
        }
        if (Abs(d) < s.r) inside = false; else if (d < 0.0f) return 0;
        if (Abs(e) < s.r) inside = false; else if (e < 0.0f) return 0;
    } else {
        s.z = -s.z;
        Sphere *c = &s;
        Plane *p = self->plane;
        for (int i = 0; i < 6; i++, p++) {
            float d = c->x * p->a + c->y * p->b + c->z * p->c + p->d;
            if (Abs(d) < s.r) inside = false; else if (d < 0.0f) return 0;
        }
    }
    self->outside = inside ? false : true;
    if (inside) return 2;
    return 1;
}
