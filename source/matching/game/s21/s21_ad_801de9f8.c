// desc: Appears to copy the three-word vector at offset 20 into the output argument and return zero.
struct S21Vec3 { int x, y, z; };
struct S21Object { char pad[20]; struct S21Vec3 value; };
int w3d_s21_get_vector_801de9f8(struct S21Object *self, struct S21Vec3 *out)
{
    *out = self->value;
    return 0;
}
