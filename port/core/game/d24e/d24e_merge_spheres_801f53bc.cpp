#include "w3d_ptr.h"
#line 1 "d24e_merge_spheres_801f53bc.cpp"
// Merges two bounding spheres into the smallest enclosing one (Worms 3D GameCube PAL, 0x801f53bc).
//
// A sphere with a negative radius is empty, so the other is returned. If one
// sphere contains the other (squared radius difference at least the squared
// distance), the larger is returned. Otherwise the centre moves along the line
// between them by (distance + dr) / (2 * distance), unless the distance is at
// most 0x803b15a4, and the radius becomes half of distance + both radii.
// Built with -mps-float (one saved FPR in a non-leaf function).
struct d24e_Vec {
    float x, y, z;
    d24e_Vec() {}
    d24e_Vec(float a, float b, float c) : x(a), y(b), z(c) {}
    d24e_Vec(const d24e_Vec &o) : x(o.x), y(o.y), z(o.z) {}
    d24e_Vec operator-(const d24e_Vec &o) const { d24e_Vec r(x - o.x, y - o.y, z - o.z); return r; }
    d24e_Vec operator+(const d24e_Vec &o) const { d24e_Vec r(x + o.x, y + o.y, z + o.z); return r; }
    d24e_Vec operator*(float s) const { d24e_Vec r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    float LengthSq() const { return x * x + y * y + z * z; }
};
struct d24e_Sphere {
    d24e_Vec c;
    float r;
    int IsEmpty(float zero) const { int e = r < zero; return e; }
};
extern const float constant_803b15a0[], constant_803b15a4[], constant_803b15a8[];
extern "C" float fn_802e82c0(float);

extern "C" Ptr32<d24e_Sphere> w3d_d24e_merge_spheres_801f53bc(Ptr32<d24e_Sphere> out, Ptr32<const d24e_Sphere> a, Ptr32<const d24e_Sphere> b) {
    float zero = constant_803b15a0[0];
    if (a->IsEmpty(zero)) { *out = *b; return out; }
    if (b->IsEmpty(zero)) { *out = *a; return out; }
    float dr = b->r - a->r;
    d24e_Vec d = b->c - a->c;
    float d2 = d.LengthSq();
    if (dr * dr >= d2) {
        if (dr >= zero) *out = *b; else *out = *a;
        return out;
    }
    float dist = fn_802e82c0(d2);
    if (dist > constant_803b15a4[0]) {
        float t = (dist + dr) / (dist + dist);
        out->c = a->c + d * t;
    } else {
        out->c = a->c;
    }
    out->r = (dist + a->r + b->r) * constant_803b15a8[0];
    return out;
}


