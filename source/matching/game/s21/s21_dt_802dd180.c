// desc: Appears to be a Lua optional-number argument reader: it returns the supplied default when the argument is absent or nil, else the checked number.
extern int fn_802cd9e8(void *, int);
extern double fn_802dd10c(void *, int);
double w3d_s21_opt_number_802dd180(void *state, int index, double fallback)
{
    if (fn_802cd9e8(state, index) <= 0)
        return fallback;
    return fn_802dd10c(state, index);
}
