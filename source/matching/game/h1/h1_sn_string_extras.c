/* SN runtime string extras that stock newlib 1.10.0 does not have
 * (session b169b320): strlwr, strrchr, a decimal-digit round-up helper,
 * strrev and itoa. Characters are handled as signed char, as in the
 * original code. */

extern const char w3d_ctype_803db449[];      /* newlib _ctype_ + 1 */
extern const char w3d_itoa_digits_80404b08[]; /* "0123456789abcdefghijklmnopqrstuvwxyz" */

#define W3D_CTYPE_UPPER 1

char *strlwr(char *s)
{
    char *p;
    for (p = s; *p != 0; p++) {
        signed char c = *p;
        if (*(c + w3d_ctype_803db449) & W3D_CTYPE_UPPER)
            *p = c + 32;
    }
    return s;
}

char *strrchr(const char *s, int c)
{
    signed char ch = c;
    const char *last = 0;
    while (*s != 0) {
        if ((signed char)*s == ch)
            last = s;
        s++;
    }
    if ((signed char)*s == ch)
        last = s;
    return (char *)last;
}

int w3d_round_up_digits_802efff4(char *digits, int length)
{
    if (length > 0) {
        length--;
        if ((signed char)digits[length] > '4') {
            do {
                digits[length] = '0';
                if (--length <= 0)
                    break;
            } while (digits[length] == '9');
            if (digits[length] == '9')
                return 0;
            digits[length] = digits[length] + 1;
        }
    }
    return 1;
}

char *strrev(char *s)
{
    int i, j;
    char t;
    j = 0;
    while (s[j] != 0)
        j++;
    for (i = 0, j--; i < j; i++, j--) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
    return s;
}

char *itoa(int value, char *buffer, int base)
{
    unsigned int n = value;
    int negative = n >> 31;
    int i;
    if (negative && base == 10)
        n = -n;
    i = 0;
    do {
        buffer[i++] = w3d_itoa_digits_80404b08[n % base];
    } while ((n /= base) != 0);
    if (negative)
        buffer[i++] = '-';
    buffer[i] = 0;
    return strrev(buffer);
}
