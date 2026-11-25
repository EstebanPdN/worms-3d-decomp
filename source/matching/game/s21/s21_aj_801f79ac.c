// desc: Appears to copy four floats from the second argument into the first, starting with the fourth, and return the destination.
struct S21Quat { float x, y, z, w; };
struct S21Quat *w3d_s21_copy_quat_801f79ac(struct S21Quat *dst, const struct S21Quat *src)
{
    dst->w = src->w;
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    return dst;
}
