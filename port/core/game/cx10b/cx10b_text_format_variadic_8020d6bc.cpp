#include "w3d_ptr.h"
#line 1 "cx10b_text_format_variadic_8020d6bc.cpp"
#include <sn-inline-stdarg.h>
struct TextSink;
extern "C" int format_list_8020d750(Ptr32<TextSink>,Ptr32<const char>,va_list);
extern "C" int w3d_cx10b_text_format_variadic_8020d6bc(Ptr32<TextSink> self,Ptr32<const char> format,...) {
 va_list args;va_start(args,format);
 int result=format_list_8020d750(self,format,args);
 va_end(args);return result;
}




