// desc: Appears to convert a text argument to a signed number and store it sign-extended into a 64-bit output, returning zero.
extern int fn_802ed89c(const char *);
int w3d_s21_text_to_s64_801fefd4(void *self, long long *out, const char *text)
{
    *out = fn_802ed89c(text);
    return 0;
}
