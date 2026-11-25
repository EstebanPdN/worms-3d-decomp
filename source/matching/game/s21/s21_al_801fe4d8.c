// desc: Appears to return a 64-bit value from a clock helper minus a global 64-bit base.
extern long long fn_80300aa0(void);
extern long long lbl_804b0628;
long long w3d_s21_elapsed_801fe4d8(void)
{
    return fn_80300aa0() - lbl_804b0628;
}
