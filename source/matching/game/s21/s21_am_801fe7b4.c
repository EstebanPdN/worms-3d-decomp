// desc: Appears to format an unsigned byte read through a pointer into the output string with a global format string, returning zero.
struct S21Text;
extern const char lbl_803b29c8[];
extern void fn_8020c510(struct S21Text *, const char *, ...);
int w3d_s21_u8_to_text_801fe7b4(void *self, struct S21Text *out, const unsigned char *value)
{
    fn_8020c510(out, lbl_803b29c8, *value);
    return 0;
}
