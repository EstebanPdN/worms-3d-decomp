#include "w3d_ptr.h"
#line 1 "f3a_suffix_8028dcd8.cpp"
// Original text wrapper layout and uppercase suffix operations; symbol roles inferred.
extern "C" void fn_8020c5c0(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020c2e8(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
extern "C" unsigned fn_802ef9c0(Ptr32<const char>);
extern "C" int fn_802ef234(Ptr32<const char>,Ptr32<const char>);
extern char ext_803cffc0[];
struct Text {Ptr32<char> data;Text(const Text&v){fn_8020c5c0(this);data=v.data;++*fn_80341884(this);}~Text(){fn_8020c5c4(this);fn_80341588(this);}};
extern "C" int w3d_f3a_suffix_8028dcd8(Ptr32<void>,Text input){Text text(input);fn_8020c2e8(&text);Ptr32<char> p=text.data;unsigned n=fn_802ef9c0(p);if(n>4 && fn_802ef234(p+n-4,ext_803cffc0)==0)return 1;return 0;}


