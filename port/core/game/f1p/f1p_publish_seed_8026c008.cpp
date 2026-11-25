#include "w3d_ptr.h"
#line 1 "f1p_publish_seed_8026c008.cpp"
// Original 0x8026c008. String representation and names inferred.
// The external C++ constructor is bound from the original call witness.
struct Owner {char pad[496];int updating;};
struct String_803426b8 {
 String_803426b8(const String_803426b8 &);Ptr32<char> text;String_803426b8();~String_803426b8();};
extern "C" void fn_803426b8(Ptr32<String_803426b8>);
extern "C" void fn_8020c5c4(Ptr32<String_803426b8>);
extern "C" void fn_80341588(Ptr32<String_803426b8>);
 inline String_803426b8::~String_803426b8(){fn_8020c5c4(this);fn_80341588(this);}
extern "C" unsigned fn_8026ce4c(Ptr32<void>);
extern "C" void fn_8020c510(Ptr32<String_803426b8>,Ptr32<const char>,...);
extern "C" int fn_800fc550(Ptr32<Ptr32<const char>>,Ptr32<const char>);
extern "C" int fn_800fc43c(Ptr32<Ptr32<const char>>,unsigned);
extern const char format_803cb8d0[],name_803cb950[],name_803cb8bc[];
extern "C" void w3d_publish_seed_8026c008(Ptr32<Owner> self,int mode) {
 int old=self->updating;self->updating=1;
 String_803426b8 value;
 Ptr32<void> seed=(Ptr32<char>)self+312;
 fn_8020c510(&value,format_803cb8d0,fn_8026ce4c(seed));
 if(mode==1){Ptr32<const char> name=name_803cb950;fn_800fc550(&name,value.text);}
 Ptr32<const char> name=name_803cb8bc;
 fn_800fc43c(&name,fn_8026ce4c(seed));
 fn_8026ce4c(seed);
 self->updating=old;
}


