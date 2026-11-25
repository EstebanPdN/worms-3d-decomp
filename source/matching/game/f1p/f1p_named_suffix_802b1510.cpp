// Original 0x802b1510. String representation and names inferred.
// The external C++ constructor is bound from the original call witness.
struct String_8020bb54 {
 String_8020bb54(const String_8020bb54 &);char *text;String_8020bb54(const char *);~String_8020bb54();};
extern "C" void fn_8020bb54(String_8020bb54 *,const char *);
extern "C" void fn_8020c5c4(String_8020bb54 *);
extern "C" void fn_80341588(String_8020bb54 *);
inline String_8020bb54::~String_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}
extern "C" char *fn_802ef198(const char *,int);
extern "C" int fn_802ed89c(const char *);
extern "C" void fn_8020c3a0(String_8020bb54 *,int);
extern "C" int fn_8015adf4(String_8020bb54 *,void **,int);
extern "C" void *fn_8034357c(void *);
extern "C" int fn_80173f88(void *,const unsigned char *);
extern "C" int w3d_named_suffix_802b1510(void *,const char *text,void **output,int flags) {
 int suffix=0;String_8020bb54 name(text);
 char *separator=fn_802ef198(text,':');
 if(separator){suffix=fn_802ed89c(separator+1);fn_8020c3a0(&name,separator-text);}
 int result=fn_8015adf4(&name,output,flags);
 if(result<0)return result;
 if(suffix){void *object=fn_8034357c(*output);unsigned char value=suffix;fn_80173f88(object,&value);}
 return 0;
}
