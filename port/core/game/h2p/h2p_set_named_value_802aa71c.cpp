#include "w3d_ptr.h"
#line 1 "h2p_set_named_value_802aa71c.cpp"
// Native shared-string and held-interface lifetimes; semantic names are inferred.
// String and Held are complete four-byte GC32 values; Owner is only an external view.
// The copy/release path is observed but its original diagnostic purpose is unknown.
struct String;
struct Header { unsigned short refs,length,capacity; };
extern "C" void fn_8020c5c0(Ptr32<String>),fn_8020c5c4(Ptr32<String>),fn_80341588(Ptr32<String>);
extern "C" Ptr32<Header> fn_80341884(Ptr32<String>);
struct String {
 Ptr32<char> text;
 String(const String&other) {fn_8020c5c0(this);text=other.text;++fn_80341884(this)->refs;}
 ~String(){fn_8020c5c4(this);fn_80341588(this);}
};
struct Interface { Ptr32<Ptr32<void>> vtable; };
struct Held { Ptr32<Interface> p; Held():p(0){} ~Held(){if(p)((Ptr32<void (Ptr32<Interface>)>)p->vtable[4])(p);} };
struct NameRef {Ptr32<char> text;NameRef(const String&s):text(s.text){} };
struct Owner {char unknown0[224];int updating;}; // external prefix only
extern "C" int fn_800fc1b0(Ptr32<const NameRef>,Ptr32<Held>);
extern "C" Ptr32<Interface> fn_803426b4(Ptr32<Interface>);
extern "C" Ptr32<Interface> fn_80342a78(Ptr32<Interface>);
extern "C" int fn_80178c54(Ptr32<Interface>,Ptr32<const unsigned int>),fn_80178d28(Ptr32<Interface>,Ptr32<const unsigned int>);
inline void setSecond(Ptr32<Interface> p,unsigned value) {fn_80178d28(p,&value);}
extern "C" void h2p_set_named_value_802aa71c(Ptr32<Owner> self,String name,unsigned value) {
 Held held;
 if(!((Ptr32<Header>)(name.text-6))->length)return;
 {
  NameRef ref(name);
  if(fn_800fc1b0(&ref,&held)<0) {{String copy(name);}return;}
  else {
   self->updating=1;
   switch(((Ptr32<int (Ptr32<Interface>)>)held.p->vtable[6])(held.p)) {
   case 0:fn_80178c54(fn_803426b4(held.p),&value);break;
   case 1:setSecond(fn_80342a78(held.p),value);break;
   default:{String copy(name);break;}
   }
   self->updating=0;
  }
 }
}


