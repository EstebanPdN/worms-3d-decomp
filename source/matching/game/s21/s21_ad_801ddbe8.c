// desc: Appears to return the float stored at an index of an inline float array.
struct S21Floats { char pad[20]; float values[1]; };
float w3d_s21_get_float_801ddbe8(struct S21Floats *self, int index)
{
    return self->values[index];
}
