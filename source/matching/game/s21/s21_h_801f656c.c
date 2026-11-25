extern void fn_801f6480(float, float, float, float, void *);
void w3d_s21_forward_vector_801f656c(void *self, const float *v, float w)
{
    fn_801f6480(v[0], v[1], v[2], w, (void *)self);
}
