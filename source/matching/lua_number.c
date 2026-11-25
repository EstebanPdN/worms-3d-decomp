/* Game decimal reader, GWMP8P. Reference compiler form; portable recovery
 * and proof receipts are documented separately. Native signed-byte ctype
 * indexing is retained here; this file is not a host-libc parser replacement. */
#define W3D_LUA_GAME_CONFIG 1
#include <ctype.h>

#ifdef __cplusplus
extern "C"
#endif
float w3d_lua_parse_number(const char *text, char **end)
{
    float divisor = 0.0f;
    float number = 0.0f;
    float sign = 1.0f;
    while (isdigit(*text) || *text == '.' || *text == '-') {
        divisor *= 10.0f;
        if (*text == '.')
            divisor = 1.0f;
        else if (*text == '-')
            sign = -sign;
        else
            number = number * 10.0f + (float)(*text - '0');
        ++text;
    }
    *end = (char *)text;
    if (divisor > 1.0f)
        number /= divisor;
    return number * sign;
}
