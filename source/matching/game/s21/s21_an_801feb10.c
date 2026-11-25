// desc: Appears to format a signed halfword read through a pointer into the output string with a global format string, returning zero.
struct S21Text;
extern const char lbl_803b29c4[];
extern void fn_8020c510(struct S21Text *, const char *, ...);
int w3d_s21_s16_to_text_801feb10(void *self, struct S21Text *out, const short *value)
{
    fn_8020c510(out, lbl_803b29c4, *value);
    return 0;
}
