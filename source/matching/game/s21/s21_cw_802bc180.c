// desc: Appears to copy a three-float vector into the object at offset 44 and call a follow-up helper when the pointer vector at offset 56 is not empty.
struct S21Vec3 { float x, y, z; };
struct S21Object { char pad[44]; struct S21Vec3 position; int *begin; int *end; };
static inline void s21_copy(struct S21Vec3 *dst, const struct S21Vec3 *src)
{
    float x, y, z;
    x = src->x;
    y = src->y;
    z = src->z;
    dst->x = x;
    dst->y = y;
    dst->z = z;
}
extern void fn_802bc1d4(struct S21Object *);
void w3d_s21_set_position_802bc180(struct S21Object *self, const struct S21Vec3 *position)
{
    s21_copy(&self->position, position);
    if ((unsigned)(self->end - self->begin) != 0)
        fn_802bc1d4(self);
}
