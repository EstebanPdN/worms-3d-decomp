// desc: Appears to construct an object with a base constructor and fill an embedded three-float member with a second global constant.
struct S21Vec3 { float x, y, z; };
struct S21Object { char pad[36]; struct S21Vec3 value; };
extern void *fn_801f656c(struct S21Object *, void *, float);
extern float lbl_803b170c[];
static inline void s21_fill(struct S21Vec3 *v, float f)
{
    v->x = f;
    v->y = f;
    v->z = f;
}
void *w3d_s21_construct_801f757c(struct S21Object *self, void * arg_r4, float arg_f1)
{
    void *base = fn_801f656c(self, arg_r4, arg_f1);
    s21_fill(&self->value, lbl_803b170c[0]);
    return base;
}
