#include "w3d_ptr.h"
#line 1 "d24b_girder_points_80095b58.cpp"
/* Girder point transform (0x80095b58): builds the girder matrix from the identity matrix
 * 0x8045e748 and the axis (+332, +312, 0) (0x801a3eb0), sets its translation from the
 * position +208, scales it (0x801f781c, 2.0 when +688 is 1, else 1.0), transforms the eight
 * corners and four markers at +348 into the table 144 bytes further on and copies the
 * position to +172. Field and type names are inferred from the original instructions.
 * Owns its float literals at 0x8037ebc4. */
struct Vec3 {
    float x, y, z;
};
struct Word3 { int x, y, z; };
struct Point : Vec3 { Point(); };
struct Matrix {
    Vec3 r0, r1, r2;
    Point t;
};
extern Matrix w3d_identity_8045e748[];
extern "C" void w3d_matrix_rotation_801a3eb0(Ptr32<Vec3>, int, Ptr32<Matrix>);
extern "C" void w3d_matrix_scale_801f781c(Ptr32<Matrix>, float, float, float);
struct GirderPoints {
    char unknown00[172];
    Vec3 lastPosition;   /* +172 */
    char unknown184[24];
    Vec3 position;       /* +208 */
    char unknown220[92];
    float axisY;         /* +312 */
    char unknown316[16];
    float axisX;         /* +332 */
    char unknown336[12];
    Vec3 corners[8];     /* +348 */
    Vec3 markers[4];     /* +444 */
    char unknown492[96];
    char unknown588[100];
    int size;            /* +688 */
};
extern "C" void w3d_d24b_girder_points_80095b58(Ptr32<GirderPoints> self)
{
    Vec3 axis;
    Ptr32<Vec3> pa = &axis;
    axis.x = self->axisX;
    pa->y = self->axisY;
    pa->z = 0.0f;
    Matrix m;
    float scale;
    if (self->size == 1) scale = 2.0f;
    else scale = 1.0f;
    m = w3d_identity_8045e748[0];
    Ptr32<const Word3> from = (Ptr32<const Word3>)&self->position;
    Ptr32<const Vec3> p0 = &m.r0;
    Ptr32<const Vec3> p1 = &m.r1; Ptr32<const Vec3> p2 = &m.r2; Ptr32<const Vec3> p3 = &m.t;
    w3d_matrix_rotation_801a3eb0(&axis, 0, &m);
    {
        int wx = ((const Word3 &)self->position).x, wy = from->y, wz = from->z;
        ((Word3 &)m.t).x = wx;
        ((Word3 &)m.t).z = wz;
        ((Word3 &)m.t).y = wy;
    }
    w3d_matrix_scale_801f781c(&m, scale, scale, scale);
    for (int i = 0; i < 8; i++) {
        Ptr32<Vec3> p = &self->corners[i];
        float y = p->y, x = p->x, z = p->z;
        p[12].x = x * m.r0.x + y * m.r1.x + z * m.r2.x + m.t.x;
        p[12].y = x * p0->y + y * p1->y + z * p2->y + p3->y;
        p[12].z = x * p0->z + y * p1->z + z * p2->z + p3->z;
    }
    for (int i = 0; i < 4; i++) {
        Ptr32<Vec3> p = &self->markers[i];
        float y = p->y, x = p->x, z = p->z;
        p[12].x = x * m.r0.x + y * m.r1.x + z * m.r2.x + m.t.x;
        p[12].y = x * p0->y + y * p1->y + z * p2->y + p3->y;
        p[12].z = x * p0->z + y * p1->z + z * p2->z + p3->z;
    }
    {
        Ptr32<Word3> to = (Ptr32<Word3>)&self->lastPosition;
        int wx = ((const Word3 &)self->position).x, wy = from->y, wz = from->z;
        ((Word3 &)self->lastPosition).x = wx;
        to->y = wy;
        to->z = wz;
    }
}


