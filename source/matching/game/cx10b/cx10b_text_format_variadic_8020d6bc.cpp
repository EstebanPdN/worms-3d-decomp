#include <sn-inline-stdarg.h>
struct TextSink;
extern "C" int format_list_8020d750(TextSink *,const char *,va_list);
extern "C" int w3d_cx10b_text_format_variadic_8020d6bc(TextSink *self,const char *format,...) {
 va_list args;va_start(args,format);
 int result=format_list_8020d750(self,format,args);
 va_end(args);return result;
}


