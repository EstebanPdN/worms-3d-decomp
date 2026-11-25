#include "w3d_ptr.h"
#line 1 "f1p_named_suffix_802b1510.cpp"
// Original 0x802b1510. String representation and names inferred.
// The external C++ constructor is bound from the original call witness.
struct String_8020bb54 {
 String_8020bb54(const String_8020bb54 &);Ptr32<char> text;template <class W3dU> String_8020bb54(Ptr32<W3dU> w3d_p) : String_8020bb54((const char *)w3d_p.get()) {}
 String_8020bb54(const char *);~String_8020bb54();};
extern "C" void fn_8020bb54(Ptr32<String_8020bb54>,Ptr32<const char>);
extern "C" void fn_8020c5c4(Ptr32<String_8020bb54>);
extern "C" void fn_80341588(Ptr32<String_8020bb54>);
inline String_8020bb54::~String_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}
extern "C" Ptr32<char> fn_802ef198(Ptr32<const char>,int);
extern "C" int fn_802ed89c(Ptr32<const char>);
extern "C" void fn_8020c3a0(Ptr32<String_8020bb54>,int);
extern "C" int fn_8015adf4(Ptr32<String_8020bb54>,Ptr32<Ptr32<void>>,int);
extern "C" Ptr32<void> fn_8034357c(Ptr32<void>);
extern "C" int fn_80173f88(Ptr32<void>,Ptr32<const unsigned char>);
extern "C" int w3d_named_suffix_802b1510(Ptr32<void>,Ptr32<const char> text,Ptr32<Ptr32<void>> output,int flags) {
 int suffix=0;String_8020bb54 name(text);
 Ptr32<char> separator=fn_802ef198(text,':');
 if(separator){suffix=fn_802ed89c(separator+1);fn_8020c3a0(&name,separator-text);}
 int result=fn_8015adf4(&name,output,flags);
 if(result<0)return result;
 if(suffix){Ptr32<void> object=fn_8034357c(*output);unsigned char value=suffix;fn_80173f88(object,&value);}
 return 0;
}


