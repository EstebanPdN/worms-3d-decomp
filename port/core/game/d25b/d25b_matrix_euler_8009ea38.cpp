#include "w3d_ptr.h"
#line 1 "d25b_matrix_euler_8009ea38.cpp"
/* Matrix to Euler angles (0x8009ea38): takes the rotated X axis of the matrix, normalizes
 * it and derives the angle about Y (asin of z, 0x802e7c30) and about Z from its planar
 * length (0x802e82c0, asin of y over length), rotates a copy of the matrix back
 * by both (0x801f621c, 0x801f61a0), takes the rotated Y axis, normalizes it and derives
 * the angle about X by quadrant. Writes x, y, z to the output vector. Field and type
 * names are inferred from the original instructions. Owns its float literals at
 * 0x80380698. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; Ptr32<Vec3> p = this; p->y = b; p->z = c; }
};
struct Matrix {
    Vec3 r[3];
    Matrix();
};
extern "C" float w3d_sqrt_802e82c0(float);
extern "C" float w3d_asin_802e7c30(float);
extern "C" void w3d_rotate_cols_801f621c(Ptr32<Matrix>, float);
extern "C" void w3d_rotate_rows_801f61a0(Ptr32<Matrix>, float);

inline void Rotate(Ptr32<Vec3> out, const Vec3 &v, const Matrix &m)
{
    const Vec3 &a = m.r[0], &b = m.r[1], &c = m.r[2];
    out->x = v.x * a.x + v.y * b.x + v.z * c.x;
    out->y = v.x * a.y + v.y * b.y + v.z * c.y;
    out->z = v.x * a.z + v.y * b.z + v.z * c.z;
}

extern "C" void w3d_d25b_matrix_euler_8009ea38(Ptr32<const Matrix> self, Ptr32<Vec3> angles)
{
    Vec3 xAxis(1.0f, 0.0f, 0.0f);
    Vec3 yAxis(0.0f, 1.0f, 0.0f);
    Vec3 dir;
    Vec3 up;
    Rotate(&dir, xAxis, *self);
    float scale = 1.0f / w3d_sqrt_802e82c0(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    dir.x *= scale;
    dir.y *= scale;
    dir.z *= scale;
    Matrix copy;
    float pitch;
    if (dir.z >= 0.0f) pitch = -w3d_asin_802e7c30(dir.z);
    else pitch = w3d_asin_802e7c30(-dir.z);
    float zero = 0.0f;
    float len2 = dir.x * dir.x + dir.y * dir.y;
    float yaw;
    if (len2 > zero) {
        len2 = w3d_sqrt_802e82c0(len2);
        if (dir.x > zero) yaw = w3d_asin_802e7c30(dir.y / len2);
        else yaw = 3.1415927f - w3d_asin_802e7c30(dir.y / len2);
    } else yaw = zero;
    copy = *self;
    float by = -yaw;
    float bp = -pitch;
    const Vec3 &second = copy.r[1];
    const Vec3 &third = copy.r[2];
    w3d_rotate_cols_801f621c(&copy, by);
    w3d_rotate_rows_801f61a0(&copy, bp);
    up.x = yAxis.x * copy.r[0].x + yAxis.y * copy.r[1].x + yAxis.z * copy.r[2].x;
    Ptr32<Matrix> m = &copy;
    up.y = yAxis.x * m->r[0].y + yAxis.y * second.y + yAxis.z * third.y;
    up.z = yAxis.x * m->r[0].z + yAxis.y * second.z + yAxis.z * third.z;
    float inv = 1.0f / w3d_sqrt_802e82c0(up.x * up.x + up.y * up.y + up.z * up.z);
    up.x *= inv;
    up.y *= inv;
    up.z *= inv;
    float roll;
    if (up.z <= 0.0f) {
        if (up.y < 0.0f) roll = w3d_asin_802e7c30(-up.z) - 3.1415927f;
        else roll = -w3d_asin_802e7c30(-up.z);
    } else {
        if (up.y < 0.0f) roll = 3.1415927f - w3d_asin_802e7c30(up.z);
        else roll = w3d_asin_802e7c30(up.z);
    }
    angles->x = roll;
    angles->y = pitch;
    angles->z = yaw;
}


