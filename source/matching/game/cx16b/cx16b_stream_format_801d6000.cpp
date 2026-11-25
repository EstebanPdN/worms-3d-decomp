/* Recovered from the original GWMP8P entry. Only the observed stream slot
   and formatting buffer are named; the containing class is unknown. */
#include <stdarg.h>
#include <sn-inline-stdarg.h>
struct Cx16bStream { void **vtable; };
struct Cx16bStreamOwner { char unknown[40]; Cx16bStream *stream; };
extern "C" int fn_802ed5e0(char *, const char *, va_list);
extern "C" void w3d_cx16b_stream_format_801d6000(Cx16bStreamOwner *self, const char *format, ...)
{
    va_list arguments;
    va_start(arguments,format);
    char text[1024];
    int length=fn_802ed5e0(text,format,arguments);
    Cx16bStream *stream=self->stream;
    ((void (*)(Cx16bStream *, const char *, int, int))stream->vtable[6])(stream,text,length,0);
    va_end(arguments);
}
