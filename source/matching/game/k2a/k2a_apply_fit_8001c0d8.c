extern void FUN_8001c36c(void *source, float *out_vec, float *out_scale);
extern void FUN_8001c134(void *self, void *a, void *source, float *vec, float scale);

void *k2a_apply_fit_8001c0d8(void *self, int a, void *source)
{
    float vec[4];
    float scale;
    FUN_8001c36c(source, vec, &scale);
    FUN_8001c134(self, a, source, vec, scale);
    return self;
}
