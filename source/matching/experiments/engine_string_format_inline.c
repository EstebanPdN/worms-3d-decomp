/* Original fixed-buffer formatting and assignment forwarding.
 * The original uses vsprintf; callers must respect its1024-byte stack buffer.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include <stdarg.h>
#include <stdio.h>
#undef va_start
#define va_start(AP,LAST) (__builtin_next_arg(LAST), *(AP) = *(struct __va_list_tag *)__builtin_saveregs())
typedef struct EngineString { char *data; } EngineString;
extern EngineString *w3d_string_assign_text(EngineString *, const char *);

EngineString *w3d_string_assign(EngineString *string, const char *text)
{
    return w3d_string_assign_text(string, text);
}

EngineString *w3d_string_format(EngineString *string, const char *format, ...)
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
