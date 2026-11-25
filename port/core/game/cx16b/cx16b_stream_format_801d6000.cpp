#include "w3d_ptr.h"
#line 1 "cx16b_stream_format_801d6000.cpp"
/* Recovered from the original GWMP8P entry. Only the observed stream slot
   and formatting buffer are named; the containing class is unknown. */
#include <stdarg.h>
#include <sn-inline-stdarg.h>
struct Cx16bStream { Ptr32<Ptr32<void>> vtable; };
struct Cx16bStreamOwner { char unknown[40]; Ptr32<Cx16bStream> stream; };
extern "C" int fn_802ed5e0(Ptr32<char>, Ptr32<const char>, va_list);
extern "C" void w3d_cx16b_stream_format_801d6000(Ptr32<Cx16bStreamOwner> self, Ptr32<const char> format, ...)
{
    va_list arguments;
    va_start(arguments,format);
    char text[1024];
    int length=fn_802ed5e0(text,format,arguments);
    Ptr32<Cx16bStream> stream=self->stream;
    ((Ptr32<void (Ptr32<Cx16bStream>, Ptr32<const char>, int, int)>)stream->vtable[6])(stream,text,length,0);
    va_end(arguments);
}


