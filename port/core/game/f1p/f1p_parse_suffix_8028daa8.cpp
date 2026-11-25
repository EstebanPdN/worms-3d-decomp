#include "w3d_ptr.h"
#line 1 "f1p_parse_suffix_8028daa8.cpp"
// String representation and semantic roles inferred from original instructions.
extern "C" void fn_8020c5c0(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020bb2c(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
struct Header {unsigned short refs,length,capacity;};inline void acquire(Ptr32<Header> h){++h->refs;}inline void release(Ptr32<Header> h){if(--h->refs==0)fn_8020bb2c(h);}
struct String {Ptr32<char> text;String(const String&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}~String(){fn_8020c5c4(this);fn_80341588(this);}int length()const{return *(Ptr32<unsigned short>)(text-4);}String &operator=(const String&o){acquire((Ptr32<Header>)(o.text-6));release((Ptr32<Header>)(text-6));text=o.text;return *this;}};
struct Temp_803426b8 {
 Temp_803426b8(const Temp_803426b8 &);Ptr32<char> text;Temp_803426b8();~Temp_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
extern const char fallback_803cffac[],separator_803cffbc[];
extern "C" void fn_8020bd38(Ptr32<String>,Ptr32<const char>),fn_8020c3a0(Ptr32<String>,int);
extern "C" int fn_8020c0fc(Ptr32<Temp_803426b8>,Ptr32<String>,int);
extern "C" Ptr32<char> fn_802efd14(Ptr32<const char>,Ptr32<const char>);
extern "C" int fn_802ed8c4(Ptr32<const char>);
extern "C" int w3d_parse_suffix_8028daa8(Ptr32<void>,Ptr32<String> input){int result=0;Ptr32<char> begin=input->text;if(!input->length())fn_8020bd38(input,fallback_803cffac);else{Ptr32<char> split=fn_802efd14(begin,separator_803cffbc);String stem(*input);if(split){int index=split-begin;fn_8020c3a0(&stem,index);if(input->length()-1!=index){Temp_803426b8 tail;int n=input->length()-1;n-=index;fn_8020c0fc(&tail,input,n);result=fn_802ed8c4(tail.text);}}*input=stem;}return result;}


