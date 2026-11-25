// Native shared-string and held-interface lifetimes; semantic names are inferred.
// String and Held are complete four-byte GC32 values; Owner is only an external view.
// The copy/release path is observed but its original diagnostic purpose is unknown.
struct String;
struct Header { unsigned short refs,length,capacity; };
extern "C" void fn_8020c5c0(String*),fn_8020c5c4(String*),fn_80341588(String*);
extern "C" Header* fn_80341884(String*);
struct String {
 char*text;
 String(const String&other) {fn_8020c5c0(this);text=other.text;++fn_80341884(this)->refs;}
 ~String(){fn_8020c5c4(this);fn_80341588(this);}
};
struct Interface { void**vtable; };
struct Held { Interface*p; Held():p(0){} ~Held(){if(p)((void(*)(Interface*))p->vtable[4])(p);} };
struct NameRef {char*text;NameRef(const String&s):text(s.text){} };
struct Owner {char unknown0[224];int updating;}; // external prefix only
extern "C" int fn_800fc1b0(const NameRef*,Held*);
extern "C" Interface* fn_803426b4(Interface*);
extern "C" Interface* fn_80342a78(Interface*);
extern "C" int fn_80178c54(Interface*,const unsigned*),fn_80178d28(Interface*,const unsigned*);
inline void setSecond(Interface*p,unsigned value) {fn_80178d28(p,&value);}
extern "C" void h2p_set_named_value_802aa71c(Owner*self,String name,unsigned value) {
 Held held;
 if(!((Header*)(name.text-6))->length)return;
 {
  NameRef ref(name);
  if(fn_800fc1b0(&ref,&held)<0) {{String copy(name);}return;}
  else {
   self->updating=1;
   switch(((int(*)(Interface*))held.p->vtable[6])(held.p)) {
   case 0:fn_80178c54(fn_803426b4(held.p),&value);break;
   case 1:setSecond(fn_80342a78(held.p),value);break;
   default:{String copy(name);break;}
   }
   self->updating=0;
  }
 }
}
