// desc: Appears to scale all four components of a vector by the reciprocal length computed from its first three components.
struct S21Vec4 { float x, y, z, w; };
extern float fn_801f3fec(float);
void w3d_s21_normalize4_801f5d2c(struct S21Vec4 *v)
{
    float scale = fn_801f3fec(v->x * v->x + v->y * v->y + v->z * v->z);
    v->x = v->x * scale;
    v->y = v->y * scale;
    v->z = v->z * scale;
    v->w = v->w * scale;
}
