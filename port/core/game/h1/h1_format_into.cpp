#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "h1_format_into.c"
/* Per-file copies of a static text-format helper (session b169b320): it
 * formats the variable arguments into buffer with vsprintf and returns
 * buffer. The same header function was emitted in six translation units. */
#include <stdarg.h>
#include <sn-inline-stdarg.h>

int vsprintf(Ptr32<char> str, Ptr32<const char> fmt, va_list ap);

#define W3D_FORMAT_INTO(NAME) \
char *NAME(char *buffer, const char *format, ...) \
{ \
    va_list arguments; \
    va_start(arguments, format); \
    vsprintf(buffer, format, arguments); \
    va_end(arguments); \
    return buffer; \
}

W3D_FORMAT_INTO(w3d_format_into_80347a10)
W3D_FORMAT_INTO(w3d_format_into_8034cb64)
W3D_FORMAT_INTO(w3d_format_into_80351df8)
W3D_FORMAT_INTO(w3d_format_into_80355a44)
W3D_FORMAT_INTO(w3d_format_into_8035cb74)
W3D_FORMAT_INTO(w3d_format_into_8035eb0c)

}
