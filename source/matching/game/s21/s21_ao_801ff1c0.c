// desc: Appears to pass a double read through a pointer to a text conversion helper for the output string, returning its result.
struct S21Text;
extern int fn_8020dd44(struct S21Text *, double);
int w3d_s21_double_to_text_801ff1c0(void *self, struct S21Text *out, const double *value)
{
    return fn_8020dd44(out, *value);
}
