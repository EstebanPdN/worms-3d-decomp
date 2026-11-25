// desc: Appears to copy two three-float vectors into the object at offsets 32 and 44 and call a follow-up helper when the mode field at offset 80 equals one.
struct S21Vec3 { float x, y, z; };
struct S21Object { char pad[32]; struct S21Vec3 first; struct S21Vec3 second; char pad1[24]; int mode; };
extern void fn_802bc1d4(struct S21Object *);
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
void w3d_s21_set_positions_802bccac(struct S21Object *self, const struct S21Vec3 *first, const struct S21Vec3 *second)
{
    s21_copy(&self->first, first);
    s21_copy(&self->second, second);
    if (self->mode == 1)
        fn_802bc1d4(self);
}
