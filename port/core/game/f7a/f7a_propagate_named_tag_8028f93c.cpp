#include "w3d_ptr.h"
#line 1 "f7a_propagate_named_tag_8028f93c.cpp"
// Observed handles and dynamic tag descriptor; semantic types inferred.
struct F7aObject{Ptr32<Ptr32<void>> table;};
inline void retain(Ptr32<F7aObject> p){if(p)((Ptr32<void (Ptr32<F7aObject>)>)p->table[3])(p);}
inline void release(Ptr32<F7aObject> p){if(p)((Ptr32<void (Ptr32<F7aObject>)>)p->table[4])(p);}
struct F7aHandle{Ptr32<F7aObject> p;F7aHandle():p(0){}template <class W3dU> F7aHandle(Ptr32<W3dU> w3d_p) : F7aHandle((F7aObject *)w3d_p.get()) {}
 F7aHandle(F7aObject*x):p(x){retain(p);}F7aHandle(const F7aHandle&o):p(o.p){retain(p);}~F7aHandle(){release(p);}template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((F7aObject *)w3d_p.get()); }
 F7aHandle&operator=(F7aObject*next){retain(next);release(p);p=next;return *this;}F7aHandle&operator=(const F7aHandle&o){Ptr32<F7aObject> next=o.p;if(next){retain(next);release(p);p=next;}return *this;}};
struct F7aTag_80178474{int zero;unsigned type;F7aTag_80178474():zero(0),type(58280){}~F7aTag_80178474();};
extern "C" void fn_80178474(Ptr32<void>,int);

struct F7aKey{Ptr32<const char> text;template <class W3dU> F7aKey(Ptr32<W3dU> w3d_p) : F7aKey((const char *)w3d_p.get()) {}
 F7aKey(const char*p):text(p){}};
extern char barracks_803ceaa0[];
extern "C" int fn_800fc1b0(const F7aKey&,F7aHandle&);
extern "C" Ptr32<F7aObject> fn_80341584(Ptr32<F7aObject>);
extern "C" Ptr32<F7aObject> fn_80179598(Ptr32<F7aObject>,Ptr32<F7aTag_80178474>);
extern "C" void fn_801ea4c8(Ptr32<F7aObject>,Ptr32<void>);
extern "C" void w3d_f7a_propagate_named_tag_8028f93c(Ptr32<void>,Ptr32<const char> name,Ptr32<void> target){
 if(target){
 F7aHandle object;
 {F7aHandle value;fn_800fc1b0(*(Ptr32<const F7aKey>)&name,value);object=fn_80341584(value.p);}
 F7aTag_80178474 tag;
 fn_801ea4c8(fn_80179598(object.p,&tag),target);
 }
}


