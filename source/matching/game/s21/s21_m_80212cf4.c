// desc: Appears to forward a value with a sign flag set only for kind ten with a negative value, and return its second argument.
extern void fn_80212c74(int, void *, int, int);
int w3d_s21_forward_negative_80212cf4(int value, int result, int kind)
{
    if (kind == 10 && value < 0)
        fn_80212c74(value, result, 10, 1);
    else
        fn_80212c74(value, result, kind, 0);
    return result;
}
