#include "w3d_ptr.h"
#line 1 "d24e_build_view_matrix_801a1008.cpp"
// Builds a camera view matrix (Worms 3D GameCube PAL, 0x801a1008).
//
// Gets the basis vectors from 0x801a0cf4, stores them as the rotation rows of
// the matrix at +20 and sets the translation row to minus the dot product of
// the position at +176 with each basis vector.
struct d24e_Vec {
    float x, y, z;
    float Dot(const d24e_Vec &o) const { return x * o.x + y * o.y + z * o.z; }
};
struct Row {
    float x, y, z, w;
    void Set(const float &a, const float &b, const float &c) { x = a; y = b; z = c; }
};
struct Camera {
    char unknown00[20];
    Row m[4];
    char unknown84[92];
    d24e_Vec position;
};
extern "C" void fn_801a0cf4(Ptr32<Camera>, Ptr32<d24e_Vec>, Ptr32<d24e_Vec>, Ptr32<d24e_Vec>);
extern "C" void w3d_d24e_build_view_matrix_801a1008(Ptr32<Camera> self) {
    d24e_Vec a, b, c;
    fn_801a0cf4(self, &a, &b, &c);
    self->m[0].Set(a.x, b.x, c.x);
    Row &r1 = self->m[1]; r1.x = a.y; r1.y = b.y; r1.z = c.y;
    Row &r2 = self->m[2]; r2.x = a.z; r2.y = b.z; r2.z = c.z;
    Row &r3 = self->m[3];
    d24e_Vec &pos = self->position;
    r3.x = -pos.Dot(a);
    r3.y = -pos.Dot(b);
    r3.z = -pos.Dot(c);
}


