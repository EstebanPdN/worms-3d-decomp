// desc: Appears to return the pointer at an index of a pointer vector, or zero when the index is out of range.
struct S21Vector { char pad[60]; int *begin; int *end; };
int w3d_s21_vector_get_801e9db8(struct S21Vector *self, unsigned index)
{
    if (index >= (unsigned)(self->end - self->begin))
        return 0;
    return *(int *)((char *)self->begin + (index << 2));
}
