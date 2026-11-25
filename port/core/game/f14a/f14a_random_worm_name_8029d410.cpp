#include "w3d_ptr.h"
#line 1 "f14a_random_worm_name_8029d410.cpp"
// Names inferred; native shared-text scopes and borrowed property strings.
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct F14aWormText_803426b8{
 F14aWormText_803426b8(const F14aWormText_803426b8 &);Ptr32<char> text;F14aWormText_803426b8();~F14aWormText_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
struct F14aWormKey{Ptr32<const char> text;template <class W3dU> F14aWormKey(Ptr32<W3dU> w3d_p) : F14aWormKey((const char *)w3d_p.get()) {}
 F14aWormKey(const char*t):text(t){}};
extern "C" unsigned fn_80162c20();
extern "C" int fn_800fc2b0(Ptr32<F14aWormKey>,Ptr32<Ptr32<const char>>),fn_800fc550(Ptr32<F14aWormKey>,Ptr32<const char>);
extern "C" int fn_802ef9c0(Ptr32<const char>),fn_802ef380(Ptr32<const char>,Ptr32<const char>);
extern "C" Ptr32<F14aWormText_803426b8> fn_8020bd38(Ptr32<F14aWormText_803426b8>,Ptr32<const char>);
extern "C" void fn_8020c3a0(Ptr32<F14aWormText_803426b8>,int),fn_8020c510(Ptr32<F14aWormText_803426b8>,Ptr32<const char>,...);
extern const char key_803d0d64[],delimiter_803d0d78[],format_803d0a0c[];
inline int remainingAfterSpan(int length,int span){int n=length-1;n-=span;return n;}
extern "C" void w3d_f14a_random_worm_name_8029d410(Ptr32<void>,int worm){
 int separators=0;unsigned random=fn_80162c20();
 F14aWormKey key(key_803d0d64);Ptr32<const char> names;Ptr32<const char> selected;
 if(fn_800fc2b0(&key,&names)>=0){
  int remaining=fn_802ef9c0(names);selected=names;int span;
  while((span=fn_802ef380(selected,delimiter_803d0d78))!=remaining){
   remaining=remainingAfterSpan(remaining,span);selected+=span+1;++separators;
  }
 }
 ++separators;random%=separators;selected=names;
 separators=0;for(;separators!=random;++separators)selected+=fn_802ef380(selected,delimiter_803d0d78)+1;
 F14aWormText_803426b8 name;fn_8020bd38(&name,selected);fn_8020c3a0(&name,fn_802ef380(selected,delimiter_803d0d78));
 F14aWormText_803426b8 property;fn_8020c510(&property,format_803d0a0c,worm);
 F14aWormKey target(property.text);fn_800fc550(&target,name.text);
}


