// desc: Appears to construct an object with a base constructor and fill an embedded three-float member with a global constant.
struct S21Vec3 { float x, y, z; };
struct S21Object { char pad[36]; struct S21Vec3 value; };
extern void *fn_801f6480(struct S21Object *, float, float, float, float);
extern float lbl_803b1708[];
static inline void s21_fill(struct S21Vec3 *v, float f)
{
    v->x = f;
    v->y = f;
    v->z = f;
}
void *w3d_s21_construct_801f7538(struct S21Object *self, float arg_f1, float arg_f2, float arg_f3, float arg_f4)
{
    void *base = fn_801f6480(self, arg_f1, arg_f2, arg_f3, arg_f4);
    s21_fill(&self->value, lbl_803b1708[0]);
    return base;
}
