// desc: Appears to convert a text argument to an unsigned number and store it zero-extended into a 64-bit output, returning zero. Identical in bytes to its sibling.
extern unsigned fn_802ed89c(const char *);
int w3d_s21_text_to_u64_b_801ff5a4(void *self, unsigned long long *out, const char *text)
{
    *out = fn_802ed89c(text);
    return 0;
}
