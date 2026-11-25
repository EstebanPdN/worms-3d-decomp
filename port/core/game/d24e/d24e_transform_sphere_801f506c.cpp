#include "w3d_ptr.h"
#line 1 "d24e_transform_sphere_801f506c.cpp"
// Transforms a bounding sphere by a 4x3 matrix (12-byte rows) (Worms 3D GameCube PAL, 0x801f506c).
//
// The centre goes through the matrix. The radius is multiplied by the square
// root (0x802e82c0) of the largest squared axis length, unless that value is
// within 0.01 of 1.0 (constant 0x803b1598), when the radius is copied. The
// lengths are compared as integers on their float bits, and the distance from
// one through the masked bits against those of 0.01f.
struct d24e_Row { float x, y, z; };
struct d24e_Sphere { float x, y, z, radius; };
struct d24e_Matrix { d24e_Row r[3]; d24e_Row t; };
extern "C" float fn_802e82c0(float);
extern const float constant_803b1598[];
inline int AsInt(float f) { return *(Ptr32<int>)&f; }
inline float AsFloat(int i) { union { float f; int i; } u; u.i = i; return u.f; }
inline const int &MaxRef(const int &a, const int &b) { return a < b ? b : a; }
inline int MaxInt(int a, int b) { return a < b ? b : a; }

extern "C" void w3d_d24e_transform_sphere_801f506c(Ptr32<d24e_Sphere> out, Ptr32<const d24e_Matrix> m, Ptr32<const d24e_Sphere> in) {
    const d24e_Row &r0 = m->r[0];
    const d24e_Row &r1 = m->r[1];
    const d24e_Row &r2 = m->r[2];
    const d24e_Row &t = m->t;
    out->x = in->x * r0.x + in->y * r1.x + in->z * r2.x + t.x;
    out->y = in->x * r0.y + in->y * r1.y + in->z * r2.y + t.y;
    out->z = in->x * r0.z + in->y * r1.z + in->z * r2.z + t.z;
    float a = r0.x * r0.x + r0.y * r0.y + r0.z * r0.z;
    float b = r1.x * r1.x + r1.y * r1.y + r1.z * r1.z;
    float c = r2.x * r2.x + r2.y * r2.y + r2.z * r2.z;
    int ia = AsInt(a);
    int ib = AsInt(b);
    float s = AsFloat(MaxInt(MaxRef(ia, ib), AsInt(c)));
    unsigned limit = 0x3c23d70a;
    if ((unsigned)(AsInt(s - constant_803b1598[0]) & 0x7fffffff) < limit) out->radius = in->radius;
    else out->radius = fn_802e82c0(s) * in->radius;
}


