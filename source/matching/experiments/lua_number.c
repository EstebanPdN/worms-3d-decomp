/* UNVERIFIED candidate for the decimal reader at 0x802d21f4.
 * Neither a complete byte match nor differential behavior is established.
 * Preserve the observed grammar while continuing investigation;
 * it is not interchangeable with the host strtod implementation. */
#define W3D_LUA_GAME_CONFIG 1
#include <ctype.h>

#ifdef __cplusplus
extern "C"
#endif
float w3d_lua_parse_number(const char *text, char **end)
{
    float number = 0.0f;
    float divisor = 0.0f;
    float sign = 1.0f;
    if (isdigit(*text) || *text == '.' || *text == '-') {
        do {
            divisor *= 10.0f;
            if (*text == '.')
                divisor = 1.0f;
            else if (*text == '-')
                sign = -sign;
            else
                number = number * 10.0f + (float)(*text - '0');
            ++text;
        } while (isdigit(*text) || *text == '.' || *text == '-');
    }
    *end = (char *)text;
    if (divisor > 1.0f)
        number /= divisor;
    return number * sign;
}
