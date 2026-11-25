// desc: Appears to copy a three-word vector from the argument into the object at offset 56 and return zero.
struct S21Vec3 { int x, y, z; };
struct S21Object { char pad[56]; struct S21Vec3 value; };
int w3d_s21_set_second_vector_801de994(struct S21Object *self, const struct S21Vec3 *value)
{
    self->value = *value;
    return 0;
}
