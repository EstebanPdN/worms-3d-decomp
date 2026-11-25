// desc: Appears to format a 64-bit value read through a pointer into the output string with a global format string, returning zero.
struct S21Text;
extern const char lbl_803b29c8[];
extern void fn_8020c510(struct S21Text *, const char *, ...);
int w3d_s21_u64_to_text_801fee68(void *self, struct S21Text *out, const long long *value)
{
    fn_8020c510(out, lbl_803b29c8, *value);
    return 0;
}
