// desc: Appears to pass a float read through a pointer to a text conversion helper for the output string, returning its result.
struct S21Text;
extern int fn_8020dcc8(struct S21Text *, float);
int w3d_s21_float_to_text_801ff0a0(void *self, struct S21Text *out, const float *value)
{
    return fn_8020dcc8(out, *value);
}
