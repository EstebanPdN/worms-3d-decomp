/* SN ProDG's float-to-text helper for _vfprintf_r: an own digit generator rather than newlib's
 * dtoa-based cvt. It returns a finished string from a static buffer, handling Inf, -Inf, NaN and
 * Ind from the high word. Names are inferred. The do/while around the word read is fdlibm's
 * GET_HIGH_WORD idiom. */
typedef union { double value; struct { int msw; int lsw; } parts; } d40z_double;
extern char cvt_buffer_8047db9c[];
extern char text_inf_803dbc70[], text_neg_inf_803dbc74[], text_nan_803dbc7c[], text_ind_803dbc80[];
double w3d_d24z_floor_802e75d0(double x);
double w3d_d40z_fmod_802e5f48(double x, double y);
int w3d_round_up_digits_802efff4(char *s, int n);
char *itoa(int value, char *s, int base);

char *w3d_d40z_cvt_802f0118(double x, int ndig, char fmtch, int trim)
{
    d40z_double u;
    int i, exp, end, pos;
    char *s;
    int last;
    int hi;
    double ip;
    int d;
    do { u.value = x; hi = u.parts.msw; } while (0);
    i = hi & 0xffff0000;
    switch (i) {
    case 0x7ff00000:
        return text_inf_803dbc70;
    case (int)0xfff00000:
        return text_neg_inf_803dbc74;
    case 0x7ff80000:
    case 0x7ffc0000:
    case (int)0xfffc0000:
        return text_nan_803dbc7c;
    case (int)0xfff80000:
        return text_ind_803dbc80;
    }
    last = ndig;
    i = 0;
    if (x < 0.0) {
        cvt_buffer_8047db9c[0] = '-';
        s = cvt_buffer_8047db9c + 1;
        x = -x;
    } else
        s = cvt_buffer_8047db9c;
    if (x >= 1.0) {
        ip = w3d_d24z_floor_802e75d0(x);
        x -= ip;
        do {
            d = (int)w3d_d40z_fmod_802e5f48(ip, 10.0);
            s[i++] = d + '0';
            ip -= d;
            ip /= 10.0;
        } while (ip >= 1.0);
        {
            int a = 0, b = i - 1;
            for (; a < b; a++, b--) {
                char t = s[a];
                s[a] = s[b];
                s[b] = t;
            }
        }
    }
    if ((exp = i) == 0) {
        if (fmtch != 'f') {
            if (x != 0.0) {
                x *= 10.0;
                while (x < 1.0 && exp > -1021) {
                    x *= 10.0;
                    exp--;
                }
                exp--;
            }
            if (x >= 1.0) {
                last = ndig + 1;
                x /= 10.0;
            }
        } else {
            s[exp] = '0';
            i = 1;
        }
    }
    if (exp < 0)
        end = last;
    else if (fmtch == 'f')
        end = last + (exp < 1 ? 1 : exp);
    else
        end = last + 1;
    last = end + 1;
    {
        double eps = 5.551115123125783e-17;
        do {
            x *= 10.0;
            eps *= 10.0;
            d = (int)x;
            x -= d;
            if (i < end && x >= eps && x <= 1.0 - eps)
                s[i++] = d + '0';
            else
                break;
        } while (1);
        if (x >= 0.5)
            d++;
        s[i++] = d + '0';
    }
    while (i <= end)
        s[i++] = '0';
    if (!w3d_round_up_digits_802efff4(s, last)) {
        s[0] = '1';
        end = last;
        exp++;
    }
    if (ndig != 0) {
        if (fmtch == 'f')
        {
            if (exp > 0)
                pos = exp;
            else
                pos = 1;
        }
        else
            pos = 1;
        for (i = end; i > pos; i--)
            s[i] = s[i - 1];
        s[pos] = '.';
    } else
        end--;
    if (trim) {
        while (end != 0 && s[end] == '0')
            end--;
        if (s[end] == '.')
            end--;
    }
    if (fmtch != 'f') {
        s[++end] = fmtch;
        if (exp >= 0) {
            s[++end] = '+';
            if (exp != 0)
                exp--;
            if (exp <= 9)
                s[++end] = '0';
        } else {
            s[++end] = '-';
            if (exp > -10)
                s[++end] = '0';
            exp = -exp;
        }
        ++end;
        itoa(exp, s + end, 10);
    } else
        s[end + 1] = 0;
    return cvt_buffer_8047db9c;
}
