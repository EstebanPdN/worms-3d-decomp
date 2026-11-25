#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "engine_string_format.c"
/* Original fixed-buffer formatting and assignment forwarding.
 * The original uses vsprintf; callers must respect its1024-byte stack buffer.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include <stdarg.h>
#include <stdio.h>
#include <sn-inline-stdarg.h>
typedef struct EngineString { Ptr32<char> data; } EngineString;
extern Ptr32<EngineString> w3d_string_assign_text(Ptr32<EngineString>, Ptr32<const char>);

Ptr32<EngineString> w3d_string_assign(Ptr32<EngineString> string, Ptr32<const char> text)
{
    return w3d_string_assign_text(string, text);
}

Ptr32<EngineString> w3d_string_format(Ptr32<EngineString> string, Ptr32<const char> format, ...)
{
    char buffer[1024];
    va_list arguments;
    va_start(arguments, format);
    vsprintf(buffer, format, arguments);
    va_end(arguments);
    return w3d_string_assign(string, buffer);
}
#ifdef __cplusplus
}
#endif

}
