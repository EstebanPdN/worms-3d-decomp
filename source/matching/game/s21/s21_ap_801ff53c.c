// desc: Appears to pass a 64-bit value read through a pointer to a text conversion helper for the output string, returning its result. Identical in bytes to its sibling.
struct S21Text;
extern int fn_8020db88(struct S21Text *, long long);
int w3d_s21_i64_to_text_b_801ff53c(void *self, struct S21Text *out, const long long *value)
{
    return fn_8020db88(out, *value);
}
