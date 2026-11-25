#include "w3d_ptr.h"
#line 1 "f6a_scheme_flag_80293020.cpp"
// Observed string ABI and interface slots only; semantic roles inferred.
extern "C" void fn_8020c5c0(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
struct String {Ptr32<char> text;String(const String&o){fn_8020c5c0(this);text=o.text;Ptr32<unsigned short> h=fn_80341884(this);++*h;}~String(){fn_8020c5c4(this);fn_80341588(this);}};
struct Key {Ptr32<const char> text;template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char*p):text(p){}};
struct Handle {Ptr32<void> p;int unknown;Handle():p(0){}~Handle(){if(p)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)p)[4](p);}int kind(){return (*(Ptr32<Ptr32<Ptr32<int (Ptr32<void>)>>>)p)[6](p);}};
extern "C" int fn_800fc1b0(Ptr32<Key>,Ptr32<Handle>);
extern "C" Ptr32<void> fn_803426b4(Ptr32<void>); Ptr32<void> fn_80342a78(Ptr32<void>);
extern "C" void fn_80178c54(Ptr32<void>,Ptr32<int>),fn_80178d28(Ptr32<void>,Ptr32<int>);
extern char schemes_803d0164[];
extern "C" Ptr32<void> fn_80341584(Ptr32<void>); Ptr32<void> fn_801797b4(Ptr32<void>);
struct List{char unknown[24];unsigned count;};
struct Data{char unknown[20];Ptr32<List> schemes;};
extern "C" void w3d_f6a_scheme_flag_80293020(Ptr32<void>,String name){
 if(((Ptr32<unsigned short>)name.text)[-2]){
 Handle valueHandle;Handle dataHandle;int value=1;
 Key dataKey(schemes_803d0164);
 if(fn_800fc1b0(&dataKey,&dataHandle)<0)return;
 Ptr32<Data> data=(Ptr32<Data>)fn_801797b4(fn_80341584(dataHandle.p));
 if(data->schemes->count>15)value=0;
 Key key(name.text);
 if(fn_800fc1b0(&key,&valueHandle)<0){String diagnostic(name);return;}
 switch(valueHandle.kind()){
 case 0:fn_80178c54(fn_803426b4(valueHandle.p),&value);break;
 case 1:fn_80178d28(fn_80342a78(valueHandle.p),&value);break;
 }
 }
}


