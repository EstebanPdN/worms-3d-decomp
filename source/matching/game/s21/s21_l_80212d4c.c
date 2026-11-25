// desc: Appears to forward a value with a sign flag for kind ten and return its second argument.
extern void fn_80212c74(int, void *, int, int);
int w3d_s21_forward_sign_80212d4c(int value, int result, int kind)
{
    int negative = 0;
    if (kind == 10)
        negative = (unsigned)value >> 31;
    fn_80212c74(value, result, kind, negative);
    return result;
}
