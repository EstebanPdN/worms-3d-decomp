// desc: Appears to format a double read through a pointer into the output string with a global format string, returning zero.
struct S21Text;
extern const char lbl_803b2988[];
extern void fn_8020c510(struct S21Text *, const char *, ...);
int w3d_s21_double_format_801ff1e8(void *self, struct S21Text *out, const double *value)
{
    fn_8020c510(out, lbl_803b2988, *value);
    return 0;
}
