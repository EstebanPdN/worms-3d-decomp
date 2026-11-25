// desc: Appears to construct an object with a base constructor and set an embedded three-float member from the three float arguments.
struct S21Vec3 { float x, y, z; };
struct S21Object { char pad[36]; struct S21Vec3 value; };
extern void *fn_801f6034(struct S21Object *);
static inline void s21_set(struct S21Vec3 *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}
void *w3d_s21_construct_801f75c0(struct S21Object *self, float x, float y, float z)
{
    void *base = fn_801f6034(self);
    s21_set(&self->value, x, y, z);
    return base;
}
