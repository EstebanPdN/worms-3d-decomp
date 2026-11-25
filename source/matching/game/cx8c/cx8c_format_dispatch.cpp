/* Observed field offsets, sizes, and call addresses; all semantic names inferred. */
struct Cx8cContext;
struct Cx8cStream {unsigned char unknown[92];Cx8cContext *context;};
struct Cx8cArguments;
extern "C" {int cx8c_format_float_802f07a0(Cx8cContext *,Cx8cStream *,const char *,Cx8cArguments *);int cx8c_format_integer_802f1cf4(Cx8cContext *,Cx8cStream *,const char *,...);}
extern "C" int w3d_cx8c_format_dispatch_802f06c8(Cx8cStream *self,const char *format,Cx8cArguments *args) {
 for(const char *p=format;*p;++p) {
  if(*p=='%' && p[1]) {++p;while(*p<='@' && p[1]) ++p;
   switch(*p) {case 'E':case 'G':case 'L':case 'e':case 'f':case 'g':return cx8c_format_float_802f07a0(self->context,self,format,args);}
  }
 }
 return cx8c_format_integer_802f1cf4(self->context,self,format,args);
}
