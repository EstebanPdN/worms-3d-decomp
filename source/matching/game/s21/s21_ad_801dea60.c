// desc: Appears to copy the three-word vector at offset 56 into the output argument and return zero.
struct S21Vec3 { int x, y, z; };
struct S21Object { char pad[56]; struct S21Vec3 value; };
int w3d_s21_get_second_vector_801dea60(struct S21Object *self, struct S21Vec3 *out)
{
    *out = self->value;
    return 0;
}
