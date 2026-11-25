// desc: Appears to pass a 64-bit value read through a pointer to a second text conversion helper for the output string, returning its result.
struct S21Text;
extern int fn_8020db18(struct S21Text *, long long);
int w3d_s21_u64_to_text_helper_801fef6c(void *self, struct S21Text *out, const long long *value)
{
    return fn_8020db18(out, *value);
}
