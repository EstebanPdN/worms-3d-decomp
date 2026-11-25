#include "w3d_ptr.h"
#line 1 "d18d_camera_view_matrix_8015aa04.cpp"
// d18d: 0x8015aa04 (276 bytes). Camera view matrix: fetch the camera basis
// (right, up, forward) from 0x8015a6f0, store it transposed into rows 0-2 and
// write the negated dot products of the camera position with each axis into
// row 3. Rows are filled through row references and a free Dot(); the d16d
// Row::Set draft lost the register reuse of the axis components in row 3.
struct D18dVec3 { float x, y, z; };
struct D18dRow { float x, y, z, w; };
struct D18dMatrix4 { D18dRow row[4]; };
// Partial view: only the position at +4 is used here.
struct D18dCamera { int unknown0; D18dVec3 position; };
extern "C" {
void w3d_camera_basis_8015a6f0(Ptr32<D18dCamera> self, Ptr32<D18dVec3> right, Ptr32<D18dVec3> up, Ptr32<D18dVec3> forward);
void d18d_camera_view_matrix_8015aa04(Ptr32<D18dCamera> self, Ptr32<D18dMatrix4> m);
}
static inline float d18d_dot(const D18dVec3 &a, const D18dVec3 &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
void d18d_camera_view_matrix_8015aa04(Ptr32<D18dCamera> self, Ptr32<D18dMatrix4> m)
{
    D18dVec3 right, up, forward;
    w3d_camera_basis_8015a6f0(self, &right, &up, &forward);
    D18dRow &r0 = m->row[0];
    r0.x = right.x; r0.y = up.x; r0.z = forward.x; r0.w = 0.0f;
    D18dRow &r1 = m->row[1];
    r1.x = right.y; r1.y = up.y; r1.z = forward.y; r1.w = 0.0f;
    D18dRow &r2 = m->row[2];
    r2.x = right.z; r2.y = up.z; r2.z = forward.z; r2.w = 0.0f;
    D18dRow &r3 = m->row[3];
    r3.x = -d18d_dot(self->position, right);
    r3.y = -d18d_dot(self->position, up);
    r3.z = -d18d_dot(self->position, forward);
    r3.w = 1.0f;
}


