#include "w3d_ptr.h"
#line 1 "d26i_pull_towards_sphere_8012100c.cpp"
// GWMP8P rev0 0x8012100c. Moves a point back along its offset from a
// reference when a sphere query along that offset hits.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r(a.x - b.x, a.y - b.y, a.z - b.z); return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r(a.x + b.x, a.y + b.y, a.z + b.z); return r; }
inline Vec operator*(const Vec &a, float s) { Vec r(a.x * s, a.y * s, a.z * s); return r; }
inline Vec operator/(const Vec &a, float s) { float f = 1.0f / s; Vec r(a.x * f, a.y * f, a.z * f); return r; }
struct Spheres {
    void set(const Vec &);
    int nearest(const Vec &, int, int);
 char w3d_empty; };
extern "C" void w3d_handle_member_query_801262c0(Ptr32<Spheres>, const Vec &);
extern "C" int d19c_nearest_sphere_801263fc(Ptr32<Spheres>, const Vec &, int, int);
extern unsigned int lbl_804b1790;
extern const float zero_8039b6ec[];
struct Owner { char u0[144]; Spheres spheres; };
extern "C" void d26i_pull_towards_sphere_8012100c(Ptr32<Owner> self, Vec &a, const Vec &b) {
    Vec start(a);
    Vec d = a - b;
    if (d.lenSq() > zero_8039b6ec[0]) {
        Vec dir = d / 1000.0f;
        w3d_handle_member_query_801262c0(&self->spheres, b);
        if (d19c_nearest_sphere_801263fc(&self->spheres, dir, 1000, -1) != 0xffff) {
            a = b + dir * (float)lbl_804b1790;
        }
    }
}


